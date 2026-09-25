#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std ;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key(k) : no. of elements < k
// *find_by_order(i) : value at index i (0-based)

using ll = long long ;
#define sesh '\n'
#define gap ' '

int main(){
    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int n ; cin >> n ; ordered_set<pair<int,int>> osat ;
    for(int i = 1 ; i <= n ; i++){
        int val ; cin >> val ; osat.insert({i,val}) ;
    }

    for(int q = 1 ; q <= n ; q++){
        int posn ; cin >> posn ;
        auto it = osat.find_by_order(posn-1) ;
        cout << it->second << gap ;
        osat.erase(it) ;
    }

    cout << endl ;

    return 0 ;
}
