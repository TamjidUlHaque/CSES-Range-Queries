#include <bits/stdc++.h>
using namespace std ;

int main(){

    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int n , query ; cin >> n >> query ;
    vector<vector<int>> forest(n+1,vector<int> (n+1,0)) ;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            char ch ; cin >> ch ;
            forest[i][j] = (ch == '*') ;
            forest[i][j] = forest[i][j] + forest[i-1][j] + forest[i][j-1] - forest[i-1][j-1] ;
        }
    }

    while(query-->0){
        int x1,y1,x2,y2 ; cin >> x1 >> y1 >> x2 >> y2 ;
        cout << forest[x2][y2] - forest[x1-1][y2] - forest[x2][y1-1] + forest[x1-1][y1-1] << '\n' ;
    }

    return 0 ;
}
