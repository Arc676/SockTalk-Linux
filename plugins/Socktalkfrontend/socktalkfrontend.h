#ifndef SOCKTALKFRONTEND_H
#define SOCKTALKFRONTEND_H

#include <QObject>

class Socktalkfrontend: public QObject {
    Q_OBJECT

public:
    Socktalkfrontend();
    ~Socktalkfrontend() = default;

    Q_INVOKABLE void speak();
};

#endif
