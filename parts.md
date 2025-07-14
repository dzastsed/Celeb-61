# Parts list

Parts required for base model are: (links are NOT affiliate)

* Arduino pro mini clone - must be 5V 16mhz variant - I bought them from [here](https://www.aliexpress.com/item/32966475348.html)

   *note - there are a couple of versions with different footprint, make sure you get the one I used in this project.*

* 4x CD66 or CD61 nixie tubes

* 4x binary to decimal converter ICs (K155ID1, SN74141N and similar)

* 4x 20K 0.4W resistors

* 4x 0603 100nF capacitors

* 2x 0603 10uF capacitors

* High-voltage power supply capable of reaching 170v - I used [these](https://www.aliexpress.com/item/1005005994400583.html)

* 5V power supply capable of pushing roughly 2 amps. (10W total)

* DS1307 RTC - I purchased mine from [here](https://www.aliexpress.com/item/1005007091017702.html)

  *note - DS3231 module is also supported, but make sure you desolder one resistor (documented [here](https://lastminuteengineers.com/ds3231-rtc-arduino-tutorial/)) if you choose to use a non-rechargeable battery. I also recommend to use this one instead because it keeps the time better due to having an integrated thermometer.*

Optional extras but highly recommended:

* CH9340C TTL board - will allow easy reprogramming without soldering - I purchased mine [here](https://www.aliexpress.com/item/4001214247042.html)

* Type-C breakout board - I purchased mine [here](https://www.aliexpress.com/item/1005006846325447.html)

* A simple tactile switch - Used for easy chip reset, can be either harvested or simply purchased, I bought them [here](https://www.aliexpress.com/item/1005004159746274.html)

* M3 Motherboard standoff kit - Purely cosmetic, can be used together with another spare board to make a good platform to stand on. [link](https://www.aliexpress.com/item/1005007498157463.html)

* 16 pin socket - HIGHLY recommended, because bin2dec converters can be faulty and it's really painful to desolder if that's the case. [link](https://www.aliexpress.com/item/1005003744699628.html)
