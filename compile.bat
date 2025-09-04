@echo off
setlocal
call eavr > nul
@echo on
avr-gcc ^
    -mmcu=atmega328p ^
    -DF_CPU=16000000 ^
    -Iusbdrv ^
    -I. ^
    -Ilib ^
    -Iconfig ^
    -Ichains ^
    -Os ^
    -o build/out.elf ^
    src/main.c ^
    usbdrv/usbdrv.c ^
    usbdrv/usbdrvasm.S
@echo off
endlocal
