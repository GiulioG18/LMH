#include "lmhqt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LMHQt w;
    w.show();
    return a.exec();
}
