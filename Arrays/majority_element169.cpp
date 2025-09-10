#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0];
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count =1;
        for(int i=1;i<nums.size();i++){
            if(count>n/2){
                return nums[i-1];
            }
            if(nums[i]==nums[i-1]){
                count++;
            }
            else{
                count =1;    
            }
        }
        if(count> n/2){
            return nums[n-1];
        }
        return -1;
    }
};  // tc = 0(nlogn) sc=O(1)

//tc=
