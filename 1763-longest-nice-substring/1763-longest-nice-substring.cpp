class Solution {
public:
    
    bool isNice(string str)
    {
        unordered_map<char,int>m;
        
        for(auto i:str)
            m[i]++;
        for(auto i:str)
        {
            if(i>64 && i<91)
            {
                if(m[i+32]==0)
                    return false;
            }
            else{
            if(m[i-32]==0)
                return false;
            }
        }
        
        return true;
    }
    
    string longestNiceSubstring(string s) {
        string max;
        int max_length=0;
        for(int i=0;i<s.length();i++)
        {
            for(int j=i+1;j<s.length();j++)
            {
                string str = s.substr(i,j-i+1);
                // if(str=="aAa")
                //     cout<<123<<endl;
                if(isNice(str))
                {
                    if(str.length()>max_length){
                        max_length=str.length();
                        max=str;
                    }
                    
                    cout<<str<<endl;
                }
            }
        }
        
        return max;
    }
};