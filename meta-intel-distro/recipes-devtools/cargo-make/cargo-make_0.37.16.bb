SUMMARY = "Rust task runner and build tool"
HOMEPAGE = "https://sagiegurari.github.io/cargo-make"
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=d2794c0df5b907fdace235a619d80314"

SRC_URI = "crate://crates.io/cargo-make/${PV};name=cargo-make"
SRC_URI[cargo-make.sha256sum] = "2c2d0abbaa456825d65db63afbe0e418d5f6464f6c68a59842c9d9da4199253f"

S = "${CARGO_VENDORING_DIRECTORY}/${BPN}-${PV}"

inherit cargo cargo-update-recipe-crates

require ${BPN}-crates.inc

BBCLASSEXTEND = "native nativesdk"
