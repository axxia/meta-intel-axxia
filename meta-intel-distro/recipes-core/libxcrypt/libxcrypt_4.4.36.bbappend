# Ignore warnings reported as errors by gcc-14 and newer
# | ../git/lib/util-base64.c:24:3: error: initializer-string for array of
# | 'unsigned char' is too long [-Werror=unterminated-string-initialization]
# |    24 |   "./0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghipqrstuvwxyz"
CPPFLAGS:append:class-nativesdk = "${@bb.utils.contains('DISTRO_FEATURES_NATIVESDK', 'gcc15', ' -Wno-error=unterminated-string-initialization', '', d)}"
