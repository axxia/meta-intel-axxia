do_install_prepend () {
# Add HOST_EXTRACFLAGS export line in SDK environment-setup scripts

line='export HOST_EXTRACFLAGS="-I./tools/include \\\
-I$OECORE_NATIVE_SYSROOT/usr/include \\\
-L$OECORE_NATIVE_SYSROOT/usr/lib \\\
-L$OECORE_NATIVE_SYSROOT/lib \\\
-Wl,-rpath-link,$OECORE_NATIVE_SYSROOT/usr/lib \\\
-Wl,-rpath-link,$OECORE_NATIVE_SYSROOT/lib \\\
-Wl,-rpath,$OECORE_NATIVE_SYSROOT/usr/lib \\\
-Wl,-rpath,$OECORE_NATIVE_SYSROOT/lib \\\
-Wl,--dynamic-linker=$OECORE_NATIVE_SYSROOT/lib/ld-linux-x86-64.so.2"'

for file in $(ls ${SDK_OUTPUT}/${SDKPATH}/environment-setup-*); do
    if ! grep -q "export HOST_EXTRACFLAGS" $file; then
        eval "sed -i '/export CONFIGURE_FLAGS/a $line' $file"
    fi
done
}

