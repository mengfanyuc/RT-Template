phony := all
all:

include config.mk

ifneq ($(MAKE_LIB),1)
TARGET := $(TARGET_NAME).elf
include source.mk
endif

$(if $(strip $(RTT_ROOT)),,$(error RTT_ROOT not defined))

include execute.mk
