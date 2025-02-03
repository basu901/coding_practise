#include<queue>
#include<iostream>


// Check to see if pq is max heap by default

using namespace std;

int main(){
    priority_queue<int> pq;

    for(int i=0;i<=10;i++)
        pq.push(i);

    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }

    return 0;
}