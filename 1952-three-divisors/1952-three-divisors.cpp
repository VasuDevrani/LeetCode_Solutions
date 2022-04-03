class Solution {
public:
    bool isThree(int n) {
        if(n==1)
            return false;
        
//         check prime
        int ct=0;
        for(int i=2;i<=n;i++)
        {
            if(n%i==0)
            {
                ct++;
            }
        }
        if(ct==2)
            return true;
        else 
            return false;
    }
};