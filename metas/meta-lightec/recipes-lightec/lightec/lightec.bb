SUMMARY = "lightec"
SECTION = "lightec"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

DEPENDS += "celix"

SRCREV = "${AUTOREV}"

SRC_URI = "git://github.com/sjgarani/lightec.git;branch=main;protocol=git"

S = "${WORKDIR}/git"

inherit pkgconfig cmake

EXTRA_OECMAKE = ""

do_configure_prepend() {
  cd ${WORKDIR}/git
  git submodule update --init bundles/lightec_api
}

do_install() {
    install -d ${D}${libexecdir}
    install -m 0755 deploy/lightec/lightec ${D}${libexecdir}
    install -d ${D}${libexecdir}/bundles
    install -m 0755 deploy/lightec/bundles/* ${D}${libexecdir}/bundles
}