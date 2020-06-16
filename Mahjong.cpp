#include "Mahjong.h"
#include <cmath>

using namespace std;

//���齫
Mahjong::Mahjong() {
    _class = -1;
    _index = -1;
    _num = -1;
    _word = -1;
    _org = -1;
}

//�����齫��������
Mahjong::Mahjong(int MJ) {
    if ((MJ < 1) || (MJ > 136)) {
        cout << "����" << endl;
        exit(-1);
    } else {
        _org = MJ;
        _class = (int) (MJ / 36.1);//����С������36�ı�������
        _index = MJ % 36 % 4;
        if (_class == 3) {
            _num = 0;
            _word = (int) (MJ % 36 / 4.1 + 1);
        } else {
            _word = 0;
            _num = (int) (ceil(fmodf((float) MJ, 36.1)) / 4.1 + 1);//ʹ��fmodfʵ�ֶ�С��ȡ������������math.h��
        }
    }
}

//��ȡ�齫���
int Mahjong::getClass() const {
    return this->_class;
}

//��ȡ�齫����
int Mahjong::getIndex() const {
    return this->_index;
}

//��ȡ�齫����
int Mahjong::getNum() const {
    return this->_num;
}

//��ȡ�齫���֣������ƣ�
int Mahjong::getWord() const {
    return this->_word;
}

//��ȡ�齫ԭʼ����
int Mahjong::getOrg() const {
    return this->_org;
}

//��ӡ�齫
void Mahjong::print() const {
    if (this->_word != 0) {
        switch (this->_word) {
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
        switch (this->_num) {
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
        switch (this->_class) {
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

    char FileNumChar[3] = {'0', '0', '0'};//intתstring
    char *p = FileNumChar + 1;
    *p++ = (char) (FileNum / 10 + '0');
    *p = (char) (FileNum % 10 + '0');
    p = FileNumChar;

    string FileNumStr;
    for (int i = 0; i < 3; i++)
        FileNumStr += *p++;

    string prefix = ":/MahjongQT/Resources/Images/";//�ϳ�·��
    string subfix = ".png";
    string FilePath;

    FilePath.append(prefix);
    FilePath.append(FileNumStr);
    FilePath.append(subfix);

    return FilePath;
}

//��������
Mahjong::~Mahjong() = default;
