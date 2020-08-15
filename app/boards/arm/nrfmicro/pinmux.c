/*
 * Copyright (c) 2017 I-SENSE group of ICCS
 *
 * SPDX-License-Identifier: MIT
 */

#include <kernel.h>
#include <device.h>
#include <init.h>
#include <drivers/gpio.h>
#include <sys/sys_io.h>
#include <devicetree.h>
#include <pinmux/stm32/pinmux_stm32.h>

static int pinmux_stm32_init(struct device *port)
{
	ARG_UNUSED(port);

	struct device *dev = device_get_binding("GPIO_1");

	// enable EXT_VCC (use 0 for nRFMicro 1.3, use 1 for nRFMicro 1.1)
	gpio_pin_configure(dev, 9, GPIO_OUTPUT);
	gpio_pin_set(dev, 9, 0);

	// enable charger (nRFMicro 1.3 only)
	gpio_pin_configure(dev, 5, GPIO_OUTPUT);
	gpio_pin_set(dev, 5, 0);

	return 0;
}

SYS_INIT(pinmux_stm32_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);

