#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

void ShowVector(vector<int> v){
    for( int i : v) cout << i << " ";
    cout << ' ' << endl;
}


int main(){

    vector<int> v = {1,2,3,4,5,6,7,8};
    
   //Base Vector

    v.push_back(1); // đẩy 1 phản từ vào sau dãy vector (tương tự queue)
    v.push_back(2);

    vector<int> v1(3,100); // tạo sẵn 3 phần tử đầu của vector với giá trị là 100

    for( int x : v) // duyệt qua tất cả phần tử của vector v ( Range base for loop)
        x = 100;  // giá trị phần tử trong mảng vẫn không thay đổi do x bản chất là copy giá trị phần tử mảng chứ không phải chiếu đến
    
    ShowVector(v);

    //cách khắc phục:  
    for( int &x : v) 
        x = 100;

    ShowVector(v);

    cout << v.size() << endl;


    //chú ý lỗi

    // vector<int> v2;
    // v2[0] = 100; 
    //--> lỗi do chưa có ô trống nào cho v2 cả, bản chất khi push_back nó cũng phải tuej tạo ra ô trống



    // Vector Iterator 

    vector<int> :: iterator testIter = v.begin();

    v.push_back(1900);
   
    cout << *(testIter + v.size() - 1) << '\n'; // na ná con trỏ nên phải dùng * để giải địa chỉ
    
    testIter = v.end();
    
    cout << *(testIter - 1) << ' '; // na ná con trỏ nên phải dùng * để giải địa chỉ

    //hàm sử dụng iterator

    v.insert(v.begin() + 1, 111); // chèn vào phần tử thứ 1 ( tình theo 0 1 2 3) giá trị 111 

    v.pop_back(); //xoá phần tử cuối cùng

    v.erase(v.begin() + 1); // xóa phần tử thứ 1 (theo 0 1 2 3)

    v.assign(v.size() , 100); // cho hết các phần tử về 100


    //Sort 

    sort(v.begin(), v.end()); //Tăng dần

    sort(v.begin(), v.end(), greater<int>()); //Giảm dần  


    //Reverse
    reverse(v.begin(), v.end());

    //Min Max Sum
    cout << *min_element(v.begin(), v.end()); // Min 
    cout << *max_element(v.begin(), v.end()); // Max
    cout << accumulate(v.begin(), v.end(), 0); // Sum Vector // 0 là giá trị ban đầu của sum
}