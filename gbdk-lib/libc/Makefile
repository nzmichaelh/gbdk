# Makefile for libc

TOPDIR = ..

include $(TOPDIR)/Makefile.common

LIBC_OBJ = string.o printf.o puts.o \
	isalpha.o isdigit.o islower.o isspace.o isupper.o \
	toupper.o tolower.o

CFLAGS = -I$(TOPDIR)/include
CFLAGS += -m$(PORT) -v
CC = $(SCC)

all: ports platforms

clean: port-clean ports-clean platform-clean

ports:
	for i in $(PORTS); do make port PORT=$$i; done

platforms:
	for i in $(PLATFORMS); do make -C $$i platform PLAT=$$i; done

# Make all the std libs
# Make all the port specific libs
port: port-clean $(LIBC_OBJ)
	mkdir -p $(TOPDIR)/build/$(PORT)
	cp $(LIBC_OBJ) $(TOPDIR)/build/$(PORT)
	cd $(TOPDIR)/build/$(PORT); ls $(LIBC_OBJ) > $(PORT).lib
	make -C asm/$(PORT) port

port-clean:
	rm -f $(LIBC_OBJ) $(CLEANSPEC)

ports-clean:
	for i in $(PORTS); do make -C asm/$$i clean PORT=$$i; done

platform-clean:
	for i in $(PLATFORMS); do make -C $$i clean PLAT=$$i; done

