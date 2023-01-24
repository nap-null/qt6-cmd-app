#include <QCoreApplication>

#include "Application.h"


namespace cmd_app
{

Application::Application(int& argc, char** argv)
  : QCoreApplication(argc, argv)
{
}

void Application::init() {
    connect(this, &Application::finished, this, &QCoreApplication::quit);
    connect(this, &QCoreApplication::aboutToQuit, this, &Application::aboutToQuitApp);
}

void Application::quit() {
    emit finished();
}

void Application::run() {
    init();

    qDebug() << arguments();

    quit();
}

void Application::aboutToQuitApp() {
    // Clean up...
}

}
