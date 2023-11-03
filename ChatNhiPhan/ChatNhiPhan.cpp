#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = unsigned long long;

#define arr (int)(2 * 1e5 + 1)

// Một nhà máy có n máy có thể được sử dụng để tạo ra sản phẩm. 
//Mục tiêu của bạn là tạo ra tổng số sản phẩm. Đối với mỗi máy, 
//bạn biết số giây nó cần để tạo ra một sản phẩm. Các máy có thể hoạt 
//động đồng thời và bạn có thể tự do quyết định lịch trình của chúng. 
//Thời gian ngắn nhất cần thiết để làm ra t sản phẩm là bao nhiêu? (Gợi ý : Binary search on answer)

//Input Format
// Dòng nhập đầu tiên có hai số nguyên n và t: số lượng máy móc
//  và sản phẩm. Dòng tiếp theo ghi n số nguyên k1, k2,…, kn: 
// thời gian cần thiết để tạo ra một sản phẩm sử dụng mỗi máy.

/*
 Ý tưởng :chặt nhị phân, thường được sử dụng trong các bài toán min max
      Giả sử xác định được thời gian min và max để tạo ra sản phẩm , đề bài yêu cầu 
      tối thiểu t sản phẩm có nghĩa là quá t sản phẩm cũng không sao, ta sẽ tìm đoạn nằm giữa min và max bằng
      cách chia đôi khoảng min max và tính số sản phẩm ở đoạn mid, nếu nhỏ hơn thì ta lại
      xét bên max , ngược lại thì bên min ( ý tưởng khá giống ninary search)
      -> công việc trở thành tìm hàm f(m) với m là thời gian, f(m) là số sản phẩm làm đc

*/
const int du = 1e9 + 7;
int n;
int a[arr];

ll f(ll x){
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        sum += 1LL * (x / a[i]);
    }

    return sum;
}

int main(){
    int t;
    cin >> n >> t;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    ll l = 1, r = 1LL * t * (*max_element(a + 1, a + n + 1)); // cần tinh ý khi chọn l và r tùy bài toán
    ll ans = -1;
    while(l <= r){
        ll mid = (r + l) / 2;
        ll temp = f(mid);
        //cout << mid << " " <<  temp << endl;
        if(temp >= t){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << ans;

    return 0;
}