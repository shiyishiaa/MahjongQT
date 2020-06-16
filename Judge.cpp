#include "Judge.h"

Judge::Judge(QStringList argument) {
    ui.setupUi(this);
    QString NumQStr = argument[1];
    string NumStr = NumQStr.toStdString();
    this->output(NumStr);

    if (this->judge())
        ui.isWin->setText(QString::fromUtf8("True"));
    else
        ui.isWin->setText(QString::fromUtf8("False"));
}

Judge::~Judge() = default;
