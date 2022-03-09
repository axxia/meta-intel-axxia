PACKAGECONFIG_remove = "${@oe.utils.conditional('PYTHON_VERSION', '3.6', 'vulkan', '', d)}"
