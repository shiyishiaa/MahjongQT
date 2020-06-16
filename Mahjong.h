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

    int getType() const;

    int getIndex() const;

    int getNum() const;

    int getWord() const;

    int getOrg() const;

    void print() const;

    static string generatePath(Mahjong *MJ);

    ~Mahjong();

private:
    int org;//ԭʼ����
    int num;//�������֣�0~9����0Ϊ���ƺͼ��ƣ�
    int word;//�������֣�0~7����0ΪͲ����1~7���������з��ף�
    int type;//�����Ͳ �� �� �������0~3��
    int index;//�齫������0~3��
};

#endif // !MAHJONG_H