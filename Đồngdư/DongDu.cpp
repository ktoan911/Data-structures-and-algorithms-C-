#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;


//Lí thuyết đồng dư
int a, b, c;

   // (a + b) % c = (a%c + b%c) % c
   // (a*b) % c = (a%c * b%c) % c
   // (a - b) % c = (a%c - b%c + c) % c 
   // (a / b) % c = ((a % c) * (b^-1 % c)) % c // => cần áp dụng kiến thức nghịch đảo modul

   //chú ý với những tập số có 3 số trở lên 
    int d;
   // (a + b + c) % d = ( (a&d + b&d) %d ) + c%d ) %d
   // -> cần nhóm theo từng cặp 2 


int main() {

    //Ví dụ : Cho N số nguyên, bạn hãy tính tổng các
    // số này và chia dư tổng cho 10^9 + 7 (1000000007)

    int n; cin >> n;
    ll bichia = 1e9 + 7;
    ll du = 0;
    while(n--){
        ll temp; cin >> temp;
       
        temp %= bichia;
       
        du += temp;
        du %= bichia; //tránh tràn số khi cộng vào cho du tiếp theo
        //kể cả :
        du %= bichia;
        du %= bichia;
        du %= bichia;
        du %= bichia;
        // nó vẫn đúng
    }
    cout << du % bichia << endl;



   
    
    
    return 0;
}