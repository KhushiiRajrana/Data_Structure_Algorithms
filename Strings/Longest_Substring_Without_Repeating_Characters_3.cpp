#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.length();
        int ans=0;
        string neww = "";
        for(int i=0;i<n;i++){
            int found = neww.find(s[i]);
            if(found==string::npos){
                // matlab nhi hai 
                neww.push_back(s[i]);
            }
            else{
                // matalb wo character already neww me present hai
                neww=neww.substr(found+1);
                //matlab jhan character match hua hai use se pehle ki hat jaega string se or founde se end tak ki string hi ab neww hogi//
                neww.push_back(s[i]);
            }
            ans=max(ans,(int)neww.length());
        }

        
    return ans;
        
    }
};