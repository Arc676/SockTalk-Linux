#include <QtQml>
#include <QtQml/QQmlContext>

#include "plugin.h"

void SockTalkFrontendPlugin::registerTypes(const char *uri) {
    //@uri SockTalkFrontend
    qmlRegisterSingletonType<SockTalkFrontend>(uri, 1, 0, "SockTalkFrontend", [](QQmlEngine*, QJSEngine*) -> QObject* { return new SockTalkFrontend; });
}
