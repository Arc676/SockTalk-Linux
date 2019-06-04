#ifndef SOCKTALKFRONTENDPLUGIN_H
#define SOCKTALKFRONTENDPLUGIN_H

#include <QQmlExtensionPlugin>
#include "socktalkfrontend.h"

class SockTalkFrontendPlugin : public QQmlExtensionPlugin {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes(const char *uri);
};

#endif
