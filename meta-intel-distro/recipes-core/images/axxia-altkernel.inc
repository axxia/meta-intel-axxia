IMGCLASSES:remove = "image-live"
IMGCLASSES:append = "${@bb.utils.contains_any('IMAGE_FSTYPES', 'live iso hddimg', ' image-live-altkernel', '', d)}"

# Add alternative lttng-modules only when LTTNG_SUPPORT is not disabled
ALTERNATIVE_KERNELS_LTTNG_MODULES_SUPPORT = "${@oe.utils.conditional('LTTNG_SUPPORT', '', '', \
                                                '${ALTERNATIVE_KERNELS_LTTNG_MODULES}', d)}"

IMAGE_INSTALL:append = " ${@oe.utils.conditional('ALTERNATIVE_KERNELS', '', '', ' \
						${ALTERNATIVE_KERNELS_INSTALL} \
						${ALTERNATIVE_KERNELS_MODULES_INSTALL} \
						${ALTERNATIVE_KERNELS_LTTNG_MODULES_SUPPORT}', d)} \
						"
