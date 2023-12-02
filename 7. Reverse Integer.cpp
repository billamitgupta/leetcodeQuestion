class Solution {
public:
    int reverse(int x) {
        long long int reversenum= 0,reml;
        while(x!=0)
        {
            
            reml=x%10;
             x=x/10;
            reversenum=(reversenum *10) +reml;
        }
        if(reversenum>INT_MAX) return 0;
        if(reversenum<INT_MIN )return 0;
        return reversenum;
    }
};