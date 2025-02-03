#include<vector>
#include<iostream>

using namespace std;


int xor_vector(vector<int>& a, vector<int>& b){

    int res = 0;

    for(int i=0;i<a.size();i++)
        res += a[i]^b[i];
    return res;
}
int main(){

    vector<int> one{1,2,3};
    vector<int> two{2,3,4};
    vector<int> three{1,2,3};

    cout<<"XOR of one and two"<<endl;
    cout<<xor_vector(one,two)<<endl;

    cout<<"XOR of one and three"<<endl;
    cout<<xor_vector(one,three)<<endl;

    for(int i=0;i<two.size();i++)
        two[i] -= 1;

    cout<<"XOR of one and two after reducing value of two"<<endl;
    cout<<xor_vector(one,two)<<endl;

return 0;

}