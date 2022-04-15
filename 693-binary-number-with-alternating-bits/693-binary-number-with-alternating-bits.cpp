class Solution {
public:
    bool hasAlternatingBits(int n) {
        long int copn=n>>1;
        while(n>0)
        {
            if((n&1)==(copn&1))
                return false;
            n=n>>1;
            copn=copn>>1;
        }
        return true;
    }
};