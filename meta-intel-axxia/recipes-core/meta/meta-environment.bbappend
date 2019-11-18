do_install_prepend () {
   for file in $(ls ${SDK_OUTPUT}/${SDKPATH}/environment-setup-*); do
       if ! grep -q "export HOST_EXTRACFLAGS" $file; then
           sed -i '/export CONFIGURE_FLAGS/a export HOST_EXTRACFLAGS="-I$OECORE_NATIVE_SYSROOT/usr/include -L$OECORE_NATIVE_SYSROOT/usr/lib"' $file
       fi
   done
}
