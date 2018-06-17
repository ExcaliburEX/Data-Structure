#include <iostream>
#define INF 1 << 30
using namespace std;

int main()
{   //39，101，25，63 -1
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
        if(in < mid)//向左更新最大值
            Max = mid;
        else//向右更新最小值
            Min = mid;
        mid = in;
    }
    if(flag == true)
        cout << "合理" << endl;
    else
        cout << "不合理" << endl;
}
