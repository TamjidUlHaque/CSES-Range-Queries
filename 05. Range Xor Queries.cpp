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
    vector<long long> aray(n) , prefix_xor(1,0) ;
    for(int i = 0 ; i < n ; i++){
        cin >> aray[i] ;
        prefix_xor.push_back(prefix_xor.back()^aray[i]) ;
    }

    while(query-->0){
        int left , right ; cin >> left >> right ;
        cout << (prefix_xor[right] ^ prefix_xor[left-1]) << '\n' ;
    }

    return 0 ;
}
