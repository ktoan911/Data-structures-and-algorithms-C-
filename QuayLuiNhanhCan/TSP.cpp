#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
int a[20][20] = {0};
bool visited[20] = {false};
ll ans = 0;
ll sum = 999999;
int min1 = 99999;
int cnt = 1;
int b[20];

void Print(){
    cout << 1 << " ";
    for(int i = 2; i <= 4; i++){
        cout << b[i] <<  " ";
    }   
    cout << endl;
}

void Try(int k){
    for(int i = 2; i <= n; i++){
        if(visited[i] == false){
            ans += a[k][i];
            visited[i] = true;
            cnt++;
            b[cnt] = i;
            if(cnt == n){
                //Print();
                if(ans + a[i][1] < sum){
                    sum = ans + a[i][1];
                    //cout << "sum " << sum << endl;
                }
            }
            else{
                if(ans + min1 * (n - cnt + 1) < sum){
                    Try(i);
                }
            }
            cnt--;
            visited[i] = false;
            ans -= a[k][i];
        }
        
            
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] < min1 && a[i][j] != 0) min1 = a[i][j];
        }

    }
    visited[1] = true;
    Try(1);

    cout << sum;

}