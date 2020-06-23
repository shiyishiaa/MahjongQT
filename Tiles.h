#pragma once
#ifndef TILES_H
#define TILES_H

#include <ctime>
#include <random>
#include "Mahjong.h"

class Tiles {
public:
    Tiles();

    explicit Tiles(unsigned int num);

    explicit Tiles(const string &PASSWORD);

    void print() const;

    void sort();

    string *getPicPath();

    unsigned int getSize() const;

    void parseTiles(string input);

    bool judge();

    ~Tiles();

    Tiles &operator=(const Tiles &another);

private:
    unsigned int size;
    Mahjong tiles[136];
    string picPath[14];
};

#endif // !TILES_H