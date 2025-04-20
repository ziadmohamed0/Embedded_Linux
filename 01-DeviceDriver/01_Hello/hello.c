#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ziad");
MODULE_DESCRIPTION("First Module in device driver course");

static int __init my_init(void) {
	printk("Hello My first driver :) \n");
	return 0;
}

static void __exit my_exit(void) {
	printk("Goodbye My first Driver :( \n");
}

module_init(my_init);
module_exit(my_exit)
