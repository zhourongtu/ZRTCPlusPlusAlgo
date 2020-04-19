#include <iostream>
using namespace std;

/*
全源最短路径算法
*/
const int INF = 0x3FFFFFFF;
const int MAXV = 200;
int N, M;
int dis[MAXV][MAXV];
void Floyd(){
    for(int k=0; k<N; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(dis[i][k] != INF && dis[k][j] != INF && dis[i][k]+dis[k][j] < dis[i][j]){
                    dis[i][j] = dis[i][k]+dis[k][j];
                }
            }
        }
    }
}
int main()
{
    int u, v, w;
    fill(dis[0], dis[0] + MAXV * MAXV, INF);
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; i++){
        scanf("%d%d%d", &u, &v, &w);
        dis[u][v] = w;
    }
    Floyd();

}