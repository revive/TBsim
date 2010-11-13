#include <QtGui/QApplication>
#include "TBsim.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    TBsim foo;
    foo.show();
    return app.exec();
}
