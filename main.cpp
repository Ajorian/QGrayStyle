// this is a simple example, as you see you have to just create an object of QGrayStyle and set is as QApplication's style!

#include "myClass.h"
#include <QtWidgets/QApplication>
#include "styleSheet/grayStyle.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	  a.setStyle(new QGrayStyle);
    myClass w;
    w.show();
    return a.exec();
}
