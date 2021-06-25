#include<iostream>
using namespace std;

void DFS(int ** Adjacency_Matrix, int N, bool * visited,int Sv){
    cout<<Sv<<"-";
    visited[Sv] = true;
    for(int i=0;i<N;i++){
        if(visited[i] == false && Adjacency_Matrix[i][Sv]){
            DFS(Adjacency_Matrix, N, visited,i);
        }
    }
    return;
}

int main()
{
    int N; cin>>N;
    int E; cin>>E;
    int ** Adjacency_Matrix = new int * [N];
    for(int i=0;i<N;i++){
        Adjacency_Matrix[i] = new int[N];
        for(int j=0;j<N;j++){
            Adjacency_Matrix[i][j] = 0;
        }
    }
    for(int i=0;i<E;i++){
        int sv,ev; cin>>sv>>ev;
        Adjacency_Matrix[sv][ev] = Adjacency_Matrix[ev][sv] = 1;
    }
    bool * visited = new bool[N];
    for(int i=0;i<N;i++){
        visited[i] = false;
    }
    DFS(Adjacency_Matrix,N,visited,0);
    return 0;
}