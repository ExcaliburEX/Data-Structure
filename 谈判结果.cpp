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
                       printf("方案%-3d:",cnt);
                       printf("双方平均分配实现共赢，鱼为%.1f斤，粮食为%.1f。\n",i,j);
                        }
                   }
                   else if(((i-HalfFish)*(HalfFood/HalfFish)+(j-HalfFood))>=0.0)
                    {
                        if(((i-ZhaoFullFish/2.0>=0.0)&&(j-ZhaoFullFood/2.0>=0.0))&&
                        (((SumFish-i)-LiFullFish/2.0>=0.0)&&((SumFood-j)-LiFullFood/2.0>=0.0))){
                            cnt++;
                        printf("方案%-3d:",cnt);
                        printf("赵家获得鱼%.1f斤,获得粮食%.1f斤，盈利%.1f斤粮食。李家获得鱼%.1f斤,获得粮食%.1f斤，亏损%.1f斤粮食。\n",i,j,
                               (i-HalfFish)*(HalfFood/HalfFish)+(j-HalfFood),SumFish-i,SumFood-j,
                               -(((SumFish-i)-HalfFish)*(HalfFood/HalfFish)+((SumFood-j)-HalfFood)));
                        }
                    }
                    else
                    {
                     if(((i-ZhaoFullFish/2.0>=0.0)&&(j-ZhaoFullFood/2.0>=0.0))&&
                        (((SumFish-i)-LiFullFish/2.0>=0.0)&&((SumFood-j)-LiFullFood/2.0>=0.0))){
                            cnt++;
                        printf("方案%-3d:",cnt);
                        printf("赵家获得鱼%.1f斤,获得粮食%.1f斤,亏损%.1f斤粮食。李家获得鱼%.1f斤,获得粮食%.1f斤，盈利%.1f斤粮食。\n",i,j,
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
                       printf("方案%-3d:",cnt);
                       printf("双方平均分配实现共赢，鱼为%.1f斤，粮食为%.1f。\n",i,j);
                        }

                   }
                   else if(((i-HalfFish)*(HalfFood/HalfFish)+(j-HalfFood))>=0.0)
                    {
                         if(((i-ZhaoFullFish/2.0>=0.0)||(j-ZhaoFullFood/2.0>=0.0))&&
                        (((SumFish-i)-LiFullFish/2.0>=0.0)||((SumFood-j)-LiFullFood/2.0>=0.0))){
                            cnt++;
                        printf("方案%-3d:",cnt);
                        printf("赵家获得鱼%.1f斤,获得粮食%.1f斤，盈利%.1f斤粮食。李家获得鱼%.1f斤,获得粮食%.1f斤，亏损%.1f斤粮食。\n",i,j,
                               (i-HalfFish)*(HalfFood/HalfFish)+(j-HalfFood),SumFish-i,SumFood-j,
                               -(((SumFish-i)-HalfFish)*(HalfFood/HalfFish)+((SumFood-j)-HalfFood)));
                        }

                    }
                    else
                    {
                         if(((i-ZhaoFullFish/2.0>=0.0)||(j-ZhaoFullFood/2.0>=0.0))&&
                        (((SumFish-i)-LiFullFish/2.0>=0.0)||((SumFood-j)-LiFullFood/2.0>=0.0))){
                            cnt++;
                        printf("方案%-3d:",cnt);
                        printf("赵家获得鱼%.1f斤,获得粮食%.1f斤,亏损%.1f斤粮食。李家获得鱼%.1f斤,获得粮食%.1f斤，盈利%.1f斤粮食。\n",i,j,
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
    cout<<"\t赵家与李家"<<endl;
    cout<<"***********************************\n";
    cout<<"生产策略1：赵家全力生产鱼，李家全力生产粮食,在满足谈判结果优于之前的生产的情况下的方案："<<endl;
    solve1(ZhaoFullFish*1.0,LiFullFood*1.0);
    cout<<"***********************************\n";
    cout<<"\n生产策略2：赵家全力生产鱼，李家平均生产,在满足谈判结果优于之前的生产的情况下的方案："<<endl;
    cout<<"***********************************\n";
    solve1(ZhaoFullFish*1.0+LiFullFish/2.0,SumFood=LiFullFood/2.0);
    cout<<"***********************************\n";
    cout<<"\n生产策略3：赵家全力生产粮食，李家平均生产,在满足谈判结果优于之前的生产的情况下的方案："<<endl;
    cout<<"***********************************\n";
    solve1(LiFullFish/2.0,LiFullFood/2.0+ZhaoFullFood*1.0);
    cout<<"***********************************\n";
    cout<<"\n生产策略4：赵家全力生产粮食，李家全力生产鱼,在满足谈判结果优于之前的生产的情况下的方案："<<endl;
    cout<<"***********************************\n";
    solve1(LiFullFish*1.0,ZhaoFullFood*1.0);
    cout<<"++++***********************************++++\n";
    cout<<"\n\t孙家与李家"<<endl;
    cout<<"***********************************\n";
    cout<<"生产策略1：孙家全力生产鱼，李家全力生产粮食,在部分满足谈判结果优于之前的生产的情况下的方案："<<endl;
    solve2(SunFullFish*1.0,LiFullFood*1.0);
    cout<<"***********************************\n";
    cout<<"生产策略2：孙家全力生产鱼，李家平均生产,在部分满足谈判结果优于之前的生产的情况下的方案："<<endl;
    cout<<"***********************************\n";
    solve2(SunFullFish*1.0+LiFullFish/2.0,LiFullFood/2.0);
    cout<<"***********************************\n";
    cout<<"生产策略3：孙家全力生产粮食，李家平均生产,在部分满足谈判结果优于之前的生产的情况下的方案："<<endl;
    cout<<"***********************************\n";
     solve2(LiFullFish/2.0,LiFullFood/2.0+SunFullFood*1.0);
     cout<<"***********************************\n";
     cout<<"生产策略4：孙家全力生产粮食，李家全力生产鱼,在部分满足谈判结果优于之前的生产的情况下的方案："<<endl;
     cout<<"***********************************\n";
     solve2(LiFullFish*1.0,SunFullFood*1.0);
    return 0;
}
