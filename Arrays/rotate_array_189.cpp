#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n; //in case k>n
        vector<int> temp(n);
        for(int i=0;i<n;i++){
            temp[(i+k)%n]=nums[i];
        }
        //copy temp to nums
        nums=temp;
    }
};
// tc=o(n) sc=o(n)
// we require to solve this in o(1) space
//OPTIMAL SOLUTION
class Solution {
public:
    void reverse(vector<int>& nums ,int start,int end){
        while(start<end){
            swap(nums[end],nums[start]);
                start++;
                end--;
            
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        //reverse the whole array
        reverse(nums,0,n-1);
        //reverse first k elements
        reverse(nums,0,k-1);
        //revrese last n-k elements
        reverse(nums,k,n-1);
    }
};
