class Solution {
public:
    bool checkPerfectNumber(int num) {
        
        vector<int> nums = {6, 28, 496, 8128, 33550336};
        for(int i=0;i<nums.size();i++){
            if(num==nums[i]){
                return true;
            }
        }
        return false;    
		}
        

//         This solution is correct but gives TLE as per question
       // long long sum=0;
       //  for(long long i=1;i<=num/2;i++)
       //  {
       //      if(num%i==0)
       //          sum+=i;
       //  }
       //  if(sum==num)
       //      return true;
       //  else 
       //      return false;
    
};