#include<bits/stdc++.h>
class Solution {
public:
    long long int tribonacci(int n) {
        //vector<long long int> v(38);
        
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;       
        long long int prepre=0;
        long long int pre=1;
        long long int curr=1;
        long long int next ;
            for(int i=0;i<=n-3;i++)
        {
            next= prepre+pre+curr;
            
            
            prepre=pre;
            pre=curr;
            curr=next;
        }
        
        return next;
    }
    
};