# Disable python support when python 3.6 is used
PACKAGECONFIG_remove = "${@oe.utils.conditional('PYTHON_VERSION', '3.6', 'python', '', d)}"
