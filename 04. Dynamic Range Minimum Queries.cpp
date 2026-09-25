#include<bits/stdc++.h>
using namespace std ;
using ll = long long ;

const int limit = 2e5+33 ;

ll seg_tree[4*limit] ;
ll aray[limit] ;

void build(int curNode , int start , int end){

    if(start==end){
        seg_tree[curNode] = aray[start] ;
        return ;
    }

    int mid = (start+end)/2 ;

    int leftnode = 2*curNode ; int rightnode = leftnode+1 ;

    build(leftnode , start , mid) ;
    build(rightnode , mid+1 , end) ;

    seg_tree[curNode] = min(seg_tree[leftnode] , seg_tree[rightnode]) ;

}

ll query(int curNode , int start , int end , int left , int right){

    if( left > end or right < start ) return LLONG_MAX ;
    if( left <= start and end <= right ) return seg_tree[curNode] ;

    int mid = (start+end)/2 ;

    int leftnode = 2*curNode ; int rightnode = leftnode+1 ;

    ll left_min  = query(leftnode , start , mid , left , right) ;
    ll right_min = query(rightnode , mid+1 , end , left , right) ;

    return min(left_min , right_min) ;

}

void update(int curNode , int start , int end , int idx , ll value){

    if( start == end and start == idx ){
        seg_tree[curNode] = value ;
        aray[idx] = value ;
        return ;
    }

    int mid = (start+end)/2 ;

    int leftnode = 2*curNode ; int rightnode = leftnode+1 ;

    if(idx <= mid)
        update(leftnode , start , mid , idx , value) ;
    else
        update(rightnode , mid+1 , end , idx , value) ;

    seg_tree[curNode] = min(seg_tree[leftnode],seg_tree[rightnode]) ;

}

int main(){
    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int n , q ; cin >> n >> q ;
    for(int i = 1 ; i <= n ; i++) cin >> aray[i] ;

    build( 1 , 1 , n ) ;

    while(q--){

        int type ; cin >> type ;

        if(type == 1){

            int idx ; ll value ; cin >> idx >> value ;

            update(1 , 1 , n , idx , value) ;

        }else{

            int left , right ; cin >> left >> right ;

            ll range_sum = query( 1 , 1 , n , left , right) ;

            cout << range_sum << endl ;

        }

    }
}
