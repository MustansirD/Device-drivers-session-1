/*
fileName	ex01.c
author	:	Mustansir
teamLead:	Rajesh Dommaraju
Details	:	Driver to understand about loading and unloading of module into
		the kernel space
License	:	Spanidea Systems Pvt. Ltd.
*/

//---------------------------------------------------------------------------

/*INCLUDES*/

#include<linux/init.h>
#include<linux/module.h>

//----------------------------------------------------------------------------

/*Local Macros*/

#define GPL_LICENSE		"GPL"
#define DRIVER_MODULE_AUTHOR	"SPANIDEA"
#define DRIVER_MODULE_DESC	"Parameter passing to the module"
#define DRIVER_MODULE_VERSION	"1.0.0"

//----------------------------------------------------------------------------

/*Local typedef */

//---------------------------------------------------------------------------

/*Global variables*/

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

Note: __FILE__ is a preprocessor macro that expands to full path to to the current file.__FILE__ is useful when generating log statements,error messages intended for programmmers,when throwing exceptions,or when writing debugging code.
*/ 

static int init_func(void)
{
	printk(KERN_ALERT "In the init function of %s at line %d\n",__FILE__,__LINE__);
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
        printk(KERN_INFO "In the exit function of %s at line %d\n",__FILE__,__LINE__);
}

//----------------------------------------------------------------------------

module_init(init_func);
module_exit(exit_func);

MODULE_LICENSE(GPL_LICENSE);
MODULE_AUTHOR(DRIVER_MODULE_AUTHOR);
MODULE_VERSION(DRIVER_MODULE_VERSION);
MODULE_DESCRIPTION(DRIVER_MODULE_DESC);

