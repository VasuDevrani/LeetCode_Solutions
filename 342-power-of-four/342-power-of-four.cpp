class Solution {
public:
    bool isPowerOfFour(int n) {
        // if(n<1)
        //     return false;
        // int ct=0;
        // int num=n;
        // while(num>1)
        // {
        //     num>>=2;
        //     ct+=2;
        // }
        // return ((num<<ct)==n);
         
//         ANOTHER METHOD
        
        return ((n>0) && ((n&(n-1))==0) && (n%3==1));
        
    }
};