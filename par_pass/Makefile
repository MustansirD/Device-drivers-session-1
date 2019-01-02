obj-m :=var_pass.o
obj-m +=array_pass.o

all:
	make	-C	/lib/modules/$(shell uname -r)/build	M=$(PWD)	modules

clean:
	make	-C	/lib/modules/$(shell uname -r)/build	M=$(PWD)	 clean
