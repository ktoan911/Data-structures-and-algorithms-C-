#include <bits/stdc++.h>
#include <cmath>

using namespace std;
using ll = long long;

//Cho mảng A[] gồm N số nguyên và số nguyên S, nhiệm vụ của bạn là đếm xem có bao nhiêu mảng con các phần tử liên tiếp 
//trong mảng mà tổng ít nhất bằng S.

int main(){
    
    int n, s; cin >> n >> s;
    int a[n + 1]; for (int i = 1; i <= n; i++) cin >> a[i];

    ll sum[n];
    sum[0] = 0;
    sum[1] = a[1];
    for(int i = 2; i <= n; i++){
        sum[i] = sum[i - 1] + a[i];
    }

    int l = 1, r = 1;
    ll ans = 0;
    while (l <= n && r <= n){
        ll temp = sum[r] - sum[l - 1];
        if(temp >= s){
            ans = ans + (n - r + 1);
            if(l < r) l++;
            else r++;
        }
        else r++;      
    }

    cout << ans;

    



    return 0;
}