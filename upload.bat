@echo off
setlocal
call eavr > nul
set AVR_DUDE_CONFIG_PATH="D:\USER\MyPrograms\ArduinoIDE\arduino-1.8.19\hardware\tools\avr\etc\avrdude.conf"
@echo on
avrdude ^
    -C %AVR_DUDE_CONFIG_PATH% ^
    -v ^
    -p m328p ^
    -c arduino ^
    -P COM3 ^
    -b 115200 ^
    -D ^
    -U flash:w:build/out.ihex:i
@echo off
endlocal
