#pragma once
#include <string>

#include "hash.h"

const int findfuncNum = 5;

bool is_match(std::string hashList[], std::string keyword, int pos);//�ж϶�Ӧ��λ���Ƿ��ҵ�

//��Ӧ�����ֳ�ͻ����ķ�ʽ���������ֲ�����һλ�õĺ���
int next_1(std::string hashList[], std::string keyword, int pos);//��Ӧ�ڿ��Ŷ�ַ���Ķ���̽����ɢ��
int next_2(std::string hashList[], std::string keyword, int pos);//��Ӧ���ٹ�ϣ��