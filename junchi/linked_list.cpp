//
// Created by 朱俊驰 on 11/16/24.
//
#include "helper.cpp"
struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *next): val(x), next(next){}
};

ListNode* removeElements(ListNode* head, int val) {
    while(head!= nullptr and head->val==val ){
        head=head->next;
    }
    ListNode* node=head;
    while(node!= nullptr and node->next!=nullptr){
        if(node->next->val==val){
            node->next=node->next->next;
        }else{
            node=node->next;
        }
    }
    return head;
}
class MyLinkedList {
private:
    int size=0;
    ListNode* head;
public:
    MyLinkedList():head(nullptr),size(0) {}

    int get(int index) {
        if(index<0 || index>=size){return -1;}
        ListNode* node = head;
        while(index--){
            node=node->next;
        }
        return node->val;
    }

    void addAtHead(int val) {
        ListNode* node=new ListNode(val);
        ListNode* next=head;
        node->next=next;
        head=node;
        size+=1;
    }

    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        if(size==0){
            head=node;
        }
        else{
            ListNode* cur = head;
            int temp=size;
            while(temp>1){
                cur=cur->next;
                temp--;
            }
            cur->next= node;
        }
        size+=1;
    }

    void addAtIndex(int index, int val) {
        if(index<0 || index>size){ return;}
        ListNode* node = new ListNode(val);;
        if(index==0){
            node->next=head;
            head=node;
        } else{
            ListNode* cur = head;
            while (index>1){
                cur=cur->next;
                index--;
            }
            node->next = cur->next;
            cur->next=node;
        }

        size+=1;
    }

    void deleteAtIndex(int index) {
        if(index<0 || index>=size || head==nullptr){ return;}
        if(index==0){
            head=head->next;
        }
        else{
            ListNode* cur = head;
            while(index>1){
                cur=cur->next;
                index-=1;
            }
            cur->next=cur->next->next;
        }
        size-=1;
    }
};
