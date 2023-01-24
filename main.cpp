#include <QTimer>

#include <Application/Application.h>


int main(int argc, char* argv[]) {
    cmd_app::Application app(argc, argv);

    QTimer::singleShot(0, &app, &cmd_app::Application::run);

    return app.exec();
}
