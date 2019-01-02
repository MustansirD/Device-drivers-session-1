ile name	:module1.c and module2.c
Description	
		:The program willdemonstate  about how to make our functions 
		 available to other modules
		 EXPORT_SYMBOL() helps to provide functions and variables to 
		 other modules.
		 The module which is expecting a variable/function will not 
		 load into the kernel. 
		 

Steps		 1.Insert module1.ko inside kernel space using "sudo insmod 
		  module1.ko" command inside the terminal
		 2.Insert module2.ko inside the kernel using "sudo insmod 
		  module2.ko" command
		 3.Open another terminal window to see the kernel log messages
		  using command "tail -f /var/log/syslog".
		 4.The log messages will appear under window on inserting the
		   respective modules.The output.txt file shows the log message
		 
modprobe utility
modprobe like insmod loads a module into the kernel. It differs in that it will look at the module to be loaded to see whether it references any symbols(var/func) that are not currently defined in the kernel. If any such references are found then modprobe  looks for other modules in the current module search path that define the relevant symbols.It loads them into the kernel as well.

If we use insmod in this situation instead,the command fails with an "unresolved symbols" message left in the system logfile.


