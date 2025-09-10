#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int ans =0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min_price){
                min_price = prices[i];
            }
            else{
                ans= max(ans, prices[i]-min_price);
            }
        }
        return ans;
        
    }
};