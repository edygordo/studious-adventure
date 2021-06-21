#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int N; cin>>N;
    int * arr = new int[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    
    int x = 0,y=0;
    for(int i=0;i<N;i++){
        if(arr[i] == 5){ x++;}
        if(arr[i] == 1){ y++;}
    }
    int max_digit = 0, x_corr = 0;
    for(int i=0;i<=x;i++){
        int P = (5*i)%9;
        P = -P;
        int Q = P%9;
        int Y = Q + ((y-Q)/9)*9;
        if(i+Y > max_digit && Y >= 0){
            x_corr = i;
            max_digit = i+Y;
        }
    }
    for(int i=0;i<max_digit;i++){
        if(i<x_corr){
            cout<<"5";
        }
        else{
            cout<<"1";
        }
    }
    if(max_digit == 0){
        cout<<"-1";
    }
    delete [] arr;
    return 0;
}