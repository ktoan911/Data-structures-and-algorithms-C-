#include <bits/stdc++.h>
#include <cmath>

using namespace std;
using ll = long long;

// Cho 2 mảng A[] và B[] có N và M phần tử 
// đã được sắp xếp theo thứ tự tăng dần, nhiệm vụ của bạn là hãy đếm xem trong 2 mảng tồn tại bao nhiêu cặp i, j sao cho A[i] = B[j]


int main(){
    
    int n, m; cin >> n >> m;
    int a[n]; for( int &x : a) cin >> x;
    int b[m]; for( int &x : b) cin >> x;

    int count = 0;
    ll temp = 0;
    int i = 0;
    for(int j = 0; j < m; ++j){
        while(a[i] <= b[j] && temp < n){
            if(a[i] == b[j]){
                count++;
                if(a[i] > a[temp]) temp = i;
            }
            i++;
        }
        i = temp;      
    }
    
   cout << count;


    return 0;
}