#include "Tiles.h"

using namespace std;

//默认随机生成14张牌
Tiles::Tiles() {
    Tiles newTile(14);
    *this = newTile;
    this->size = 14;
}

//随机生成N张牌
Tiles::Tiles(int num) {
    this->size = num;
    if (num <= 0) {
        cout << "错误输入！" << endl;
        exit(-1);
    }

    random_device e;
    unsigned int random[14];
    random[0] = (e() % 136) + 1;
    this->tiles[0] = Mahjong(random[0]);//获取1~136内的随机正整数
    for (int i = 1; i < this->size; i++) {
        random[i] = (e() % 136) + 1;
        int j = 0;
        for (; j < i;)//避免重复获取
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

//生成136张牌（极为慢速）
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

//打印手牌
void Tiles::print() const {
    for (int i = 0; i < size; i++) {
        this->tiles[i].print();
    }
    cout << endl;
}

//牌组排序（选择排序）
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

//选择第N张麻将
Mahjong Tiles::select(int N) const {
    return this->tiles[N - 1];
}

//获取牌堆麻将图片路径
string *Tiles::getPicPath() {
    return this->picPath;
}

//析构函数
Tiles::~Tiles() = default;

//转换字符串载入手牌
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
//判断胡牌
bool Tiles::judge() {
    unsigned int typeNum[14];//牌类
    unsigned int mahjongNum[14];//牌面数字
    unsigned int word[14];//牌面字
    unsigned int result[14] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};//全为0则胡牌，用于剔除已使用的牌

    for (int i = 0; i < 14; i++)//存入手牌信息
    {
        typeNum[i] = this->tiles[i].getType();
        mahjongNum[i] = this->tiles[i].getNum();
        word[i] = this->tiles[i].getWord();
    }

    int nowResult = 0;//现在正在检索的组合的首张牌
    bool AA = false;//AA类型是否已找到

    for (int i = nowResult + 1; (i < 14) && (nowResult < 14); i = nowResult + 1)//在当前牌后找符合胡牌条件的牌
    {
        if ((typeNum[i] == typeNum[nowResult]) && (typeNum[i] != 3) &&
            mahjongNum[i] == (mahjongNum[nowResult] + 1) &&
            (result[i] != 0))//找到万条筒中的AB
        {
            int a = i;
            for (int ii = i + 1;;)//在AB后找C
            {
                if ((typeNum[ii] == typeNum[nowResult]) && mahjongNum[ii] == (mahjongNum[nowResult] + 2) &&
                    (result[ii] != 0))//找到ABC
                {
                    result[nowResult] = 0;
                    result[a] = 0;
                    result[ii] = 0;//三张牌对应的位置标为已查
                    break;
                } else//在剩下的牌中，AB后找不到C，不能胡牌
                    return false;
            }
        } else if ((typeNum[i] == typeNum[nowResult]) && (typeNum[i] != 3) &&
                   (mahjongNum[i] == mahjongNum[nowResult]) &&
                   (result[i] != 0))//找到AA
        {
            int a = i;
            for (int ii = i + 1;;)//在AA后找A
                if ((typeNum[ii] == typeNum[nowResult]) && (mahjongNum[ii] == mahjongNum[nowResult]) &&
                    (result[ii] != 0))//找到AAA
                {
                    result[nowResult] = 0;
                    result[a] = 0;
                    result[ii] = 0;//三张牌对应的位置标为已查
                    break;//已找到，结束寻找
                } else if (!AA)//找到AA，这是否是第一次找到AA
                {
                    AA = true;
                    result[nowResult] = 0;
                    result[a] = 0;
                    break;//两张牌对应的位置标为已查
                } else
                    return false;//第二次出现AA，不能胡牌
        } else if ((typeNum[i] == typeNum[nowResult]) && (typeNum[i] == 3) && (word[i] == word[nowResult]) &&
                   (result[i] != 0))//找到风牌的AA
        {
            int a = i;
            for (int ii = i + 1;;)//在AA后找A
                if ((typeNum[ii] == typeNum[nowResult]) && (word[ii] == word[nowResult]) && (result[ii] != 0))//找到AAA
                {
                    result[nowResult] = 0;
                    result[a] = 0;
                    result[ii] = 0;
                    break;
                } else if (!AA)//找到AA，这是否是第一次找到AA
                {
                    AA = true;
                    result[nowResult] = 0;
                    result[a] = 0;//两张牌对应的位置标为已查
                    break;
                } else
                    return false;//第二次出现AA，不能胡牌
        } else return false;//匹配到A但没有找到B或A

        nowResult++;
        for (int b = nowResult; (result[b] == 0) && (b < 14); b++)//找到新组合的首张牌
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
