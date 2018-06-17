//
///*
//kmp彻底理解
//next 数组 ：用来指导S【i】串 T【j】串 对应字符失配
//指导 i 不回溯，即j应该走多少个位置
//next[j]:j位置前一个元素 需要
//计算某个字符对应的next值，就是看这个j对应字符之前的字符串中有多大长度的相同前缀后缀
//
//
//*/
//
#include<iostream>
#include<cstring>
using namespace std;
void nextval(char *T,int next[]){
    int j=-1,i=0;//i为后缀，j为前缀
    int len=strlen(T);
    next[0]=-1;
    while(i<len-1){
        if(j==-1||T[i]==T[j]){
            i++;j++;
            if(T[i]!=T[j]){
                next[i]=j;
            }else{
                next[i]=next[j];
            }
        }else{
            j=next[j];
        }
    }
}

int kmp(char *S,char *T){
    int i=0,j=0;
    int len1=strlen(S);
    int len2=strlen(T);
    int next[255];
    nextval(T,next);
    while(i<len1&&j<len2){
        if(j==-1||S[i]==T[j]){
            i++;j++;
        }else{
            j=next[j];
        }
    }
    if(j==len2)return i-j;
    else return -1;
}

int main(){
    char a[255],b[255];
    cin>>a>>b;
    char *ch=a;
    int len3=strlen(b);
    int pos=kmp(a,b);
    cout<<"pos is:"<<pos;
    cout<<endl<<"found:";
    while(len3--)cout<<a[pos++];
    return 0;
}
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include<iostream>
//using namespace std;
//void get_Next(char *pattern,int next[])//j前缀 i后缀
//{
//    int j = -1;
//	int i = 0;
//	int m = strlen(pattern);
//	next[0] = -1;
//	while(i < m - 1)
//	{
//		if(j == -1||pattern[j] == pattern[i])
//		{
//			i++;
//			j++;
//			if(pattern[j] != pattern[i])
//			{
//				next[i] = j;
//			}
//			else
//			{
//				next[i] = next[j];
//			}
//
//		}
//		else
//		{
//			j = next[j];
//		}
//
//	}
//}
//
//int KmpSearch(char* s, char* p)
//{
//    int i = 0;
//    int j = 0;
//    int sLen = strlen(s);
//    int pLen = strlen(p);
//	int next[100];
//	get_Next(p,next);
//    while (i < sLen && j < pLen)
//    {
//        //①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++
//        if (j == -1 || s[i] == p[j])
//        {
//            i++;
//            j++;
//        }
//        else
//        {
//            //②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]
//            //next[j]即为j所对应的next值
//            j = next[j];
//        }
//    }
//    if (j == pLen)
//        return i - j;
//    else
//        return -1;
//}
//
//int main(void)
//{
//	char text[255];
//	while(cin>>text){
//	char pattern[]="bkpstor";
//	char *ch = text;
//	int i = KmpSearch(text, pattern);
//	if(i >= 0)cout<<"Warning"<<endl;
//	else cout<<"Safe"<<endl;
//        //printf("matched@: %s\n", ch + i);
//	//printf("pos is %d\n",i);
//	}
//	return 0;
//}
/*
#include<iostream>
#include<cstring>
using namespace std;
char a[100];
char b[]="bkpstor";
int main(){
    while(cin>>a){
        if(strstr(a,b)){
            cout<<"Warning"<<endl;
        }
        else cout<<"Safe"<<endl;
    }
    return 0;
}
*/
