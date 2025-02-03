/*

Given a set of integers, check if the integers add up to a target number. Similar to knapsack, but you aren't maximizing or minimizing.

*/

#include<iostream>
#include<bitset>

int main(){

    int target,n;

    std::cout<<"Please provide the target number(Max 100):";
    std::cin>>target;

    std::cout<<"Please enter the size of the sequence:";
    std::cin>>n;

    std::cout<<"Please enter the numbers in the sequence:";
    std::bitset<100> data;
    data[0] = true;

    for(int i=0;i<n;i++){
        int number;
        std::cin>>number;
        data |= (data<<number);
    }

    if(data[target])
        std::cout<<"Target can be reached!"<<std::endl;
    else
        std::cout<<"Not possible to reach target :("<<std::endl;

    return 0;
}


