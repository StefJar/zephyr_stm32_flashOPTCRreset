/*
 * flashExt.c
 *
 *  Created on: 16 Aug 2019
 *      Author: stefan jaritz
 */

#include "flashExt.h"

#include <zephyr.h>
#include <logging/log.h>
LOG_MODULE_REGISTER(FLASHEXT, 4);

#include <flash.h>
#include <flash/flash_stm32.h>
#include <flash_registers.h>

bool flashExt_resetFlashOPTCR(struct device * flashDev) {

#ifdef CONFIG_SOC_SERIES_STM32F4X
	/*
	 * make sure that user options are disabled
	 * they affecting if flash read/write operations
	 * are allowed on the flash for spezific sectors
	 */
	struct stm32f4x_flash *regs = FLASH_STM32_REGS(flashDev);

	/* check if we are not in the typical reset config*/
	if (regs->optcr != 0x0FFFFFED) {
		LOG_DBG("flash OPTCR does not have the reset config");
		/* clear OPTLOCK */
		regs->optkeyr = 0x08192A3B;
		regs->optkeyr = 0x4C5D6E7F;
		if (regs->optkeyr & 1) {
			/* still locked so we failed*/
			LOG_ERR("reset flash OPTCR failed");
			return false;
		}
		/* write reset config register content*/
		regs->optcr = 0x0FFFFFED;
		LOG_DBG("flash OPTCR reset");
	} else {
		LOG_DBG("flash OPTCR regisiter is fine");
	}
#endif
	return true;
}
