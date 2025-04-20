/* Includes */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>

/* Meta Informations */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ziad Mohammed Fathy");
MODULE_DESCRIPTION("Device Read session.");

/* Macros */
#define minor_num	0
#define minor_count	1
#define device_name	"deviceTest"
#define device_count	1
#define class_name	"classTest"
#define SIZE		255

/* Variables */
dev_t device;
struct class *myClass;
struct device *myDevice;
struct cdev st_characterDevice;
static unsigned char buffer[SIZE] = "this massage from the driver";

/* file operations */
ssize_t driver_read(struct file *file, char __user *user_buffer, size_t count, loff_t *offs) {
	int not_copied = 0; 
	printk("%s : the count to read %d\n", __func__, count);
	printk("%s : the offs %lld\n", __func__, *offs);
	if((count + *offs) > SIZE) {
		count = SIZE - *offs;
	}
	not_copied = copy_to_user(user_buffer, &buffer[*offs], count);
	if(not_copied) {
		return -1;
	}
	* offs = count;
	printk("%s : not copied %d\n",__func__, not_copied);
	printk("%s : massage : %s\n", __func__, user_buffer);
	return 0;	
}

static int driver_open(struct inode *device_file, struct file *instance) {
	printk("Device is open\n");
	return 0;
}

static int driver_close(struct inode *device_file, struct file *instance) {
	printk("Device is close\n");
	return 0;
}

struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = driver_open,
	.release = driver_close,
	.read = driver_read,
};

static int __init my_init(void) {
	int retval = 0;
	
	/* 1- allocated device */
	retval = alloc_chrdev_region(&device, minor_num, minor_count, device_name);
	if(retval == 0) {
		printk("minor number = %d\n major number = %d\n",MINOR(device),MAJOR(device));
	}
	else {
		printk("ERROR - device can not allocated\n");
		return -1;
	}

	/* 2- character device */
	cdev_init(&st_characterDevice, &fops);
	retval = cdev_add(&st_characterDevice, device, device_count); 
	if(retval != 0) {
		printk("ERROR - device can not allocated\n");
		goto ERROR_CHARACTER;
	}

	/* 3- class add */
	if((myClass = class_create(class_name)) == NULL) {
		printk("ERROR - Class can not be created\n");
		goto ERROR_CLASS;
	}	

	/* 4- device driver create */
	myDevice = device_create(myClass, NULL, device, NULL, "deviceTest");
	if(myDevice == NULL) {
		printk("ERROR - can not be create a device\n");
		goto ERROR_DEVICE;
	}
	return 0;

ERROR_DEVICE:
	class_destroy(myClass);	
ERROR_CLASS:
	cdev_del(&st_characterDevice);
ERROR_CHARACTER:
	unregister_chrdev_region(device, minor_count);
	return -1;
}

static void __exit my_exit(void) {
	cdev_del(&st_characterDevice);
	device_destroy(myClass, device);
	class_destroy(myClass);	
	unregister_chrdev_region(device, minor_count);
}


module_init(my_init);
module_exit(my_exit);
