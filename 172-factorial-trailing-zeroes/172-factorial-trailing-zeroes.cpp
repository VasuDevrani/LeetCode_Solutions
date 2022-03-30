class Solution {
public:
    
    int trailingZeroes(int n) {
       int count = 0;
        int k = 5;
        while(n/k != 0){
            count += n/k;
            k = k*5;
        }
        return count;
    
    
    

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
//     TLE solution
//     int checkten(int n)
//     {
//         int res=0;
//         while(n!=1)
//         {
//             n=n/10;
//             res++;
//         }
//         return res;
//     }
    
//     int checkfive(int n)
//     {
//         int res=0;
//         while(n!=1)
//         {
//             n=n/5;
//             res++;
//         }
//         return res;
//     }
    
//     int trailingZeroes(int n) {
//         if(n==0)
//             return 0;
//         int ct=0;
//         for(int i=1;i<=n;i++)
//         {
//             if(i%10==0)
//                 ct+=checkten(i);
//             if(i%5==0 && i%10!=0)
//                 ct+=checkfive(i);
//         }
//         return ct;
        
        
        
        
        
        
        
          
        
        
//       Int overflow error  
        // long long p=1;
        // for(int i=1;i<=n;i++)
        // {
        //     if(i%5==0)
        //         p=p*i;
        //     else if(i%2==0)
        //         p=p*i;
        // }
        // int last=0;
        // int ct=0;
        // while(last!=0)
        // {
        //     if(p%10==0)
        //         ct++;
        //     last=p%10;
        //     p=p/10;
        // }
        // return ct;
    }
};