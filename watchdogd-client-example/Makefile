include $(TOPDIR)/rules.mk

PKG_NAME:=watchdogd-client-example
PKG_VERSION:=1.0
PKG_RELEASE:=1

# SOURCE_DIR:=/home/buildbot/watchdogd-client-example

include $(INCLUDE_DIR)/package.mk

define Package/watchdogd-client-example
  SECTION:=utils
  CATEGORY:=Examples
  TITLE:=watchdogd example client
  DEPENDS:=+watchdogd
endef

define Package/watchdogd-client-example/description
  a simple watchdogd client example
endef

# define Build/Prepare
# 		mkdir -p $(PKG_BUILD_DIR)
# 		cp $(SOURCE_DIR)/* $(PKG_BUILD_DIR)
# 		$(Build/Patch)
# endef

define Build/Compile
		$(TARGET_CC) $(TARGET_CFLAGS) -o $(PKG_BUILD_DIR)/wdt-sub.o -c $(PKG_BUILD_DIR)/wdt-sub.c
		$(TARGET_CC) $(TARGET_LDFLAGS) -lwdog -o $(PKG_BUILD_DIR)/$1 $(PKG_BUILD_DIR)/wdt-sub.o
endef

define Package/watchdogd-client-example/install
		$(INSTALL_DIR) $(1)/usr/bin
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/watchdogd-client-example $(1)/usr/bin
endef

$(eval $(call BuildPackage,watchdogd-client-example))