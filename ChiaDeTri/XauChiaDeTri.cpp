#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define arr (int)1e6 + 5;

// Cho xâu F được định nghĩa như sau : F(1) = "28tech", F(2) = "C++", F(3) = "DSA JAVA". F(N) = F(N - 3) + " " + F(N -2) + " " + F(N - 1).
// Vì thế F(4) = "28tech C++ DSA JAVA", F(5) = "C++ DSA JAVA 28tech C++ DSA JAVA".
// Nhiệm vụ của bạn là tìm từ thứ K trong xâu F(N), dữ liệu đảm bảo xâu F(N) có từ thứ K

// Input Format
// Dòng 1 là T : số bộ test
// T dòng tiếp theo mỗi dòng gồm 2 số N, K

// Contraints
// 1<=T<=100
// 1<=N<=60
// 1<=K<=10^16

// Output Format
// In ra kết quả của mỗi test trên từng dòng
// Sample Input
// 10
// 3 2
// 6 2
// 10 24
// 4 2
// 5 4
// 6 12
// 7 22
// 8 1
// 7 18
// 8 14

// Sample Output
// JAVA
// JAVA
// JAVA
// C++
// 28tech
// DSA
// C++
// C++
// C++
// C++

ll F[105];

string Fibo(int n, ll k)
{
    if (n == 1)
        return "28tech";
    if (n == 2)
        return "C++";
    if (n == 3)
    {
        if (k == 1)
            return "DSA";
        if (k == 2)
            return "JAVA";
    }

    if (k <= F[n - 3])
        return Fibo(n - 3, k);
    else if (k > F[n - 3] && k <= F[n - 2] + F[n - 3])
        return Fibo(n - 2, k - F[n - 3]);
    else
        return Fibo(n - 1, k - F[n - 3] - F[n - 2]);
}

int main()
{
    F[1] = 1;
    F[2] = 1;
    F[3] = 2;

    for (int N = 4; N <= 60; N++)
    {
        F[N] = F[N - 2] + F[N - 1] + F[N - 3];
    }

    int T;
    cin >> T;

    while (T--)
    {
        int n;
        ll k;
        cin >> n >> k;

        cout << Fibo(n, k);
        cout << endl;
    }

    return 0;
}