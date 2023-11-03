#include <bits/stdc++.h>
using namespace std;

using ll =unsigned long long;

#define arr 300

vector<pair<int,int>> vt = {{-2, -1}, {-1, -2}, {1, 2}, {2, 1}, {-2, 1}, {1, -2}, {2, -1}, {-1, 2}};

int n, m; 
int s,t,u,v; 
int a[arr][arr];
bool check[arr][arr] = {false};


void Loang(int i, int j){
    if(i > n || j > n || i < 1 || j < 1) return;
    if(a[i][j] != 1) return;
    check[i][j] = true;
    a[i][j] = 0;
    cout << i<< " " <<  j << endl;
    if(i == u && j == v) return;

    for(int b = 0; b < 8; b++){
        if(check[u][v]) break;
        Loang(i + vt[b].first, j + vt[b].second);
    }
}


int main(){
    cin >> n;
    cin >> s >> t >> u >> v;
 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    Loang(s, t);

    if(check[u][v]) cout << "YES";
    else cout << "NO";

    return 0;
}