/********************************************************************************
** Form generated from reading UI file 'Judge.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JUDGE_H
#define UI_JUDGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Judge
{
public:
    QGridLayout *gridLayout;
    QLabel *isWin;

    void setupUi(QWidget *Judge)
    {
        if (Judge->objectName().isEmpty())
            Judge->setObjectName(QString::fromUtf8("Judge"));
        Judge->resize(300, 200);
        Judge->setMinimumSize(QSize(300, 200));
        Judge->setMaximumSize(QSize(300, 200));
        gridLayout = new QGridLayout(Judge);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        isWin = new QLabel(Judge);
        isWin->setObjectName(QString::fromUtf8("isWin"));
        isWin->setMinimumSize(QSize(278, 178));
        isWin->setMaximumSize(QSize(278, 178));
        QFont font;
        font.setPointSize(20);
        isWin->setFont(font);
        isWin->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(isWin, 0, 0, 1, 1);


        retranslateUi(Judge);

        QMetaObject::connectSlotsByName(Judge);
    } // setupUi

    void retranslateUi(QWidget *Judge)
    {
        Judge->setWindowTitle(QCoreApplication::translate("Judge", "Judge", nullptr));
        isWin->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Judge: public Ui_Judge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JUDGE_H
