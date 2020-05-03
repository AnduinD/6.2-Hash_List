#include "..\inc.\main.h"

int print_table(std::string hashList[])//��ӡ��������ϣ��ĺ���
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

//���벿��
    queue<string> student;//��һ�����д洢���е�ÿһ��ѧ������
    string line;//�ݴ�ÿ�е�����
    ifstream in("in.txt");//��Ҫ������ļ�
    while (in.eof() == false)
    {
        getline(in, line);//��in���ж������ַ�����line����
        student.push(line);//�����ѧ�������ִ���student������
    }
    in.close();//�ر��ļ�
    //�������е������Ѿ��浽��������

//������
    string hashList[MAXSIZE] = { "" };//�������¼�Ĺ�ϣ��

    extern int (*hash_funcs[hashfuncNum])(string);//ָ���ϣ�������ָ��
    extern int (*handle_funcs[handlefuncNum])
        (string hashList[], string str,int hashNum);//ָ���ͻ������ȡ��ָ��

    while (student.empty() == false)
    {
        string tempStr = student.front(); student.pop();//ȡ������Ԫ��

        int pos = hash_funcs[HASHNUM](tempStr);//ɢ�е���һ��λ��

        while (is_conflict(hashList, pos))
            //���posֵ��ԭ�ȵı���ֵ�г�ͻ,�ó�ͻ����������posֵ
            cout << "pos="<<pos << endl,pos = handle_funcs[HANDLEFIND_NUM](hashList, tempStr, pos);

        hashList[pos] = tempStr;//�ѹؼ���ӳ����Ӧ��λ����ȥ
    }

    print_table(hashList);//�������Ĺ�ϣ���ӡ����


//���Ҳ���
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
        int headPos = searchPos;//����һ����ʼλ�ã���ɢ�е�ʱ������ɻ��˾�������ж�
        
        extern int (*next_funcs[findfuncNum])
            (string hashList[], 
             string keyword,
                int pos);//��next������������

        while ((!is_match(hashList, keyword, searchPos))
            && (!hashList[searchPos].empty()))
            //������ֵ�ǲ��ǹؼ���ĵ�ַ�������ǣ���Ҫ���ݶ�Ӧ�ĵ�ַ��ͻ����Ѱַ
        {
            searchPos = next_funcs[HANDLEFIND_NUM](hashList, keyword, searchPos);
            if (searchPos == headPos) break;//���ת��һȦ��û�ҵ�����ֻ���˳�
        }

        if (hashList[searchPos].empty()||hashList[searchPos]!=keyword)
            cout << "Not Found!" << endl;//����û����ؼ���ƥ�����
        else
            cout << searchPos << endl;//�����ؼ���ƥ��Ķ�Ӧλ�õ�λ��ֵ
    }

    return 0;
}