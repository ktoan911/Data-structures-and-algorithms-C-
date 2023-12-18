#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

#define arr (int)1e6 + 5;

// Xâu S chỉ bao gồm các kí tự A và B được gọi là xâu Fibonacci
// nếu S(1) = 'A', S(2) = 'B', S(n) = S(n - 2) + S(n - 1),
// trong đó phép + là phép nối 2 xâu. Bài toán đặt ra là tìm kí tự thứ K
// trong xâu fibonacci thứ N.

// Input Format
// Dòng duy nhất chứa 2 số N và K
// Constraints
// 1<=N<=92; 1<=K<=7e18 và đảm bảo là vị trí hợp lệ trong xâu fibonacci thứ N
// Output Format
// In ra kí tự tìm được
// Sample Input
// 5 3
// Sample Output
// B

// => Ý tưởng: dãy thứ n tạo bởi dãy n - 1 và dãy n-2, ta xác định vị trí k thuộc dãy n-1 hay n-2 để đó biết được kí tự thứ k
// là kí tự nào

ll F[100]; // mảng dãy số fibonacy

char Fibo(int n, ll k) // tìm kí tự thứ k trong dãy fibo thứ n
{
    if (n == 1)
        return 'A';
    if (n == 2)
        return 'B';

    if (k <= F[n - 2]) // nếu vị trí k nằm trong đoạn đầu tiên
    {
        return Fibo(n - 2, k); // đệ quy lại
    }
    else // nếu vị trí k nằm trong đoạn sau
        return Fibo(n - 1, k - F[n - 2]);
}

int main()
{

    int n, k;
    cin >> n >> k;
    F[1] = 1;
    F[2] = 1;
    for (int i = 3; i <= 92; i++)
    {
        F[i] = F[i - 2] + F[i - 1];
    }

    cout << Fibo(n, k);

    return 0;
}