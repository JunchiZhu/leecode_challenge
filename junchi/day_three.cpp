//
// Created by 朱俊驰 on 11/17/24.
//

#include "helper.h"
#include "linked_list.cpp"
using namespace std;
// dummy 1 2 3 4
// dummy 2 1 4 3
ListNode* swapPairs(ListNode* head) {
    ListNode* dummy_head= new ListNode();
    if(head!= nullptr){
        dummy_head->next=head;
    }
    ListNode* cur=dummy_head;
    while(cur->next!= nullptr and cur->next->next!= nullptr){
        ListNode* next_node =  cur->next;
        ListNode* next_next_node =  next_node->next;
        ListNode* next_next_next_node =  next_next_node->next;
        cur->next=next_next_node;
        next_next_node->next=next_node;
        next_node->next=next_next_next_node;
        cur=next_node;
    }
    head=dummy_head->next;
    delete dummy_head;
    return head;
}
// dummy 1 2 3
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int num=0;
    ListNode* dummy_head=new ListNode();
    dummy_head->next=head;
    ListNode* temp=dummy_head;
    while (temp!= nullptr){
        temp=temp->next;
        num+=1;
    }
    ListNode* cur=dummy_head;
    int count = num-n-1;
    while(count--){
        cur=cur->next;
    }
    cur->next=cur->next->next;
    return dummy_head->next;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int num_a=0, num_b=0;
    ListNode *cur_a=headA;
    ListNode *cur_b=headB;
    while(cur_a!=nullptr){
        cur_a=cur_a->next;
        num_a+=1;
    }
    while(cur_b!=nullptr){
        cur_b=cur_b->next;
        num_b+=1;
    }
    int num=abs(num_a-num_b);
    ListNode *temp_a=headA;
    ListNode *temp_b=headB;
    if(num_a>num_b){
        while(num--){
            temp_a=temp_a->next;
        }
    }else{
        while(num--){
            temp_b=temp_b->next;
        }
    }
    while(temp_a!=nullptr){
        if(temp_a==temp_b){
            return temp_a;
        }
        temp_a=temp_a->next;
        temp_b=temp_b->next;
    }
    return nullptr;
}

int main(){
    ListNode* head= new ListNode(1);
    ListNode* node1= new ListNode(2);
    head->next=node1;
    removeNthFromEnd(head, 2);
    return 0;
}