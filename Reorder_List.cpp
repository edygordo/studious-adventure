#include<iostream>
using namespace std;

struct ListNode
{
   ListNode * next;
   int val;
   ListNode(): val(0), next(nullptr){}
   ListNode(int x): val(x), next(nullptr){}
   ListNode(int x, ListNode *next): val(x), next(next){}
};

ListNode * head = nullptr; // Initialize the Link List

void display(){
    if(head == nullptr){
        return;
    }
    ListNode * temp = head;
    while(temp != nullptr){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    return;
}

ListNode * CreateNode(int x){
    ListNode * NewNode = (ListNode*)malloc(sizeof(ListNode));
    NewNode->next = nullptr;
    NewNode->val = x;
    return NewNode;
}

void addNode(int Data){
    if(head == nullptr){
        ListNode * Node = CreateNode(Data);
        head = Node;
        return;
    }
    ListNode * temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = CreateNode(Data);
    return;
}

void reorderList(){
    int * arr = new int[50000];
    ListNode * temp = head;
    int i=0,Size=0;
    while(temp){
        arr[i] = temp->val; i++; temp = temp->next;
        Size++;
    }
    head = nullptr;
    i=0; int j=Size-1;
    while(i<j){
        addNode(arr[i]); addNode(arr[j]); i++; j--; 
    }
    if(i == j){ // List is of Odd length
        addNode(arr[i]);
    }
    delete [] arr;
}

int main(){
    addNode(1); addNode(2); addNode(3); addNode(4); 
    reorderList();
    display();
    return 0;
}