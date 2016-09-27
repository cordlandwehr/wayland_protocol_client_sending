#include <QObject>
#include <QDebug>
#include "customextension.h"

class Transmitter : public QObject
{
    Q_OBJECT

public:
    explicit Transmitter(QtWaylandClient::CustomExtension *custom)
    : QObject()
    , m_custom(custom)
    {
    }

public slots:
    void cppSlot() {
        qDebug() << "Called the C++ slot with message:";
        m_custom->sendRequest("test", 1);
    }

private:
    QtWaylandClient::CustomExtension *m_custom;
};
