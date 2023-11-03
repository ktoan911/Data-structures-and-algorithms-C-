#include <bits/stdc++.h>
#include <cmath>

using namespace std;
using ll = long long;

//Cho mảng A[] gồm N số nguyên và số nguyên S, nhiệm vụ của bạn là đếm xem có bao nhiêu mảng con các phần tử liên tiếp 
//trong mảng mà tổng không vượt quá S.

int main(){
    
    int n, s; cin >> n >> s;
    int a[n + 1]; 
    for(int i = 0; i < n; i++) cin >> a[i];
    a[n] = INT16_MAX;

    ll sum = 0;
    int l = 0;
    int ans = 0;

    for(int i = 0; i <= n; i++){

        sum += a[i];
        while(l <= i && sum > s){
            sum -= a[l++];
        }
        ans += i - l + 1;

    }
    cout << ans ;

    



    return 0;
}