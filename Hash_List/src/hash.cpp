#include"..\inc\hash.h"
#include<iostream>

std::string get_first_word(std::string line)
{//取出字符串中的第一个单词
    std::string word = "";
    for (std::string::iterator i = line.begin(); *i != ' '; i++)
        word += *i;
    return word;
}
std::string get_last_word(std::string line)
{//取出字符串中的最后一个单词
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
{//进行线性哈希,然后除留余数
    int a = 7, b = 13;//线性哈希的参数
    return (a * x.length() + b) % (MAXSIZE);
}

int hash_2(std::string x)
{//把姓和名分开,用更多的参数来做线性处理
    using namespace std;
    string lastName = get_first_word(x);//取姓
    string firstName = get_last_word(x);//取名
    
    int y = ((
        (firstName.front() - 'A' + lastName.size()) * 11
        + (firstName.back() - 'a' + firstName.size())
        ) % MAXSIZE + MAXSIZE/*加个MAXSIZE免得模出个负数来*/
        )%MAXSIZE;
    
    return y;

}

int hash_3(std::string x)
{//用固定的随机数，然后除留余数来建哈希表
    using namespace std;
    srand(x.length() * x.front() * x.back());
    int y = rand() % MAXSIZE;

    return y;
}


int hash_4(std::string x)
{//平方取中，然后除留余数来建表（目前有问题，考虑删掉了）
    using namespace std;    
    int y = (x.size())% MAXSIZE;

    return 0;
}
