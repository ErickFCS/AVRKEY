call eavr > nul
avr-gcc -mmcu=atmega328p -DF_CPU=16000000 -Iusbdrv -I. -Os -o out.elf main.c usbdrv/usbdrv.c usbdrv/usbdrvasm.S
