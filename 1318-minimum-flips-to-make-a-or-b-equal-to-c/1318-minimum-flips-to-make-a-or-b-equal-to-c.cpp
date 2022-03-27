class Solution {
public:
    int minFlips(int a, int b, int c) {
        long int ans=0;
        int ct=0;
        if((int)(a|b)==c)
        {
            return 0;
        }
         while(c>0)
         {
             if((int)(c&1)==1)
             {
                 if((int)(a&1)!=1 && (int)(b&1)!=1)
                 ans++;
             }
             else
             {
                 if((int)(a&1)!=0)
                 {
                     ans++;
                 }
                 if((int)(b&1)!=0)
                     ans++;
             }
             a=a>>1;
             b=b>>1;
             c=c>>1;
             ct++;
         }
// //         creating mask;
//         int mask=(~0)<<(8-ct);
        
//        if()
        
        while(a!=0)
        {
            if((a&1)==1)
                ans++;
            a=a>>1;
        }
        while(b!=0)
        {
            if((b&1)==1)
                ans++;
            b=b>>1;
        }
        return ans;
    }
};