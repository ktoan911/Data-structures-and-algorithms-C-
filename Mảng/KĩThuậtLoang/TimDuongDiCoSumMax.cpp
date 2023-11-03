#include <bits/stdc++.h>

using namespace std;

using ll = long long;

// Cho ma trận A các số nguyên có N hàng và M cột. Tìm đường đi từ ở [1, 1] tới ô [N, M] sao cho tổng các số trên đường đi là lớn nhất có thể, biết rằng ở mỗi bước chỉ có thể đi
// từ ô hiện tại xuống ô phía dưới hoặc đi sang phải.

// Input Format
// Dòng đầu tiên N và M. N dòng tiếp theo mỗi dòng gồm M phần tử.

// Constraints
// 1≤N,M≤100; 1≤A[i][j]≤10^9
// Output Format
// In ra đường đi có tổng lớn nhất.



int n, m;
ll a[300][300];
vector<pair<int, int>> vt = {{0, 1}, {1, 0}};

ll sum = 0;
ll maximun = 0;

void DeQuy(int i, int j){ // out time
    if(i > n || j > m) return;
    sum += a[i][j];
    if(i == n && j == m){
        if(sum > maximun) maximun = sum;
        return;
    }

    for(int b = 0; b < 2; b++) {
        DeQuy(i + vt[b].first, j + vt[b].second);
        sum -= a[i + vt[b].first][j + vt[b].second];
    }
}

ll f[300][300];
void Loang(int i, int j){ // vẽ lại 1 test để hiểu kĩ hơn (Quy hoạch động)
    if(i > 1) f[i][j] = max(f[i][j], f[i - 1][j] + a[i][j]); 
    if(j > 1) f[i][j] = max(f[i][j], f[i][j - 1] + a[i][j]);
}

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    f[0][1] = f[1][0] = 0;
    f[1][1] = a[1][1];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            Loang(i, j);

            // có thể thay bằng : 
            
            //f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];

        }
    }

    cout << f[n][m];
    

    return 0;
}