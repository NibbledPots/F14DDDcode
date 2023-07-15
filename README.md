# F14DDDcode
The code for the F-14 PCB
This code is split into two sections, the original code I used with QMK and setting keybinds for each button, and the newer version that I intend to use with DCSBios.

QMK is the software that I am most familiar with, and I know this code will work, all you need to do is flash the hex file with QMK toolbox, then assign the key binds.
More on QMK here: https://docs.qmk.fm/#/

The DCSBios code is very rough around the edges, and I have had trouble getting it to work with the Pro Micro, as DCSBios isn't great for ATMega32u4 controllers. However, I have included it regardless of the issues because I believe this repository's audience will be more familiar with DCSBios than QMK.
