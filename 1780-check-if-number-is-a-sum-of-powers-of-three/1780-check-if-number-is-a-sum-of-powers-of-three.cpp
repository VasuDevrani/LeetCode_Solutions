class Solution {
public:
    bool checkPowersOfThree(int n) {
        long long p=0;
        while(n>=1)
        {
            long long thm=1;
            while(1)  
            {
                thm*=3;
                if(thm>n)
                    break;
            }
            n=n-(thm/3);
            if(thm/3==p)
            {
                return false;
            }
            p=thm/3;
            if(n==0)
               return true;
            if(n<0)
                break;
        }
        return false;
    }
};