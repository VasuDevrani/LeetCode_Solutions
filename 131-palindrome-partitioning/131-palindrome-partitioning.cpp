class Solution {
public:
    
    bool is_palindrome(string s)
    {
        if(s.length()==1)
            return true;
        int mid=s.length()/2;
            int i=0,j=s.length()-1,c=0;
            while(i<mid)
            {
                if(s[i]!=s[j])
                    c++;
                i++;
                j--;
            }
            if(c>0)
                return false;
            else 
                return true;
    }
    
    
    void strings_seq(string s,vector<vector<string>>&ans,int i,vector<string>temp)
    {
//         base case
        if(i==s.length())
        {
            ans.push_back(temp);
            return;
        }
        if(i>s.length())
            return;
        
//         recursive case
//         taking multiple char
        string t="";
          for(int j=i;j<s.length();j++)
          {
              t=t+s[j];
              if(is_palindrome(t)){
                  temp.push_back(t);
              strings_seq(s,ans,j+1,temp);
                  temp.pop_back();
                  }
          }
        
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        strings_seq(s,ans,0,temp);
        return ans;
    }
};