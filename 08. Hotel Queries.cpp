#include<bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define sesh '\n'
#define gap ' '

const int limit = 1e6+33 ;
vector<int> aray(limit) ;
vector<int> seg_tree(limit) ;

int n , query ;

void build( int node , int st , int e ){
    if(st==e){
        seg_tree[node] = aray[st] ;
        return ;
    }
    int mid = (st+e)/2 ;
    build(node*2,st,mid) ;
    build(node*2+1,mid+1,e) ;
    seg_tree[node] = max(seg_tree[node*2],seg_tree[node*2+1]) ;
}

void update(int node , int st , int e , int idx , int value){

    if(st>idx or e<idx) return ;
    if(st==idx and e==idx){
        aray[st] = seg_tree[node] = value ;
        return ;
    }

    int mid = (st+e)/2 ;

    if(mid>=idx) update(node*2,st,mid,idx,value) ;
    else update(node*2+1,mid+1,e,idx,value) ;

    seg_tree[node] = max(seg_tree[2*node],seg_tree[2*node+1]) ;

}

int ask( int node , int st , int e , int group ){
    if(group > seg_tree[node]) return limit ;
    if(st==e and aray[st] >= group){
        update(1 , 1 , n , st , aray[st] - group ) ;
        return st ;
    }
    int mid = (st+e)/2 ;
    int left = ask(node*2,st,mid,group) ;
    if(left != limit) return left ;
    int right = ask(node*2+1,mid+1,e,group) ;
    return min(left,right) ;
}

int main(){
    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    cin >> n >> query ;
    for(int i = 1 ; i <= n ; i++) cin >> aray[i] ;
    build( 1 , 1 , n ) ;

    while(query-->0){
        int group ; cin >> group ;
        int room_number = ask( 1 , 1 , n , group ) ;
        if(room_number==limit) cout << 0 << ' ' ;
        else cout << room_number << gap ;
    }

    cout << endl ;

    return 0 ;
}
