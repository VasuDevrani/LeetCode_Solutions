class Solution {
public:
    
    int countPrimes(int n) {
        bool arr[n+1]; 
    // marking all as true;
    for(int i=2;i<=n;i++)
    {
         arr[i]=true; 
    }

    // picking the primes in the black box;
    for(int i=2;i*i<=n;i++)
    {
        if(arr[i]!=false){
        for(int j=i*i;j<=n;j+=i)
        {
            arr[j]=false;
        }
        }
    }
        
//         counting numbers
        int ct=0;
        for(int i=2;i<n;i++)
        {
            if(arr[i]==true)
                ct++;
        }
        return ct;
    }
};