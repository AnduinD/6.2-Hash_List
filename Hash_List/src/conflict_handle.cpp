#include"..\inc\conflict_handle.h"
#include<iostream>

bool is_conflict(std::string hashList[], int hashNum)
{
    return (!hashList[hashNum].empty());
}


extern int (*handle_funcs[handlefuncNum])(std::string hashList[], std::string str,int hashNum) = { handle_1,handle_2 };

int handle_1(std::string hashList[], std::string voidStr,int hashNum)
{//开放定址法，二次探测再散列
    int d = 1;
    int tempInt=(hashNum + d) % MAXSIZE;

    while (is_conflict(hashList, tempInt)==true)
    {
        d = (d > 0) ? (-d) : pow(sqrt(-d) + 1, 2);//d序列按二次探测递增
        tempInt = (((hashNum + d) % MAXSIZE) + MAXSIZE)%MAXSIZE;//更新位置
    }
    return tempInt;
}



int handle_2(std::string hashList[], std::string keyword,int hashNum)
{//再哈希法(貌似很容易哈出死循环，放弃这个了o(*￣▽￣*)ブ)
    extern int (*hash_funcs[hashfuncNum])(std::string);
    int temp;
    temp = hash_funcs[2](keyword);
    return temp;
}
