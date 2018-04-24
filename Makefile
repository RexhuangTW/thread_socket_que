#
# Copyright 2016-2017, Gemtek Corporation
# All Rights Reserved.
# 
# $Id$
#

include $(TOPDIR)/rules.mk

PKG_NAME:=thread_socket_que
PKG_RELEASE:=1.0.0

include $(INCLUDE_DIR)/package.mk

define Package/$(PKG_NAME)
  SECTION:=utils
  CATEGORY:=Test package
  SUBMENU:=Packages
  TITLE:=Thread Socket Que
  DEPENDS:= +libpthread +librt
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
	$(MAKE) -C "$(PKG_BUILD_DIR)" \
                CC="$(TARGET_CC)" \
                LD="$(TARGET_CROSS)ld" \
                TARGET_CFLAGS="$(TARGET_CFLAGS)"
endef


define Package/$(PKG_NAME)/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/socket_server $(1)/usr/bin/socket_server
endef

$(eval $(call BuildPackage,$(PKG_NAME)))
