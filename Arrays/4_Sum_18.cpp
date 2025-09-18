#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int first = nums[i];
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int sum = nums[i]+nums[j];
                long long req_sum = (long long)target-sum;
                    int start=j+1;
                    int end=nums.size()-1;
                    while(start<end){
                        if(nums[start]+nums[end]==req_sum){
                            ans.push_back({first , nums[j],nums[start],nums[end]});
                            while(start<end && nums[start]==nums[start+1]){
                                start++;
                            }
                            while(start<end && nums[end]==nums[end-1]){
                                end--;
                            }

                            start++;
                            end--;
                        }
                        else if(nums[start]+nums[end]>req_sum){
                            end--;
                        }
                        else{
                            start++;
                        }
                    }

            }
        }

        return ans;
        
    }
};