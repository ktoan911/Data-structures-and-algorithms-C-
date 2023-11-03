#include <bits/stdc++.h>

using namespace std;

#define FORU(i, a, b) for(int i = a; i <= b; i ++)
#define FORD(i, b, a) for(int i = b; i >= a; i --)
#define UFOR(i, a, b) for(int i = a; i < b; i ++)
#define DFOR(i, b, a) for(int i = b; i > a; i --)
#define fi first
#define se second
#define N 10
typedef pair < int, int > ii;

int a[N][N], sz = 0;
vector < ii > vc;
bool ans = 0;

int check(int id, int val)
{
    ii x = vc[id];
    FORU(i, 1, 9)
        if(a[i][x.se] == val || a[x.fi][i] == val)
            return 0;
    ii left_top = make_pair((x.fi - 1)/3 * 3 + 1, (x.se - 1)/3 * 3 + 1);
    FORU(i, 0, 2)
        FORU(j, 0, 2)
            if(a[left_top.fi + i][left_top.se + j] == val)
                return 0;
    return 1;
}

void solve()
{
    FORU(i, 1, 9)
    {
        FORU(j, 1, 9)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    ans = 1;
}

void Try(int id)
{
    if(ans)
        return;
    FORU(i, 1, 9)
    {
        ii x = vc[id];
        if(check(id, i))
        {
            a[x.fi][x.se] = i;
            if(id == sz)
                solve();
            else
                Try(id + 1);
            a[x.fi][x.se] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("quanhau.inp", "r", stdin);
    freopen("quanhau.out", "w", stdout);
    FORU(i, 1, 9)
        FORU(j, 1, 9)
        {
            cin >> a[i][j];
            if(a[i][j] == 0)
                vc.push_back(ii({i, j}));
        }
    sz = vc.size() - 1;
    Try(0);
    return 0;
}