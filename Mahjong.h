#pragma once
#ifndef MAHJONG_H
#define MAHJONG_H

#include <iostream>
#include <string>

using namespace std;

class Mahjong {
public:
    Mahjong();

    explicit Mahjong(int MJ);

    int getClass() const;

    int getIndex() const;

    int getNum() const;

    int getWord() const;

    int getOrg() const;

    void print() const;

    static string generatePath(Mahjong *MJ);

    ~Mahjong();

private:
    int _org;//ԭʼ����
    int _num;//�������֣�0~9����0Ϊ���ƺͼ��ƣ�
    int _word;//�������֣�0~7����0ΪͲ����1~7���������з��ף�
    int _class;//�����Ͳ �� �� �������0~3��
    int _index;//�齫������0~3��
};

#endif // !MAHJONG_H