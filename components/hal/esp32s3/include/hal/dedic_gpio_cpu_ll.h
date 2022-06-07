/*
 * SPDX-FileCopyrightText: 2020-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <stdint.h>

#include "soc/soc_caps.h"

#include "xt_instr_macros.h"
#include "xtensa/config/specreg.h"
#include "xtensa/config/extreg.h"
#include "esp_bit_defs.h"
#include "esp_attr.h"
#include "xtensa/config/core.h"

#ifdef __cplusplus
extern "C" {
#endif

static inline uint32_t dedic_gpio_cpu_ll_read_in(void)
{
    uint32_t value = 0;
    asm volatile("ee.get_gpio_in %0" : "=r"(value) : :);
    return value;
}

static inline uint32_t dedic_gpio_cpu_ll_read_out(void)
{
    uint32_t value = 0;
    asm volatile("rur.gpio_out %0" : "=r"(value) : :);
    return value;
}

static inline void dedic_gpio_cpu_ll_write_all(uint32_t value)
{
    asm volatile("wur.gpio_out %0"::"r"(value):);
}

static inline void dedic_gpio_cpu_ll_write_mask(uint32_t mask, uint32_t value)
{
    asm volatile("ee.wr_mask_gpio_out %0, %1" : : "r"(value), "r"(mask):);
}

#ifdef __cplusplus
}
#endif
