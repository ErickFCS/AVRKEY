@echo off
setlocal
call eavr > nul
@echo on
avr-objcopy ^
    -O ihex ^
    -R .eeprom ^
    build/out.elf ^
    build/out.ihex
@echo off
endlocal
