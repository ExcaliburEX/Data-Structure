#include <iostream>
#define INF 1 << 30
using namespace std;

int main()
{   //39��101��25��63 -1
    int in,mid,Min = -INF,Max = INF;
    bool flag = true;
    cin >> mid;
    while(cin >> in)
    {
        if(in <= Min || in >= Max)
        {
            flag = false;
            break;
        }
        if(in < mid)//����������ֵ
            Max = mid;
        else//���Ҹ�����Сֵ
            Min = mid;
        mid = in;
    }
    if(flag == true)
        cout << "����" << endl;
    else
        cout << "������" << endl;
}
