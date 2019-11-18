do_install_prepend () {
   # Add HOST_EXTRACFLAGS export line in SDK environment-setup scripts
   line='export HOST_EXTRACFLAGS="-I./tools/include -I$OECORE_NATIVE_SYSROOT/usr/include -L$OECORE_NATIVE_SYSROOT/usr/lib"'
   for file in $(ls ${SDK_OUTPUT}/${SDKPATH}/environment-setup-*); do
       if ! grep -q "export HOST_EXTRACFLAGS" $file; then
           eval "sed -i '/export CONFIGURE_FLAGS/a $line' $file"
       fi
   done
}
