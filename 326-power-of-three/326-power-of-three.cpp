class Solution {
public:
    bool checkpower(long long i,int n)
    {
//         base case
        if(i==n)
            return true;
        if(i>n)
            return false;
        
//         recursive case
        bool ans=checkpower(i*3,n);
        return ans;
    }
    bool isPowerOfThree(int n) {
        if(n==1)
            return true;
     return checkpower(3,n);
    }
};