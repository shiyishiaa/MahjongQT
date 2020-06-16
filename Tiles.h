#pragma once
#ifndef TILES_H
#define TILES_H

#include <ctime>
#include "Mahjong.h"

class Tiles {
public:
    Tiles();

    explicit Tiles(int N);

    explicit Tiles(const string &PASSWORD);

    void print() const;

    void sort();

    Mahjong select(int N) const;

    string *getPicPath();

    void output(string input);

    bool judge();

    ~Tiles();

private:
    int num;
    Mahjong tiles[136];
    string picPath[14];
};

#endif // !TILES_H