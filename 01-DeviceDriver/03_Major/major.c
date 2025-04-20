#include <linux/init.h>
#include <linux/moduleparam.h>
#include <linux/module.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ziad");
MODULE_DESCRIPTION("Module test Major in Device Driver");

dev_t Major_num = 0;

static int __init my_init(void) {
	int retval = 0 ;
	retval = alloc_chrdev_region(&Major_num,0,1,"Test_Device");
	if(retval == 0) {
		printk("%s - return value = 0 , registed device number = %d, Minor = %d \n", __FUNCTION__, MAJOR(Major_num),MINOR(Major_num));
	}
	else {
		printk("could not registed device number\n");
		return -1;
	}
	
	return 0;
}

static void __exit my_exit(void) {
	unregister_chrdev_region(Major_num, 1);
	printk("Goodby Major :( \n");
}

module_init(my_init);
module_exit(my_exit);
