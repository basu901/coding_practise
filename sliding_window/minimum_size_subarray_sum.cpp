/*

https://leetcode.com/problems/minimum-size-subarray-sum/

Find the minimum size of the subarray whose sum is equal to or greater than the target
*/

#include<vector>
#include<algorithm>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
       int left=0,right=0;
        int m_len = INT_MAX;
        int sum = 0;
        while(right<nums.size())
        {
            sum += nums[right];

            while(sum>=target && left<=right)
            {
                m_len = std::min(m_len, right-left+1);
                sum -= nums[left];
                left++;
            }

            right++;
        }

        return (m_len==INT_MAX)? 0: m_len;
    }
};