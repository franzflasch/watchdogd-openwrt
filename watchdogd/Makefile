include $(TOPDIR)/rules.mk

PKG_NAME:=watchdogd
PKG_VERSION:=master
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/franzflasch/watchdogd.git
PKG_SOURCE_DATE:=2024-08-05
PKG_SOURCE_VERSION:=6e8b63248ab1cc2969ffe898f1c403fb9d8048e9
PKG_MIRROR_HASH:=e0f186a0c139ccfac3d311f49e2fecdbd02fa3f9fe6ced4b1ce0baa603d49fc3
PKG_MAINTAINER:=Franz Flasch <franz.flasch@gmx.at>
PKG_LICENSE:=ISC

#PKG_MIRROR_HASH=skip

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/watchdogd
	SECTION:=base
	CATEGORY:=Utils
	TITLE:=Watchdogd system & process monitor
	URL:=https://troglobit.com/watchdogd.html
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
	$(INSTALL_DIR) $(1)/usr/bin $(1)/usr/lib $(1)/etc/init.d $(1)/etc $(1)/etc/config
	$(CP) $(PKG_BUILD_DIR)/src/.libs/libwdog.so.* $(1)/usr/lib/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/.libs/watchdogd $(1)/usr/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/.libs/watchdogctl $(1)/usr/bin/
	$(INSTALL_BIN) ./files/watchdogd_start.sh $(1)/usr/bin/
	$(INSTALL_BIN) ./files/watchdogd.cfg $(1)/etc/watchdogd.cfg
	$(INSTALL_BIN) ./files/watchdogd.init $(1)/etc/init.d/watchdogd
	$(INSTALL_CONF) ./files/etc/config/watchdogd $(1)/etc/config/
endef

$(eval $(call BuildPackage,watchdogd))
