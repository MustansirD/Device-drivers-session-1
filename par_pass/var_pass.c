/*
fileName	var_pass.c
author	:	Mustansir
teamLead:	Rajesh Dommaraju
Details	:	Driver to understand about integer datatype parameter passing to 		module
License	:	Spanidea Systems Pvt. Ltd.
*/

//---------------------------------------------------------------------------

/*INCLUDES*/

#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

//----------------------------------------------------------------------------

/*Local Macros*/

#define GPL_LICENSE		"GPL"
#define DRIVER_MODULE_AUTHOR	"SPANIDEA"
#define DRIVER_MODULE_DESC	"Parameter passing to the module"
#define DRIVER_MODULE_VERSION	"2.0.0"

//----------------------------------------------------------------------------

/*Local typedef */

//---------------------------------------------------------------------------

/*Global variables*/

int paramTest;//variable that will passed when the module will be loaded into the kernel
module_param(paramTest,int,S_IRUSR|S_IWUSR);
/*
macro takes  3 parameters:the name of the var,datatype and permissions
The definition of the macro is in linux/moduleparam.h header file located at
/usr/src/$(uname -r)/include/linux path
*/
//---------------------------------------------------------------------------

/*Local variables*/

//---------------------------------------------------------------------------

/*Local Functions prototype*/

static int init_func(void);
static void exit_func(void);

//---------------------------------------------------------------------------

/*
function	:init_func
desc		:This is called when the module is loaded into the kernel by the 		 insmod utitity
input_param	:none
output_param	:none
*/ 

static int init_func(void)
{
	printk(KERN_ALERT "In the init function of var_pass.c file\n");
	printk(KERN_ALERT "value of paramTest=%d\n",paramTest);
	return 0;
}

//---------------------------------------------------------------------------

/*
function        :exit_func
desc            :This is called when the module is unloaded from the kernel by r		 mmod utility
input_param     :none
output_param    :none
*/

static void exit_func(void)
{
        printk(KERN_INFO "In the exit function of var_pass.c file\n");
}

//----------------------------------------------------------------------------

module_init(init_func);
module_exit(exit_func);

MODULE_LICENSE(GPL_LICENSE);
MODULE_AUTHOR(DRIVER_MODULE_AUTHOR);
MODULE_VERSION(DRIVER_MODULE_VERSION);
MODULE_DESCRIPTION(DRIVER_MODULE_DESC);

