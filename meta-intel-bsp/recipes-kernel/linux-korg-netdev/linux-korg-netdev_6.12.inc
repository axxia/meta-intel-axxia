LINUX_VERSION = "6.12.0"
SRCREV_machine = "adc218676eef25575469234709c2d87185ca223a"
SRCREV_meta = "8f57fada9d056588228a27f6eaaaed9e176cd6a5"

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
