class Solution {
public:
    string makeGood(string s) {
        stack<char>temp;
        
        for(int i=0;i<s.length();i++)
        {
            if(temp.empty())
                temp.push(s[i]);
            else if(s[i]+32==temp.top() || s[i]==temp.top()+32)
                temp.pop();
            else
                temp.push(s[i]);
        }
        string ans="";
        
        while(!temp.empty())
        {
            ans+=temp.top();
            temp.pop();
        }
        for (int i = 0; i < ans.length()/ 2; i++)
        swap(ans[i], ans[ans.length() - i - 1]);
        
        return ans;
    }
    
};