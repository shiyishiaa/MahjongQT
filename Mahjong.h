#pragma once
#ifndef MAHJONG_H
#define MAHJONG_H

#include <iostream>
#include <string>

using namespace std;

class Mahjong {
public:
    Mahjong();

    explicit Mahjong(unsigned int inputNum);

    unsigned int getType() const;

    unsigned int getIndex() const;

    unsigned int getNum() const;

    unsigned int getWord() const;

    unsigned int getOrg() const;

    void print() const;

    static string generatePath(Mahjong *mahjong);

    Mahjong &operator=(const Mahjong& another);

    ~Mahjong();

private:
    unsigned int org;//ԭʼ����(1~136)
    unsigned int num;//�������֣�0~9����0Ϊ���ƺͼ��ƣ�
    unsigned int word;//�������֣�0~7����0ΪͲ����1~7���������з��ף�
    unsigned int type;//�����Ͳ �� �� �������0~3��
    unsigned int index;//�齫������0~3��
};

#endif // !MAHJONG_H