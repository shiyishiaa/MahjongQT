#pragma once
#ifndef MAHJONGQT_H
#define MAHJONGQT_H

#include <QtWidgets/QDialog>
#include "ui_MahjongQT.h"
#include "Tiles.h"

class MahjongQT : public QDialog, public Tiles {
Q_OBJECT

public:
    explicit MahjongQT(QWidget *parent = Q_NULLPTR);

    ~MahjongQT() override;

private:
    QString PicPath[13];
    Ui::MainLayout ui{};

    void Connect();

    void iniPic();

    QString *generatePath();

private slots:

    void Shuffle();
};

#endif // !MAHJONGQT_H
