#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll mod  = 1e9 + 7;

ll ModLuyThua(ll a, ll b, ll mod){
    if(b == 0) return 1;
    ll x = ModLuyThua(a, b / 2, mod);

    if(b % 2 == 0) return ((x % mod) * (x % mod)) % mod;
    else return a % mod * (x % mod) * (x % mod) % mod;
}



int main()
{
    int n; 
    ll a, b, c;
    cin >> n; 

    while(n--){
        cin  >> a >> b >> c;
        ll temp = ModLuyThua(b, c , mod - 1);
        cout << ModLuyThua(a, temp, mod) << endl;
    }

    

}