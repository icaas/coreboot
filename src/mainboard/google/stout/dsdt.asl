/* SPDX-License-Identifier: GPL-2.0-only */
/* This file is part of the coreboot project. */

#include <acpi/acpi.h>
#include <acpi/acpi.h>
DefinitionBlock(
	"dsdt.aml",
	"DSDT",
	0x02,       // DSDT revision: ACPI v2.0 and up
	OEM_ID,
	ACPI_TABLE_CREATOR,
	0x20110725  // OEM revision
)
{
	#include <southbridge/intel/common/acpi/platform.asl>

	#include "acpi/platform.asl"
	#include "acpi/mainboard.asl"

	// Thermal handeler
	#include "acpi/thermal.asl"

	// global NVS and variables
	#include <southbridge/intel/bd82x6x/acpi/globalnvs.asl>

	#include <cpu/intel/common/acpi/cpu.asl>

	Scope (\_SB) {
		Device (PCI0)
		{
			#include <northbridge/intel/sandybridge/acpi/sandybridge.asl>
			#include <southbridge/intel/bd82x6x/acpi/pch.asl>

			#include <drivers/intel/gma/acpi/default_brightness_levels.asl>
		}
	}

	#include <vendorcode/google/chromeos/acpi/chromeos.asl>

	#include <southbridge/intel/common/acpi/sleepstates.asl>
}
