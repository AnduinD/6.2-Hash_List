#pragma once
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

#define HASHNUM 1//��ʶ������һ����ϣ������ǰ���׹�ϣ������û�������ˣ�
#define HANDLEFIND_NUM 0//��ʶ����һ����ͻ���������������Ӧ�Ĳ�����һ��������Ŀǰ�͵�0�׿��èr(�s���t)�q��

const int MAXSIZE = 119;//��ϣ���������������Ｔstring��������Ԫ������
const int hashfuncNum = 10;//�ܹ��洢�Ĺ�ϣ������������

//������ͬ�Ĺ�ϣ����
int hash_1(std::string x);
int hash_2(std::string x);
int hash_3(std::string x);
int hash_4(std::string x);