/*

https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/description/

Find the minimum time taken to reach cell (m-1)(n-1).

*/

#include<utility>
#include<vector>
#include<queue>

using namespace std;

typedef pair<int, pair<int,int>> par;
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
    if(min(grid[0][1],grid[1][0])>1) return -1;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}}); //time,row,column
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visit(m,vector<int>(n,0));
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int t = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r==m-1 && c==n-1) return t;
            int row[] = {0,-1,0,1};
            int col[] = {-1,0,1,0};
            for(int i=0;i<4;i++){
                int nr = r+row[i];
                int nc = c+col[i];
                if(nr<0 || nc<0 || nr==m || nc==n || visit[nr][nc]==1){
                    continue;
                }
                int wait = 0;
                if(abs(grid[nr][nc]-t)%2==0){
                    wait = 1;
                }
                //We check the max time as the new cell can have a value much lower than t;
                int newtime = max(grid[nr][nc]+wait,t+1);
                pq.push({newtime,{nr,nc}});
                visit[nr][nc] = 1;
            }
        }
        return 0;
    }
};