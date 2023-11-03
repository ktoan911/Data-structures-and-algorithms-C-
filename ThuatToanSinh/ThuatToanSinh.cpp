#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

// Thuật toán sinh -> vét cạn -> độ phức tạp lớn
// thường dùng cho liệt kê hoặc đếm câu hình, thỏa các yêu cầu liệt kê và đếm cấu hình

int n; 
int a[10000];

void Print(){
    for(int i = 1; i <= n; i++){
        cout << a[i];
    }
    cout << endl;
}

void Init(){
    for(int i = 1; i <= n; i++){
        a[i] == 0;
    }
}

bool final = false;

void Sinh(){
    int i = n;
    while(i > 0 && a[i] == 1){
        a[i] = 0;
        i--;
        if(i == 0) final = true;        
    }
    a[i] = 1;
}

int main(){

    cin >> n;

    while(!final){
        Print();
        Sinh();
    }

    return 0;
}