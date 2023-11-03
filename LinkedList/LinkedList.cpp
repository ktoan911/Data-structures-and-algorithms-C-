#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *prv, *nxt;

    Node(int _data){
        data = _data;
        prv = NULL;
        nxt = NULL;
    }
};

struct LinkedList{
    Node *head;
    int sz = 0;

    void addNewNode(int pos, int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            sz++;
            return;
        }

        if(pos == 1){ // Chèn vào đầu
            newNode->nxt = head;
            head->prv = newNode;
            head = newNode;
            sz++;
            return;
        }

        if(pos > sz) pos == sz + 1;
        if(pos == sz + 1){ // Chèn vào sau phần tử cuối cùng
            Node* temp = head;
            // Node temp sau thao tác này là node cuối cùng
            while(temp->nxt != NULL) temp = temp->nxt;
            newNode->prv = temp;
            temp->nxt = newNode;
            sz++;
            return;
        }

        int count = 1;
        Node* temp = head;
        // Node temp sau thao tác này chính là node ở vị trí thứ pos
        while(count < pos){
            temp = temp->nxt;
            count++;
        }

        newNode->nxt = temp;
        newNode->prv = temp->prv;
        newNode->prv->nxt = newNode;
        temp->prv = newNode;
        sz++;
    }

    void deleteNode(int pos){
        Node* temp = head;

        if(sz == 1){
            head = NULL;
            sz--;
            return;
        }

        int count = 1;
        // Node temp sau thao tác này chính là node ở vị trí thứ pos
        while(count < pos){
            temp = temp->nxt;
            count++;
        }

        if(pos == 1){ // Xoá bỏ node đầu
            temp->nxt->prv = NULL;
            head = temp->nxt;
            sz--;
            return;
        }

        if(pos == sz){ // Xoá bỏ node cuối
            temp->prv->nxt = NULL;
            sz--;
            return;
        }

        temp->prv->nxt = temp->nxt;
        temp->nxt->prv = temp->prv;
        sz--;
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->nxt;
        }
    }
} LinkedList;
