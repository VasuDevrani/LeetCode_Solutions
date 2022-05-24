class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int>perm(n);
        vector<int>dup(n);
        
        for(int i=0;i<n;i++)
        {
            perm[i]=i;
            dup[i]=i;
        }
        
        int ct=0;
        while(1)
        {
            vector<int>temp(n);
            ct++;
            for(int i=0;i<n;i++)
            {
                if(i%2==0)
                {
                    temp[i]=perm[i/2];
                }
                else
                    temp[i]=perm[n/2+(i-1)/2];
            }
            if(temp==dup)
                return ct;
            else
                perm=temp;
        }
        
    }
};