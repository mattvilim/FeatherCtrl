all: compile

compile:
	mkdir bin -p
	arduino-cli compile $(shell pwd)/src/firmware.ino -b adafruit:nrf52:feather52840 -o $(shell pwd)/bin/firmware.ino --build-path $(shell pwd)/bin

flash:
	arduino-cli upload -i $(shell pwd)/bin/firmware.ino.hex -p /dev/ttyACM0 -b adafruit:nrf52:feather52840
