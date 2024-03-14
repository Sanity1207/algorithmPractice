#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/**
 * 
 * 
 * wine
 * 
 * 쉼표와 덧셈 기호를 빼먹으면 안된다. 이거는 어떻게 체크할까?
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    

    vector<long> liquidAmount (n,0);
    vector<long> accumMax (n,0);

    for(int i=0;i<n;i++){
        cin>>liquidAmount[i];
    }

    accumMax[0] = liquidAmount[0];
    accumMax[1] = liquidAmount[1] + liquidAmount[0];
    accumMax[2] = max({liquidAmount[0]+liquidAmount[1],liquidAmount[1]+liquidAmount[2],liquidAmount[0]+liquidAmount[2]});

    for(int i=3;i<n;i++){
        accumMax[i] = max({accumMax[i-3] + liquidAmount[i-1] + liquidAmount[i],accumMax[i-2] + liquidAmount[i],accumMax[i-1]});
    }

    cout<<accumMax[n-1]<<endl;

}