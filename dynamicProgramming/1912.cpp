#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;


/**
 * [n번째까지의 최대값] = max([n-1번째의 최대값] + i, i); 
*/
int main(){
    int n;
    cin>>n;

    vector<int> numbers (n,0);

    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }

    int maxval = -1001;
    int curval = numbers[0];

    if(curval > maxval){
        maxval = curval;
    }

    
    for(int i=1;i<n;i++){
        if(curval > 0){//이어 간다
            curval = curval + numbers[i];
        }else{//새로 시작한다.
            curval = numbers[i];
        }

        if(maxval < curval){
            maxval = curval;
        }
    }

    cout<<maxval;
    
    



}