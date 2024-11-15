//
// Created by 朱俊驰 on 11/16/24.
//

#include "helper.cpp"

using namespace std;

int main(){
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