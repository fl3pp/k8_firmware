ROOT_DIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
MSYS := $(ROOT_DIR)msys.cmd

all: build

build:
	$(MSYS) qmk compile -j 8

console:
	$(MSYS) qmk console

setup:
	$(MSYS) qmk config user.hide_welcome=True
	$(MSYS) qmk setup --home "C:/dev/qmk_sonix" --yes
	$(MSYS) qmk config user.keyboard=keychron/k8/rgb/ansi
	$(MSYS) qmk config user.keymap=fl3pp

clean:
	$(MSYS) qmk clean
