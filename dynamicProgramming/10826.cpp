#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



string sum(string x, string y){
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());

    
}

int main(){
    int N;
    cin>>N;
    cout<<"what";
    
    vector<string> fib(N+1);

    fib[0] = "0";
    fib[1] = "1";
    for(int i=2;i<=N;i++){
        fib[i] = sum(fib[i-1],fib[i-2]);
    } 

    cout<<fib[N];
}

