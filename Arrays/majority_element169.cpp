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

//tc=o(n) ,sc=o(n);
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        int n=nums.size();
        for(int num:nums){
            freq[num]++;
            if(freq[num]>n/2){
                return num;
            }
        }

        return -1;

    }
};


//OPTIMAL SOLUTION--->moore's voting algorithm
//tc=o(n) ,sc=o(1);
//step1 : Apply the Alogrihtm
//Step2 : Verify Whether the candidate is majority or not
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elem_to_check = nums[0];
        int count =0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                elem_to_check=nums[i];
            }
            if(nums[i]==elem_to_check){
                count++;
            }
            else{
                count--;
            }
        }

        //check frequency for the possible majority element;
        int freq = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==elem_to_check){
                freq++;
            }
        }

        int n=nums.size();
        if(freq>n/2){
            return elem_to_check;
        }

        return -1;
        
    }
};
