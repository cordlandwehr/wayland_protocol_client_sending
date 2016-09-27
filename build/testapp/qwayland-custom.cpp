#include "qwayland-custom.h"

QT_BEGIN_NAMESPACE

namespace QtWayland {
    qt_example_extension::qt_example_extension(struct ::wl_registry *registry, int id, int version)
    {
        init(registry, id, version);
    }

    qt_example_extension::qt_example_extension(struct ::qt_example_extension *obj)
        : m_qt_example_extension(obj)
    {
        init_listener();
    }

    qt_example_extension::qt_example_extension()
        : m_qt_example_extension(0)
    {
    }

    qt_example_extension::~qt_example_extension()
    {
    }

    void qt_example_extension::init(struct ::wl_registry *registry, int id, int version)
    {
        m_qt_example_extension = static_cast<struct ::qt_example_extension *>(wl_registry_bind(registry, id, &qt_example_extension_interface, version));
        init_listener();
    }

    void qt_example_extension::init(struct ::qt_example_extension *obj)
    {
        m_qt_example_extension = obj;
        init_listener();
    }

    bool qt_example_extension::isInitialized() const
    {
        return m_qt_example_extension != 0;
    }

    const struct wl_interface *qt_example_extension::interface()
    {
        return &::qt_example_extension_interface;
    }

    void qt_example_extension::qtrequest(const QString &text, int32_t value)
    {
        qt_example_extension_qtrequest(
            m_qt_example_extension,
            text.toUtf8().constData(),
            value);
    }

    void qt_example_extension::example_extension_qtevent(struct ::wl_surface *, uint32_t , const QString &, uint32_t )
    {
    }

    void qt_example_extension::handle_qtevent(
        void *data,
        struct ::qt_example_extension *object,
        struct ::wl_surface *surface,
        uint32_t time,
        const char *text,
        uint32_t value)
    {
        Q_UNUSED(object);
        static_cast<qt_example_extension *>(data)->example_extension_qtevent(
            surface,
            time,
            QString::fromUtf8(text),
            value);
    }

    const struct qt_example_extension_listener qt_example_extension::m_qt_example_extension_listener = {
        qt_example_extension::handle_qtevent
    };

    void qt_example_extension::init_listener()
    {
        qt_example_extension_add_listener(m_qt_example_extension, &m_qt_example_extension_listener, this);
    }
}

QT_END_NAMESPACE
