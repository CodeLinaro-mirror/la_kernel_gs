// SPDX-License-Identifier: GPL-2.0
/*
 * Module to print ARM64 processor information such as:
 *
 *   - Memory info (granule size, vm address size, etc).
 *   - Cache information.
 *   - System register information.
 */

#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/types.h>

#include "arm64-cache.h"
#include "arm64-mm.h"

static int __init arm64info_init(void)
{
	pr_info("-----------------ARM64 CPU INFO ------------------\n");
	mm_pr_aa64mmfr0_el1_reg();
	mm_pr_sctlr_el1_reg();
	mm_pr_tcr_el1_reg();

	cache_print_clidr_el1();

	return 0;
}

static void __exit arm64info_exit(void)
{
	pr_info("Unloading the module\n");
}

module_init(arm64info_init);
module_exit(arm64info_exit);

MODULE_DESCRIPTION("ARM64 info");
MODULE_LICENSE("GPL v2");
