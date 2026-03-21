#include <MD_DS1307.h>
#include <Wire.h>
#include <math.h>
#include <stdlib.h>

#define A4 3
#define B4 4
#define C4 5
#define D4 6
#define A1 7
#define B1 8
#define C1 9
#define D1 10
#define A2 17
#define B2 12
#define C2 13
#define D2 14
#define A3 15
#define B3 16
#define C3 2
#define D3 1

char A[4] = {A1, A2, A3, A4};
char B[4] = {B1, B2, B3, B4};
char C[4] = {C1, C2, C3, C4};
char D[4] = {D1, D2, D3, D4};

int zero;
int one;
int two;
int three;
int hour;
int minute;
int second;
int scrambleCounter = 0;
bool scrambleActive = false;
unsigned long previousTime = 0;
const unsigned long interval = 1000; // Delay interval in milliseconds

// --- FUNCTION PROTOTYPES ---
int calculateDST(int d, int m, int y, int h);
void writenumber(int a, int b);
void tubeScramble(int timeInSeconds);
void off(int a);

void setup() {
  pinMode(A1, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(B2, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(B3, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(B4, OUTPUT);
  pinMode(C4, OUTPUT);
  pinMode(D4, OUTPUT);
  
  for (char i = 0; i < 4; i++) {
    digitalWrite(A[i], HIGH);
    digitalWrite(B[i], HIGH);
    digitalWrite(C[i], HIGH);
    digitalWrite(D[i], HIGH);
  }

  if (!RTC.isRunning())
    RTC.control(DS1307_CLOCK_HALT, DS1307_OFF);
  
  tubeScramble(30);
}

void loop() {
  RTC.readTime();
  
  // Get raw time from RTC (Standard Time)
  int rawHour = RTC.h;
  int currentDay = RTC.dd;
  int currentMonth = RTC.mm;
  int currentYear = RTC.yyyy; // Ensure your library returns full year (e.g. 2024), if not add 2000
  
  // Calculate adjusted hour
  hour = calculateDST(currentDay, currentMonth, currentYear, rawHour);
  minute = RTC.m;
  second = RTC.s;

  // Handle Overflow (if DST makes 23:00 -> 24:00, wrap to 00:00)
  if (hour >= 24) {
    hour = hour - 24;
  }

  unsigned long currentTime = millis();
  if (currentTime - previousTime >= interval) {
    previousTime = currentTime;

    // Check if it's time for a character scramble
    // Added check to ensure we only scramble once per hour
    if (minute == 31 && second == 30 && !scrambleActive) {
      scrambleActive = true;
      tubeScramble(30);
      scrambleActive = false;
    }

    // Display the time or scrambled characters
    if (!scrambleActive) {
      zero = (hour / 10) % 10;
      one = hour % 10;
      two =  (minute / 10) % 10;
      three = minute % 10;
    } else {
      // Perform the Nixie tube scramble
      tubeScramble(30);
    }

    writenumber(1, zero);
    writenumber(2, one);
    writenumber(3, two);
    writenumber(0, three);
  }
}

// --- DST CALCULATION FUNCTION ---
// Returns the hour + 1 if DST is active, otherwise returns original hour
int calculateDST(int d, int m, int y, int h) {
  // DST in Europe/Lithuania:
  // Starts: Last Sunday of March at 03:00 (Clocks go forward to 04:00)
  // Ends: Last Sunday of October at 04:00 (Clocks go back to 03:00)
  
  // If month is Jan, Feb, Nov, Dec -> Standard Time (Winter)
  if (m < 3 || m > 10) return h; 

  // If month is Apr, May, Jun, Jul, Aug, Sep -> DST (Summer)
  if (m > 3 && m < 10) return h + 1; 

  // Calculation for March and October
  // We need to find the previous Sunday.
  // This formula finds the date of the last Sunday of the current month
  int previousSunday = d - (RTC.dow - 1); // dow: 1=Sun, ... 7=Sat. Check your library if Sunday is 0 or 1.
  // MD_DS1307 usually uses 1=Sunday. If calculation seems off, check if library returns 0 for Sunday.
  
  // But a simpler way for "Last Sunday" rule:
  // The last Sunday in a month with 31 days (Mar, Oct) falls on:
  // 31-(dow of last day).
  // Formula to get day of week for specific date is complex, so we approximate:
  
  // Standard approximation for EU DST:
  // DST starts last Sun March, ends last Sun Oct.
  
  int previousSundayDay = d - RTC.dow + 1; // Assuming RTC.dow returns 1 for Sunday.
  if(RTC.dow == 1) previousSundayDay = d; 

  // MARCH: DST starts on last Sunday at 03:00
  if (m == 3) {
      // Calculate date of last Sunday in March
      // (31 - (5 * y / 4 + 4) % 7) is a common formula for March last sunday
      int lastSunday = 31 - (5 * y / 4 + 4) % 7;
      
      if (d > lastSunday) return h + 1;
      if (d < lastSunday) return h;
      // If it IS the last Sunday
      if (h >= 3) return h + 1; // After 3am, add hour
      return h;
  }

  // OCTOBER: DST ends on last Sunday at 04:00 (Standard time 3am)
  if (m == 10) {
      // Calculate date of last Sunday in October
      int lastSunday = 31 - (5 * y / 4 + 1) % 7;
      
      if (d > lastSunday) return h; // Back to winter time
      if (d < lastSunday) return h + 1; // Still summer time
      // If it IS the last Sunday
      if (h < 3) return h + 1; // Before 3am UTC (which is 4am Summer time), still add hour
      return h;
  }

  return h;
}

void writenumber(int a, int b) {
  switch (b) {
    case 0:
      digitalWrite(A[a], LOW);
      digitalWrite(B[a], LOW);
      digitalWrite(C[a], LOW);
      digitalWrite(D[a], LOW);
      break;
    case 9:
      digitalWrite(A[a], HIGH);
      digitalWrite(B[a], LOW);
      digitalWrite(C[a], LOW);
      digitalWrite(D[a], HIGH);
      break;
    case 8:    
      digitalWrite(A[a], LOW);
      digitalWrite(B[a], LOW);
      digitalWrite(C[a], LOW);
      digitalWrite(D[a], HIGH);      
      break;
    case 7:
      digitalWrite(A[a], HIGH);
      digitalWrite(B[a], HIGH);
      digitalWrite(C[a], HIGH);
      digitalWrite(D[a], LOW);      
      break;
    case 6:
      digitalWrite(A[a], LOW);
      digitalWrite(B[a], HIGH);
      digitalWrite(C[a], HIGH);
      digitalWrite(D[a], LOW);  
      break;
    case 5:
      digitalWrite(A[a], HIGH);
      digitalWrite(B[a], LOW);
      digitalWrite(C[a], HIGH);
      digitalWrite(D[a], LOW);
      break;
    case 4:
      digitalWrite(A[a], LOW);
      digitalWrite(B[a], LOW);
      digitalWrite(C[a], HIGH);
      digitalWrite(D[a], LOW);
      break;
    case 3:
      digitalWrite(A[a], HIGH);
      digitalWrite(B[a], HIGH);
      digitalWrite(C[a], LOW);
      digitalWrite(D[a], LOW);
      break;
    case 2:
      digitalWrite(A[a], LOW);
      digitalWrite(B[a], HIGH);
      digitalWrite(C[a], LOW);
      digitalWrite(D[a], LOW);
      break;
    case 1:
      digitalWrite(A[a], HIGH);
      digitalWrite(B[a], LOW);
      digitalWrite(C[a], LOW);
      digitalWrite(D[a], LOW);      
      break;
  }
}

void tubeScramble(int timeInSeconds) {
  int n1 = round(sqrt((2 * timeInSeconds)/0.001));
  int n2 = 0;
  
  while (n1 > 0) {
    writenumber(1, n2 % 10);
    writenumber(2, n2 % 10);
    writenumber(3, n2 % 10);
    writenumber(0, n2 % 10);
    
    n1--;
    n2++;
    delay(n1);
  }
}

void off(int a) {
  digitalWrite(A[a], HIGH);
  digitalWrite(B[a], HIGH);
  digitalWrite(C[a], HIGH);
  digitalWrite(D[a], HIGH);
}