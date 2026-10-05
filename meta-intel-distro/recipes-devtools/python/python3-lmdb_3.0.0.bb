DESCRIPTION = "Universal Python binding for the LMDB 'Lightning' Database"
SECTION = "devel/python"
HOMEPAGE = "https://github.com/jnwatson/py-lmdb"
LICENSE = "OLDAP-2.8"
LIC_FILES_CHKSUM = "file://LICENSE;md5=153d07ef052c4a37a8fac23bc6031972"

inherit pypi python_setuptools_build_meta

SRC_URI[md5sum] = ""
SRC_URI[sha256sum] = "06dda0723545e14d56ac7dcd6f582d9922c2ed5e16f1c3f8d0e670a96ec2ee65"

SRC_URI:append = " file://0001-Remove-host-contamination-from-extra_sources-and-ext.patch"

# cffi and patch-ng are listed as PEP 517 build requirements but are only
# needed for the cffi implementation and for applying patches on Windows.
# The Linux build uses the CPython extension, so drop them to avoid pulling
# unavailable build dependencies.
do_configure:prepend() {
    sed -i -e 's/, "cffi>=0.8", "patch-ng"//' ${S}/pyproject.toml
}

