#include<bitset>
#include<iostream>

int main(){

    int n;

    std::cout<<"This program provides the total count of distinct elements.\n"<<std::endl;
    std::cout<<"Number of elements you want to input(Max 128):";
    std::cin>>n;
    
    std::bitset<128> data;
    int answer=0;

    std::cout<<"Please enter elements"<<std::endl;

    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        if(!data[x]){
            data[x] = true;
            answer++;
        }
    }
    std::cout<<"Unique elements: "<<answer<<std::endl;

    return 0;
}

