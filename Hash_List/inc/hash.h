#pragma once
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

#define HASHNUM 1//标识调用哪一个哈希函数（前三套哈希函数都没有问题了）
#define HANDLEFIND_NUM 0//标识用哪一个冲突处理函数，及于其对应的查找下一个函数（目前就第0套可用╮(╯▽╰)╭）

const int MAXSIZE = 119;//哈希表的最大容量，这里即string数组的最大元素数量
const int hashfuncNum = 10;//能够存储的哈希函数的最大个数

//几个不同的哈希函数
int hash_1(std::string x);
int hash_2(std::string x);
int hash_3(std::string x);
int hash_4(std::string x);