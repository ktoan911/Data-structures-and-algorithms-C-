#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

#define arr (int)1e6

//Cho một mảng gồm n số nguyên dương, nhiệm vụ của bạn là đếm số mảng con (dãy con các phần tử liên tiếp) có tổng bằng x.
//ĐK: Cả số âm

int main(){

    int n, x; cin >> n >> x;
    int a[arr]; 
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    map<ll, int> mp;
    ll sum = 0;
    ll count = 0;

    for(int i = 1; i <= n; i++){
        sum += a[i];
        mp[sum]++;
        if(sum == x) count++; // TH đặc biệt
        if(mp.count(sum - x)) count += mp[sum - x]; // xét từ vị trí đầu đến vị trí i xem có tổng dãy nào từ 0 đến i bằng sum - x không sẽ suy ra đươc tiếp nối dãy đó đến y có tổng bằng x
    }

    cout << count;
    






    return 0;
}