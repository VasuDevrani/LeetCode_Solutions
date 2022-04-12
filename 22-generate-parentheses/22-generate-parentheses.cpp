class Solution {
public:
    
    vector<string>ans;
    
    void brackets(int n,int i,int j,string s)
    {
//         base
        if(i>n && j!=n)
            return;
        else if(j>n && i!=n)
            return;
        else if(i>n-1 && j>n-1)
        {
            ans.push_back(s);
            return;
        }
        
        
//        recursive
        brackets(n,i+1,j,s+'(');
        if(j<i)
            brackets(n,i,j+1,s+')');
        
    }
    
    
    vector<string> generateParenthesis(int n) {
      brackets(n,0,0,""); 
        
        return ans;
        
    }
};