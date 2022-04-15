class Solution {
public:
    int hammingDistance(int i, int j) {
        long int d=0;
        while(i>0 || j>0)
        {
            if((i&1)!=(j&1))
                d++;
            i=i>>1;
            j=j>>1;
        }
        return d;
    }
};