sclass Solution {
public:
    int totalMoney(int n) {
        int sum=0;
        int z=0;
        for(int i=1;i<=n;i)
        {
          
          int p = i/7;
          for(int j=1;j<=7;j++)
          {
              sum= sum+j+p;
            i++;
            z++;
            if(z==n) return sum;
          }
       
        }
      return sum;  
    }
};