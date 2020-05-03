#if 0
#pragma once
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include "hash.h"

//检测是否和原有数值发生冲突
bool is_conflict(std::list<std::string> hashList[], int hashNum);

int handle_link_addr(std::list<std::string> hashList[], int hashNum);//链地址法处理冲突

#endif