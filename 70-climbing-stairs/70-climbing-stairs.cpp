class Solution {
public:
    int climbStairs(int n) {
        // if(n==0)
        // {
        //     int c=1;
        //     return c;
        // }
        // if(n<0)
        // {
        //     return 0;
        // }
        // int x=climbStairs(n-2);
        // int y=climbStairs(n-1);
        // return x+y;
        int p1=1,p2=1;
        for(int i=2;i<=n;i++){
            int t = p2;
            p2=p1+p2;
            p1=t;
        }
        return p2;
    
    }
};