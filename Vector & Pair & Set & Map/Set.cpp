#include <bits/stdc++.h>
using namespace std;

// không có chỉ số ( không tuyến tính)
// tự loại bỏ phần tử trùng
//luôn tự sắp xếp theo thứ tự tăng dần


int main(){

    set<int> st = {12,3,3,4};

    st.insert(0);
    st.insert(10);
    st.insert(20);
    st.insert(5);
    st.insert(10);

    //xóa phần tử

    st.erase(10); // xóa tất cả giá trị có giá trị 10
    st.erase(*st.rbegin()); // xóa dựa vào giá trị phần tử (như ví dụ là giá trị thứ 0)

    //for( auto x : st) cout << x << endl;

    //iterator ngược

    for(auto it = st.rbegin(); it != st.rend();it++){
        cout << *it << ' '; // in ngược
    }

    //iterator thuận

    for (auto it = st.begin(); it != st.end(); ++it) {
        std::cout << *it << " ";
    }

    cout << '\n' << endl;

    for(auto it = st.rend(); it != st.rbegin();it--){
        cout << *it << ' ';
    }
    cout << '\n' << endl;

    //check sự tồn tại 1 phần tử
    if(st.find(0) != st.end()){
        cout << "Found" << "\n";
        auto it = st.find(0);
        cout << "Chi so thu: " << *it;
    }
    else cout << "Not Found" << "\n";


    //MULTISET

    multiset<int> mulst;

}