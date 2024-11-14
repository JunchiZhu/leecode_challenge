//
// Created by 朱俊驰 on 11/15/24.
//

#include "helper.cpp"

int search(vector<int>& nums, int target) {
    int mid = nums.size()/2;
    int left = 0, right = nums.size()-1;
    if(nums.size()==1 and nums[0]==target){
        return 0;
    }
    while(left<=right){
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
        mid=(right+left)/2;
    }
    return -1;
}

int removeElement(vector<int>& nums, int val) {
    int slow = 0;
    for(int fast=0;fast<nums.size();++fast){
        if(nums[fast]!=val){
            nums[slow]=nums[fast];
            slow+=1;
        }
    }
    return slow;
}

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> answer(nums.size(),0);
    int left=0,right=nums.size()-1;
    int counter=nums.size()-1;
    while(left<=right){
        if(nums[right]*nums[right]>=nums[left]*nums[left]){
            answer[counter]=nums[right]*nums[right];
            right-=1;
        } else{
            answer[counter]=nums[left]*nums[left];
            left+=1;
        }
        counter-=1;

    }
    return answer;
}

int minSubArrayLen(int target, vector<int>& nums) {

}

int main(){
    vector<int> nums1{2,5};
    cout<<search(nums1,2)<<endl;
    vector<int> nums2{2,2,3,3};
    removeElement(nums2,3);
    vector_printer(nums2);
}