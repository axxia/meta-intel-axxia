FILESEXTRAPATHS:prepend := "${THISDIR}/${BPN}:"

SRC_URI:append = " file://0001-fix-hrtimer-Reduce-trace-noise-in-hrtimer_start-v7.1.patch \
                   file://0001-fix-hrtimer-Drop-unnecessary-pointer-indirection-in.patch \
                   file://0001-fix-mm-vmscan-Convert-pageout-to-take-a-folio-v5.18.patch \
                   file://0001-fix-mm-vmscan-add-cgroup-IDs-to-vmscan-tracepoints-v7.1.patch \
                   file://0001-fix-vfs-widen-trace-event-i_ino-fields-to-u64-v7.1.patch \
                   file://0001-fix-treewide-change-inode-i_ino-from-unsigned-long-to-u64-v7.1.patch \
                   file://0001-fix-ext4-enhance-tracepoints-during-the-folios-writeback-v6.17.patch \
                   file://0001-fix-ext4-widen-trace-event-i_ino-fields-to-u64-v7.1.patch \
                "
