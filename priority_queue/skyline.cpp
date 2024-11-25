/*
This is a good example of a multiset being used to replace a priority queue.


https://leetcode.com/problems/the-skyline-problem/description/?envType=problem-list-v2&envId=heap-priority-queue


*/

#include<vector>
#include<set>
#include<utility>
#include<map>

class Solution {
public:

    struct compare{
        bool operator()(const std::pair<int,int>& a, const std::pair<int,int>& b){
            if(a.first==b.first)
                return a.second<b.second;
            return a.first<b.first;
        }
    };

    std::vector<std::vector<int>> getSkyline(std::vector<std::vector<int>>& buildings) {

        std::vector<std::pair<int,int>> x_axis;
        std::map<int,int> building_ended;
        std::multiset<int> point;
        std::vector<std::vector<int>> res;

        for(std::vector<int> i: buildings){
            x_axis.push_back(std::pair<int,int>(i[0],-i[2]));
            x_axis.push_back(std::pair<int,int>(i[1],i[2]));
        }
        
        sort(x_axis.begin(), x_axis.end(), compare());

        point.insert(0);

        for(auto p:x_axis){
            int cur = *point.rbegin();
            int x = p.first;
            int height = p.second;
            //std::cout<<"x:"<<x<<",height:"<<height<<endl;

            if(height>0)
                point.erase(point.find(height));
            else
                point.insert(-height);

            if(*point.rbegin()!=cur)
                res.push_back({x,*point.rbegin()});
        }

        return res;
    }
};