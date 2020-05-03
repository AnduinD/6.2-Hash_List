#include "..\inc.\main.h"
#include<cstdlib>

int print_table(std::list<std::string> hashList[])//��ӡ��������ϣ��ĺ���
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
    string line;//�ݴ�ÿ�е�����
    ifstream in("in.txt");//��Ҫ������ļ�

    while (in.eof() == false)
    {
        getline(in, line);//��in���ж������ַ�����line����
        student.push(line);//�����ѧ�������ִ���student������
    }
    in.close();//�ر��ļ�
    //�������е������Ѿ��浽��������

///////////////////////////////////////////////////////////////////////////////
    //���濪ʼ���й�ϣ����
    list<string> hashList[MAXSIZE];//�������¼�Ĺ�ϣ��

                                   //ָ���ϣ�������ָ��
    extern int (*hash_funcs[hashfuncNum])(std::string);
    while (student.empty() == false)
    {
        string tempStr = student.front(); student.pop();//ȡ������Ԫ��
        hashList[hash_funcs[HASHNUM](tempStr)].push_back(tempStr);//�ѹؼ���ӳ����Ӧ��λ����ȥ
        //ע������ַ�����õ����ĳ�ͻ����ֻ��ÿ�μ�Ԫ�ض�����βappend�Ϳ�����
    }
    print_table(hashList);

    ///////////////////////////////////////////////////////////////////////////////
        //������в��Ҳ���
    cout << "now is time to search from the hash table!" << endl;
    while (true)
    {
        cout <<
            "please input the keyword" <<
            "( input \"exit\" to exit the program): ";

        string keyword = "";//���û�����Ĺؼ���
        getline(cin, keyword);//�����û�����Ĺؼ���

        //�����������
        if (keyword == "exit") break;
        if (keyword == "\0") continue;

        int searchPos = (hash_funcs[HASHNUM](keyword));//���ع�ϣ��������ֵ
        int subPos = 1;//���������еõڼ���λ��

        //������ֵ�ǲ��ǹؼ���ĵ�ַ�������ǣ���Ҫ��ʽѰַ
        bool notFound = false;
        if (hashList[searchPos].empty()) notFound = true;//������һ���ձ�
        else //�������ǿձ����޶�Ӧ�ı���
        {
            notFound = true;
            for (list<string>::iterator cur = hashList[searchPos].begin();
                cur != hashList[searchPos].end(); cur++, subPos++)
                if (cur->data() == keyword)
                {notFound = false; break;}
        }


        if (notFound)//���ڱ���û�ҵ�
            cout << "Not Found!" << endl;//����û����ؼ���ƥ�����
        else//�ڱ����ҵ��ˣ���������ź����еı��
            cout << searchPos << ", " << subPos << endl;//�����ؼ���ƥ��Ķ�Ӧλ�õ�λ��ֵ
    }

    return 0;
}