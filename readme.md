# Keychron K8 Firmware

Custom QMK Firmware for the Keychron K8 for me. 

Note that Keychron never officially released a QMK port of the non-pro K8, but
the SonixQMK community provides an open-source in-official setup. Use at your
own risk.

Also note that I do not use the Bluetooth functionality on my board and
removed the battery, so these features may or may not work for you.

## Prerequisities

- The [Sonix port](https://github.com/SonixQMK/qmk_firmware) of QMK. At the
  time of writing, the `sn32_master` branch seems to be the most stable.

- A [QMK build envionment](https://docs.qmk.fm/newbs_getting_started) with all required prerequisites. Setup the SonixQMK repository using `qmk setup -H <directory>`,

- This repository cloned into the `keyboards\keychron\k8\keymaps\fl3pp` subdirectory and configure the `qmk` environment to build this keymap (you can use `./setup_qmk.sh`)

- The [Sonix Flasher](https://github.com/SonixQMK/sonix-flasher)

- At _runtime_: [WinCompose](http://wincompose.info/) to enter Unicode code-points. Set
  the compose key to `F13` (in `%appdata%\WinCompose\settings.ini` ->
  `[composing]compose_key=VK.F13`)

## Flashing

To flash your keyboard with your custom firmware binary you to launch the Sonix
flasher tool. Start the executable and select following options:

- `Device`: SN32F24X and your connected keyboard
- `qmk offset`: `0x00`
- `Flash QMK...`: Find your compiled binary in the `.build` directory

Before you can flash you need to put your keyboard into bootloader mode. There
is a key for that in QMK, but for the first time you need to jump some pins.

The [CanUnesis guide](https://github.com/CanUnesi/QMK-on-K6/blob/main/README.md)
for the K6 works fine for the K8 as well, with the pins located just under
the space bar.

