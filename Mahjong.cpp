#include "Mahjong.h"
#include <cmath>

using namespace std;

//���齫
Mahjong::Mahjong() {
    type = -1;
    index = -1;
    num = -1;
    word = -1;
    org = -1;
}

//�����齫��������
Mahjong::Mahjong(unsigned int inputNum) {
    if ((inputNum < 1) || (inputNum > 136)) {
        cout << "����" << endl;
        exit(-1);
    } else {
        org = inputNum;
        type = (int) (inputNum / 36.1);//����С������36�ı�������
        index = inputNum % 36 % 4;
        if (type == 3) {
            num = 0;
            word = (int) (inputNum % 36 / 4.1 + 1);
        } else {
            word = 0;
            num = (int) (ceil(fmodf((float) inputNum, 36.1)) / 4.1 + 1);//ʹ��fmodfʵ�ֶ�С��ȡ������������math.h��
        }
    }
}

//��ȡ�齫���
unsigned int Mahjong::getType() const {
    return this->type;
}

//��ȡ�齫����
unsigned int Mahjong::getIndex() const {
    return this->index;
}

//��ȡ�齫����
unsigned int Mahjong::getNum() const {
    return this->num;
}

//��ȡ�齫���֣������ƣ�
unsigned int Mahjong::getWord() const {
    return this->word;
}

//��ȡ�齫ԭʼ����
unsigned int Mahjong::getOrg() const {
    return this->org;
}

//��ӡ�齫
void Mahjong::print() const {
    if (this->word != 0) {
        switch (this->word) {
            default: {
                cout << "���齫��" << endl;
                return;
            }
            case 1: {
                cout << "���� ";
                break;
            }
            case 2: {
                cout << "�Ϸ� ";
                break;
            }
            case 3: {
                cout << "���� ";
                break;
            }
            case 4: {
                cout << "���� ";
                break;
            }
            case 5: {
                cout << "���� ";
                break;
            }
            case 6: {
                cout << "���� ";
                break;
            }
            case 7: {
                cout << "�װ� ";
                break;
            }
        }
    } else {
        switch (this->num) {
            default: {
                cout << "���齫��" << endl;
                return;
            }
            case 1: {
                cout << "һ";
                break;
            }
            case 2: {
                cout << "��";
                break;
            }
            case 3: {
                cout << "��";
                break;
            }
            case 4: {
                cout << "��";
                break;
            }
            case 5: {
                cout << "��";
                break;
            }
            case 6: {
                cout << "��";
                break;
            }
            case 7: {
                cout << "��";
                break;
            }
            case 8: {
                cout << "��";
                break;
            }
            case 9: {
                cout << "��";
                break;
            }
        }
        switch (this->type) {
            case 0: {
                cout << "Ͳ ";
                break;
            }
            case 1: {
                cout << "�� ";
                break;
            }
            case 2: {
                cout << "�� ";
                break;
            }
        }
    }
}

//�����齫·��
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

    char FileNumChar[3] = {'0', '0', '0'};//intתstring
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

//��������
Mahjong::~Mahjong() = default;
