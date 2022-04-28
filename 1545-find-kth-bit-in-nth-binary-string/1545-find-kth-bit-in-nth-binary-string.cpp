class Solution {
public:
    
    char solution(int n,int k,string s)
    {
//         base case
        if(n==1)
        {
            return s[k-1];
        }
        
//         recursive case
        string temp="";
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='0')
                temp+='1';
            else
                temp+='0';
        }
        char ans=solution(n-1,k,s+"1"+temp);
        return ans;
    }
    
    char findKthBit(int n, int k) {
         return solution(n,k,"0");
    }
};