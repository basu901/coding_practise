/*
https://leetcode.com/problems/maximum-frequency-stack/

Retrieving the element which has the maximum frequency of occurrence in a stack. If there is a tie, retrieve the most recently inserted element.
*/

#include<stack>
#include<map>
#include<queue>
#include<vector>

class FreqStack {
public:
    FreqStack() {
        count = 0;
    }
    
    void push(int val) {
        element* e = new element;
        e->freq = m[val]++;
        e->time = count++;
        e->num = val;

        pq.push(e);      
    }
    
    int pop() {
        int val = pq.top()->num;
        m[val]--;
        pq.pop();
        return val;
    }

private:
    int count;

    struct element{
        int num;
        int time;
        int freq;
    };

    struct comp{
        bool operator()(const element* a, const element* b)
        {
            if(a->freq!=b->freq)
                return a->freq<b->freq;
            else
                return a->time<b->time;
        }
    };
    std::priority_queue<element*, std::vector<element*>,comp> pq;
    std::map<int,int> m;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
