#include<iostream>
#include<cstdio>
using namespace std;
#define N 100
#define INFINITY 65535
int G[N][N];
int n, m;
int D[N][N];
int FindMaxDist(int i);
void Folyd(){
    int i, j, k;
    for (i = 0; i < n;i++){
        for (j = 0; j < n;j++){
            D[i][j] = G[i][j];
        }
    }

    for (k = 0; k < n;k++)
        for (i = 0; i < n;i++)
            for (j = 0; j < n;j++)
                if(D[i][k]+D[k][j]<D[i][j])
                    D[i][j] = D[i][k] + D[k][j];
}

void FindAnimal()
{
    Folyd();
    int Animal, MaxDist, MinDist = INFINITY;
    for (int i = 0; i < n;i++){
        MaxDist = FindMaxDist(i);
        if(MaxDist==INFINITY){
            printf("0\n");
            return;
        }
        if(MinDist>MaxDist){
            MinDist = MaxDist;
            Animal = i + 1;
        }

    }
    printf("%d %d\n", Animal, MinDist);
}


int FindMaxDist(int i){
    int MaxDist=0;
    for (int j = 0; j < n;j++)
        if(D[i][j]>MaxDist)
            MaxDist = D[i][j];
    return MaxDist;
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n;i++)
        for (int j = 0;j<n;j++){
            if(i==j)
                G[i][j] = 0;
            else
                G[i][j] = INFINITY;
        }
            for (int i = 0; i < m; i++)
            {
                int v1, v2, w;
                cin >> v1 >> v2 >> w;
                v1--, v2--;
                G[v1][v2] = w;
                G[v2][v1] = w;
            }
            FindAnimal();
            return 0;
}
