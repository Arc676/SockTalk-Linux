#include <QtQml>
#include <QtQml/QQmlContext>

#include "plugin.h"
#include "socktalkfrontend.h"

void SocktalkfrontendPlugin::registerTypes(const char *uri) {
    //@uri Socktalkfrontend
    qmlRegisterSingletonType<Socktalkfrontend>(uri, 1, 0, "Socktalkfrontend", [](QQmlEngine*, QJSEngine*) -> QObject* { return new Socktalkfrontend; });
}
