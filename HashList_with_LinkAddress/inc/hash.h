#pragma once
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>

#define HASHNUM 2//��ʶ������һ����ϣ������ǰ���׹�ϣ������û�������ˣ�

const int MAXSIZE = 59;//��ϣ���������������Ｔstring��������Ԫ������
const int hashfuncNum = 10;//�ܹ��洢�Ĺ�ϣ������������

//������ͬ�Ĺ�ϣ����
//����ؼ��֣����ع�ϣֵ
int hash_1(std::string x);//���Թ�ϣ
int hash_2(std::string x);//�����ӵ�һ�����Թ�ϣ
int hash_3(std::string x);//�����ϣ