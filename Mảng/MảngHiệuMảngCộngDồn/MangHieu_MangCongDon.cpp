#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;

//MẢNG CỘNG DỒN
//Mảng prefix -> mục đích để giảm độ phức tạp cảu 1 hay 2 vòng lặp for 

// * 1 chiều
// ví dụ : mảng a[5] = [1,2,3,4,5]
// mảng cộng dồn của A : [1,3,6,10,15] -> pre[i] = a[0] + ... + a[i]

// * 2 chiều
// pre[a][b] là tổng các phần tử trong hình chữ nhật từ hàng 1 đến hàng a và từ cột 1 đến cột b ( khó hiểu thì cứ vẽ hình ra )
// ví dụ : mảng a[5][5] = [1,2,3,4,5][1,2,3,4,5]
// công thức mảng cộng dồn của a: pre[i][j] = pre[i - 1][j] + pre[i][j -1] - pre[i -1][j - 1] + a[i][j]
// tip: khi nhập mảnh prefix 2 chiều ta có thể cho thêm full hàng 1 là 0 va full cột 1 là 0 thì không cần phải if

//Bài tập ví dụ : Tèo hiện tại đã bỏ làm lập trình viên và trở về về quê trồng rau nuôi cá, 
    //anh ta có một mảnh vườn hình chữ nhật có kích thước NxM. Anh ta chia vườn của mình thành NXM
    // ô vuông và trồng vào đó một cây cà rốt, tới vụ thu hoạch có những cây cà rốt bị chết và có những 
    //cây cà rốt có củ, anh ta muốn biết với mỗi mảnh vườn hình chữ nhật bắt đầu từ hàng x1 tới hàng x2 và từ cột y1 tới cột y2 thì số cà rốt thu hoạch được là bao nhiêu.
    // Biết rằng mảnh vườn được mô tả bởi một ma trận nhị phân, 0 tương ứng với cây cà rốt chất và 1 tương ứng với cây cà rốt có củ.
//Input:
//Dòng 1 là N và M
//N dòng tiếp theo mỗi dòng M số mô tả mảnh vườn
//Dòng tiếp theo là Q : số lượng truy vấn
//Q dòng tiếp theo mỗi dòng gồm 4 số : x1, x2, y1, y2


//MẢNG HIỆU (Mảng D)
//Cho mảng a
// D[0] = a[0]
// D[i] = a[i] - a[i - 1]
// Tính chất : mảng cộng dồn của mảng hiệu là mảng a ban đầu

//áp dụng : 
//Cho mảng số nguyên A[] gồm N phần tử, có Q thao tác, mỗi thao tác yêu cầu các bạn tăng tất cả các phần tử từ chỉ số L tới chỉ số R lên K đơn vị. Bạn hãy in ra mảng sau khi thực hiện các thao tác trên.
//Input:
//Dòng 1 là N và Q
//Dòng 2 là N phần tử trong mảng A[]
//Q dòng tiếp theo mỗi dòng là 3 số L, R, K

int main() {

    #pragma region   Giai BT Ví dụ mảng cộng dồn
    // int n; cin >> n;
    // int m; cin >> m;
    // int a[n + 1][m + 1];

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++){
    //         cin >> a[i][j];              
    //     }
    // }

    // int prefix[n + 1][m + 1];

    // for (int i = 1; i <= n; i++){
    //     for (int j = 1; j <= m; j++){
    //         prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + a[i][j];
    //     }       
    // }

    // int soLuong; cin >> soLuong;
    // int x1,x2,y1,y2;
    // vector<int> vt;
    // int tmp;

    // while(soLuong--){
    //     cin >> x1 >> x2 >> y1 >> y2;
    //     tmp = prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];

    //     vt.push_back(tmp);
    // }

    // for(auto x : vt) cout << x << endl;

    #pragma endregion
    
    
    #pragma region   Giai BT Ví dụ mảng hiệu
    int n, m; cin >> n >> m;
    int a[n];

    for(auto &x : a) cin >> x;
    
    int D[n + 1]; // n + 1 để chống lỗi tràn bộ nhớ ở dòng ***
    D[0] = a[0];
    for(int i = 1; i < n; i++){
        D[i] = a[i] - a[i - 1];
    } 

    int l,r,k;
    while (m--){
        cin >> l >> r >> k; // chú ý l,r được tính từ 1 nên các thao tác phía sau phải từ 1 vì mảng bắt đầu từ index 0
        l -= 1;
        r -= 1;
        //****CÚ PHÁP CẦN NHỚ**** -> muốn hiểu thì viết hẳn bản chất mảng hiệu ra
        D[l] += k;  
        D[r + 1] -= k; // ***
    }

    //ĐỂ THỎA MÃN YÊU CẦU ĐỀ BÀI, TA CỘNG DỒN MẢNG HIỆU ĐỂ TRỞ THÀNH MẢNG CẦN TÌM
    int ans[n];
    ans[0] = D[0];
    for(int i = 1; i < n; i++){
        ans[i] = D[i] + ans[i - 1];
    }

    //in ra kết quả
    for(auto x : ans) cout << x << endl;
    #pragma endregion
    
    return 0;
}