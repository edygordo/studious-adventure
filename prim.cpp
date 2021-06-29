#include<iostream>
#include<limits.h>
using namespace std;

class Edges{
    public:
    int sv,ev,w;
    Edges(){
        sv = ev = w = 0;
    }
    Edges(int a, int b,int c){
        sv = a; ev = b; w = c;
    }
    void print(){
        if(sv<ev){ cout<<this->sv<<" "<<this->ev<<" "<<this->w<<endl; }
        else{cout<<this->ev<<" "<<this->sv<<" "<<this->w<<endl;}
    }
};

bool allvisited(bool * visited,int N){
    for(int i=0;i<N;i++){
        if(visited[i] == false){
            return false;
        }
    }
    return true;
}

void Prim(int ** Adjacency_Matrix,int V){
    int * Parent = new int[V];
    int * vertex = new int[V];
    for(int i=0;i<V;i++){ vertex[i] = i; }
    bool * visited = new bool[V];
    for(int i=0;i<V;i++){ visited[i] = false; }
    int * weight = new int[V]; // from sv to any other vertex
    for(int i=0;i<V;i++){ weight[i] = INT_MAX; }
    int sv = 0; weight[sv] = 0; visited[sv] = true;
    for(int i=0;i<V;i++){ Parent[i] = -1; }

    while(!allvisited(visited,V)){
        for(int i = 0;i<V;i++){
            if(Adjacency_Matrix[sv][i] != 0 && visited[i] == false){
                if(weight[sv] + Adjacency_Matrix[sv][i] < weight[i]){
                    weight[i] = weight[sv] + Adjacency_Matrix[sv][i]; Parent[i] = sv;
                }
            }
        }
        // find greedily minimum weight unvisited vertex to join to this graph
        int min_vertex, min_weight = INT_MAX;
        for(int i=0;i<V;i++){
            if(visited[i] == false && weight[i] < min_weight){
                min_vertex = i; min_weight = weight[i];
            }
        }
        sv = min_vertex; visited[sv] = true;
    }

    for(int i=1;i<V;i++){
        if(i<Parent[i]){ cout<<i<<" "<<Parent[i]<<" "<<Adjacency_Matrix[i][Parent[i]]<<endl; }
        else{ cout<<Parent[i]<<" "<<i<<" "<<Adjacency_Matrix[i][Parent[i]]<<endl; }
    }
}

int main(){
    int V; cin>>V;
    int E; cin>>E;
    int ** Adjaceny_Matrix = new int*[V];
    for(int i=0;i<V;i++){
        Adjaceny_Matrix[i] = new int[V];
        for(int j=0;j<V;j++){
            Adjaceny_Matrix[i][j] = 0;
        }
    }
    while(E--){
        int x,y,w; cin>>x>>y>>w;
        Adjaceny_Matrix[x][y] = w;
        Adjaceny_Matrix[y][x] = w;
    }
    Prim(Adjaceny_Matrix,V);
    return 0;
}