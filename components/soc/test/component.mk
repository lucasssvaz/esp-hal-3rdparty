SOC_NAME := $(IDF_TARGET)

COMPONENT_SRCDIRS := $(SOC_NAME)

COMPONENT_ADD_LDFLAGS = -Wl,--whole-archive -l$(COMPONENT_NAME) -Wl,--no-whole-archive


