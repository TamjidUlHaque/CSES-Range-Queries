#include <bits/stdc++.h>
using namespace std ;

using ll = long long ;
#define sesh '\n'
#define gap ' '

const int limit = 1e6+33 ;
int aray[limit] ;
int seg_tree[limit] ;

void build( int node , int st , int e ){
    if(st==e){
        seg_tree[node] = 1 ;
        return ;
    }
    int mid = (st+e)/2 ;
    int l = 2*node ; int r = 2*node + 1 ;
    build( l , st , mid ) ;
    build( r , mid+1 , e ) ;
    seg_tree[node] = seg_tree[l] + seg_tree[r] ;
}

int query( int node , int st , int e , int posn ){
    if(st==e){
        seg_tree[node] = 0 ;
        return aray[st] ;
    }
    int mid = (st+e)/2 ; int ans = 0 ;
    if(posn<=seg_tree[node*2])
        ans = query( node*2 , st , mid , posn) ;
    else{
        posn -= seg_tree[node*2] ;
        ans = query( node*2+1 , mid+1 , e , posn) ;
    }

    seg_tree[node] = seg_tree[2*node] + seg_tree[2*node+1] ;

    return ans ;
}


int main(){
    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    int n ; cin >> n ;
    for(int i = 1 ; i <= n ; i++) cin >> aray[i] ;
    build(1 , 1 , n) ;

    for(int q = 1 ; q <= n ; q++){
        int posn ; cin >> posn ;
        int val_at_posn = query( 1 , 1 , n , posn ) ;
        cout << val_at_posn << gap ;
    }

    cout << endl ;

    return 0 ;
}
