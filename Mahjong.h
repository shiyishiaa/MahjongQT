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
    int org;//原始序数
    int num;//牌面数字（0~9）（0为风牌和箭牌）
    int word;//牌面文字（0~7）（0为筒条万，1~7东南西北中发白）
    int type;//牌类别（筒 条 万 风箭）（0~3）
    int index;//麻将索引（0~3）
};

#endif // !MAHJONG_H