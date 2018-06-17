//
///*
//kmp�������
//next ���� ������ָ��S��i���� T��j���� ��Ӧ�ַ�ʧ��
//ָ�� i �����ݣ���jӦ���߶��ٸ�λ��
//next[j]:jλ��ǰһ��Ԫ�� ��Ҫ
//����ĳ���ַ���Ӧ��nextֵ�����ǿ����j��Ӧ�ַ�֮ǰ���ַ������ж�󳤶ȵ���ͬǰ׺��׺
//
//
//*/
//
#include<iostream>
#include<cstring>
using namespace std;
void nextval(char *T,int next[]){
    int j=-1,i=0;//iΪ��׺��jΪǰ׺
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
//void get_Next(char *pattern,int next[])//jǰ׺ i��׺
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
//        //�����j = -1�����ߵ�ǰ�ַ�ƥ��ɹ�����S[i] == P[j]��������i++��j++
//        if (j == -1 || s[i] == p[j])
//        {
//            i++;
//            j++;
//        }
//        else
//        {
//            //�����j != -1���ҵ�ǰ�ַ�ƥ��ʧ�ܣ���S[i] != P[j]�������� i ���䣬j = next[j]
//            //next[j]��Ϊj����Ӧ��nextֵ
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
