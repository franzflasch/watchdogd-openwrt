include $(TOPDIR)/rules.mk

PKG_NAME:=libuev
PKG_VERSION:=2.4.0
PKG_RELEASE:=1

PKG_FIXUP:=autoreconf
PKG_FIXUP:=patch-libtool
PKG_SOURCE:=libuev-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/troglobit/libuev/releases/download/v$(PKG_VERSION)
PKG_HASH:=9ed359f3196098c5fd68fa7bed617308

include $(INCLUDE_DIR)/package.mk

define Package/libuev
	SECTION:=base
	CATEGORY:=Libraries
	TITLE:=Simple event loop for linux
	URL:=codedocs.xyz/troglobit/libuev/
endef

define Package/libuev/description
	libuEv is a small event loop that wraps the 
	Linux epoll() family of APIs. 
endef

define Package/libuev/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/src/.libs/libuev.so.* $(1)/usr/lib/
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include/uev
	$(CP) $(PKG_BUILD_DIR)/src/*.h $(1)/usr/include/uev/
	$(INSTALL_DIR) $(1)/usr/lib
	$(CP) $(PKG_BUILD_DIR)/src/.libs/libuev.so* $(1)/usr/lib/
	$(INSTALL_DIR) $(1)/usr/lib/pkgconfig
	$(CP) \
			$(PKG_BUILD_DIR)/src/libuev.pc \
			$(1)/usr/lib/pkgconfig/
endef

$(eval $(call BuildPackage,libuev))
