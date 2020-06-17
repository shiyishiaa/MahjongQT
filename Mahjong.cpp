#include "Mahjong.h"
#include <cmath>

using namespace std;

//空麻将
Mahjong::Mahjong() {
    type = -1;
    index = -1;
    num = -1;
    word = -1;
    org = -1;
}

//分析麻将是那张牌
Mahjong::Mahjong(unsigned int inputNum) {
    if ((inputNum < 1) || (inputNum > 136)) {
        cout << "错误！" << endl;
        exit(-1);
    } else {
        org = inputNum;
        type = (int) (inputNum / 36.1);//除以小数避免36的倍数出错
        index = inputNum % 36 % 4;
        if (type == 3) {
            num = 0;
            word = (int) (inputNum % 36 / 4.1 + 1);
        } else {
            word = 0;
            num = (int) (ceil(fmodf((float) inputNum, 36.1)) / 4.1 + 1);//使用fmodf实现对小数取余数，函数在math.h里
        }
    }
}

//获取麻将类别
unsigned int Mahjong::getType() const {
    return this->type;
}

//获取麻将索引
unsigned int Mahjong::getIndex() const {
    return this->index;
}

//获取麻将数字
unsigned int Mahjong::getNum() const {
    return this->num;
}

//获取麻将文字（非万牌）
unsigned int Mahjong::getWord() const {
    return this->word;
}

//获取麻将原始序数
unsigned int Mahjong::getOrg() const {
    return this->org;
}

//打印麻将
void Mahjong::print() const {
    if (this->word != 0) {
        switch (this->word) {
            default: {
                cout << "空麻将！" << endl;
                return;
            }
            case 1: {
                cout << "东风 ";
                break;
            }
            case 2: {
                cout << "南风 ";
                break;
            }
            case 3: {
                cout << "西风 ";
                break;
            }
            case 4: {
                cout << "北风 ";
                break;
            }
            case 5: {
                cout << "红中 ";
                break;
            }
            case 6: {
                cout << "发财 ";
                break;
            }
            case 7: {
                cout << "白板 ";
                break;
            }
        }
    } else {
        switch (this->num) {
            default: {
                cout << "空麻将！" << endl;
                return;
            }
            case 1: {
                cout << "一";
                break;
            }
            case 2: {
                cout << "二";
                break;
            }
            case 3: {
                cout << "三";
                break;
            }
            case 4: {
                cout << "四";
                break;
            }
            case 5: {
                cout << "五";
                break;
            }
            case 6: {
                cout << "六";
                break;
            }
            case 7: {
                cout << "七";
                break;
            }
            case 8: {
                cout << "八";
                break;
            }
            case 9: {
                cout << "九";
                break;
            }
        }
        switch (this->type) {
            case 0: {
                cout << "筒 ";
                break;
            }
            case 1: {
                cout << "条 ";
                break;
            }
            case 2: {
                cout << "万 ";
                break;
            }
        }
    }
}

//生成麻将路径
string Mahjong::generatePath(Mahjong *mahjong) {
    int FileNum;
    switch (mahjong->word) {
        default:
            exit(-1);
        case 0:
            FileNum = mahjong->type * 9 + mahjong->num;
            break;
        case 1:
            FileNum = 28;
            break;
        case 2:
            FileNum = 29;
            break;
        case 3:
            FileNum = 30;
            break;
        case 4:
            FileNum = 31;
            break;
        case 5:
            FileNum = 32;
            break;
        case 6:
            FileNum = 33;
            break;
        case 7:
            FileNum = 34;
            break;
    }

    char FileNumChar[3] = {'0', '0', '0'};//int转string
    char *p = FileNumChar + 1;
    *p++ = (char) (FileNum / 10 + '0');
    *p = (char) (FileNum % 10 + '0');
    p = FileNumChar;

    string FileNumStr;
    for (int i = 0; i < 3; i++)
        FileNumStr += *p++;

    string FilePath;

    FilePath.append(":/MahjongQT/Resources/Images/")
            .append(FileNumStr)
            .append(".png");

    return FilePath;
}

Mahjong &Mahjong::operator=(const Mahjong &another) {
    if (this == &another)return *this;
    this->org = another.getOrg();
    this->num = another.getNum();
    this->word = another.getWord();
    this->type = another.getType();
    this->index = another.getIndex();
    return *this;
}

//析构函数
Mahjong::~Mahjong() = default;
