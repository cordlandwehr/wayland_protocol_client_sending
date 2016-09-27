#include "qwayland-server-custom.h"

QT_BEGIN_NAMESPACE

namespace QtWaylandServer {
    qt_example_extension::qt_example_extension(struct ::wl_client *client, int id, int version)
        : m_resource_map()
        , m_resource(0)
        , m_global(0)
    {
        init(client, id, version);
    }

    qt_example_extension::qt_example_extension(struct ::wl_display *display, int version)
        : m_resource_map()
        , m_resource(0)
        , m_global(0)
    {
        init(display, version);
    }

    qt_example_extension::qt_example_extension(struct ::wl_resource *resource)
        : m_resource_map()
        , m_resource(0)
        , m_global(0)
    {
        init(resource);
    }

    qt_example_extension::qt_example_extension()
        : m_resource_map()
        , m_resource(0)
        , m_global(0)
    {
    }

    qt_example_extension::~qt_example_extension()
    {
    }

    void qt_example_extension::init(struct ::wl_client *client, int id, int version)
    {
        m_resource = bind(client, id, version);
    }

    void qt_example_extension::init(struct ::wl_resource *resource)
    {
        m_resource = bind(resource);
    }

    qt_example_extension::Resource *qt_example_extension::add(struct ::wl_client *client, int version)
    {
        Resource *resource = bind(client, 0, version);
        m_resource_map.insert(client, resource);
        return resource;
    }

    qt_example_extension::Resource *qt_example_extension::add(struct ::wl_client *client, int id, int version)
    {
        Resource *resource = bind(client, id, version);
        m_resource_map.insert(client, resource);
        return resource;
    }

    void qt_example_extension::init(struct ::wl_display *display, int version)
    {
        m_global = wl_global_create(display, &::qt_example_extension_interface, version, this, bind_func);
        m_globalVersion = version;
    }

    const struct wl_interface *qt_example_extension::interface()
    {
        return &::qt_example_extension_interface;
    }

    qt_example_extension::Resource *qt_example_extension::example_extension_allocate()
    {
        return new Resource;
    }

    void qt_example_extension::example_extension_bind_resource(Resource *)
    {
    }

    void qt_example_extension::example_extension_destroy_resource(Resource *)
    {
    }

    void qt_example_extension::bind_func(struct ::wl_client *client, void *data, uint32_t version, uint32_t id)
    {
        qt_example_extension *that = static_cast<qt_example_extension *>(data);
        that->add(client, id, qMin(that->m_globalVersion, version));
    }

    void qt_example_extension::destroy_func(struct ::wl_resource *client_resource)
    {
        Resource *resource = Resource::fromResource(client_resource);
        qt_example_extension *that = resource->example_extension_object;
        that->m_resource_map.remove(resource->client(), resource);
        that->example_extension_destroy_resource(resource);
        delete resource;
#if !WAYLAND_VERSION_CHECK(1, 2, 0)
        free(client_resource);
#endif
    }

    qt_example_extension::Resource *qt_example_extension::bind(struct ::wl_client *client, uint32_t id, int version)
    {
        Q_ASSERT_X(!wl_client_get_object(client, id), "QWaylandObject bind", QStringLiteral("binding to object %1 more than once").arg(id).toLocal8Bit().constData());
        struct ::wl_resource *handle = wl_resource_create(client, &::qt_example_extension_interface, version, id);
        return bind(handle);
    }

    qt_example_extension::Resource *qt_example_extension::bind(struct ::wl_resource *handle)
    {
        Resource *resource = example_extension_allocate();
        resource->example_extension_object = this;

        wl_resource_set_implementation(handle, &m_qt_example_extension_interface, resource, destroy_func);
        resource->handle = handle;
        example_extension_bind_resource(resource);
        return resource;
    }
    qt_example_extension::Resource *qt_example_extension::Resource::fromResource(struct ::wl_resource *resource)
    {
        if (wl_resource_instance_of(resource, &::qt_example_extension_interface, &m_qt_example_extension_interface))
            return static_cast<Resource *>(resource->data);
        return 0;
    }

    const struct ::qt_example_extension_interface qt_example_extension::m_qt_example_extension_interface = {
        qt_example_extension::handle_qtrequest
    };

    void qt_example_extension::example_extension_qtrequest(Resource *, const QString &, int32_t )
    {
    }


    void qt_example_extension::handle_qtrequest(
        ::wl_client *client,
        struct wl_resource *resource,
        const char *text,
        int32_t value)
    {
        Q_UNUSED(client);
        Resource *r = Resource::fromResource(resource);
        static_cast<qt_example_extension *>(r->example_extension_object)->example_extension_qtrequest(
            r,
            QString::fromUtf8(text),
            value);
    }

    void qt_example_extension::send_qtevent(struct ::wl_resource *surface, uint32_t time, const QString &text, uint32_t value)
    {
        send_qtevent(
            m_resource->handle,
            surface,
            time,
            text,
            value);
    }

    void qt_example_extension::send_qtevent(struct ::wl_resource *resource, struct ::wl_resource *surface, uint32_t time, const QString &text, uint32_t value)
    {
        qt_example_extension_send_qtevent(
            resource,
            surface,
            time,
            text.toUtf8().constData(),
            value);
    }

}

QT_END_NAMESPACE
