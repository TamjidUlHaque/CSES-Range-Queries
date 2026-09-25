#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){

    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int n , query ; cin >> n >> query ;
    ordered_set<pair<int,int>> osat ; map<int,int> mp ;

    for(int i = 1 ; i <= n ; i++){
        int x ; cin >> x ; osat.insert({x,i}) ;
        mp[i] = x ;
    }

    while(query-->0){
        char type ; cin >> type ;
        if(type == '?'){
            int left , right ; cin >> left >> right ;
            int x = osat.order_of_key({left,-1}) ;
            int y = osat.order_of_key({right+1,-1}) ;
            cout << y-x << '\n' ;
        }else{
            int person , salary ; cin >> person >> salary ;
            int current = mp[person] ;
            osat.erase(osat.find({current,person})) ;
            osat.insert({salary,person}) ;
            mp[person] = salary ;
        }
    }

    return 0 ;
}
