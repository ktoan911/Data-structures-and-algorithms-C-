#include <bits/stdc++.h>
using namespace std;

using ll =unsigned long long;

#define arr 300

vector<pair<int,int>> vt = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool CHeckPrime(ll n){
    if(n == 1 || n == 0) return false;
    for(ll i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int n, m; 
bool visited[arr][arr] = {false};
int a[arr][arr];
int ans[arr][arr];
bool isFinished = false;
void Loang(int i, int j, int u, int v){ // lỗi về thời gian
    if(i > n || j > m || isFinished) return;
    visited[i][j] = true;
    if( i == u && j == v){
        isFinished = true;
        return;
    }
    for(int b = 0; b < 4; b++){
        if(isFinished) break;
        if(!visited[i + vt[b].first][j + vt[b].second] && a[i + vt[b].first][j + vt[b].second] == 1){
            Loang(i + vt[b].first, j + vt[b].second, u, v);
            visited[i + vt[b].first][j + vt[b].second] = false;
        }
    }
}

bool check[arr][arr] = {false};

void Loang2(int i, int j){
    if(!check[i][j]) return;

    for(int b = 0; b < 4; b++){
        if(a[i][j] == 1) check[i + vt[b].first][j + vt[b].second] = true;
    } 
}

int main(){
    cin >> n >> m;
    int s,t,u,v; cin >> s >> t >> u >> v;
 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    
    // Loang(s, t, u, v);

    // if(isFinished) cout << "YES";
    // else cout << "NO";

    check[s][v] = true;

    for(int i = s; i <= n; i++){
        for(int j = t; j <= m; j++){
            if(check[u][v]) break;

            Loang2(i, j);
        }
        if(check[u][v]) break;
    }

    if(check[u][v]) cout << "YES";
    else cout << "NO";

    return 0;
}