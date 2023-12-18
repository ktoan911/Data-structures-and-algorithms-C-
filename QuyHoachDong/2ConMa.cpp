#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

// Đếm số cách đặt 2 con mã trên bàn cờ vua cỡ k × k với k = 1, 2, 3, .. n sao cho chúng 
// không ăn nhau, 2 con mã này được coi là giống nhau.

#define arr 300

int f[arr][arr];
bool prime[10000001];
int maxn = 1e7;

long long gt(int n) {
    if(n == 1) return 1;
	long long s = 1;
	for (int i = 2; i <= n; i++)
		s *= i;
	return s;
}

ll tich(int n, int k){
    ll s = 1;
    for(int i = k + 1; i <= n; i++){
        s *= i;
    }

    return s;
}
long long C(int k, ll m) {
	return  m * ( m - 1) / 2;
}



int main(){

    int m; cin >> m;
    cout << 0 << endl;

    vector<pair<int,int>> vt = {{ -2, -1}, { -2, 1}, { -1, -2}, { -1, 2}, { 1, -2}, { 1, 2}, { 2, -1}, { 2, 1}};

    ll temp = 0;

    for(int n = 2; n <= m; n++){
        ll ans = C(2, 1LL * n * n);
        if(n <= 4){
            temp = 0;
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    for(int a = 0; a < vt.size(); a++){
                        int b = i + vt[a].first;
                        int c = j + vt[a].second;
                        if(b >= 1 && c >= 1 && b <= n && c <= n){
                            temp++;
                        }
                    }
                }
            }
            temp/= 2;
        }
        else{
            temp += 2 * (2 + 3) + (n - 4) * 4 + 2 + 3 + 2 + 3 + (n - 2 - 3) * 4;     
            //cout <<n << " " <<  ans << " " << temp << endl;
        } 
            cout << ans - temp << endl;
    }
    

    return 0;
}