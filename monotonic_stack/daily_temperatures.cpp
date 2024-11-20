/*
https://leetcode.com/problems/daily-temperatures/description/

Find the index of the next greatest integer in the array
*/

#include<vector>
#include<stack>
#include<utility>

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        
        std::stack<std::pair<int,int>> next_day;
        std::vector<int> results(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            while(!next_day.empty() && next_day.top().first<temperatures[i]){
                std::pair<int,int> cur = next_day.top();
                next_day.pop();
                results[cur.second] = i-cur.second;
            }
            next_day.push(std::pair<int,int>{temperatures[i],i});
        }

        return results;
    }
};