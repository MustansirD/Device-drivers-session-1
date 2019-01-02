/*
Filename	:module2.c
Author		:Mustansir
Teamlead	:Rajesh Dommaraju
Details		:Module2 for exporting symbol demonstation
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

/****************************Declaring  extern func and variables**********/

void print_hello(int);
void add_two_numbers(int,int); 
int GLOBAL_VARIABLE;
//Note:If undeclared then gives error for implicit declrtn for a function and undecld for a var
//error
/***************************Local Functions*********************************/



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
	printk(KERN_INFO "Inside the init_func module2\n");
	print_hello(10);
	add_two_numbers(78,100);
	printk(KERN_INFO "Value of Global Variable %d\n",GLOBAL_VARIABLE);
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
	printk(KERN_INFO "Inside the exit func module2\n");

}

//--------------------------------------------------------------------------
module_init(init_func);
module_exit(exit_func);

MODULE_LICENSE(GPL_LICENSE);
MODULE_AUTHOR(DRIVER_MODULE_AUTHOR);
MODULE_VERSION(DRIVER_MODULE_VERSION);
MODULE_DESCRIPTION(DRIVER_MODULE_DESC);


