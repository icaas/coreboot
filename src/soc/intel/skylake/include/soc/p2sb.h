/* SPDX-License-Identifier: GPL-2.0-only */
/* This file is part of the coreboot project. */

#ifndef _SOC_P2SB_H_
#define _SOC_P2SB_H_

#define HPTC_OFFSET		0x60
#define HPTC_ADDR_ENABLE_BIT	(1 << 7)

#define PCH_P2SB_IBDF			0x6c
#define PCH_P2SB_HBDF			0x70

#define PCH_P2SB_EPMASK0		0xB0

#define PCH_PWRM_ACPI_TMR_CTL		0xFC

#endif /* _SOC_P2SB_H_ */
