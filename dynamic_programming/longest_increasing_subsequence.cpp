/*
https://leetcode.com/problems/longest-increasing-subsequence/description/

Given an integer array nums, return the length of the longest strictly increasing 
subsequence.

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4

*/


#include<vector>
#include<algorithm>


class Solution {
public:
    
    int max_length=1;

    int length_of_sub(std::vector<int>& nums, int pos, std::vector<int>& dp){
        if(pos==nums.size()-1)
        {
            dp[pos] = 1;
            return dp[pos];
        }
        
        if(dp[pos]!=-1)
            return dp[pos];

        dp[pos] = 1;

        for(int j=pos+1;j<nums.size();j++){
            if(nums[pos]<nums[j])
                dp[pos] = std::max(dp[pos], length_of_sub(nums,j, dp)+1);
        }
        

        max_length = std::max(max_length, dp[pos]);
        
        return dp[pos];
    }

    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> dp(nums.size(),-1);
        
        for(int i=nums.size()-1;i>-1;i--)
            length_of_sub(nums, i, dp);

        //for(int i: dp)
        //    std::cout<<i<<std::endl;

        return max_length;
    }
};




/*Binary Search Approach*/

class Solution {
public:
    
    int bS(std::vector<int>& s, int num)
    {
        int low = 0;
        int high = s.size()-1;
        //std::cout<<num<<std::endl;
        //for(int i=0;i<s.size();i++)
        //    std::cout<<s[i]<<" ";
        //std::cout<<std::endl;
        while(low<high)
        {
            int mid = low + (high-low)/2;
            //std::cout<<"mid:"<<mid<<std::endl;
            if(s[mid]<num)
                low = mid+1;
            else if(s[mid]>num)
                high = mid;
            else
                return mid;
        }
        
        return low;
    }
    
    int lengthOfLIS(std::vector<int>& nums) {
        
        if(nums.size()==0)
            return 0;
        
        std::vector<int> sequence;
        
        sequence.push_back(nums[0]);
        
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<=sequence.back())
            {
                int idx = bS(sequence,nums[i]);
                sequence[idx] = nums[i];
                //std::cout<<idx<<std::endl;
            }
            else
                sequence.push_back(nums[i]);
            
            
            //std::cout<<"h"<<sequence.size()<<std::endl;
        }
        
        return sequence.size();
    }
};