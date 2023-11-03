#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

//====SÀNG SỐ NGUYÊN TỐ ERATOSTHENES====
bool prime[1000001]; // sử dụng mảng bool vì đỡ tốn bộ nhớ hơn int
// xây dựng mảng prime sao cho prime[i] = 1 thì i là SNT, còn bằng 0 thì i kp SNT
// thông thường chỉ sàng đến 10 triệu, lớn hơn dễ bị tràn bộ nhớ
//Dựa trên cơ chế : Bội số của 1 SNT khác nó thì không thể là SNT
//sử dụng cho việc kiểm tra nhiều số nguyên tố
int maxn = 1e6;
void sang(){
    //Bước 1 : Khởi tạo 
    for(int i = 0; i <= maxn; ++i) prime[i] = true; // chú ý phải <= vì mình đang xét cả số maxn có phải số nguyên tố không
    //Bước 2 : loại bội
    prime[0] = false; prime[1] = false;
    for(int i = 2; i <= sqrt(maxn); ++i){ // tìm tất cả các số nguyên tố trong n
        if(prime[i]){
            //loại bội của i <= maxn
            //do kể từ i đến i*i đã bị loại hết bởi các số trước nên chỉ xét từ i*i
            for(int j = i * i; j <= maxn; j += i){
                prime[j] = false;
            }
        }
    }
    //Cuối hàm ta sẽ có mảng prime với các số nguyên tố i thỏa mãn prime[i] = true
}


// ==== LŨY THỪA NHỊ PHÂN ========
// tính lũy thừa
// Cơ sở lí thuyết : a^b = a^(b/2) * a^(b/2)  <b chẵn>
//                         a^(b/2) * a^(b/2)  <b lẻ>


ll LuyThuaBinary(ll a, ll b){
    if(b == 0) return 1;

    //Đi tìm a^(b/2)
    ll x = LuyThuaBinary(a, b/2);

    if(b % 2 == 0) return x*x;
    else return x*x*a;   
}


int main(){
    
    return 0;
}