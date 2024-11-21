/*
https://leetcode.com/problems/maximum-subarray/description/

Given an array find the maximum sum that can be formed from a given subarray.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

*/

//1st approach

#include<vector>
#include<algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
     
        int max_sub = INT_MIN;
        int cur_max = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            cur_max = std::max(nums[i],cur_max+nums[i]);
            max_sub = std::max(max_sub,cur_max);
        }
        
        return max_sub;
        
    }
};


//2nd approach
class Solution {
public:
    
    int maxSubArray(std::vector<int>& nums) {
     int sum=0,max_num=INT_MIN;
     for(int i:nums){
        sum += i;
        max_num = std::max(std::max(max_num,sum),i);
        if(sum<0)
            sum=0;
     }

     return max_num;
    }
};