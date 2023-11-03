#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
//1:28

using namespace std;

int n;

int NhapSo() {
    int a;
    cin >> a;
    return a;
}

int main() {
    string str = "alo23";
    cout << str.size() << endl; // in ra số kí tự trong chuỗi ( đúng luôn nhé ko có \0 đâu :>)  

    cin >> str; // chỉ nhập ăn được đến dấu cách -> không thể nhập chuỗi có dấu cách
    getline(cin,str); // đọc đến khi gặp phím enter rồi dừng (ko lấy enter)

    //chú ý :
    cin >> str; getline(cin,str); // getline sẽ không lấy được gì vì cin sẽ để lại phím enter xong getline sẽ đọc đến phím
    //enter rồi dừng luôn
    //cách khắc phục : 
    cin >> str;
    cin.ignore(1); // xóa 1 kí tự trong stdin
    getline(cin,str); // getline tự động xử lí enter 


    // duyệt qua các kí tự 
    for(char x : str) cout << x << endl;
    //hoặc:
    for(auto it = str.begin(); it != str.end();++it) cout << *it << endl;


    // hàm hay dùng:
    str.push_back('a'); // thêm vào cuối xâu kí tự 'a'
    str.insert(2,"aa"); // thêm chuỗi vào vị trí thứ 2
    str.erase(2); //xóa từ 2 đến hết
    str.erase(2,4); // xóa 4 kí tự từ chỉ số thứ 2 ( 2 3 4 5)
    //tìm chuỗi xon:
    if(str.find("abc") != string::npos){ // nếu tìm thấy, ngược lại sẽ ko tìm thấy
        cout<<str.find("abc"); // trả về chỉ số chuỗi
    }

    //phép nối chuỗi
    string str1 = "ola";
    str += str1 + " ";
    //có thể cộng kí tự, tuy nhiên phải viết theo cú pháp 
    //s+='a' chứ không được s = s + 'a';

    //có thể dùng toán tử so sánh để so sánh chuỗi (so sánh theo thứ tự từ điển)

    //6 hàm để kiểm tra kí tự:
    // isdigit(char c); // kiểm tra chữ số
    // islower(char c); // kiểm tra viết thường
    // isupper(char c); // kiểm tra viết hoa
    // isalpha(char c); // kiểm tra chữ cái
    // int tolower(char c); // chuyển thành chữ thường
    // int toupper(char c); // chuyển thành chữ hoa

    //chuyển chuỗi thành số int

    string SoStr = "123";
    int SoInt = stoi(SoStr); // string to int

    string SoStrll = "123456434565";
    long long SoLongLong = stoll(SoStrll); 

    //số thành xâu
    int intStr = 1299494;
    string strStr = to_string(intStr);

    //cắt xâu
    string strTmp = str.substr(2,4); //cắt chuỗi từ vị trí 2 đến 4

    //tách các từ trong 1 chuỗi theo kí tự cách
    stringstream ss(str); // biến chuỗi str thành các luồng, coi các từ trong xâu là các token
    // cin là luồng vào từ bàn phím
    string tmp;
    while(ss >> tmp){
        cout << tmp << endl;
    }
    //nếu kí tự khác dấu cách -> duyệt qua toàn xâu để dổi thành dấu cách

    


    return 0;
}