class Solution {
public:
    
    int getAns(int n){
        int a = 0, b = 1;
        
        for(int i=2;i<=n;i++)
        {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
    
    int fib(int n) {
        if(n <= 0)
            return 0;
        if(n == 1)
            return 1;
        
//         return fib(n-1) + fib(n-2);
        
        return getAns(n);
    }
};