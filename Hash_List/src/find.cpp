#include"..\inc\find.h"
#include<iostream>

bool is_match(std::string hashList[], std::string keyword, int pos)
{
    return (hashList[pos] == keyword);
}

extern int (*next_funcs[findfuncNum])(std::string hashList[],std::string keyword ,int pos) = { next_1,next_2 };

int next_1(std::string hashList[], std::string keyword, int pos)
{//��Ӧ�ڿ��Ŷ�ַ���Ķ���̽����ɢ��
    int d = 1;
    int tempInt = (pos + d) % MAXSIZE;
    while ((!is_match(hashList, keyword, tempInt))
        && (!hashList[pos].empty())
        &&tempInt!=pos/*ȷ��û�л�����*/)
    {
        d = (d > 0) ? (-d) : pow(sqrt(-d) + 1, 2);//d���а�����̽�����
        tempInt = ((pos + d) % MAXSIZE+MAXSIZE)%MAXSIZE;
    }

    return tempInt;
}

int next_2(std::string hashList[], std::string keyword, int pos)
{//��Ӧ���ٹ�ϣ���������ٹ�ϣ��д����������ѭ�����������ĿǰҲ���ˣ�
    extern int (*hash_funcs[hashfuncNum])(std::string);
    int temp;
    temp = hash_funcs[pos % 4](hashList[pos]);
    return temp;
}
