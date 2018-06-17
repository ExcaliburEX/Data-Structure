#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ZhaoFullFish 10
#define ZhaoFullFood 10
#define SunFullFish 6
#define SunFullFood 13
#define LiFullFish 5
#define LiFullFood 18
double SumFish,SumFood;
double HalfFish,HalfFood;
int cnt=0;

void solve1(int a,int b)
{
    SumFish=a,SumFood=b;
    HalfFish=SumFish/2.0;
    HalfFood=SumFood/2.0;
    cnt=0;
    for(double i=0.5;i<=SumFish;i+=0.5)
    {
        for(double j=0.5;j<=SumFood;j+=0.5)
        {

            if((((i-HalfFish)*(HalfFood/HalfFish)+(j-HalfFood))>=0.0)||
               ((((SumFish-i)-HalfFish)*(HalfFood/HalfFish)+((SumFood-j)-HalfFood))>=0.0))
               {

                   if((((i-HalfFish)*(HalfFood/HalfFish)+(j-HalfFood))>=0.0)&&
                      ((((SumFish-i)-HalfFish)*(HalfFood/HalfFish)+((SumFood-j)-HalfFood))>=0.0))
                   {

                       if(((i-ZhaoFullFish/2.0>=0.0)&&(j-ZhaoFullFood/2.0>=0.0))&&
                        (((SumFish-i)-LiFullFish/2.0>=0.0)&&((SumFood-j)-LiFullFood/2.0>=0.0))){
                       cnt++;
                       printf("����%-3d:",cnt);
                       printf("˫��ƽ������ʵ�ֹ�Ӯ����Ϊ%.1f���ʳΪ%.1f��\n",i,j);
                        }
                   }
                   else if(((i-HalfFish)*(HalfFood/HalfFish)+(j-HalfFood))>=0.0)
                    {
                        if(((i-ZhaoFullFish/2.0>=0.0)&&(j-ZhaoFullFood/2.0>=0.0))&&
                        (((SumFish-i)-LiFullFish/2.0>=0.0)&&((SumFood-j)-LiFullFood/2.0>=0.0))){
                            cnt++;
                        printf("����%-3d:",cnt);
                        printf("�Լһ����%.1f��,�����ʳ%.1f�ӯ��%.1f����ʳ����һ����%.1f��,�����ʳ%.1f�����%.1f����ʳ��\n",i,j,
                               (i-HalfFish)*(HalfFood/HalfFish)+(j-HalfFood),SumFish-i,SumFood-j,
                               -(((SumFish-i)-HalfFish)*(HalfFood/HalfFish)+((SumFood-j)-HalfFood)));
                        }
                    }
                    else
                    {
                     if(((i-ZhaoFullFish/2.0>=0.0)&&(j-ZhaoFullFood/2.0>=0.0))&&
                        (((SumFish-i)-LiFullFish/2.0>=0.0)&&((SumFood-j)-LiFullFood/2.0>=0.0))){
                            cnt++;
                        printf("����%-3d:",cnt);
                        printf("�Լһ����%.1f��,�����ʳ%.1f��,����%.1f����ʳ����һ����%.1f��,�����ʳ%.1f�ӯ��%.1f����ʳ��\n",i,j,
                               -((i-HalfFish)*(HalfFood/HalfFish)+(j-HalfFood)),SumFish-i,SumFood-j,
                               ((SumFish-i)-HalfFish)*(HalfFood/HalfFish)+((SumFood-j)-HalfFood));
                        }
                    }
               }

        }
    }

}

void solve2(int a,int b)
{
    SumFish=a,SumFood=b;
    HalfFish=SumFish/2.0;
    HalfFood=SumFood/2.0;
    cnt=0;
    for(double i=0.5;i<=SumFish;i+=0.5)
    {
        for(double j=0.5;j<=SumFood;j+=0.5)
        {

            if((((i-HalfFish)*(HalfFood/HalfFish)+(j-HalfFood))>=0.0)||
               ((((SumFish-i)-HalfFish)*(HalfFood/HalfFish)+((SumFood-j)-HalfFood))>=0.0))
               {

                   if((((i-HalfFish)*(HalfFood/HalfFish)+(j-HalfFood))>=0.0)&&
                      ((((SumFish-i)-HalfFish)*(HalfFood/HalfFish)+((SumFood-j)-HalfFood))>=0.0))
                   {

                        if(((i-ZhaoFullFish/2.0>=0.0)||(j-ZhaoFullFood/2.0>=0.0))&&
                        (((SumFish-i)-LiFullFish/2.0>=0.0)||((SumFood-j)-LiFullFood/2.0>=0.0))){
                       cnt++;
                       printf("����%-3d:",cnt);
                       printf("˫��ƽ������ʵ�ֹ�Ӯ����Ϊ%.1f���ʳΪ%.1f��\n",i,j);
                        }

                   }
                   else if(((i-HalfFish)*(HalfFood/HalfFish)+(j-HalfFood))>=0.0)
                    {
                         if(((i-ZhaoFullFish/2.0>=0.0)||(j-ZhaoFullFood/2.0>=0.0))&&
                        (((SumFish-i)-LiFullFish/2.0>=0.0)||((SumFood-j)-LiFullFood/2.0>=0.0))){
                            cnt++;
                        printf("����%-3d:",cnt);
                        printf("�Լһ����%.1f��,�����ʳ%.1f�ӯ��%.1f����ʳ����һ����%.1f��,�����ʳ%.1f�����%.1f����ʳ��\n",i,j,
                               (i-HalfFish)*(HalfFood/HalfFish)+(j-HalfFood),SumFish-i,SumFood-j,
                               -(((SumFish-i)-HalfFish)*(HalfFood/HalfFish)+((SumFood-j)-HalfFood)));
                        }

                    }
                    else
                    {
                         if(((i-ZhaoFullFish/2.0>=0.0)||(j-ZhaoFullFood/2.0>=0.0))&&
                        (((SumFish-i)-LiFullFish/2.0>=0.0)||((SumFood-j)-LiFullFood/2.0>=0.0))){
                            cnt++;
                        printf("����%-3d:",cnt);
                        printf("�Լһ����%.1f��,�����ʳ%.1f��,����%.1f����ʳ����һ����%.1f��,�����ʳ%.1f�ӯ��%.1f����ʳ��\n",i,j,
                               -((i-HalfFish)*(HalfFood/HalfFish)+(j-HalfFood)),SumFish-i,SumFood-j,
                               ((SumFish-i)-HalfFish)*(HalfFood/HalfFish)+((SumFood-j)-HalfFood));
                        }

                    }
               }

        }
    }

}


int main()
{
    freopen("ans.txt","w",stdout);
    cout<<"++++***********************************++++\n";
    cout<<"\t�Լ������"<<endl;
    cout<<"***********************************\n";
    cout<<"��������1���Լ�ȫ�������㣬���ȫ��������ʳ,������̸�н������֮ǰ������������µķ�����"<<endl;
    solve1(ZhaoFullFish*1.0,LiFullFood*1.0);
    cout<<"***********************************\n";
    cout<<"\n��������2���Լ�ȫ�������㣬���ƽ������,������̸�н������֮ǰ������������µķ�����"<<endl;
    cout<<"***********************************\n";
    solve1(ZhaoFullFish*1.0+LiFullFish/2.0,SumFood=LiFullFood/2.0);
    cout<<"***********************************\n";
    cout<<"\n��������3���Լ�ȫ��������ʳ�����ƽ������,������̸�н������֮ǰ������������µķ�����"<<endl;
    cout<<"***********************************\n";
    solve1(LiFullFish/2.0,LiFullFood/2.0+ZhaoFullFood*1.0);
    cout<<"***********************************\n";
    cout<<"\n��������4���Լ�ȫ��������ʳ�����ȫ��������,������̸�н������֮ǰ������������µķ�����"<<endl;
    cout<<"***********************************\n";
    solve1(LiFullFish*1.0,ZhaoFullFood*1.0);
    cout<<"++++***********************************++++\n";
    cout<<"\n\t��������"<<endl;
    cout<<"***********************************\n";
    cout<<"��������1�����ȫ�������㣬���ȫ��������ʳ,�ڲ�������̸�н������֮ǰ������������µķ�����"<<endl;
    solve2(SunFullFish*1.0,LiFullFood*1.0);
    cout<<"***********************************\n";
    cout<<"��������2�����ȫ�������㣬���ƽ������,�ڲ�������̸�н������֮ǰ������������µķ�����"<<endl;
    cout<<"***********************************\n";
    solve2(SunFullFish*1.0+LiFullFish/2.0,LiFullFood/2.0);
    cout<<"***********************************\n";
    cout<<"��������3�����ȫ��������ʳ�����ƽ������,�ڲ�������̸�н������֮ǰ������������µķ�����"<<endl;
    cout<<"***********************************\n";
     solve2(LiFullFish/2.0,LiFullFood/2.0+SunFullFood*1.0);
     cout<<"***********************************\n";
     cout<<"��������4�����ȫ��������ʳ�����ȫ��������,�ڲ�������̸�н������֮ǰ������������µķ�����"<<endl;
     cout<<"***********************************\n";
     solve2(LiFullFish*1.0,SunFullFood*1.0);
    return 0;
}
