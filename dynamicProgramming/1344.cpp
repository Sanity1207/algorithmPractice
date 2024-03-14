/**
 * 90분 = 인터벌 18개 
 * 0개부터 18 개 
 * 0개부터 18 개
 * 0 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 
 * A 팀이 n개의 골을 넣을 확률
 * A(n) =   
 * 두 팀의 골이 합쳐서 N이 될 확률
 * C(N) = C(N-1)*A가 하나 더 넣는다 + C(N-1)*B가 하나 더 넣는다.
 * 
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
bool atLeastOnePrime(int i, int j);
int main(){
    double aProb;
    double bProb;
    cout.precision(16);
    cin>>aProb>>bProb;

    aProb /= 100.0;
    bProb /= 100.0;
    int rows = 18; //이닝 수
    int columns = 19; //가능한 골의 경우의 수
    
    vector<vector<double>> a(rows,vector<double>(columns));
    vector<vector<double>> b(rows,vector<double>(columns));

    a[0][0] = 1-aProb;
    a[0][1] = aProb;

    b[0][0] = 1-bProb;
    b[0][1] = bProb;

    for(int i=1;i<rows;i++){ //이닝 
        for(int j=0;j<=i+1;j++){ //J = 골의 개수
            a[i][j] = a[i-1][j-1]*aProb + a[i-1][j]*(1-aProb);
            b[i][j] = b[i-1][j-1]*bProb + b[i-1][j]*(1-bProb);
        }
    }

    // for(int i=0;i<19;i++){
    //     cout<<i<<"골을 넣을 수 있는 경우: "<<a[17][i]<<endl;
    // }
    double finalProb = 0.0;

    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            if(atLeastOnePrime(i,j)){
                finalProb+=  a[17][i]*b[17][j];
            }
        }
    }
    cout<<finalProb<<endl;
}

bool atLeastOnePrime(int i, int j){
    vector<int> primes = {2,3,5,7,11,13,17};
    for(auto a : primes){
        if(i==a || j==a){
            return true;
        }
    }
    return false;
}