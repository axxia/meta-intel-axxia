################################################################################
#
# GNUmakefile
#
# Image makefile for LSI Axxia systems.  Along with CROSS_COMPILE and
# tools in the PAT, the following are required.
#
#        ARCH : The architecture.
# DESCRIPTION : A descriptive string for the image.
#     ADDRESS : The load and entry address.
#         DTB : The device tree.
#     VMLINUX : The Linux ELF image.
#
################################################################################

ifdef ARCH
ASSERT_ARCH = 
else
ASSERT_ARCH = \
@echo "ARCH is not defined!" ; exit 1
endif

ifdef DESCRIPTION
ASSERT_DESCRIPTION = 
else
ASSERT_DESCRIPTION = \
@echo "DESCRIPTION is not defined!" ; exit 1
endif

ifdef ADDRESS
ASSERT_ADDRESS = 
else
ASSERT_ADDRESS = \
@echo "ADDRESS is not defined!" ; exit 1
endif

ifdef DTB
ASSERT_DTB = 
else
ASSERT_DTB = \
@echo "DTB is not defined!" ; exit 1
endif

ifdef VMLINUX
ASSERT_VMLINUX = 
else
ASSERT_VMLINUX = \
@echo "VMLINUX is not defined!" ; exit 1
endif

%.its: %.its.in
	@$(ASSERT_ARCH)
	@$(ASSERT_ADDRESS)
	@$(ASSERT_DESCRIPTION)
	@sed -e 's/ARCH/$(ARCH)/' -e 's/LOAD/$(ADDRESS)/' \
		-e 's/ENTRY/$(ADDRESS)/' \
		-e 's/DESCRIPTION/"$(DESCRIPTION)"/' $< >$@

all: clean linux.fit fdt.fit multi.fit

linux.fit: linux.its vmlinux.bin.gz
	mkimage -f linux.its $@

fdt.fit: fdt.its
	@$(ASSERT_DTB)
	cp $(DTB) linux.dtb
	mkimage -f fdt.its $@
	rm -f linux.dtb

multi.fit: multi.its vmlinux.bin.gz
	@$(ASSERT_DTB)
	cp $(DTB) linux.dtb
	mkimage -f multi.its $@
	rm -f linux.dtb

vmlinux.bin.gz: vmlinux.bin
	gzip -f -c -9 $< >$@

vmlinux.bin: $(VMLINUX)
	@$(ASSERT_VMLINUX)
	${CROSS_COMPILE}objcopy -O binary -R .note -R .comment -S $< $@

clean:
	@rm -f vmlinux.bin vmlinux.bin.gz *.its *.img *.fit
