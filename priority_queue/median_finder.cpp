/*

Find the median of a given data stream

Link: https://leetcode.com/problems/find-median-from-data-stream/description/

Example:

["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]

[null, null, null, 1.5, null, 2.0]
*/

#include<queue>
#include<math.h>
#include<iostream>

using namespace std;


class MedianFinder {
public:
    priority_queue<int> topmost;
    priority_queue<int,vector<int>,greater<int>> lowest;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!lowest.empty() && num>lowest.top())
            lowest.push(num);
        else if(!topmost.empty() && num<topmost.top())
            topmost.push(num);
        else
            lowest.push(num);

        //Rebalance
        if(abs((int)lowest.size() - (int)topmost.size())>1){
            if(lowest.size()>topmost.size()){
                topmost.push(lowest.top());
                lowest.pop();
            }
            else{
                lowest.push(topmost.top());
                topmost.pop();
            }
        }

    }
    
    double findMedian() {
        if((lowest.size()+topmost.size())%2){
            if(lowest.size()>topmost.size())
                return lowest.top();
            else
                return topmost.top();
        }
        else
            return (lowest.top() + topmost.top())/2.0;
    }
};
