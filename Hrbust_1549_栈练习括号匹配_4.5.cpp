#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
    char str1[55],str2[55];
    int flag;
    int q;
    while(gets(str1)!=NULL)//直到文件结束
    {
        memset(str2,0,sizeof(str2));//清空
        flag = 0;
        q = 0;
        int len = strlen(str1);
        for(int i=0; i<len ; i++)
        {
            if(str1[i] == '('||str1[i] == '{'||str1[i] == '[')
            {
                q++;//入栈++
                str2[q] = str1[i];//保存左括号
            }
            else if(str1[i] == ')'||str1[i] == '}'||str1[i] == ']')
            {
                if(q==0)//q = 0说明没有左括号，但有右括号不匹配
                {
                    flag = 1;
                    break;
                }
                else if(str2[q]==str1[i]-1 || str2[q]==str1[i]-2)//根据ASCLL码表'['与']'之间差二另外两个差一
                {
                    str2[q--]='\0';//出栈--
                }
                else
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 0&&q==0)//这里q=0判断字符串中没有右括号
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
