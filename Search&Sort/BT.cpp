#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

#define arr (int)1e6

// Bạn được cung cấp một mảng chứa mỗi số từ 1… n đúng một lần. Nhiệm vụ của bạn là thu thập các số từ 1 đến n theo thứ tự tăng dần. 
//Trên mỗi vòng, bạn đi qua mảng từ trái sang phải và thu thập càng nhiều số càng tốt. Tổng số vòng sẽ là bao nhiêu?

// Input Format
// 5
// 4 2 1 5 3
// Sample Output 0

// Giải thích test : Vòng 1 chọn số 1, vòng 2 chọn số 2 và 3, 
//vòng 3 chọn số 4 và 5 Ở mỗi vòng bạn được chọn số x 
//nếu như tất cả các số từ 1 tới x-1 đã được chọn trước đó rồi, mỗi vòng bạn có thể chọn nhiều số cùng 1 lúc.


int main(){

    int n; cin >> n;
    int pos[arr]; // mảng lưu vị trí ban đầu trong mảng đã cho của các giá trị
    for(int i = 1; i <= n; i++){
        int temp; cin >> temp;
        pos[temp] = i;
    }
    
    int count = 1;
    for(int i = 2; i <= n; i++){
        if(pos[i] < pos[i - 1]) count++;
    }

    cout << count << endl;




    return 0;
}