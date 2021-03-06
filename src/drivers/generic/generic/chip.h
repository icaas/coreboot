/* SPDX-License-Identifier: GPL-2.0-only */
/* This file is part of the coreboot project. */

#ifndef __GENERIC_GENERIC_CHIP_H__
#define __GENERIC_GENERIC_CHIP_H__

#if CONFIG(HAVE_ACPI_TABLES)

#include <acpi/acpi_device.h>

#define MAX_GENERIC_PROPERTY_LIST 10

struct drivers_generic_generic_config {
	const char *hid;	/* ACPI _HID (required) */
	const char *cid;	/* ACPI _CID */
	const char *name;	/* ACPI Device Name */
	/*
	 * Autogenerated ACPI Device Name if name is not provided in
	 * devicetree.
	 */
	char autogen_name[5];
	const char *desc;	/* ACPI _DDN */
	unsigned int uid;	/* ACPI _UID */

	/* Generic properties for exporting device-specific data to the OS */
	struct acpi_dp property_list[MAX_GENERIC_PROPERTY_LIST];
	int property_count;
};

#else /* CONFIG_HAVE_ACPI_TABLES */

struct drivers_generic_generic_config { };

#endif /* !CONFIG_HAVE_ACPI_TABLES */

#endif /* __GENERIC_GENERIC_CHIP_H__ */
