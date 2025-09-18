#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        prefix[0]=1;
        int mul=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=mul;
            mul=mul*nums[i];
        }
        mul=nums[nums.size()-1];
        suffix[nums.size()-1]=1;
        for(int i=nums.size()-2;i>=0;i--){
            suffix[i]=mul;
            mul*=nums[i];    
        }

        for(int i=0;i<nums.size();i++){
            nums[i]=prefix[i]*suffix[i];
        }

        return nums;
        
    }
};