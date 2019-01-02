/*
fileName:	array_pass.c
author	:	Mustansir
teamLead:	Rajesh Dommaraju
Details	:	Driver to understand about array as parameter passing to module
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
#define DRIVER_MODULE_DESC	"array as a parameter  passing to the module"
#define DRIVER_MODULE_VERSION	"1.0.0"

//----------------------------------------------------------------------------

/*Local typedef */

//---------------------------------------------------------------------------

/*Global variables*/

int paramTest[3];// Integer array that will pass at module load time
module_param_array(paramTest,int,NULL,S_IRUGO);
/*
	module_param_array is a macro used to send array as argument
	The macro takes the following paramaters
	name of the array,datatype of the array and permisiion mask
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
	printk(KERN_ALERT "In the init function of array_pass.c file\n");
	printk(KERN_ALERT "value of paramTest0=%d\n paramTest1=%d\n paramTest2=%d\n",paramTest[0],paramTest[1],paramTest[2]);
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
        printk(KERN_INFO "In the exit function of array_pass.c file\n");
}

//----------------------------------------------------------------------------

module_init(init_func);
module_exit(exit_func);


MODULE_LICENSE(GPL_LICENSE);
MODULE_AUTHOR(DRIVER_MODULE_AUTHOR);
MODULE_VERSION(DRIVER_MODULE_VERSION);
MODULE_DESCRIPTION(DRIVER_MODULE_DESC);

