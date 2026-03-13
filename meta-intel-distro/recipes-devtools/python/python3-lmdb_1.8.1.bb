DESCRIPTION = "Universal Python binding for the LMDB 'Lightning' Database"
SECTION = "devel/python"
HOMEPAGE = "https://github.com/jnwatson/py-lmdb"
LICENSE = "OLDAP-2.8"
LIC_FILES_CHKSUM = "file://LICENSE;md5=153d07ef052c4a37a8fac23bc6031972"

inherit pypi setuptools3

SRC_URI[md5sum] = "de895e4a88eeb179aa0c185a08523d62"
SRC_URI[sha256sum] = "44ef24033929e9cc227a7e17287473c452b462d716f118db885c667c80f57429"

SRC_URI:append = " file://0001-Remove-host-contamination-from-extra_sources-and-ext.patch"
