#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

//1: 08 : 00

using namespace std;
int NhapSo() {
    int a;
    cin >> a;
    return a;
}

//a và b là các cặp phần tử trong mảng, a đứng trước b đứng sau
//true khi a và b đã đúng thứ tự cần sắp xếp
//false a và b đang sai thứ tự cần sắp xếp
bool cmpTest_1(int a, int b){
    if(a < b) return true; // thứ tự từ bé đến lớn
    else return false;
}

//sắp xếp các phần tử theo thứ tự tổng chữ số tăng dần
//nếu 2 số có cùng tổng chữ số thì số nào lớn hơn đứng trước
int TongChuSo(int n){
    int sum = 0;
    while (n) {
        sum += n % 10;
        n/= 10;
    }
    return sum;
}
bool cmpTest_2(int a, int b){
    if(TongChuSo(a) != TongChuSo(b)) return TongChuSo(a) < TongChuSo(b);
    else return a < b;
}


int main() {

    int n; cin >>  n;
    int  a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    //theo mảng

    //sắp xếp theo tăng dần từ phần tử 0 đến n-1
    sort (a, a + n); // hàm sử dụng intro sort : kết hợp bởi quick sort và heap sort

    //sắp xếp giảm dần từ 0 đến n - 1
    sort (a, a + n, greater<int>()); 

    for(int x : a) cout << x << " ";

    //với vector tương tự mảng nhung thay vì truyền con trỏ có thể truyền iterator

    vector<int> vt;
    int n; cin >> n;
    for(int i = 0; i < n; i ++){
        vt.push_back(NhapSo());
    }

    sort(vt.begin(), vt.end(), greater<int>()); // xếp ngược 
    sort(vt.begin(), vt.end()); // xếp thuận


    //với vector<pair> so sánh theo pair.first

    //có thể sort string theo câu để xếp lại theo chữ cái đầu

    // tham số thứ 3 comparison function (QUAN TRỌNG)

    sort (a, a + n, cmpTest_1); // xếp theo comparitor cmp là tăng dần
    for(int x : a) cout << x << " ";

    sort (a, a + n, cmpTest_2); // xếp theo comparitor cmp2
    for(int x : a) cout << x << " ";

    stable_sort(vt.begin(), vt.end(), cmpTest_2); // giữ được sự ổn định trong lúc sort là phần tử nào xuất hiện trước sẽ xếp trc




    return 0;
}
