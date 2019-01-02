File name	:ex01.c
Description	:The file contains two function init_func and exit_func. The 			 message in the init_func is printed using printk func at the 
		 time of loading into the kernel by using the insmod utility.
		 Also the message in the exit_func is primted using the printk
		 function defined under it on using rmmod utility to remove the 		 module from the kernel space.

Steps		:1.Create a Makefile and run the makefile using make command
		 2.A .ko with the same filename as .c file will be generated.
		 3.run the command "dmesg" or "tail -f /var/log/syslog" before 
		 loading the kernel module into the kernel space(step 4). here
		 the messages that are present printk will be displayed.
		 4.Now load the module into the kernel using the following 
		 command under the terminal
		 "sudo insmod filename.ko"
		 The message present inside the init_func will logged and 
		 displayed.
		 5.In order to check whether the module got loaded into the 
		 kernel space run command
		 "lsmod" which will list all the modules which are loaded by the		 kernel.
		 6.Use "sudo rmmod filename.ko" command to remove the module
		 from the kernel space.The message that is present in the printk		 function in the exit_func will be printed under log
