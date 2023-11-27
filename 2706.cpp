#include <bits/stdc++.h>
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min=INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            for(int j=i+1;j<prices.size();j++)
            {
                int min1=prices[i]+prices[j];
                if(min1<min)
                {
                    min=min1;
                }
            }
        }
        if(min<=money)
        {
            return money-min;
        }else{
            return money;
        }
    }
};