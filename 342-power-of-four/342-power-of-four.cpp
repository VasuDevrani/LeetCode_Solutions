class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1)
            return false;
        int ct=0;
        int num=n;
        while(num>1)
        {
            num>>=2;
            ct+=2;
        }
        return ((num<<ct)==n);
    }
};