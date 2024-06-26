# Parts list

Parts required for base model are:

* Arduino pro mini clone - must be 5V 16mhz variant - I bought them from [here](https://www.aliexpress.com/item/32966475348.html)

* 4x CD66 or CD61 nixie tubes

* LM7805L voltage regulator (or equivalent) - I used L7805CV purchased from [here](https://www.aliexpress.com/item/32549779686.html)

* 4x 20K 0.4W resistors

* 4x 0603 100nF capacitors

* 2x 0603 10uF capacitors

* High-voltage power supply capable of reaching 170v

* 12V power supply with at least 3 amps of output power

Optional extras but highly recommended:

* DS3231 RTC - will keep time if power is lost - I purchased mine from [here](https://www.aliexpress.com/item/32533518502.html)

  *note - currently on the schematic it is attached to VCC lines - you'll want to use some sort of rechargeable battery with it.*

* CH9340C TTL board - will allow easy reprogramming without soldering - I purchased mine [here](https://www.aliexpress.com/item/4001214247042.html)

* Type-C decoy board - will allow you to use PD power bricks for powering this board. I designed this project with [this](https://www.aliexpress.com/item/1005005492367745.html) board in mind.
