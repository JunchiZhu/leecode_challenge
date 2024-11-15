//
// Created by 朱俊驰 on 11/14/24.
//
#include "iostream"
#include "vector"
using namespace std;

void vector_printer(const vector<int>& print_vector){
    for(auto element:print_vector){
        cout<<element<<" ";
    }
    cout<<endl;
}