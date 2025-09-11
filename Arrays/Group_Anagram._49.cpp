#include<bits/stdc++.h>
using namespace std;
 vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>> ans;

    for(int i=0;i<strs.size();i++){
        string s = strs[i];
        sort(s.begin(),s.end());
        ans[s].push_back(strs[i]);
    }

    vector<vector<string>> res;
    for(auto it : ans){
        res.push_back(it.second);

    }

    return res;
 }