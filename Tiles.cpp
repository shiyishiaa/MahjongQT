#include "Tiles.h"

using namespace std;

//Ĭ���������14����
Tiles::Tiles() {
    Tiles newTile(14);
    *this = newTile;
    this->size = 14;
}

//�������N����
Tiles::Tiles(int num) {
    this->size = num;
    if (num <= 0) {
        cout << "�������룡" << endl;
        exit(-1);
    }

    random_device e;
    unsigned int random[14];
    random[0] = (e() % 136) + 1;
    this->tiles[0] = Mahjong(random[0]);//��ȡ1~136�ڵ����������
    for (int i = 1; i < this->size; i++) {
        random[i] = (e() % 136) + 1;
        int j = 0;
        for (; j < i;)//�����ظ���ȡ
        {
            while (random[i] == random[j++]) {
                random[i] = (e() % 136) + 1;
                j = 0;
            }
        }
        this->tiles[i] = Mahjong(random[i]);
    }
    this->sort();
    string *p = this->picPath;
    for (int i = 0; i < this->size; i++) {
        *p = Mahjong::generatePath(&tiles[i]);
        p++;
    }
}

//����136���ƣ���Ϊ���٣�
Tiles::Tiles(const string &PASSWORD) {
    if (PASSWORD == "&((fdsiojfs@") {
        Tiles newTiles(136);
        *this = newTiles;
        return;
    }
    Mahjong emptyMahjong;
    this->tiles[0] = emptyMahjong;
    this->picPath[0] = "";
    this->size = 0;
}

//��ӡ����
void Tiles::print() const {
    for (int i = 0; i < size; i++) {
        this->tiles[i].print();
    }
    cout << endl;
}

//��������ѡ������
void Tiles::sort() {
    unsigned int newNum = this->size;
    Mahjong *outer = this->tiles;
    Mahjong *inner = this->tiles;
    auto *temp = new Mahjong;
    for (int i = 0; i < newNum; i++) {
        for (int j = 0; j < i; j++) {
            if ((outer->getOrg()) < (inner->getOrg())) {
                *temp = *inner;
                *inner = *outer;
                *outer = *temp;
            }
            inner++;
        }
        outer++;
        inner = this->tiles;
    }
    delete temp;
}

//ѡ���N���齫
Mahjong Tiles::select(int N) const {
    return this->tiles[N - 1];
}

//��ȡ�ƶ��齫ͼƬ·��
string *Tiles::getPicPath() {
    return this->picPath;
}

//��������
Tiles::~Tiles() = default;

//ת���ַ�����������
void Tiles::parseTiles(string input) {
    int index;
    for (int i = 0; i < size; i++) {
        index = input.find(',');
        string inputStr = input.substr(0, index), *stop;
        int newNum = strtol(inputStr.c_str(), reinterpret_cast<char **>(stop), 10);
        this->tiles[i] = Mahjong(newNum);
        input = input.erase(0, index + 1);
    }
    sort();
    for (int j = 0; j < size; j++) {
        this->picPath[j] = Mahjong::generatePath(&tiles[j]);
    }
}

/**
 * Code created by my classmate Seto Lian
 * @return if completed a hand
 */
//�жϺ���
bool Tiles::judge() {
    unsigned int typeNum[14];//����
    unsigned int mahjongNum[14];//��������
    unsigned int word[14];//������
    unsigned int result[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};//ȫΪ0����ƣ������޳���ʹ�õ���

    for (int i = 0; i < 14; i++)//����������Ϣ
    {
        typeNum[i] = this->tiles[i].getType();
        mahjongNum[i] = this->tiles[i].getNum();
        word[i] = this->tiles[i].getWord();
    }

    int nowResult = 0;//�������ڼ�������ϵ�������
    bool AA = false;//AA�����Ƿ����ҵ�

    for (int i = nowResult + 1; (i < 14) && (nowResult < 14); i = nowResult + 1)//�ڵ�ǰ�ƺ��ҷ��Ϻ�����������
    {
        if ((typeNum[i] == typeNum[nowResult]) && (typeNum[i] != 3) &&
            mahjongNum[i] == (mahjongNum[nowResult] + 1) &&
            (result[i] != 0))//�ҵ�����Ͳ�е�AB
        {
            int a = i;
            for (int ii = i + 1;;)//��AB����C
            {
                if ((typeNum[ii] == typeNum[nowResult]) && mahjongNum[ii] == (mahjongNum[nowResult] + 2) &&
                    (result[ii] != 0))//�ҵ�ABC
                {
                    result[nowResult] = 0;
                    result[a] = 0;
                    result[ii] = 0;//�����ƶ�Ӧ��λ�ñ�Ϊ�Ѳ�
                    break;
                } else//��ʣ�µ����У�AB���Ҳ���C�����ܺ���
                    return false;
            }
        } else if ((typeNum[i] == typeNum[nowResult]) && (typeNum[i] != 3) &&
                   (mahjongNum[i] == mahjongNum[nowResult]) &&
                   (result[i] != 0))//�ҵ�AA
        {
            int a = i;
            for (int ii = i + 1;;)//��AA����A
                if ((typeNum[ii] == typeNum[nowResult]) && (mahjongNum[ii] == mahjongNum[nowResult]) &&
                    (result[ii] != 0))//�ҵ�AAA
                {
                    result[nowResult] = 0;
                    result[a] = 0;
                    result[ii] = 0;//�����ƶ�Ӧ��λ�ñ�Ϊ�Ѳ�
                    break;//���ҵ�������Ѱ��
                } else if (!AA)//�ҵ�AA�����Ƿ��ǵ�һ���ҵ�AA
                {
                    AA = true;
                    result[nowResult] = 0;
                    result[a] = 0;
                    break;//�����ƶ�Ӧ��λ�ñ�Ϊ�Ѳ�
                } else
                    return false;//�ڶ��γ���AA�����ܺ���
        } else if ((typeNum[i] == typeNum[nowResult]) && (typeNum[i] == 3) && (word[i] == word[nowResult]) &&
                   (result[i] != 0))//�ҵ����Ƶ�AA
        {
            int a = i;
            for (int ii = i + 1;;)//��AA����A
                if ((typeNum[ii] == typeNum[nowResult]) && (word[ii] == word[nowResult]) && (result[ii] != 0))//�ҵ�AAA
                {
                    result[nowResult] = 0;
                    result[a] = 0;
                    result[ii] = 0;
                    break;
                } else if (!AA)//�ҵ�AA�����Ƿ��ǵ�һ���ҵ�AA
                {
                    AA = true;
                    result[nowResult] = 0;
                    result[a] = 0;//�����ƶ�Ӧ��λ�ñ�Ϊ�Ѳ�
                    break;
                } else
                    return false;//�ڶ��γ���AA�����ܺ���
        } else return false;//ƥ�䵽A��û���ҵ�B��A

        nowResult++;
        for (int b = nowResult; (result[b] == 0) && (b < 14); b++)//�ҵ�����ϵ�������
            nowResult++;
    }
    return true;
}

Tiles &Tiles::operator=(const Tiles &another) {
    if (this == &another)return *this;

    for (int i = 0; i < another.size; i++) {
        this->tiles[i] = another.tiles[i];
        this->picPath[i] = another.picPath[i];
    }
    this->size = another.getSize();
    return *this;
}

unsigned int Tiles::getSize() const {
    return this->size;
}
