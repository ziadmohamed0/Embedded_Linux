#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/fs.h>
#include <linux/cdev.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ziad Mohammed");
MODULE_DESCRIPTION("implement file device driver session.");

dev_t Driver;
struct cdev st_characterDevice;
struct class *myClass;
struct device *myDevice;

static int open_device(struct inode *devic_file, struct file *instance) {
	return 0; 
}

static int close_device(struct inode *devic_file, struct file *instance) {
	return 0;
}

struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = open_device,
	.release = close_device,
};

static int __init my_init(void) {
	int retval = 0;
	retval = alloc_chrdev_region(&Driver,0,1,"CreateFile");
	
	/* 1- allocate device number  */
	if(retval == 0) {
		printk("%s return value = 0 - Major number = %d - Minor number = %d\n",__FUNCTION__, MAJOR(Driver), MINOR(Driver));		
	}
	else {
		printk("could not registed Device number\n");
		return -1;
	}

	/* 2- define driver character or block or network */
	cdev_init(&st_characterDevice, &fops);
	retval = cdev_add(&st_characterDevice, Driver, 1);
	if(retval != 0) {
		unregister_chrdev_region(Driver, 1);
		printk("Registering of device to kernel dailed!\n");
		return -1;
	}

	/* 3- Generate file (class) */
	if((myClass = class_create("test_class")) == NULL) {
		printk("Device class can not be created\n");
		cdev_del(&st_characterDevice);
		unregister_chrdev_region(Driver, 1);
		return -1;
	}

	/* 4- Create a Device File */
	myDevice = device_create(myClass, NULL, Driver, NULL, "test_file");
	if(myDevice == NULL) {
		printk("Device class can not be created\n");
		cdev_del(&st_characterDevice);
		class_destroy(myClass);
		unregister_chrdev_region(Driver, 1);
		return -1;
	}
	printk("Device Driver is created");
	return 0;
}

static void __exit my_exit(void) {
	cdev_del(&st_characterDevice);	
	device_destroy(myClass, Driver);
	class_destroy(myClass);
	unregister_chrdev_region(Driver, 1);
	printk("Goodby Device :(\n");
}

module_init(my_init);
module_exit(my_exit);
