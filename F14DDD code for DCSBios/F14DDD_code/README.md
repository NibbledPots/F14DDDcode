# DCSBios README
This section is code for DCSBios written in the arduino IDE. I recommend you introduce yourself to DCSBios with [the documentation](https://dcs-bios.readthedocs.io/en/latest/installation.html) before you download this.
A couple of notes:
* This code was originally intended for use with my [DDD PCB](https://github.com/NibbledPots/F14-DDD), which uses a Pro-Micro, because of this I have used the default Serial library (#define DCSBIOS_DEFAULT_SERIAL), since that is the only one compatible with ATMega32u4 controllers. If you use anything with an ATMega328 or ATMega2560 controller, then use IRQ_SERIAL. I intend to add better ATMega32u4 support with the joystick library method.
* Massive credit goes to [this comment](https://forum.dcs.world/topic/80377-hmas-cockpit-build/?do=findComment&comment=3862124) for guiding me through the matrix setup.
