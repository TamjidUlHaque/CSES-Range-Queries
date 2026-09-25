#include<bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define len(x) (int(x.size()))

const int maxSize = 2e5+33 ;
const int Log = 19 ;
int aray[maxSize] ;
int SparseTable[maxSize][Log] ;

int minimum_value(int left , int right){
    int range = right-left+1 ;
    int exp = 0 ;
    while((1<<(exp+1))<= range) exp++ ;

    return min(SparseTable[left][exp],SparseTable[right-(1<<exp)+1][exp]) ;
}

int main(){
    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int n , query ; cin >> n >> query ;

    for(int i = 0 ; i < maxSize ; i++){
        aray[i] = INT_MAX ; SparseTable[i][0] = aray[i] ;
    }

    for(int i = 1 ; i <= n ; i++){
        cin >> aray[i] ;
        SparseTable[i][0] = aray[i] ;
    }

    for(int exp = 1 ; exp < Log ; exp++){
        for(int i = 1 ; i + (1<<exp)-1 <= n ; i++){
            int minVal = min(SparseTable[i][exp-1],SparseTable[i+(1<<(exp-1))][exp-1]) ;
            SparseTable[i][exp] = minVal ;
        }
    }

    while(query-->0){
        int left , right ; cin >> left >> right ;
        cout << minimum_value(left,right) << '\n' ;
    }

    return 0 ;
}
