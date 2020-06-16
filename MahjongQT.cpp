#include "MahjongQT.h"

MahjongQT::MahjongQT(QWidget *parent)
        : QDialog(parent) {
    ui.setupUi(this);
    generatePath();
    Connect();
    iniPic();
}

MahjongQT::~MahjongQT() = default;

void MahjongQT::Connect() {
    QObject::connect(ui.btnClose, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(ui.btnShuffle, SIGNAL(clicked()), this, SLOT(Shuffle()));
}

void MahjongQT::iniPic() {
    ui.Mahjong_1->setPixmap(QPixmap(PicPath[0]));
    ui.Mahjong_2->setPixmap(QPixmap(PicPath[1]));
    ui.Mahjong_3->setPixmap(QPixmap(PicPath[2]));
    ui.Mahjong_4->setPixmap(QPixmap(PicPath[3]));
    ui.Mahjong_5->setPixmap(QPixmap(PicPath[4]));
    ui.Mahjong_6->setPixmap(QPixmap(PicPath[5]));
    ui.Mahjong_7->setPixmap(QPixmap(PicPath[6]));
    ui.Mahjong_8->setPixmap(QPixmap(PicPath[7]));
    ui.Mahjong_9->setPixmap(QPixmap(PicPath[8]));
    ui.Mahjong_10->setPixmap(QPixmap(PicPath[9]));
    ui.Mahjong_11->setPixmap(QPixmap(PicPath[10]));
    ui.Mahjong_12->setPixmap(QPixmap(PicPath[11]));
    ui.Mahjong_13->setPixmap(QPixmap(PicPath[12]));
}

QString *MahjongQT::generatePath() {
    string *p = this->getPicPath();
    for (auto &i : PicPath) {
        i = QString::fromStdString(*p++);
    }
    return PicPath;
}

void MahjongQT::Shuffle() {
    Tiles re(13);
    string *p = re.getPicPath();
    for (auto &i : PicPath) {
        i = QString::fromStdString(*p++);
    }
    ui.Mahjong_1->setPixmap(QPixmap(PicPath[0]));
    ui.Mahjong_2->setPixmap(QPixmap(PicPath[1]));
    ui.Mahjong_3->setPixmap(QPixmap(PicPath[2]));
    ui.Mahjong_4->setPixmap(QPixmap(PicPath[3]));
    ui.Mahjong_5->setPixmap(QPixmap(PicPath[4]));
    ui.Mahjong_6->setPixmap(QPixmap(PicPath[5]));
    ui.Mahjong_7->setPixmap(QPixmap(PicPath[6]));
    ui.Mahjong_8->setPixmap(QPixmap(PicPath[7]));
    ui.Mahjong_9->setPixmap(QPixmap(PicPath[8]));
    ui.Mahjong_10->setPixmap(QPixmap(PicPath[9]));
    ui.Mahjong_11->setPixmap(QPixmap(PicPath[10]));
    ui.Mahjong_12->setPixmap(QPixmap(PicPath[11]));
    ui.Mahjong_13->setPixmap(QPixmap(PicPath[12]));
}