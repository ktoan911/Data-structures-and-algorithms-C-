#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>

using namespace std;

// lưu dữ liệu theo key - value
// Key ko trùng nhau
// Các phần tử xếp theo giá trị tăng dần của key
// mặc định khi mới tạo map thì các value đều = 0 


int main() {
    
    //khai báo
    map<int, int> mp;
    map<string, vector<int>> mp2;
    

    // thêm phần tử
    mp.insert({2,4});
    mp[2] = 5; // thành công ghi đè
    mp.insert({2,5}); // ko thành công

    //check empty
    mp.empty(); // -> true or false

    //số lượng ptu 
    mp.size();
    
    //tìm kiếm tương tự set có thể tìm bằng iterator và giá trị
    if(mp.find(10 /* key*/) != mp.end()) cout << "co phan tu 10";

    //. in ra map
    for(auto x : mp) cout << x.first << " " << x.second <<endl;

    // in ra map theo thứ tự ngược 
    for(auto i = mp.rbegin(); i != mp.rend(); ++i){  // rbegin là chỉ phần tử cuối, rend() là chỉ trước phần tử đầu
         cout << i->first << " " << i->second << "\n";
    }

    // in ra map theo thứ tự thuận
    for(auto i = mp.begin(); i != mp.end(); i++) {
        cout << i->first << " " << i->second << "\n";
    }


    return 0;
}
