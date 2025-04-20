#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>

/* Meta Informations */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ziad Mohammed");
MODULE_DESCRIPTION("Module init");

/* variables */
dev_t device;
struct cdev st_characterDevice;
struct class *myClass;
struct device *myDevice;

/* Macros */
#define minor_num	0
#define minor_count	1
#define device_name	"myDevice"
#define device_count	1
#define class_name	"myClass"

/* file operations */
static int driver_open(struct inode *device_file, struct file *instance) {
	printk("Driver file is open\n");
	return 0;
}

static int driver_close(struct inode *device_file, struct file *instance) {
	printk("Driver file is closed\n");
	return 0;
}

struct file_operations fops = {
	.owner   = THIS_MODULE,
	.open    = driver_open,
	.release = driver_close,
};

/* initializations & exit functions */
static int __init my_init(void) {
	int retval = 0;

	/* 1- allocated device number */
	retval = alloc_chrdev_region(&device, minor_num, minor_count, device_name);
	if(retval != 0) {
		printk("Device can not allocated\n");
		return -1;
	}
	
	else {
		printk("Minor number = %d - Major number = %d\n", MINOR(device), MAJOR(device));
	}

	/* 2- define driver character or network or block */
	cdev_init(&st_characterDevice, &fops);
	retval = cdev_add(&st_characterDevice, device, device_count);
	if(retval != 0) {
		printk("Failed to register driver\n");
		goto CHARACTER_ERROR;
	}
	
	/* 3- class create */
	if((myClass = class_create(class_name)) == NULL) {
		printk("class can not be created \n");
		goto CLASS_ERROR;
	}

	/* 4- device file */
	myDevice = device_create(myClass, NULL, device, NULL, "myDevice");
       	if(myDevice == NULL) {
		printk("class can not be created \n");
		goto DEVICE_ERROR;
	}
	printk("class created\n");
	return  0;

DEVICE_ERROR:
	class_destroy(myClass);
CLASS_ERROR:
	cdev_del(&st_characterDevice);
CHARACTER_ERROR:
	unregister_chrdev_region(device, minor_count);
	return -1;
}

static void __exit my_exit(void) {
	cdev_del(&st_characterDevice);
	device_destroy(myClass, device);
	class_destroy(myClass);
	unregister_chrdev_region(device, minor_count);
	printk("Goodby driver\n");
}

module_init(my_init);
module_exit(my_exit);
