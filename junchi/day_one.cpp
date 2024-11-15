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
   int answer=INT_MAX;
   int temp_length=0;
   int sum=0;
   int left=0;
   for(int right=0;right<nums.size();++right){
       sum+=nums[right];
       while(sum>=target){
           temp_length=right-left+1;
           sum-=nums[left];
           left+=1;
           if(temp_length<answer){
               answer=temp_length;
           }
       }
   }
   if(answer==INT_MAX){
       return 0;
   }
    return answer;
}

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> answer(n, vector<int>(n,0));
    int startx=0,starty=0;
    int loop=n/2;
    int count=1;
    int offset=1;
    while(loop--){
        int x=startx,y=starty;
        for(;y<n-offset;++y){
            answer[x][y]=count;
            count+=1;
        }
        for(;x<n-offset;++x){
            answer[x][y]=count;
            count+=1;
        }
        for(;y>starty;--y){
            answer[x][y]=count;
            count+=1;
        }
        for(;x>startx;--x){
            answer[x][y]=count;
            count+=1;
        }
        offset+=1;
        startx+=1;
        starty+=1;
    }
    if(n%2!=0){
        answer[n/2][n/2]=count;
    }
    return answer;
}

int main(){
    vector<int> nums1{2,5};
    cout<<search(nums1,2)<<endl;
    vector<int> nums2{2,2,3,3};
    removeElement(nums2,3);
    vector_printer(nums2);
}