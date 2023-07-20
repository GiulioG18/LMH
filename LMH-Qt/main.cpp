#include "lmhqt.h"
#include <QtWidgets/QApplication>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    LMHQt mainWindow;
    mainWindow.show();

    return app.exec();
}
