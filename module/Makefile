SRC_DIR = src

OBJ = $(SRC_DIR)/fops.o $(SRC_DIR)/driver.o $(SRC_DIR)/param.o

EXTRA_CFLAGS=-I$(PWD)/include/

obj-m += sui_gpio.o

sui_gpio-objs := $(OBJ)

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean