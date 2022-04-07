class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i=0;i<haystack.length();i++)
        {
            int j=0;
            int k=i;
            int ct=1;
            while(haystack[k]==needle[j] && k<haystack.length() && j<needle.length())
            {
                k++;
                j++;
                if(j==needle.length())
                    ct=0;
            }
            if(ct==0)
                return i;
        }
        return -1;
    }
};