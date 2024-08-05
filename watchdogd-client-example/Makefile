include $(TOPDIR)/rules.mk

PKG_NAME:=watchdogd-client-example
PKG_VERSION:=1.0
PKG_RELEASE:=1

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

define Build/Compile
	$(TARGET_CC) $(TARGET_CFLAGS) -o $(PKG_BUILD_DIR)/wdt-sub.o -c $(PKG_BUILD_DIR)/wdt-sub.c
	$(TARGET_CC) $(TARGET_LDFLAGS) -lwdog -o $(PKG_BUILD_DIR)/$1 $(PKG_BUILD_DIR)/wdt-sub.o

	$(TARGET_CC) $(TARGET_CFLAGS) -o $(PKG_BUILD_DIR)/wdt-mandatory-client-test.o -c $(PKG_BUILD_DIR)/wdt-mandatory-client-test.c
	$(TARGET_CC) $(TARGET_LDFLAGS) -lwdog -o $(PKG_BUILD_DIR)/watchdogd-mandatory-client-test $(PKG_BUILD_DIR)/wdt-mandatory-client-test.o
endef

define Package/watchdogd-client-example/install
	$(INSTALL_DIR) $(1)/usr/bin $(1)/usr/lib $(1)/etc/init.d $(1)/etc $(1)/etc/config

	$(INSTALL_BIN) $(PKG_BUILD_DIR)/watchdogd-client-example $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/watchdogd-mandatory-client-test $(1)/usr/bin

	$(INSTALL_BIN) ./files/watchdogd_client_start.sh $(1)/usr/bin/
	$(INSTALL_BIN) ./files/watchdogd-client-example.init $(1)/etc/init.d/watchdogd-client-example

	$(INSTALL_CONF) ./files/etc/config/watchdogd-client-example $(1)/etc/config/
endef

$(eval $(call BuildPackage,watchdogd-client-example))
