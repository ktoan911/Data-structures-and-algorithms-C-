#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

//Kĩ thuật duyệt ô liền kề mảng 2 chiều (Kĩ thuật loang)
// https://drive.google.com/file/d/1WUTWZCFhehHqFBINAEhRPTEmxpoBe4Hm/view?usp=sharing
//ví dụ : 
//Cho ma trận A các số nguyên có N hàng và M cột. Điểm được coi là cực đại trong ma trận nếu nó lớn hơn tất các số ở các số ở ô xung quanh mà chung đỉnh với nó. Hãy đếm xem trong ma trận có bao nhiêu điểm cực đại.
//Input
//Dòng đầu tiên N và M. N dòng tiếp theo mỗi dòng gồm M phần tử.

int main(){

    vector<pair<int,int>>  p = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}} ;
    int n, m; cin >> n >> m;
    int a[n + 2][m + 2];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }   

    //CHÚ Ý ĐÂY LÀ TRONG TRƯỜNG HỢP TẤT CẢ PHẦN TỬ LỚN HƠN 0, NẾU KHÔNG PHẢI XÉT PHẦN VIỀN NGOÀI BẰNG ÂM VÔ CÙNG
    for(int j = 0; j <= m + 1; j++){
        a[0][j] = 0;
        a[n + 1][j] = 0;
    }
    for(int j = 0; j <= n + 1; j++){
        a[j][0] = 0;
        a[j][m + 1] = 0;
    }

    int count = 0;
    bool isTrue = true;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int x = 0; x < 8; x++){
                if(a[i][j] <= a[i + p[x].first][j + p[x].second]){
                    isTrue = false;
                    break;
                }
            }

            if(isTrue){
                    count++;
                }
            isTrue = true;
        }
    }
     cout << count << endl;
    return 0;
}