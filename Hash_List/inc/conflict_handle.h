#pragma once
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include "hash.h"

const int handlefuncNum = 5;//�ܹ��洢�Ĺ�ϣ������������

//����Ƿ��ԭ����ֵ������ͻ
bool is_conflict(std::string hashList[], int hashNum);

int handle_1(std::string hashList[],std::string voidStr, int hashNum);//����Ѱַ��
int handle_2(std::string hashList[],std::string keyword, int hashNum);//�ٹ�ϣ��