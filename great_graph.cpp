#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n; 
        long long int * dist = new long long int[n];
        for(int i=0;i<n;i++){
            cin>>dist[i];
        }
        sort(dist, dist+n);
        long long int * prefix_sum = new long long int[n]; prefix_sum[0] = 0;
        for(int i=1;i<n;i++){
            prefix_sum[i] = prefix_sum[i-1] + dist[i];
        }
        long long int cost = 0;
        for(long long int i=1;i<n;i++){
            cost += (prefix_sum[i-1] - (i*dist[i]));
        }
        cost +=dist[n-1];
        cout<<cost<<endl;
    }
    return 0;
}