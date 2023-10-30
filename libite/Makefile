include $(TOPDIR)/rules.mk

PKG_NAME:=libite
PKG_VERSION:=2.6.1
PKG_RELEASE:=1

PKG_SOURCE:=libite-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/troglobit/libite/releases/download/v$(PKG_VERSION)
PKG_HASH:=ffee04b12ea102faf5bf528e548a9291

include $(INCLUDE_DIR)/package.mk

define Package/libite
	SECTION:=base
	CATEGORY:=Libraries
	TITLE:=Frog DNA, basically
	URL:=codedocs.xyz/troglobit/libite/
endef

define Package/libite/description
	Libite is a lightweight library of 
	frog DNA that can be used to 
	fill the gaps in any dinosaur project.
endef

define Package/libite/install
		$(INSTALL_DIR) $(1)/usr/lib
		$(CP) $(PKG_BUILD_DIR)/src/.libs/libite.so.* $(1)/usr/lib/
endef

define Build/InstallDev
		$(INSTALL_DIR) $(1)/usr/include/libite
		$(CP) $(PKG_BUILD_DIR)/src/*.h $(1)/usr/include/libite/
		$(INSTALL_DIR) $(1)/usr/lib
		$(CP) $(PKG_BUILD_DIR)/src/.libs/libite.so* $(1)/usr/lib/
		$(INSTALL_DIR) $(1)/usr/lib/pkgconfig
		$(CP) \
				$(PKG_BUILD_DIR)/src/libite.pc \
				$(1)/usr/lib/pkgconfig/
endef

$(eval $(call BuildPackage,libite))