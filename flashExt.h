/*
 * flashExt.h
 *
 *  Created on: 16 Aug 2019
 *      Author: stefan jaritz
 */

#ifndef DRV_FLASHEXT_H_
#define DRV_FLASHEXT_H_

#include <stdbool.h>
#include <device.h>

bool flashExt_resetFlashOPTCR(struct device * flashDev);

#endif
