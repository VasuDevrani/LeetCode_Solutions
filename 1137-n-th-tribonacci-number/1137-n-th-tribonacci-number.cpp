class Solution {
public:
    int tribonacci(int n) {
        if(n == 0 || n == 1)
            return n;
        else if(n == 2)
            return 1;
        
        long int a = 0, b = 1, c = 1;
        
        for(int i=3;i<=n;i++)
        {
            long int sum = a + b + c;
            a = b;
            b = c;
            c = sum;
        }
        
        return c;
    }
};