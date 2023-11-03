#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

#define arr (int)1e6

//Cho một mảng gồm n số nguyên dương, nhiệm vụ của bạn là đếm số mảng con (dãy con các phần tử liên tiếp) có tổng bằng x.
//Điều kiện : tất cả số trong mảng đều dương




int main(){

    int n, x; cin >> n >> x;
    int a[arr]; 
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    map<ll, int> mp;
    ll sum = 0;
    int count = 0;

    for(int i = 1; i <= n; i++){
        sum += a[i];
        if(sum == x) count++; // TH đặc biệt
        if(mp.count(sum - x)) count++; // xét từ vị trí đầu đến vị trí i xem có tổng dãy nào từ 0 đến i bằng sum - x không sẽ suy ra đươc tiếp nối dãy đó đến y có tổng bằng x
        mp[sum] = 1;
    }


    cout << count;
    






    return 0;
}