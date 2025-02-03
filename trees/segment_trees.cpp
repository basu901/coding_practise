#include<bitset>
#include<iostream>
#include <bitset>
#include<vector>
#include<math.h>
#include<queue>

using namespace std;

vector<int> tree;

void show_tree(vector<int> arr){
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int s=q.size();
        while(s>0){
            int cur=q.front();
            q.pop();
            std::cout<<arr[cur]<<" ";
            q.push(2*cur+1);
            q.push(2*cur+2);
            s-=1;
        }
        cout<<endl;
    }
}

void build_tree(vector<int> arr, int n,int o_size)
{
    while(__builtin_popcount(n)!=1)
    {
        arr.push_back(0);
        n += 1;
    }
    cout<<n<<endl;
    int idx=n/2;
    cout<<"Please enter the array elements"<<endl;
    for(int i=0;i<o_size;i++)
        cin>>arr[idx+i];
    
    for(idx=idx-1;idx>=0;idx--)
        arr[idx] = arr[2*idx+1] + arr[2*idx+2];

    cout<<arr.size()<<endl;
}


int main()
{
    int n;
    cout<<"Enter the number of elements in the array:"<<endl;
    cin>>n;
    int orig_size=n;
    vector<int> arr(n);
    tree.resize(2*n-1);
    n = 2*n-1;
    build_tree(arr,n,orig_size);
    //show_tree(arr);
}

