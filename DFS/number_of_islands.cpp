/*
https://leetcode.com/problems/number-of-islands/description/


Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

*/
#include<vector>

class Solution {
public:

    void cover_island(std::vector<std::vector<char>>& grid, int x, int y){
        
        grid[x][y] = '0';

        std::vector<int> dir{-1,0,1,0,-1};
        for(int i=0;i<dir.size()-1;i++){
            int new_x = x + dir[i];
            int new_y = y + dir[i+1];
            if(new_x>-1 && new_x<grid.size() && new_y>-1 && new_y<grid[0].size()){
                if(grid[new_x][new_y]=='1')
                    cover_island(grid,new_x,new_y);
            }
        }
    }

    int numIslands(std::vector<std::vector<char>>& grid) {
     
        int count = 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1')
                {
                    cover_island(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};