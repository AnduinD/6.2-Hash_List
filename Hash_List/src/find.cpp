#include"..\inc\find.h"
#include<iostream>

bool is_match(std::string hashList[], std::string keyword, int pos)
{
    return (hashList[pos] == keyword);
}

extern int (*next_funcs[findfuncNum])(std::string hashList[],std::string keyword ,int pos) = { next_1,next_2 };

int next_1(std::string hashList[], std::string keyword, int pos)
{//对应于开放定址法的二次探测再散列
    int d = 1;
    int tempInt = (pos + d) % MAXSIZE;
    while ((!is_match(hashList, keyword, tempInt))
        && (!hashList[pos].empty())
        &&tempInt!=pos/*确保没有环回来*/)
    {
        d = (d > 0) ? (-d) : pow(sqrt(-d) + 1, 2);//d序列按二次探测递增
        tempInt = ((pos + d) % MAXSIZE+MAXSIZE)%MAXSIZE;
    }

    return tempInt;
}

int next_2(std::string hashList[], std::string keyword, int pos)
{//对应于再哈希法（由于再哈希法写得老是有死循环，所以这个目前也废了）
    extern int (*hash_funcs[hashfuncNum])(std::string);
    int temp;
    temp = hash_funcs[pos % 4](hashList[pos]);
    return temp;
}
