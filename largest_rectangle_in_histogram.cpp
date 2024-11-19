/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.

Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/
*/

#include<stack>
#include<algorithm>
#include<vector>
#include<utility>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {

        std::stack<std::pair<int,int>> st;
        int maxArea = INT_MIN;

        for(int i=0;i<heights.size();i++)
        {
            int cur_pos = i;
            while(!st.empty() && st.top().first>heights[i])
            {
                std::pair<int,int> cur = st.top();
                st.pop();
                maxArea = std::max(maxArea,cur.first*(i-cur.second));
                cur_pos = cur.second;   
            }

            st.push(std::pair<int,int>(heights[i],cur_pos));
        }

        while(!st.empty())
        {
            int n_area = st.top().first*(heights.size()-st.top().second);
            maxArea = std::max(maxArea, n_area);
            st.pop();
        }   

        return maxArea;
    }
};