class Solution {
public:
    
    int gcd(int b,int a)
    {
        while(b%a!=0)
        {
            int r=b%a;
            b=a;
            a=r;
        }
        return a;
    }
    
    vector<string> simplifiedFractions(int n) {
        vector<string>ans;
        
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(gcd(j,i)!=1)
                    continue;
                string s = to_string(i) + "/" + to_string(j);
                // char str[3];
                // str[0]=(char)(i+'0');
                // str[1]='/';
                // str[2]=(char)(j+'0');
                ans.push_back(s);
            }
        }
        return ans;
    }
};