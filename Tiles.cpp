#include "Tiles.h"

using namespace std;

//Ĭ���������14����
Tiles::Tiles() {
    this->num = 14;
    // TODO Ч�ʵ���
    srand(time(nullptr));//���������
    int random[14];
    random[0] = (rand() % 136) + 1;
    this->tiles[0] = Mahjong(random[0]);//��ȡ1~136�ڵ����������
    for (int i = 1; i < this->num; i++) {
        random[i] = (rand() % 136) + 1;
        int j = 0;
        for (; j < i;)//�����ظ���ȡ
        {
            while (random[i] == random[j++]) {
                srand(time(nullptr));
                random[i] = (rand() % 136) + 1;
                j = 0;
            }
        }
        this->tiles[i] = Mahjong(random[i]);
    }
    this->sort();
    string *p = this->picPath;
    for (int i = 0; i < this->num; i++) {
        *p = this->tiles[i].generatePath(&tiles[i]);
        p++;
    }
}

//�������N����
Tiles::Tiles(int N) {
    this->num = N;
    if (N >= 15) {
        cout << "������14���ƣ�" << endl;
        this->num = 14;
    }
    if (N <= 0) {
        cout << "�������룡" << endl;
        exit(-1);
    }
    srand(time(nullptr));//���������
    int random[14];
    random[0] = (rand() % 136) + 1;
    this->tiles[0] = Mahjong(random[0]);//��ȡ1~136�ڵ����������
    for (int i = 1; i < this->num; i++) {
        random[i] = (rand() % 136) + 1;
        int j = 0;
        for (; j < i;)//�����ظ���ȡ
        {
            while (random[i] == random[j++]) {
                srand(time(nullptr));
                random[i] = (rand() % 136) + 1;
                j = 0;
            }
        }
        this->tiles[i] = Mahjong(random[i]);
    }
    this->sort();
    string *p = this->picPath;
    for (int i = 0; i < this->num; i++) {
        *p = this->tiles[i].generatePath(&tiles[i]);
        p++;
    }
}

//����136���ƣ���Ϊ���٣�
Tiles::Tiles(const string &PASSWORD) {
    while (PASSWORD == "&((fdsiojfs@") {
        this->num = 136;
        srand(time(nullptr));//���������
        int random[136];
        random[0] = (rand() % 136) + 1;
        this->tiles[0] = Mahjong(random[0]);//��ȡ1~136�ڵ����������
        for (int i = 1; i < this->num; i++) {
            random[i] = (rand() % 136) + 1;
            int j = 0;
            for (; j < i;)//�����ظ���ȡ
            {
                while (random[i] == random[j++]) {
                    srand(time(nullptr));
                    random[i] = (rand() % 136) + 1;
                    j = 0;
                }
            }
            this->tiles[i] = Mahjong(random[i]);
        }
        string *p = this->picPath;
        for (int i = 0; i < this->num; i++) {
            *p = this->tiles[i].generatePath(&tiles[i]);
            p++;
        }
        return;
    }
    exit(-1);
}

//��ӡ����
void Tiles::print() const {
    for (int i = 0; i < num; i++) {
        this->tiles[i].print();
    }
    cout << endl;
}

//��������ѡ������
void Tiles::sort() {
    int newNum = this->num;
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
void Tiles::output(string input) {
    int Index = 0;
    for (int i = 0; i < num; i++) {
        Index = input.find(',');
        string inputStr = input.substr(0, Index);
        int newNum = atoi(inputStr.c_str());
        this->tiles[i] = Mahjong(newNum);
        input = input.erase(0, Index + 1);
    }
    sort();
    for (int j = 0; j < num; j++) {
        this->picPath[j] = tiles[j].generatePath(&tiles[j]);
    }
}


/**
 * Code created by my classmate Seto Lian
 * @return if completed a hand
 */
//�жϺ���
bool Tiles::judge() {
    int classNum[14];//����
    int mahjongNum[14];//��������
    int word[14];//������
    int result[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};//ȫΪ0����ƣ������޳���ʹ�õ���

    for (int i = 0; i < 14; i++)//����������Ϣ
    {
        classNum[i] = this->tiles[i].getClass();
        mahjongNum[i] = this->tiles[i].getNum();
        word[i] = this->tiles[i].getWord();
    }

    int nowResult = 0;//�������ڼ�������ϵ�������
    bool AA = false;//AA�����Ƿ����ҵ�

    for (int i = nowResult + 1; (i < 14) && (nowResult < 14); i = nowResult + 1)//�ڵ�ǰ�ƺ��ҷ��Ϻ�����������
    {
        if ((classNum[i] == classNum[nowResult]) && (classNum[i] != 3) &&
            mahjongNum[i] == (mahjongNum[nowResult] + 1) &&
            (result[i] != 0))//�ҵ�����Ͳ�е�AB��
        {
            int a = i;
            for (int ii = i + 1; ii < 14; ii++)//��AB����C
            {
                if ((classNum[ii] == classNum[nowResult]) && mahjongNum[ii] == (mahjongNum[nowResult] + 2) &&
                    (result[ii] != 0))//�ҵ�ABC
                {
                    result[nowResult] = 0;
                    result[a] = 0;
                    result[ii] = 0;//�����ƶ�Ӧ��λ�ñ�Ϊ�Ѳ�
                    break;
                } else//��ʣ�µ����У�AB���Ҳ���C�����ܺ���
                    return false;
            }
        } else if ((classNum[i] == classNum[nowResult]) && (classNum[i] != 3) &&
                   (mahjongNum[i] == mahjongNum[nowResult]) &&
                   (result[i] != 0))//�ҵ�AA��
        {
            int a = i;
            for (int ii = i + 1; ii < 14; ii++)//��AA����A
                if ((classNum[ii] == classNum[nowResult]) && (mahjongNum[ii] == mahjongNum[nowResult]) &&
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
        } else if ((classNum[i] == classNum[nowResult]) && (classNum[i] == 3) && (word[i] == word[nowResult]) &&
                   (result[i] != 0))//�ҵ����Ƶ�AA��
        {
            int a = i;
            for (int ii = i + 1; ii < 15; ii++)//��AA����A
                if ((classNum[ii] == classNum[nowResult]) && (word[ii] == word[nowResult]) && (result[ii] != 0))//�ҵ�AAA
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