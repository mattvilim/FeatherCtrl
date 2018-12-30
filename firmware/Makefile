all: compile

compile:
	arduino-cli compile --fqbn adafruit:nrf52:feather52832 -o firmware.hex

flash:
	adafruit-nrfutil dfu genpkg --dev-type 0x0052 --application firmware.hex firmware.zip
	adafruit-nrfutil dfu serial --package firmware.zip -p /dev/ttyUSB0 -b 115200

