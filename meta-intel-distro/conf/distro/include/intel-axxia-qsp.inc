INHERIT += "archiver"
ARCHIVER_MODE[src] = "original"

COPY_LIC_MANIFEST = "1"
COPY_LIC_DIRS = "1"

# Use busybox ip since ip.iproute2 has wrong interpreter
RDEPENDS:iproute2:remove = "iproute2-ip"
