/*
Filename	:module1.c
Author		:Mustansir
Teamlead	:Rajesh Dommaraju
Details		:Module1 for demonstation of dependency
License		:Spanidea Systems Pvt. Ltd. All rights reserved
*/

/*****************************INCLUDES****************************************/

#include<linux/module.h>
#include<linux/init.h>

/*****************************Local Macros***********************************/

#define GPL_LICENSE		"GPL"
#define DRIVER_MODULE_AUTHOR	"SPANIDEA"
#define DRIVER_MODULE_DESC	"Module Dependency"
#define DRIVER_MODULE_VERSION	"1.0.0"

/****************************Local Typedef***********************************/

/***************************Global variables**********************************/

int GLOBAL_VARIABLE = 1000;

EXPORT_SYMBOL(GLOBAL_VARIABLE);

/***************************Local Functions*********************************/

//--------------------Function definitions------------------------------

/*
funtion		:print_hello
description	:print hello in log file until "num" is equal to 0
input_param	:int num
output_param	:none
*/

void print_hello(int num){
	while(num--){
	printk(KERN_INFO "Hello\n");
	}
}

EXPORT_SYMBOL(print_hello);

//---------------------------------------------------------------------

/*
funtion         :add_two_numbers
description     :print the addition result
input_param     :int a,int b
output_param    :none
*/



void add_two_numbers(int a,int b){
	printk(KERN_INFO "sum of the numbers %d\n",a+b);
}

EXPORT_SYMBOL(add_two_numbers);

//-----------------Declaration of init and exit func-------------------------------------

static int init_func(void);
static void exit_func(void);

//-------------------------------------------------------------------------

/*
function	:init_func
description	:the function is loaded into the kernel space by using insmod			 utility
input_param	:none
output_param	:none
*/

static int init_func(void){
	printk(KERN_INFO "Inside the init_func of module1.c file\n");
	return 0;
	
}

//--------------------------------------------------------------------------

//-------------------------------------------------------------------------

/*
function        :exit_func
description     :The func is unloaded from the kernel space using rmmod utility
input_param     :none
output_param    :none
*/

static void exit_func(void){
	printk(KERN_INFO "Inside the exit func of module1.c file\n");

}

//--------------------------------------------------------------------------
module_init(init_func);
module_exit(exit_func);

MODULE_LICENSE(GPL_LICENSE);
MODULE_AUTHOR(DRIVER_MODULE_AUTHOR);
MODULE_VERSION(DRIVER_MODULE_VERSION);
MODULE_DESCRIPTION(DRIVER_MODULE_DESC);

