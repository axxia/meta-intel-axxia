# Solve mktime signature conflict with GCC-15 with C23 on

do_patch[postfuncs] += "fix_posix_files"

fix_posix_files() {
	sed -i 's|#include <config.h>|#include "config.h"|g' ${S}/posixtm.c
	sed -i '/time_t mktime ();/d' ${S}/posixtm.c
}
