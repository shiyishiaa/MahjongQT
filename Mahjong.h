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
    unsigned int org;//原始序数(1~136)
    unsigned int num;//牌面数字（0~9）（0为风牌和箭牌）
    unsigned int word;//牌面文字（0~7）（0为筒条万，1~7东南西北中发白）
    unsigned int type;//牌类别（筒 条 万 风箭）（0~3）
    unsigned int index;//麻将索引（0~3）
};

#endif // !MAHJONG_H