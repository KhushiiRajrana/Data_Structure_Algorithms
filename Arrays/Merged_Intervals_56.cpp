#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return {};
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int j=0;
        for(int i=1;i<intervals.size();i++){
            if(ans[j][1]>=intervals[i][0]){
                ans[j][1]=max(ans[j][1],intervals[i][1]);   
            }
            else{
                ans.push_back(intervals[i]);
                j++;
            }
    
        }

        return ans;
        
    }
};