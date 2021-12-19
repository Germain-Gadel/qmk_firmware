# Square46

![Square46](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [Germain Gadel](https://github.com/germain-gadel)
* Hardware Supported: Square46 PCB, Pro Micro and clones
* Hardware Availability: no

Make example for this keyboard (after setting up your build environment):

    make square46:default

Flashing example for this keyboard:

    make square46:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 2 ways:

* **Physical reset pads**: Briefly short the plated holes on the left side of the PCB labeled `RST`.
* **Keycode in layout**: Press the key mapped to `RESET`:  `FN4 + 1` with the default keymap.