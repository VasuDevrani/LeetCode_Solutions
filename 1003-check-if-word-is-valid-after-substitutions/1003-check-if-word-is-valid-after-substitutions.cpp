class Solution {
public:
    bool isValid(string s) {
        stack<char>temp;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='a' || s[i]=='b')
                temp.push(s[i]);
            else if(s[i]=='c')
            {
                if(temp.empty())
                    return false;
               if(temp.top()=='b')
               {
                   temp.pop();
                   if(temp.empty())
                       return false;
                   if(temp.top()=='a')
                       temp.pop();
                   else
                       return false;
               }
                else if(temp.top()=='a')
                    return false;
            }
        }
        if(temp.empty())
            return true;
        else
            return false;
    }
};