#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

#define arr (int)1e6

//Có n sợi dây, bạn cần cắt k đoạn dây có cùng chiều dài từ chúng. 
//Tìm chiều dài tối đa của các mảnh dây bạn có thể nhận được.

int n, k;
double a[arr]; 
ll f(double length){    // sử dụng được vì số mét dây càng tăng thì số độ chia càng giảm -> tuyến tính
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        sum += (ll) (a[i] / length);
    }

    return sum;
}   


int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    double max =  -1;

    double l = 0, r = 1e13;
    double ans = 0;
    while(r - l > 0.0000001){
            double mid = (l + r) / 2.0;
            //cout << l << " " << r << " " << mid << endl;
            if(f(mid) >= k){
                ans = mid;
                l = mid;
            } 
            else r = mid;
        }

    std::cout << std::fixed << std::setprecision(6) << ans << std::endl;
    return 0;
}