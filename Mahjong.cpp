#include "Mahjong.h"
#include <cmath>

using namespace std;

//空麻将
Mahjong::Mahjong() {
    _class = -1;
    _index = -1;
    _num = -1;
    _word = -1;
    _org = -1;
}

//分析麻将是那张牌
Mahjong::Mahjong(int MJ) {
    if ((MJ < 1) || (MJ > 136)) {
        cout << "错误！" << endl;
        exit(-1);
    } else {
        _org = MJ;
        _class = (int) (MJ / 36.1);//除以小数避免36的倍数出错
        _index = MJ % 36 % 4;
        if (_class == 3) {
            _num = 0;
            _word = (int) (MJ % 36 / 4.1 + 1);
        } else {
            _word = 0;
            _num = (int) (ceil(fmodf((float) MJ, 36.1)) / 4.1 + 1);//使用fmodf实现对小数取余数，函数在math.h里
        }
    }
}

//获取麻将类别
int Mahjong::getClass() const {
    return this->_class;
}

//获取麻将索引
int Mahjong::getIndex() const {
    return this->_index;
}

//获取麻将数字
int Mahjong::getNum() const {
    return this->_num;
}

//获取麻将文字（非万牌）
int Mahjong::getWord() const {
    return this->_word;
}

//获取麻将原始序数
int Mahjong::getOrg() const {
    return this->_org;
}

//打印麻将
void Mahjong::print() const {
    if (this->_word != 0) {
        switch (this->_word) {
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
        switch (this->_num) {
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
        switch (this->_class) {
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
string Mahjong::generatePath(Mahjong *M) {
    int FileNum = 0;
    switch (M->_word) {
        default:
            exit(-1);
        case 0:
            FileNum = M->_class * 9 + M->_num;
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

    string prefix = ":/MahjongQT/Resources/Images/";//合成路径
    string subfix = ".png";
    string FilePath;

    FilePath.append(prefix);
    FilePath.append(FileNumStr);
    FilePath.append(subfix);

    return FilePath;
}

//析构函数
Mahjong::~Mahjong() = default;
