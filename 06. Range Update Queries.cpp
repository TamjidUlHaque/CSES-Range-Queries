#include<bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define sesh '\n'
#define gap ' '

const int limit = 1e6 + 33 ;
vector<ll> aray(limit,0) ;
vector<int> visited(limit,0) ;
vector<ll> propagation(limit,0) ;

void build(int node , int st , int e){
    if(st==e){
        propagation[node] = aray[st] ;
        return ;
    }
    int mid = (st+e)/2 ;
    int left_node = 2 * node ; int right_node = 2 * node + 1 ;
    build( left_node , st , mid ) ;
    build( right_node , mid+1 , e ) ;
}

void update(int node , int st , int e , int left , int right , ll value){
    if(left>e or right<st) return ;
    if(left <= st and e <= right){
        propagation[node] += value ;
        visited[node] = 1 ;
        return ;
    }
    int mid = (st+e)/2 ;
    int left_node = 2 * node ; int right_node = 2 * node + 1 ;
    update( left_node , st , mid , left , right , value) ;
    update( right_node , mid+1 , e , left , right , value ) ;
}

void shift_data(int node){
    int left_node = node * 2 ;
    int right_node = node * 2 + 1 ;
    if(left_node>=(int(propagation.size()))) return ;
    propagation[left_node] += propagation[node] ;
    propagation[right_node] += propagation[node] ;
    visited[left_node] = visited[right_node] = 1 ;
    propagation[node] = visited[node] = 0 ;
}

ll query(int node , int st , int e , int index){
    if(st>index or e < index) return 0LL ;
    if(st==e and st==index) return  propagation[node] ;

    if(visited[node]) shift_data(node) ;

    int mid = (st+e)/2 ;
    int left_node = 2 * node ;
    int right_node = 2 * node + 1 ;

    ll answer = 0LL ;

    answer += query( left_node , st , mid , index ) ;
    answer += query( right_node , mid+1 , e , index ) ;

    return answer ;
}

int main(){
    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int n , q ; cin >> n >> q ;
    for(int i = 1 ; i <= n ; i++) cin >> aray[i] ;

    build( 1 , 1 , n ) ;

    while(q-->0){

        int type ; cin >> type ;

        if(type==2){
            int idx ; cin >> idx ;
            ll val_at_idx = query( 1 , 1 , n , idx ) ;
            cout << val_at_idx << sesh ;
        }else{
            int left , right ; ll value ;
            cin >> left >> right >> value ;
            update( 1 , 1 , n , left , right , value ) ;
        }

    }

    return 0 ;

}
