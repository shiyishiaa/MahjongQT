#pragma once
#ifndef JUDGE_H
#define JUDGE_H

#include <QWidget>
#include "ui_Judge.h"
#include "Tiles.h"

class Judge : public QWidget, public Tiles {
Q_OBJECT

public:

    explicit Judge(QStringList argument);

    ~Judge() override;

private:
    Ui::Judge ui{};
};

#endif // !JUDGE_H