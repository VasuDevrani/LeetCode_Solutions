class Solution {
public:
    int findComplement(int num) 
    {
        vector<int>v;
        while(num>0)
        {
            int last_bit=(num&1);
            if(last_bit==1)
            {
                v.push_back(0);
            }else
                v.push_back(1);
            num=num>>1;
        }
        long long int mult=1,ans=0;
        for(int i=0;i<v.size();i++)
        {
            ans=ans+mult*v[i];
            mult=mult*2;
        }
        return ans;
    }
};