#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int testCaseNo = 0;
    int N=0,M=0;
    long long result = 1;

    cin>>testCaseNo;

    for(int i=0;i<testCaseNo;i++){
        result = 1;

        //need M Combination N;
        cin>>N>>M;
        
        N = min(N, M-N);

        //크기 줄여주기
        if(N>M/2){
            N = M-N;
        }

        for(int i=0;i<N;i++){ // 분자 만들기
            result *= (M-i);
            result /= (i+1);
        }
        

        cout<<result<<"\n";
    }
}