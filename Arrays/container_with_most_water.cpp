#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int area = 0;

        while (left < right) {
            int len = min(height[left], height[right]);
            int width = right - left; // fixed here
            area = max(area, len * width);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return area;
    }
};
