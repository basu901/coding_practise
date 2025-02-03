#include<set>
#include<iterator>
#include<iostream>

using namespace std;

int main(){
    
    multiset<int> elements;

    elements.insert(3);
    elements.insert(4);
    elements.insert(5);
    elements.insert(6);
    elements.insert(5);
    elements.insert(4);
    elements.insert(3);

    elements.erase(3);
    elements.erase(elements.find(5));

    multiset<int>::iterator it = elements.begin();

    while(it != elements.end()){
        cout<<*it<<endl;
        it++;
    }
    return 0;
}