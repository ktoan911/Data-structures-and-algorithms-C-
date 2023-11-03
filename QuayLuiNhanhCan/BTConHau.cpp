#include <bits/stdc++.h>
#include <cmath>

using namespace std;
using ll = long long;

int maxn = 300;
int du = 1e9 + 7;
bool a[200][200] = {false};
int n;

bool check(int k, int m){ //tại sao nếu đểu else if trong hàm for lại sai ??
     if(k == 1) return 1;
    for(int i = 1; i <= n; i++){
        if(a[i][m]) return false;
        if(k + i <= n && m + i <= n) {
            if(a[k + i][m +i]) return false;
        }
        if(k - i >= 1 && m - i >= 1){
            if(a[k - i][m - i]) return false;
        }
        if(k + i <= n && m - i >= 1){
            if(a[k + i][m - i]) return false;
        }
        if(m + i <= n && k - i >= 1){
            if(a[k - i][m + i]) return false;
        }
    }

    return true;
}

ll number = 0;
ll QuayLui(int k){ // n là số cột
    for(int i = 1; i <= n; i++){
        if(check(k, i)){
            // cout << k << " " << i << endl;
            a[k][i] = true;
            if(k == n) number++;
            else QuayLui(k + 1);

            a[k][i] = false;
        }
    }
     return number;
}



int main(){
    
    cin >> n;
    cout <<  QuayLui(1);
}

