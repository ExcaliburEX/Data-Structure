#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct stu
{
    int id;
    int s[5];
    int score;
    int pass;
    int flag;
    stu()
    {
        id=0;
        score=0;
        pass=0;
        flag=0;
        for(int i=0;i<5;i++)
            s[i]=-2;
    }
};

bool cm(const stu &s1,const stu &s2)
{
    if(s1.score>s2.score)
        return true;
    else if(s1.score==s2.score)
        return s1.pass>s2.pass;
    else return false;
}

int main()
{
    int n,k,m;
    cin>>n>>k>>m;
    stu *student=new stu[n];
    int i,j,p[5];
    for(i=0;i<k;i++)
    {
        cin>>p[i];
    }
    int id,p_id,ps;
    for(i=0;i<m;i++)
    {
        cin>>id>>p_id>>ps;
        if(ps>student[id-1].s[p_id-1])
            student[id-1].s[p_id-1]=ps;
    }

    for(i=0;i<n;i++)
    {
        student[i].id=i+1;
        for(j=0;j<k;j++)
        {
            if(student[i].s[j]>=0)
            {
                student[i].score+=student[i].s[j];
                student[i].flag=1;
            }
            if(student[i].s[j]==p[j])
                student[i].pass++;
        }
    }
    stable_sort(student,student+n,cm);
    int rank=1;
    int score=student[0].score;
    for(i=0;i<n;i++)
    {
        if(student[i].flag==0)
            break;
        if(student[i].score!=score)
        {
            rank=i+1;
            score=student[i].score;
        }
        printf("%d %05d %d",rank,student[i].id,student[i].score);
        for(j=0;j<k;j++)
        {
            if(student[i].s[j]>=0)
                printf(" %d",student[i].s[j]);
            else if(student[i].s[j]==-1)
                printf(" 0");
            else
                printf(" -");
        }
        cout<<endl;
    }
    delete [] student;
    return 0;
}
