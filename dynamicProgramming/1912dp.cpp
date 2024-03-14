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
    vector<int> rememberAccumMax(n,0);
    rememberAccumMax[0] = numbers[0];

    for(int i=1;i<n;i++){
        //the maximum sum of the array that ends at i;
        rememberAccumMax[i] = max(rememberAccumMax[i-1] + numbers[i], numbers[i]);
    }

    int maxSum = *max_element(rememberAccumMax.begin(),rememberAccumMax.end());

    cout<<maxSum;
    
}