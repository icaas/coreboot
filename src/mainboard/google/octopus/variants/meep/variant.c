/* SPDX-License-Identifier: GPL-2.0-only */
/* This file is part of the coreboot project. */

#include <ec/google/chromeec/ec.h>
#include <drivers/intel/gma/opregion.h>
#include <baseboard/variants.h>
#include <variant/sku.h>
#include <sar.h>

const char *get_wifi_sar_cbfs_filename(void)
{
	const char *filename = NULL;
	uint32_t sku_id = google_chromeec_get_board_sku();

	switch (sku_id) {
	case SKU_1_MEEP:
	case SKU_2_MEEP:
	case SKU_3_MEEP:
	case SKU_4_MEEP:
		filename = "wifi_sar-meep.hex";
		break;
	case SKU_49_VORTININJA:
	case SKU_50_VORTININJA:
	case SKU_51_VORTININJA:
	case SKU_52_VORTININJA:
		filename = "wifi_sar-vortininja.hex";
		break;
	}
	return filename;
}

const char *mainboard_vbt_filename(void)
{
	uint32_t sku_id;

	sku_id = google_chromeec_get_board_sku();

	switch (sku_id) {
	case SKU_33_DORP:
	case SKU_34_DORP:
	case SKU_35_DORP:
	case SKU_36_DORP:
		return "vbt_dorp_hdmi.bin";
	case SKU_49_VORTININJA:
	case SKU_50_VORTININJA:
	case SKU_51_VORTININJA:
	case SKU_52_VORTININJA:
	case SKU_65_VORTICON:
	case SKU_66_VORTICON:
		return "vbt_vortininja.bin";
	default:
		return "vbt.bin";
	}
}
