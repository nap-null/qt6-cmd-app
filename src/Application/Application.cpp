#include <QCoreApplication>
#include <QTimer>

#include "Application.h"


Application::Application(int& argc, char** argv)
  : QCoreApplication(argc, argv)
{
    QTimer::singleShot(0, &app, &Application::run);
}

void Application::init() {
    connect(this, &Application::finished, this, &QCoreApplication::quit);
    connect(this, &QCoreApplication::aboutToQuit, this, &Application::aboutToQuitApp);
}

void Application::run() {
    init();

    qDebug() << arguments();

    quit();
}

void Application::quit() {
    emit finished();
}

void Application::aboutToQuitApp() {
    // Clean up...
}
