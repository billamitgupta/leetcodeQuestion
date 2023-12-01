class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.length();i++)
        {
            int count=0;
            for(int j=0;j<needle.length();j++)
            {
                
                if(haystack[j+i]==needle[j])
                {
                    count=count+1;
                }else break;
            }
        if(count==needle.length())
        {
            return i;
        }
        }
        return -1;
    }
};