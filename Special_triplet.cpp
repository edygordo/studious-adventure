#include<iostream>
using namespace std;

int main(){
    int t; cin>>t;
    while (t--)
    {
        int N; cin>>N;
        int sum = 0;
        for(int c=1;c<=N;c++){
            int terms = (N/c)-1;
            if(terms > 0){
                int k = N-c;
                int series_sum = 0;
                int t = 2;
                while(k/(t*c)){
                    series_sum += k/(t*c);
                    t++;
                }
                sum += terms + series_sum;
            }else{
                break;
            }
        }
        cout<<sum<<endl;
    }
    
}