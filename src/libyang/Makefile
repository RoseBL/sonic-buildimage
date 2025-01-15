.ONESHELL:
SHELL = /bin/bash
.SHELLFLAGS += -e
LIBYANG_VERSION_BASE = 1.0
LIBYANG_VERSION = $(LIBYANG_VERSION_BASE).73
CONFIGURED_ARCH = sw_64
LIBYANG_DEV = libyang-dev_$(LIBYANG_VERSION)_$(CONFIGURED_ARCH).deb
LIBYANG_DBGSYM = libyang-dbgsym_$(LIBYANG_VERSION)_$(CONFIGURED_ARCH).deb
LIBYANG_CPP = libyang-cpp_$(LIBYANG_VERSION)_$(CONFIGURED_ARCH).deb
LIBYANG_PY3 = python3-yang_$(LIBYANG_VERSION)_$(CONFIGURED_ARCH).deb
LIBYANG = libyang_$(LIBYANG_VERSION)_$(CONFIGURED_ARCH).deb
MAIN_TARGET = $(LIBYANG)
DERIVED_TARGETS = $(LIBYANG_DEV) $(LIBYANG_DBGSYM) $(LIBYANG_PY3) $(LIBYANG_CPP)

$(addprefix $(DEST)/, $(MAIN_TARGET)): $(DEST)/% :
        # Obtaining the libyang
	rm -fr ./libyang-$(LIBYANG_VERSION)
	git clone https://github.com/CESNET/libyang.git libyang-$(LIBYANG_VERSION)
	pushd libyang-$(LIBYANG_VERSION)
	git checkout tags/v1.0-r4 -b libyang
	# Apply patch series
	stg init
	stg import -s ../patch/series

ifeq ($(CROSS_BUILD_ENVIRON), y)
	dpkg-buildpackage -rfakeroot -b -us -uc -a$(CONFIGURED_ARCH) -Pcross,nocheck -j$(SONIC_CONFIG_MAKE_JOBS) --admindir $(SONIC_DPKG_ADMINDIR)
else
	dpkg-buildpackage -rfakeroot -b -us -uc -j$(SONIC_CONFIG_MAKE_JOBS) --admindir $(SONIC_DPKG_ADMINDIR)
endif
	popd

	mv $(DERIVED_TARGETS) $* $(DEST)/

$(addprefix $(DEST)/, $(DERIVED_TARGETS)): $(DEST)/% : $(DEST)/$(MAIN_TARGET)
