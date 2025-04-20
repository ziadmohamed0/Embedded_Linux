#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ziad");
MODULE_DESCRIPTION("Secound module in Devise Driver Course");

int cnt = 0;
module_param(cnt, int, 0664);

static int __init my_init(void) {
	int i = 0;
	for(i = 0; i < cnt; i++) {
		printk("Hi Module :) \n");
	}
	return 0;
}

static void __exit my_exit(void) {
	int i = 0;
	for(i = 0; i < cnt; i++) {
		printk("Goodbye Module :( \n");
	}
}

module_init(my_init);
module_exit(my_exit);
