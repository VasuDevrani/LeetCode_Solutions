class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>index;
        stack<char>bracket;
        
        for(int i=s.length()-1;i>=0;i--)
        {
            if(bracket.empty() && (s[i]=='(' || s[i]==')') )
            {
                index.push(i);
                bracket.push(s[i]);
                continue;
            }
            if(s[i]==')')
            {
                index.push(i);
                bracket.push(s[i]);
                continue;
            }
            if(s[i]=='(' && bracket.top()==')')
            {
                index.pop();
                bracket.pop();
            }
            else if(s[i]=='(' && bracket.top()!=')')
            {
                index.push(i);
                bracket.push(s[i]);
            }
        }
        
        if(bracket.empty())
            return s;
        
        
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(index.empty())
                ans+=s[i];
            else{
            if(i==index.top())
            index.pop();
            else
                ans+=s[i];
            }
        }
        return ans;
        
    }
};