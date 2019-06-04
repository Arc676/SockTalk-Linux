#ifndef SOCKTALKFRONTEND_H
#define SOCKTALKFRONTEND_H

#include <QObject>

class SockTalkFrontend: public QObject {
    Q_OBJECT

public:
    SockTalkFrontend();
    ~SockTalkFrontend() = default;

    Q_INVOKABLE void speak();
};

#endif
