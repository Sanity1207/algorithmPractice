#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){


    int n=0;
    cin>>n;

    vector<long long> fibArr(n+1,0);

    // cout<<fibArr.size();

    fibArr[0] = 0;
    fibArr[1] = 1;

    for(int i=2;i<=n;i++){ //for n variables
        fibArr[i] = fibArr[i-1] + fibArr[i-2];
    }

    cout<<fibArr[n];

    return 0;
}