# Celeb-61 
*a nod towards Celeb-17 nickname of Makise Kurisu*


<img width="1402" height="767" alt="{D4E6624E-90EE-470E-BB59-F3589989F7F6}" src="https://github.com/user-attachments/assets/66c8f970-3d43-4cd6-9549-1f6cf862453a" />

Working beta version with 2025-05 board design. No more bodges!
# DISCLAIMER
This design is still a prototype, stuff may break and/or change. You've been warned.

## New features:

* usb-c to ttl adapter (optional)

* usb-c power supply (optional)

* better layout

* mounting screw holes


Preview pics 

<img width="1474" height="599" alt="{12444C88-0332-4251-8D5A-DB2188448844}" src="https://github.com/user-attachments/assets/6499dc59-0d23-42ea-a37e-91643f8fdb02" />


Bottom

<img width="1473" height="592" alt="{63C3DD92-8271-487E-8219-108E031BC739}" src="https://github.com/user-attachments/assets/d9e878bb-998f-452a-99f2-5d76ae5440e0" />


Top

![image](https://github.com/dzastsed/Celeb-61/assets/63074962/f1b7556f-8dd0-4f89-9f5b-60615c9a27cb)


Top, artwork edition (legacy design in `old project and gerbers (do not use)` folder)

# Schematic

<img width="2158" height="1558" alt="{0ACC69AB-D940-442C-9313-E54FB51414F8}" src="https://github.com/user-attachments/assets/30bf2764-85bc-494b-a6d4-b268b972f1a2" />

# Firmware

Regular clock, and clock with scrambling code implemented are included `firmware` folder.

- Regular firmware:
Just does the clock function, and nothing more. It probably isn't even up to date with current board design. Not recommended to use.

- Scramlin' firmware:
Does character scramble every hour (after 30 seconds pass at 31 minute mark) to prevent cathode poisoning. Up to date. Use this firmware.

# Known issues

Summer/Winter time improperly (or does not at all?) triggers in Europe.

# Setup guide

refer to [installation.md](https://github.com/dzastsed/Celeb-61/blob/main/installation.md)

# Parts list

refer to [parts.md](https://github.com/dzastsed/Celeb-61/blob/main/parts.md)

# Future improvements

ESP32 support - for wi-fi clock sync etc.

Diode on TTL module power rail to prevent powering it from secondary USB port (or complete removal of 2ndary USB port as this board can be powered by TTL module just fine).

Different board versions for different tube footprints.

# Credits

TheMobas0 - for help on making the scramble code

Greatsccott! - original board design

Elli - for drawing Makise Kurisu art



