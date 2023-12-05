class Solution {
public:
    int numberOfMatches(int n) {
        int total=0;
       while(n!=1)
       {
            if(n%2==0)
        {
            int c=n/2;
            n=n/2;
            total=total+c;
        }
        if(n%2==1)
        {
            int c=n/2;
            n=(n/2)+1;
            total=total+c;
        }
       }
        return total;
    }
};