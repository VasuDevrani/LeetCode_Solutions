class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>index;
        stack<char>brackets;
        
        if(s.length()==1)
            return s;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='('){
                brackets.push(s[i]);
                index.push(i+1);
            }
            if(s[i]==')' && brackets.top()=='(')
            {
                int ind=i-1;
                reverse(s.begin() + index.top(), s.begin() + ind+1);
                index.pop();
                brackets.pop();
            }   
        }
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='(' && s[i]!=')')
                ans+=s[i];
        }
        
        return ans;
    }
};