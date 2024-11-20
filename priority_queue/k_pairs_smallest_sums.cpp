/*
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/

Given two arrays, form the first k UNIQUE pairs, which have the smallest sum
*/
#include<queue>
#include<set>
#include<vector>
#include<utility>

class Solution {
public:

    struct compare{
        bool operator()(const std::pair<int, std::pair<int,int>>& a, const std::pair<int, std::pair<int,int>>& b){
            return a.first>b.first;
        }
    };

    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {

        std::vector<std::vector<int>> res;

        if(nums1.size()==0 || nums2.size()==0)
            return res;

        std::priority_queue<std::pair<int,std::pair<int,int>>,std::vector<std::pair<int,std::pair<int,int>>>, compare> pq;
        std::set<std::pair<int,int>> visited;

        pq.push({nums1[0]+nums2[0],{0,0}});
        visited.insert({0,0});

        while(k>0){
            auto cur = pq.top();
            pq.pop();
            int cur_i = cur.second.first;
            int cur_j = cur.second.second;

            res.push_back({nums1[cur_i],nums2[cur_j]});

            if(cur_i+1<nums1.size()){
                int new_i = cur_i+1;

                if(visited.find({new_i,cur_j})==visited.end()){
                    pq.push({nums1[new_i] + nums2[cur_j],{new_i,cur_j}});
                    visited.insert({new_i,cur_j});
                }
                    
            }

            if(cur_j+1<nums2.size()){
                int new_j = cur_j+1;

                if(visited.find({cur_i,new_j})==visited.end())
                    pq.push({nums1[cur_i] + nums2[new_j],{cur_i,new_j}});
                    visited.insert({cur_i,new_j});
            }

            k--;
        }

      return res;

    }
};