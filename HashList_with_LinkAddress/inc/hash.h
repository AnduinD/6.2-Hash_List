#pragma once
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>

#define HASHNUM 2//标识调用哪一个哈希函数（前三套哈希函数都没有问题了）

const int MAXSIZE = 59;//哈希表的最大容量，这里即string数组的最大元素数量
const int hashfuncNum = 10;//能够存储的哈希函数的最大个数

//几个不同的哈希函数
//读入关键字，返回哈希值
int hash_1(std::string x);//线性哈希
int hash_2(std::string x);//更复杂的一个线性哈希
int hash_3(std::string x);//随机哈希