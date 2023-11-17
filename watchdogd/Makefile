include $(TOPDIR)/rules.mk

PKG_NAME:=watchdogd
PKG_VERSION:=3.5
PKG_RELEASE:=1

PKG_SOURCE:=watchdogd-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/troglobit/watchdogd/releases/download/$(PKG_VERSION)
PKG_HASH:=b271cc4e29d3bb61d050180d6c219b55

include $(INCLUDE_DIR)/package.mk

define Package/watchdogd
	SECTION:=base
	CATEGORY:=Utils
	TITLE:=Watchdogd system & process monitor
	URL:=troglobit.com/watchdogd.html
	DEPENDS:=+libite +libuev +confuse
endef

define Package/watchdogd/description
	watchdogd is an advanced system and
	process supervisor daemon,
	primarily intended for
	embedded Linux and server systems.
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/src/*.h $(1)/usr/include
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/src/.libs/libwdog.so* $(1)/usr/lib/
	$(INSTALL_DIR) $(1)/usr/lib/pkgconfig
	$(CP) \
			$(PKG_BUILD_DIR)/src/libwdog.pc \
			$(1)/usr/lib/pkgconfig/
endef

define Package/watchdogd/install
	$(INSTALL_DIR) $(1)/usr/bin $(1)/usr/lib $(1)/etc/init.d $(1)/etc
	$(CP) $(PKG_BUILD_DIR)/src/.libs/libwdog.so.* $(1)/usr/lib/

	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/.libs/watchdogd $(1)/usr/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/.libs/watchdogctl $(1)/usr/bin/
	$(INSTALL_BIN) ./files/watchdogd_start.sh $(1)/usr/bin/

	$(INSTALL_BIN) ./files/watchdogd.cfg $(1)/etc/watchdogd.cfg
	$(INSTALL_BIN) ./files/watchdogd.init $(1)/etc/init.d/watchdogd
endef

$(eval $(call BuildPackage,watchdogd))
