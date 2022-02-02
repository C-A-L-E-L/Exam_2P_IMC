#include "imc.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IMC w;
    w.show();
    return a.exec();
}
