PREMIRRORS = "ftp://.*/.* https://mirror.myf.cloud/mirror/p/postfix-release/official/postfix-${PV}.tar.gz \n"

# use gnu17 for now as recommended in:
# https://marc.info/?l=postfix-users&m=173542420611213
CFLAGS += "-std=gnu17"
