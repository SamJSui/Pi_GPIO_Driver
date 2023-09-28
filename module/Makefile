SRC_DIR = src

OBJ = $(SRC_DIR)/fops.o $(SRC_DIR)/driver.o $(SRC_DIR)/param.o

EXTRA_CFLAGS=-I$(PWD)/include/

obj-m += sui_gpio.o

sui_gpio-objs := $(OBJ)

all: modules junk

modules:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) $@

# Removes all the junk (intermediate compilation) files besides the kernel module
junk:
	@rm -rf *.o
	@rm -rf *.mod *.mod.c
	@find -iname "*.o" -o -iname "*.cmd" -o -iname "Module.symvers" | xargs rm -rf
	@find -iname "*.mod" -o -iname "*.mod.c" -o -iname "modules.order" | xargs rm -rf

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) $@