/**
 * c(i번째 집까지 칠한다, i번째 집의 색깔) ---> i번째 집까지 칠하고, 마지막 집을 x 색깔로 칠했을 때의 최소값 
 * 
 * 26  
 * 40  --> 26 + 60 vs 40 + 49 vs ... --> 
 * 83
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    //집 = N개
    int N;
    cin>>N;

    vector<vector<int>> price (N,vector<int> (3,0));
    vector<vector<int>> lowestPrice (N,vector<int> (3,0));

    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            cin>>price[i][j];
        }
    }

    for(int i=0;i<3;i++){
        lowestPrice[0][i] = price[0][i];
    }

    

    for(int i=1;i<N;i++){
        for(int j=0;j<3;j++){
            //이전 색깔 = 0 = r, 1 = g, 2 = b
            //만약 이전 집을 r 로 칠했다면 다음 집은 r로 칠할 수 없다.
            lowestPrice[i][j] = price[i][j] + min(lowestPrice[i-1][(j+1)%3], lowestPrice[i-1][(j+2)%3]);
        }
    }
    

    vector<int> compare;
    for(int i=0;i<3;i++){
        compare.push_back(lowestPrice[N-1][i]);
    }
    sort(compare.begin(), compare.end());




    cout<<compare[0];
    
}

void logValues(vector<vector<int>> price, vector<vector<int>> lowestPrice, int N){
        cout<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<N;j++){
            cout<<price[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<N;j++){
            cout<<lowestPrice[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}