#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
    char str1[55],str2[55];
    int flag;
    int q;
    while(gets(str1)!=NULL)//ֱ���ļ�����
    {
        memset(str2,0,sizeof(str2));//���
        flag = 0;
        q = 0;
        int len = strlen(str1);
        for(int i=0; i<len ; i++)
        {
            if(str1[i] == '('||str1[i] == '{'||str1[i] == '[')
            {
                q++;//��ջ++
                str2[q] = str1[i];//����������
            }
            else if(str1[i] == ')'||str1[i] == '}'||str1[i] == ']')
            {
                if(q==0)//q = 0˵��û�������ţ����������Ų�ƥ��
                {
                    flag = 1;
                    break;
                }
                else if(str2[q]==str1[i]-1 || str2[q]==str1[i]-2)//����ASCLL���'['��']'֮��������������һ
                {
                    str2[q--]='\0';//��ջ--
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 0&&q==0)//����q=0�ж��ַ�����û��������
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
