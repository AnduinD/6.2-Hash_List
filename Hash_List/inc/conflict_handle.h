#pragma once
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include "hash.h"

const int handlefuncNum = 5;//能够存储的哈希函数的最大个数

//检测是否和原有数值发生冲突
bool is_conflict(std::string hashList[], int hashNum);

int handle_1(std::string hashList[],std::string voidStr, int hashNum);//开放寻址法
int handle_2(std::string hashList[],std::string keyword, int hashNum);//再哈希法