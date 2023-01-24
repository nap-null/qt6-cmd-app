#pragma once

#include <QCoreApplication>


namespace cmd_app
{

class Application : public QCoreApplication
{
    Q_OBJECT

public:
    explicit Application(int& argc, char** argv);

    void init();
    void quit();

signals:
    void finished();

public slots:
    void run();

public:
    void aboutToQuitApp();
};

#define pApp ((Application*)qApp)

}
