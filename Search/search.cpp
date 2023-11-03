#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

using namespace std;

int NhapSo() {
    int a;
    cin >> a;
    return a;
}



int main() {

    int n; cin >>  n;
    int  a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n); // cần thiết cho binary search
    
    int GiaTriCanTim = NhapSo();

    //binary search => kiểu boolean
    if(binary_search(a, a + n, GiaTriCanTim)) cout << "FOUND";

    // trả về thứ tự phần tử
    auto it = lower_bound(a, a + n, GiaTriCanTim);  // trả về phần tử đầu tiên trong mảng gần với Giatricantim nhat, neu không có thì trả về giá trị nhỏ hơn hoặc bằng gàn nhát 
    //nếu a là mảng -> trả về it là 1 con trỏ
    //nếu là vector -> trả về iterator 
    //muốn biết thứ tự phần tử in ra :
    cout << (it - a); 
    // do sẽ trả về con trỏ trỏ đến phần tử k -> giả trị con trỏ là a + k
    //nếu là vector -> trả về iterator -> trả về a - a.begin()

    // trong trường hợp k thấy -> trả về a + n -> giá trị rác
    

     auto it = lower_bound(a, a + n, GiaTriCanTim); // như lowerbound nhưng là lớn hơn hẳn

    return 0;
}