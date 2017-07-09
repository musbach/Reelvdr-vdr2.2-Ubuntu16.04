#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xb9d24654, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x7af7faf2, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x6bc3fbc0, __VMLINUX_SYMBOL_STR(__unregister_chrdev) },
	{ 0xe7326be1, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0x264571f2, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0xedc03953, __VMLINUX_SYMBOL_STR(iounmap) },
	{ 0x91f345a6, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x82350d1e, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x347fbc3d, __VMLINUX_SYMBOL_STR(__register_chrdev) },
	{ 0xae8d36e0, __VMLINUX_SYMBOL_STR(unregister_framebuffer) },
	{ 0xd8ccc581, __VMLINUX_SYMBOL_STR(register_framebuffer) },
	{ 0x7a890c8, __VMLINUX_SYMBOL_STR(fb_alloc_cmap) },
	{ 0xe914e41e, __VMLINUX_SYMBOL_STR(strcpy) },
	{ 0xf0b0d220, __VMLINUX_SYMBOL_STR(arch_dma_alloc_attrs) },
	{ 0xb9e72aa5, __VMLINUX_SYMBOL_STR(dma_alloc_from_coherent) },
	{ 0x5247c802, __VMLINUX_SYMBOL_STR(dma_ops) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x4f8b5ddb, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x5944d015, __VMLINUX_SYMBOL_STR(__cachemode2pte_tbl) },
	{ 0xa19de3fd, __VMLINUX_SYMBOL_STR(boot_cpu_data) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x78e739aa, __VMLINUX_SYMBOL_STR(up) },
	{ 0xcc5005fe, __VMLINUX_SYMBOL_STR(msleep_interruptible) },
	{ 0x6dc6dd56, __VMLINUX_SYMBOL_STR(down) },
	{ 0x8329e6f0, __VMLINUX_SYMBOL_STR(memset) },
	{ 0xda7d9b4c, __VMLINUX_SYMBOL_STR(pci_get_device) },
	{ 0x42c8de35, __VMLINUX_SYMBOL_STR(ioremap_nocache) },
	{ 0x28c13fdb, __VMLINUX_SYMBOL_STR(cfb_imageblit) },
	{ 0x5e0cb1dd, __VMLINUX_SYMBOL_STR(cfb_copyarea) },
	{ 0x40b38371, __VMLINUX_SYMBOL_STR(cfb_fillrect) },
	{ 0x50eedeb8, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xf6cca22e, __VMLINUX_SYMBOL_STR(remap_pfn_range) },
	{ 0x3f9dcdb9, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x6e3d0c0e, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xb4390f9a, __VMLINUX_SYMBOL_STR(mcount) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "98DED4F7E9C41B00AD7898D");
