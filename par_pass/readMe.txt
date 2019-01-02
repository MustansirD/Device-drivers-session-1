File name	:var_pass.c
Description	:The program is used to pass the  value of a variable during the 		 time of  loading the module inside the kernel space.
  
Steps to compile:1.Create a Makefile and run the makefile using make command
		 2.A .ko with the same filename as .c file will be generated.
		 3.run the command "dmesg" or "tail -f /var/log/syslog" before 
		 loading the kernel module into the kernel space(step 4). here
		 the messages that are present in the printk will be displayed.
		 4.Now load and pass the value of paramTest=18  into the kernel 		 using the following command under the terminal
		 "sudo insmod filename.ko paramTest=18"
		 The message present inside the init_func will logged and 
		 displayed under tail -f /var/log/syslog command
		 5.In order to check whether the module got loaded into the 
		 kernel space run command
		 "lsmod" which will list all the modules which are loaded by the kernel.
		 6.Use "sudo rmmod filename.ko" command to remove the module
		 from the kernel space.The message that is present in the printk function in the exit_func will be printed under log


//-----------------------------------------------------------------------------

File name       :array_pass.c
Description     :The program is used pass for an array  during the time of
                 loading module  inside the kernel space.

Steps to compile:1.Create a Makefile and run the makefile using make command
                 2.A .ko with the same filename as .c file will be generated.
                 3.run the command "dmesg" or "tail -f /var/log/syslog" before
                 loading the kernel module into the kernel space(step 4). here
                 the messages that are present in the printk will be displayed.
                 4.Now load and pass the value of paramTest=18  into the kernel                  using the following command under the terminal
                 "sudo insmod filename.ko paramTest=1,100,1000"
                 The message present inside the init_func will logged and
                 displayed under tail -f /var/log/syslog command
                 5.In order to check whether the module got loaded into the
                 kernel space run command
                 "lsmod" which will list all the modules which are loaded by the kernel.
                 6.Use "sudo rmmod filename.ko" command to remove the module
                 from the kernel space.The message that is present in the printk function in the exit_func will be printed under log

