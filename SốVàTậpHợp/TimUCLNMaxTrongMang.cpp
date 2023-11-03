#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = unsigned long long;

//Bạn được cung cấp một mảng gồm n số nguyên dương. Nhiệm vụ của bạn là tìm hai số nguyên
// sao cho ước số chung lớn nhất của chúng càng lớn càng tốt

// -> ý tưởng: liệt kê ra bội số từ to đến nhỏ


#define arr 300

const int du = 1e9 + 7;

int d[1000001] = {0};

int SangUCLN(){
    for(int i = 1e6; i >= 2; i--){
        int cnt = 0;
        for(int j = i; j <= 1e6; j+=i){
            cnt += d[j];
            if(cnt >= 2) return i;
        }
    }
    return -1;
}


int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        d[a[i]]++;
    }

    cout << SangUCLN();

    
    return 0;
}