/*
https://leetcode.com/problems/defuse-the-bomb/description/

Sum of K number of elements from current location, which can be in either direction from the current index in the array
*/

#include<vector>
#include<algorithm>

class Solution {
public:
    std::vector<int> decrypt(std::vector<int>& code, int k) {
        
        int n = code.size();
        std::vector<int> res(n,0);

        if(k==0)
            return res;

        if(k>0){
            int j=0;
            int sum = 0;
            int count = 0;
            while(count<k)
            {
                sum += code[(count+1)%n];
                count++;
            }
            res[j] = sum;
            j++;

            while(j<n){
                count = (count+1)%n;
                sum += code[count] - code[j];
                res[j] = sum;
                j++;
            }
        }
        else{
            int j=n-1;
            int sum=0;
            int count=0;

            while(count<-k){
                sum += code[n-2-count];
                count++;
            }

            res[j] = sum;
            j--;

            while(j>=0){ 
                count = count+1;
                sum += code[(((n-1-count)%n)+n)%n] - code[j];
                res[j] = sum;
                j--;

            }

        }

        return res;
    }
};