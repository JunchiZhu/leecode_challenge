//
// Created by 朱俊驰 on 11/16/24.
//

#include "helper.cpp"
#include "linked_list.cpp"
using namespace std;
// dummy -> a -> b -> c
ListNode* reverseList(ListNode* head) {
    ListNode* node=head;
    ListNode* dummy_head= nullptr;
    while(node!= nullptr){
        ListNode* node_next=node->next;
        node->next=dummy_head;
        dummy_head=node;
        node=node_next;
    }
    head=dummy_head;
    return head;
}

ListNode* swapPairs(ListNode* head) {

}

int main(){
    MyLinkedList *list=new MyLinkedList();
    list->addAtIndex(0,10);
    list->addAtIndex(0,20);
    list->addAtIndex(1,30);
    list->get(0);

    int num;
    cin>>num;
    vector<int> nums(num);
    vector<int> pre_sum(num);
    int preSum=0;
    for(int i=0;i<num;++i){
        cin>>nums[i];
        preSum+=nums[i];
        pre_sum[i]=preSum;
    }
    int left,right;
    while(cin>>left>>right){
        if(left==0){
            cout<<pre_sum[right]<<endl;
        }
        else{
            cout<<pre_sum[right]-pre_sum[left-1]<<endl;
        }
    }
}