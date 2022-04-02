class Solution {
public:
    int brokenCalc(int s, int t) {
        int ct=0;
       if(s>=t)
       {
           while(s!=t)
           {
               s--;
               ct++;
           }
       } 
        else 
        {
            // while(s!=t)
            // {
            //     if(s*2>t){
            //         s--;
            //         ct++;
            //     }
            //     else if(s*2<=t)
            //     {
            //         s=s*2;
            //         ct++;
            //     }
            // }
            
            while(s<t)
            {
                if(t%2==0)
                {t/=2;
                 ct++;
                }
                else
                {t++;
                 ct++;
                }
            }
        }
        return ct+(s-t);
    }
};