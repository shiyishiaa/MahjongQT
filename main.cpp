#include "MahjongQT.h"
#include "Judge.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QStringList arguments = QApplication::arguments();
    if (arguments.count() < 2) {
        MahjongQT w;
        w.show();
        return QApplication::exec();
    } else {
        Judge w(arguments);
        w.show();
        return QApplication::exec();
    }
}