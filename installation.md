# Installation guide

## Hardware
First of all, order PCB from any PCB service you like. I used JLCPCB, their default settings worked fine.

After you get the PCBs, solder in all parts. A couple of reccomendations:

ALWAYS use flux. There will never be too much of it. 

Leave nixie tubes for the end. First solder everything else, and write the firmware. Then insert each tube individually, and turn the clock on without soldering them in to test.

## Software
After successfuly soldering everything in, flash the `NixieClock-Scramblin` firmware. In arduino setup select `Arduino Pro or Pro mini` board and upload the firmware.

Now check and see if every single segment shows up correctly in bootup sequence. If everything is right, go to the next step: 

Flash [this](https://github.com/MajicDesigns/MD_DS1307/tree/master/examples/MD_DS1307_Test) firmware, then open up Serial Monitor, set baudrate to 57600 bps, and write in the current clock (refer to the guide that gets printed out.) Make sure you have inserted the RTC battery, otherwise time will be lost upon power loss again.

After successfully setting up and verifying the time, flash `NixieClock-Scramblin` firmware back. And that's it! Clock is now ready for use!
