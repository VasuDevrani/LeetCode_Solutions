class Solution {
public:
    
    bool isGood(string s)
    {
        cout<<s<<" ";
        sort(s.begin(),s.end());
        
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]==s[i+1])
                return false;
        }
        return true;
    }
    
    int countGoodSubstrings(string s) {
        int ct=0;
        
        if(s.length()==1 || s.length()==2)
            return 0;
        
        for(int i=0;i<s.length()-2;i++)
        {
            string s1="";
            s1+=s[i];
            for(int j=i+1;j<i+3;j++)
            {
                s1+=s[j];
            }
            if(isGood(s1))
                ct++;
        }
        return ct;
    }
};