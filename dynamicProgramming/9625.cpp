#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){

//a[k+1] = b[k]
//a[k] = b[k-1]
//b[k+1] = a[k] + b[k]

//b[k+1] = b[k-1] + b[k]
//this is fibonacci.

    int K;
    cin>>K;

    vector<int> fib(K+1,0);

    fib[0] = 0;
    fib[1] = 1;

    for(int i=2;i<=K;i++){
        fib[i] = fib[i-1] + fib[i-2];
    }

    cout<<fib[K-1]<<" "<<fib[K]<<endl;
    
}