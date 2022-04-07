class Solution {
public:
    
//     using two pointer
     int maxArea(vector<int>& height)
    {
        int ans=INT_MIN;
        int i=0,j=height.size()-1;
        while(i<j)
        {
            int current=min(height[i],height[j])*(j-i);
            ans=max(ans,current);
            if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return ans;
    }
         
//     using double for loop
    
//         int ans_l=INT_MIN;
//         int left,area,right;
        
//         int n=height.size();
//         for(int i=n-1;i>=0;i--)
//         {
//             for(int j=i-1;j>=0;j--)
//             {
//                 if(height[i]<=height[j])
//                 {
//                     left=j;
//                     area=(i-j)*height[i];
                    
//                     if(area>ans_l)
//                         ans_l=area;
//                 }
//             }
//         }
        
//         int ans_r=INT_MIN;
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 if(height[i]<=height[j])
//                 {
//                     right=j;
//                     area=(j-i)*height[i];
                    
//                     if(area>ans_r)
//                         ans_r=area;
//                 }
//             }
//         }
        
//         if(ans_l>ans_r)
//             return ans_l;
//         else 
//             return ans_r; 
//     }
        
        
};