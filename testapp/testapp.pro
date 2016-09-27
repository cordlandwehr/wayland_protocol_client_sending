CONFIG += wayland-scanner
CONFIG += link_pkgconfig

TARGET = testapp

QT += waylandclient-private quick
!contains(QT_CONFIG, no-pkg-config) {
    PKGCONFIG += wayland-client
} else {
    LIBS += -lwayland-client
}

WAYLANDCLIENTSOURCES += ../protocol/custom.xml

OTHER_FILES += client.json

SOURCES += main.cpp \
           customextension.cpp \
           transmitter.cpp

HEADERS += customextension.h \
    transmitter.h


target.path = $$[QT_INSTALL_EXAMPLES]/wayland/custom-title/testapp
INSTALLS += target

