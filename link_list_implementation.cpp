#include<iostream>
using namespace std;

struct LinkList
{
   LinkList * next;
   int val;
   LinkList(): val(0), next(nullptr){}
   LinkList(int x): val(x), next(nullptr){}
   LinkList(int x, LinkList *next): val(x), next(next){}
};

LinkList * head = nullptr;

void display(){
    if(head == nullptr){
        return;
    }
    LinkList * temp = head;
    while(temp != nullptr){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    return;
}

LinkList * CreateNode(int x){
    LinkList * NewNode = (LinkList*)malloc(sizeof(LinkList));
    NewNode->next = nullptr;
    NewNode->val = x;
    return NewNode;
}

void addNode(int Data){
    if(head == nullptr){
        LinkList * Node = CreateNode(Data);
        head = Node;
        return;
    }
    LinkList * temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = CreateNode(Data);
    return;
}

int main(){
    int List[5] = {1,2,3,4,5};
    LinkList * head = nullptr;
    for(int i=0;i<5;i++){
        addNode(List[i]);
    }
    display();
    return 0;
}