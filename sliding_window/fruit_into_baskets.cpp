/*

https://leetcode.com/problems/fruit-into-baskets/description/

Find the maximum length of a subarray which comprises of only 2 distinct numbers.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].

*/
#include<vector>
#include<map>
#include<algorithm>

class Solution {
public:
    int totalFruit(std::vector<int>& fruits) {
        std::map<int,int> items;
        int left=0,right=0;
        int max_length = 1;

        while(right<fruits.size()){
            items[fruits[right]]++;

            while(items.size()>2 && left<=right){
                items[fruits[left]]--;
                if(items[fruits[left]]==0)
                    items.erase(fruits[left]);
                left++;
            }
            
            max_length = std::max(max_length,right-left+1);
            right++;
        }

    return max_length;
    }
};