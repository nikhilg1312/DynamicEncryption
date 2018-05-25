#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
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
	{ 0x5eadf54a, "module_layout" },
	{ 0x42566f9c, "nf_unregister_hook" },
	{ 0x3c0c2222, "nf_register_hook" },
	{ 0x2124474, "ip_send_check" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0x79aa04a2, "get_random_bytes" },
	{ 0x2e60bace, "memcpy" },
	{ 0x1795e732, "skb_put" },
	{ 0x83699014, "kmem_cache_alloc_trace" },
	{ 0x85e90336, "kmalloc_caches" },
	{ 0x50eedeb8, "printk" },
	{ 0x7138d6df, "skb_copy_bits" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "752B0B70BB3A4344193646B");
