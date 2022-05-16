class Solution {
public:
    int subtractProductAndSum(int n)
    {
        int m=1,sum=0,r;
        while(n!=0)
        {
            r=n%10;
            n=n/10;
            m=m*r;
            sum+=r;
        }
        return (m-sum);
    }
};