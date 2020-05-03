#pragma once
#include <string>

#include "hash.h"

const int findfuncNum = 5;

bool is_match(std::string hashList[], std::string keyword, int pos);//判断对应得位置是否找到

//对应于两种冲突处理的方式，定义两种查找下一位置的函数
int next_1(std::string hashList[], std::string keyword, int pos);//对应于开放定址法的二次探测再散列
int next_2(std::string hashList[], std::string keyword, int pos);//对应于再哈希法