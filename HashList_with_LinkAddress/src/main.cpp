#include "..\inc.\main.h"
#include<cstdlib>

int print_table(std::list<std::string> hashList[])//打印出完整哈希表的函数
{
    using namespace std;
    cout << "\n\n****Hash Table****\n" << endl;
    for (int i = 0; i < MAXSIZE; i++)
    {
        cout << i << "  ";
        for (list<string>::iterator j = hashList[i].begin(); j != hashList[i].end(); j++)
            cout << (j->empty() ? "NULL" : " --> ") << j->data();
        cout << endl;
    }
    return 0;
}

int main()
{
    using namespace std;

    ///////////////////////////////////////////////////////////////////////////////
    queue<string> student;
    string line;//暂存每行的内容
    ifstream in("in.txt");//打开要读入的文件

    while (in.eof() == false)
    {
        getline(in, line);//从in流中读单行字符串到line里面
        student.push(line);//把这个学生的名字存入student队列中
    }
    in.close();//关闭文件
    //现在所有的人名已经存到队列里了

///////////////////////////////////////////////////////////////////////////////
    //下面开始进行哈希建表
    list<string> hashList[MAXSIZE];//用来存记录的哈希表

                                   //指向哈希函数组的指针
    extern int (*hash_funcs[hashfuncNum])(std::string);
    while (student.empty() == false)
    {
        string tempStr = student.front(); student.pop();//取出队首元素
        hashList[hash_funcs[HASHNUM](tempStr)].push_back(tempStr);//把关键字映到对应的位置上去
        //注：链地址法不用单独的冲突处理，只是每次加元素都往表尾append就可以了
    }
    print_table(hashList);

    ///////////////////////////////////////////////////////////////////////////////
        //下面进行查找操作
    cout << "now is time to search from the hash table!" << endl;
    while (true)
    {
        cout <<
            "please input the keyword" <<
            "( input \"exit\" to exit the program): ";

        string keyword = "";//由用户输入的关键码
        getline(cin, keyword);//读入用户输入的关键码

        //两种特判情况
        if (keyword == "exit") break;
        if (keyword == "\0") continue;

        int searchPos = (hash_funcs[HASHNUM](keyword));//返回哈希函数给的值
        int subPos = 1;//返回在链中得第几个位置

        //检查这个值是不是关键码的地址，若不是，则要链式寻址
        bool notFound = false;
        if (hashList[searchPos].empty()) notFound = true;//索引到一个空表
        else //索引到非空表，但无对应的表项
        {
            notFound = true;
            for (list<string>::iterator cur = hashList[searchPos].begin();
                cur != hashList[searchPos].end(); cur++, subPos++)
                if (cur->data() == keyword)
                {notFound = false; break;}
        }


        if (notFound)//即在表中没找到
            cout << "Not Found!" << endl;//表中没有与关键字匹配的项
        else//在表中找到了，输出表项编号和链中的编号
            cout << searchPos << ", " << subPos << endl;//输出与关键码匹配的对应位置的位置值
    }

    return 0;
}