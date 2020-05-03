#include"..\inc\conflict_handle.h"
#include<iostream>

bool is_conflict(std::string hashList[], int hashNum)
{
    return (!hashList[hashNum].empty());
}


extern int (*handle_funcs[handlefuncNum])(std::string hashList[], std::string str,int hashNum) = { handle_1,handle_2 };

int handle_1(std::string hashList[], std::string voidStr,int hashNum)
{//���Ŷ�ַ��������̽����ɢ��
    int d = 1;
    int tempInt=(hashNum + d) % MAXSIZE;

    while (is_conflict(hashList, tempInt)==true)
    {
        d = (d > 0) ? (-d) : pow(sqrt(-d) + 1, 2);//d���а�����̽�����
        tempInt = (((hashNum + d) % MAXSIZE) + MAXSIZE)%MAXSIZE;//����λ��
    }
    return tempInt;
}



int handle_2(std::string hashList[], std::string keyword,int hashNum)
{//�ٹ�ϣ��(ò�ƺ����׹�����ѭ�������������o(*������*)��)
    extern int (*hash_funcs[hashfuncNum])(std::string);
    int temp;
    temp = hash_funcs[2](keyword);
    return temp;
}
