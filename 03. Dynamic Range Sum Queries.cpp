#include<bits/stdc++.h>
using namespace std ;
using ll = long long ;
#define len(x) (int(x.size()))

/*
_______________Binary Indexed Tree / Fenwick Tree___________________

    Ei topic er shobcheye basic jei problem ta solve kora lage ta holo
    amader ke ekta array dewa thake , er upore query kora hoy dui dhoroner.

    Type1-> Kuno ekta index er value update korte bolbe .
    Type2-> Kuno ekta range er summation value jante chaibe .

    Ei topic sikhar jonne amader ke ekta bit related trick sikhte hobe .
    Amader ke jodi ekta number dewa thake tobe O(1) time complexity teh
    amader ke oi element er right most set bit kunta oita bolte hobe + oita
    remove korte hobe . Ekhon dhori amader ke jei shongkha ta dewa ache
    tar structure ta holo

    (a1b) jekhane a er part er bit gula set unset jekuno obosthay thakte
    pare. Erpore rightmost set bit 1 , erpore shobgula bit unset obosthay
    ache . Eita ke jodi amra compliment kori tahole (a1b)' er negative
    number ta pawa jabe . Negative number ta ber korte 2's compliment korte
    hoy .

    Dhori songkha ta (101001000) . Jodi er one's compliment kori tahole
    songkha ta hobe  (010110111) . Tarmane oi songkha tar 2's compliment
    holo (a1b)'+ 1 = (010111000) . Ekhane dekha jacche je compliment number tar
    kebol rightmost set bit baad dile baki shobgula bit hoy mismatch , ar
    jodi mismatch na hoy tahole dui jaygay 0 . Tarmane jodi amra ekhane bitwise
    & operation kori tahole ekmatro common bit hishabe rightmost bit ta peye jabo .

    RightMost Bit = (number & (-number)) ;
    Remove RightMost Bit = number - (number & (-number)) ;

    Mone kori amader ke n size er ekta array dewa ache . Oi size er array er
    jonne amra n size er ekta array toiri korbo jar proti ta element kuno
    ekta partial range er sum store korbe .

    Bit[i] er moddhe store thakbe arr[i-(i&(-i))+1] theke arr[i] er value er sum .
    Tarmane proti ta index er moddhe er last bit remove kore remaining value + 1
    theke current index projonto value store korbe .

    Bit[1] = 1 theke 1 porjonto value er cumulative sum store korbe.
    Bit[2] = 1 theke 2 porjonto value er cumulative sum store korbe.
    Bit[3] = 3 theke 3 porjonto value er cumulative sum store korbe.
    Bit[4] = 1 theke 4 porjonto value er cumulative sum store korbe.
    Bit[5] = 5 theke 5 porjonto value er cumulative sum store korbe.
    Bit[6] = 5 theke 6 porjonto value er cumulative sum store korbe.
    Bit[7] = 7 theke 7 porjonto value er cumulative sum store korbe.
    Bit[8] = 1 theke 8 porjonto value er cumulative sum store korbe.
    Bit[9] = 9 theke 9 porjonto value er cumulative sum store korbe.
    Bit[10] = 9 theke 10 porjonto value er cumulative sum store korbe.
    Bit[11] = 11 theke 11 porjonto value er cumulative sum store korbe.
    Bit[12] = 9 theke 12 porjonto value er cumulative sum store korbe.
    Bit[13] = 13 theke 13 porjonto value er cumulative sum store korbe.
    Bit[14] = 13 theke 14 porjonto value er cumulative sum store korbe.
    Bit[15] = 15 theke 15 porjonto value er cumulative sum store korbe.
    Bit[16] = 1 theke 16 porjonto value er cumulative sum store korbe.

    Ekhon amader ke jodi 1 theke kuno ekta range er summation bolte bole
    tahole amra amader create kora bit array ta use kore sohoje answer bolte
    parbo . Dhori Bit array ta already toiri ache . Tahole amader answer hobe

    ll ans = 0 ; int idx = range ;
    while(idx != 0){ // Time Complexity O(log2(range))
        ans += Bit[idx] ;
        idx -= (idx & (-idx)) ;
    }

    Tarmane Cumulative_Sum[13]  = Bit[13] + Bit[12] + Bit[8]
                                = (13,13) + (9,12) + (1,8)

    Jodi ekhon bole 5 theke 11 index er summation koto tahole amra ekhon log2(range)
    e answer ta bole dite parbo .

    Cumulative_Sum[5,11] == Cumulative_Sum[11] - Cumulative_Sum[4] .

    Ekhon amra answer kivabe calculate korte pari BIT array theke ei
    jinish ta bujhte parsi , Ekhon amader ke BIT array create korte hobe.
    Initially BIT array er shokol index er moddhe 0 value stored obosthay
    thakbe . Ekhon jodi amader ke k-th index er moddhe kuno ekta value p
    add korte hoy tahole jeishokol index er moddhe partial sum hishabe oi
    k-th index er presence ache oi shokol index e amader ke value update
    korte hobe .

    Dhori 13-th index e amader ke notun ekta value add korte hobe . Tahole
    Uporer chart theke amra dekhte parbo je 13-th index er contribution ache
    13 , 14 , 16 , 32 , 64.......... position gula te . Tar mane jei index
    er moddhe value ta add hocche oi index er rightmost bit + oi index kore
    barte thakbe jotokkhon na BIT array er size cross kore jay .


*/

int n , query ;
vector<ll> BinIndTree ;

ll prefix_sum(ll index){
    ll curSum = 0 ;
    while(index>0){
        curSum += BinIndTree[index] ;
        index -= (index & (-index)) ;
    }
    return curSum ;
}

void update(ll index , ll value){
    while(index<=n){
        BinIndTree[index] += value ;
        index += (index&(-index)) ;
    }
}



int main(){
    ios_base::sync_with_stdio(0) ; cin.tie(0) ;

    cin >> n >> query ; BinIndTree.assign(n+1,0) ;

    vector<ll> aray(n+1,0) ;
    for(int i = 1 ; i <= n ; i++) cin >> aray[i] ;

    for(int i = 1 ; i <= n ; i++) update(i,aray[i]) ;

    while(query-->0){
        int type ; cin >> type ;
        if(type==2){
            ll left , right ; cin >> left >> right ;
            cout << prefix_sum(right) - prefix_sum(left-1) << '\n' ;
        }else{
            ll idx , value ; cin >> idx >> value ;
            update(idx,value-aray[idx]) ;
            aray[idx] = value ;
        }
    }

}
