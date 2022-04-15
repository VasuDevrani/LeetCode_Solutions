class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1;
        stack<char>s2;
        
        if(s.length()==0 || t.length()==0)
            return false;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='#' && !s1.empty())
                s1.pop();
            else if(s[i]!='#')
                s1.push(s[i]);
        }
        for(int i=0;i<t.length();i++)
        {
            if(t[i]=='#' && !s2.empty())
                s2.pop();
            else if(t[i]!='#')
                s2.push(t[i]);
        }
        
        s="";
        t="";
        
        while(!s1.empty())
        {
          
            s+=s1.top();
            s1.pop();
        }
        while(!s2.empty())
        {
            t+=s2.top();
            s2.pop();
        }
        cout<<s<<" "<<t<<endl;
        if(s!=t)
            return false;
        return true;
    }
};









