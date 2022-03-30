class Solution {
public:
    bool isPalindrome(int x) {
            if(x<0)
            return false;
        long long int rev=0;
        long long int c=x;
        while(x!=0)
        {
            rev=rev*10+(x%10);
            x/=10;
        }
        cout<<rev;
        if(rev==c)
            return true;
        else
            return false;
    }
};