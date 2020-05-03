#include "..\inc.\main.h"

int print_table(std::string hashList[])//打印出完整哈希表的函数
{
    using namespace std;
    cout << "\n\n****Hash Table****\n" << endl;
    for (int i = 0; i < MAXSIZE; i++)
    {
        if (hashList[i].empty() == false)
            cout << i << '\t' << hashList[i].data() << endl;
    }
    return 0;
}


int main()
{
    using namespace std;

//读入部分
    queue<string> student;//用一个队列存储表中的每一个学生名字
    string line;//暂存每行的内容
    ifstream in("in.txt");//打开要读入的文件
    while (in.eof() == false)
    {
        getline(in, line);//从in流中读单行字符串到line里面
        student.push(line);//把这个学生的名字存入student队列中
    }
    in.close();//关闭文件
    //现在所有的人名已经存到队列里了

//建表部分
    string hashList[MAXSIZE] = { "" };//用来存记录的哈希表

    extern int (*hash_funcs[hashfuncNum])(string);//指向哈希函数组的指针
    extern int (*handle_funcs[handlefuncNum])
        (string hashList[], string str,int hashNum);//指向冲突处理函数取得指针

    while (student.empty() == false)
    {
        string tempStr = student.front(); student.pop();//取出队首元素

        int pos = hash_funcs[HASHNUM](tempStr);//散列到第一个位置

        while (is_conflict(hashList, pos))
            //如果pos值与原先的表中值有冲突,用冲突处理函数更新pos值
            cout << "pos="<<pos << endl,pos = handle_funcs[HANDLEFIND_NUM](hashList, tempStr, pos);

        hashList[pos] = tempStr;//把关键字映到对应的位置上去
    }

    print_table(hashList);//把完整的哈希表打印出来


//查找部分
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
        int headPos = searchPos;//定义一个起始位置，在散列的时候如果成环了就用这个判断
        
        extern int (*next_funcs[findfuncNum])
            (string hashList[], 
             string keyword,
                int pos);//把next函数组引过来

        while ((!is_match(hashList, keyword, searchPos))
            && (!hashList[searchPos].empty()))
            //检查这个值是不是关键码的地址，若不是，则要根据对应的地址冲突法来寻址
        {
            searchPos = next_funcs[HANDLEFIND_NUM](hashList, keyword, searchPos);
            if (searchPos == headPos) break;//如果转了一圈都没找到，就只能退出
        }

        if (hashList[searchPos].empty()||hashList[searchPos]!=keyword)
            cout << "Not Found!" << endl;//表中没有与关键字匹配的项
        else
            cout << searchPos << endl;//输出与关键码匹配的对应位置的位置值
    }

    return 0;
}