#ifndef QT_WAYLAND_CUSTOM
#define QT_WAYLAND_CUSTOM

#include "wayland-custom-client-protocol.h"
#include <QByteArray>
#include <QString>

QT_BEGIN_NAMESPACE

namespace QtWayland {
    class  qt_example_extension
    {
    public:
        qt_example_extension(struct ::wl_registry *registry, int id, int version);
        qt_example_extension(struct ::qt_example_extension *object);
        qt_example_extension();

        virtual ~qt_example_extension();

        void init(struct ::wl_registry *registry, int id, int version);
        void init(struct ::qt_example_extension *object);

        struct ::qt_example_extension *object() { return m_qt_example_extension; }
        const struct ::qt_example_extension *object() const { return m_qt_example_extension; }

        bool isInitialized() const;

        static const struct ::wl_interface *interface();

        void qtrequest(const QString &text, int32_t value);

    protected:
        virtual void example_extension_qtevent(struct ::wl_surface *surface, uint32_t time, const QString &text, uint32_t value);

    private:
        void init_listener();
        static const struct qt_example_extension_listener m_qt_example_extension_listener;
        static void handle_qtevent(
            void *data,
            struct ::qt_example_extension *object,
            struct ::wl_surface *surface,
            uint32_t time,
            const char *text,
            uint32_t value);
        struct ::qt_example_extension *m_qt_example_extension;
    };
}

QT_END_NAMESPACE

#endif
