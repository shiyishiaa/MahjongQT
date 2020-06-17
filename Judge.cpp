#include "Judge.h"

Judge::Judge(QStringList argument) {
    ui.setupUi(this);
    QString tilesQStr = argument[1];
    string NumStr = tilesQStr.toStdString();
    this->parseTiles(NumStr);

    if (this->judge())
        ui.isWin->setText(QString::fromUtf8("True"));
    else
        ui.isWin->setText(QString::fromUtf8("False"));
}

Judge::~Judge() = default;
