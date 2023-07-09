#pragma once

#include <QCoreApplication>


class Application : public QCoreApplication
{
    Q_OBJECT

public:
    explicit Application(int& argc, char** argv);

signals:
    void finished();

public:
    void init();
    void run();
    void quit();
    void aboutToQuitApp();
};
