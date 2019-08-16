zephyr_stm32_flashOPTCRreset
############################

a "driver" that resets the OPTC register of the STM32F412 MCU.

This code ONLY works for the stm32F412 series. For other ones the preset value is different.

work around for flash presets that using the OPTC register. Current stm32 flash driver is `not handling OPTC registers <https://github.com/zephyrproject-rtos/zephyr/issues/18263>`_
