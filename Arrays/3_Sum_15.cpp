#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int first=nums[i];
            // use 2 sum ;
            int reqsum = 0-(first);
            int left =i+1;
            int right=nums.size()-1;
            while(right>left){
                if(nums[left]+nums[right]==reqsum){
                    ans.push_back({nums[i],nums[left],nums[right]});
                    while(left<right && nums[left ]==nums[left+1]) left++;// to avoid dupliacte elementsuu
                    while(left<right && nums[right ]==nums[right-1]) right--;
                     left++;
                    right--;
                }
                else if(nums[left]+nums[right] > reqsum){
                    right--;
                }
                else{
                    left++;
                }
            }
        }

        return ans;
        
    }
};