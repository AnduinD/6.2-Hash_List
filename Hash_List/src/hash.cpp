#include"..\inc\hash.h"
#include<iostream>

std::string get_first_word(std::string line)
{//ȡ���ַ����еĵ�һ������
    std::string word = "";
    for (std::string::iterator i = line.begin(); *i != ' '; i++)
        word += *i;
    return word;
}
std::string get_last_word(std::string line)
{//ȡ���ַ����е����һ������
    std::string word = "";
    std::stack<char> rWord;
    for (std::string::reverse_iterator i = line.rbegin(); *i != ' '; i++)
        rWord.push(*i);

    while (rWord.empty() == false)
        word += rWord.top(), rWord.pop();
    return word;
}

int (*hash_funcs[hashfuncNum])(std::string) = { hash_1,hash_2,hash_3,hash_4 };
int hash_1(std::string x)
{//�������Թ�ϣ,Ȼ���������
    int a = 7, b = 13;//���Թ�ϣ�Ĳ���
    return (a * x.length() + b) % (MAXSIZE);
}

int hash_2(std::string x)
{//���պ����ֿ�,�ø���Ĳ����������Դ���
    using namespace std;
    string lastName = get_first_word(x);//ȡ��
    string firstName = get_last_word(x);//ȡ��
    
    int y = ((
        (firstName.front() - 'A' + lastName.size()) * 11
        + (firstName.back() - 'a' + firstName.size())
        ) % MAXSIZE + MAXSIZE/*�Ӹ�MAXSIZE���ģ����������*/
        )%MAXSIZE;
    
    return y;

}

int hash_3(std::string x)
{//�ù̶����������Ȼ���������������ϣ��
    using namespace std;
    srand(x.length() * x.front() * x.back());
    int y = rand() % MAXSIZE;

    return y;
}


int hash_4(std::string x)
{//ƽ��ȡ�У�Ȼ���������������Ŀǰ�����⣬����ɾ���ˣ�
    using namespace std;    
    int y = (x.size())% MAXSIZE;

    return 0;
}
