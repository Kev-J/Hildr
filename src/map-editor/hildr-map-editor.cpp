#include "MainWindow.h"

#include <hildr-tools/hildr-tools.h>

#include <QApplication>
#include <iostream>

int main(int argc, char **argv)
{
    if (!HildrTools::XmlConfig::initializeSubsystem()) {
        std::cerr << "Unable to initialize XML subsystem" << std::endl;
        return -1;
    }

    QApplication app(argc, argv);

    MainWindow win;

    win.show();

    app.exec();

    return 0;
}
