# Keychron K8 Firmware

Custom QMK Firmware for the Keychron K8 for me. 

Note that Keychron never officially released a QMK port of the non-pro K8, but
the SonixQMK community provides an open-source in-official setup. Use at your
own risk. Since fork is also not officially supported by QMK, it may lack behind
the current development in features.

Also note that I do not use the Bluetooth functionality on my board, so that
may or may not work for you.

## Prerequisities

- The [Sonix Flasher](https://github.com/SonixQMK/sonix-flasher)
- The [Make](https://gnuwin32.sourceforge.net/packages/make.htm#:~:text=Make%20is%20a%20tool%20which,compute%20it%20from%20other%20files) build tool
- The [QMK MSYS](https://msys.qmk.fm/) development environment (set
  environment variable `QMK_HOME` to path of installation)
- The [Sonix port](https://github.com/SonixQMK/qmk_firmware) of QMK. At the
  time of writing, the `sn32` branch seems to be the most stable. \
  Take care to clone submodules as well.

``` bash
git clone git@github.com:SonixQMK/qmk_firmware.git qmk_sonix --recurse-submodules --branch sn32_master
```

- This repository cloned into the `keyboards\keychron\k8\keymaps\fl3pp`
  subdirectory

## Make

This repository contains a `Makefile` with all necessary commands. Your need to
execute `make setup` once before the other commands work though.

## Flashing

To flash your keyboard with your custom firmware binary your need the Sonix
flasher tool. Start the executable and select following options:

- `Device`: SN32F24X and your connected keyboard
- `qmk offset`: `0x00`
- `Flash QMK...`: Find your compiled binary in the `.build` directory

Before you can flash you need to put your keyboard into bootloader mode. There
is a key for that in QMK, but for the first time you need to jump some pins.

[CanUnesis guide](https://github.com/CanUnesi/QMK-on-K6/blob/main/README.md)
works fine for the K8 as well, with the pins located just under the space bar.
Use the official [Keychron
guide](https://www.keychron.com/pages/disassemble-process-for-k8) to take your
board apart. 

