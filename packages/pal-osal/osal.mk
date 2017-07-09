
#
#	osal 
#
OSAL_VERSION:=18.3.10471.226317
OSAL_DIR:=$(PROJECT_BUILD_DIR)/osal-$(OSAL_VERSION)
OSAL_DEPS+= kernel SMD_Common toolchain 

ifneq ($(wildcard package/Makefile.IntelCE.in),)
$(eval $(call INTELCE_AUTOTARGETS,package,osal))
else

.PHONY: osal
osal: $(OSAL_DEPS) $(OSAL_DIR)/.built

$(OSAL_DIR)/.unpacked:
	mkdir -p $(OSAL_DIR)
	$(call INTELCE_UNPACKAGE_COMPONENT,osal,$(OSAL_VERSION))
	rm -f $(BASE_DIR)/package/osal/src
	ln -s $(OSAL_DIR)/ $(BASE_DIR)/package/osal/src
	touch $@

.PHONY: osal-unpackage
osal-unpackage: $(OSAL_DIR)/.unpacked

$(OSAL_DIR)/.built: $(OSAL_DIR)/.unpacked
	mkdir -p $(OSAL_DIR)
	$(call INTELCE_DYNAMIC_MAKE,$(OSAL_DIR))
ifneq ($(BR2_INTELCE_FORCE_REBUILD),y)
	touch $@
endif

osal-clean:
ifneq ($(wildcard $(OSAL_DIR)/[Mm]akefile),)
	$(MAKE) $(INTELCE_CONFIGURE_OPTS) -C $(OSAL_DIR) clean
endif
	rm -f $(OSAL_DIR)/.built

ifeq ($(BR2_PACKAGE_OSAL),y)
TARGETS+=osal
INTELCE_TARGETS+=osal
endif
endif
