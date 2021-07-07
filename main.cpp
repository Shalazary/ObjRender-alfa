#include <QCoreApplication>
#include "viewport.h"
#include <QImage>
#include <QDebug>

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    Viewport port;
    port.addModel("/home/shalazary/Testovye_modeli/african_head.obj");
    port.render().save("render.png");

    return a.exec();
}
