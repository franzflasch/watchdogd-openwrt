include $(TOPDIR)/rules.mk

PKG_NAME:=watchdogd
PKG_VERSION:=3.5
PKG_RELEASE:=1

#PKG_BUILD_DIR:=$(BUILD_DIR)/bridge-utils-$(PKG_VERSION)
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

# define Build/Configure
#   $(call Build/Configure/Default,--with-linux-headers=$(LINUX_DIR))
# endef

define Package/watchdogd/install
		$(INSTALL_DIR) $(1)/usr/lib
		$(CP) $(PKG_BUILD_DIR)/src/.libs/libwdog.so.* $(1)/usr/lib/

		$(INSTALL_DIR) $(1)/usr/bin
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/.libs/watchdogd $(1)/usr/bin/
		$(INSTALL_BIN) $(PKG_BUILD_DIR)/src/.libs/watchdogctl $(1)/usr/bin/
endef

$(eval $(call BuildPackage,watchdogd))