LINUX_VERSION = "6.11.0"
SRCREV_machine = "a350e30e1463d8486ba61362985cf96f9fcd9799"
SRCREV_meta = "5293b566f02543bb3e000cac8bd846c3f5ab14f5"

COMMON_PATCHES = " \
"

SNR_PATCHES = " \
"

GRR_PATCHES = " \
"

PMR_PATCHES = " \
file://0001-bpf-add-bpf_verifier_env-pointer-to-bpf_prog_aux-str.patch \
file://0002-bpf-rename-bpf_convert_shinfo_access-to-bpf_convert_.patch \
file://0003-bpf-add-support-for-writing-__sk_buff-hwtstamp.patch \
file://0004-bpf_skb_kfunc-module-added-with-kfuncs-for-skb.patch \
"
