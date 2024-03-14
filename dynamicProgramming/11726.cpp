#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

/**
 * c[n] = c[n-1] + c[n-2]
 * 세워진 타일 하나 더 붙이면 길이 1이 늘어나고,누운 타일 두  개 붙이면 길이 2가 더 늘어나기 때문ㄴ
 * 
 * 피보나치의 시간복잡도는 2^n 승이다.
*/

int main(){

    int n;
    cin>>n;

    vector<long> c(n,0);

    if(n==1){
        cout<<1;
    }else if (n==2){
        cout<<2;
    }else{
        c[0] = 1;
        c[1] = 2;

        for(int i=2;i<n;i++){
            c[i] = (c[i-2] + c[i-1])%10007;
        }
        cout<<c[n-1]<<endl;
    }


    
}