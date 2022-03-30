class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
       vector<vector<int>>ans(n,vector<int>(n,0));
        int sr=0,sc=0,er=n-1,ec=n-1;
        int value=1;
        while(sr<=er && sc<=ec && value<=n*n)
        {
        for(int i=sc;i<=ec;i++)
        {
            ans[sr][i]=value;
            value++;
        }
        sr++;
        for(int i=sr;i<=er;i++)
        {
            ans[i][ec]=value;
            value++;
        }
        ec--;
            if(sr<=er){
        for(int i=ec;i>=sc;i--)
        {
            ans[er][i]=value;
            value++;
        }
        er--;}
            if(sc<=ec){
        for(int i=er;i>=sr;i--)
        {
            ans[i][sc]=value;
            value++;
        }
        sc++;}
    }
        
    return ans;     
    }
};












// class Solution {
// public:
//     vector<vector<int>> generateMatrix(int n) 
//     {
//         int startrow=0;
//         int startcol=0;
//         int endrow=n-1;
//         int endcol=n-1;
//         int insert=1;
//         vector<vector<int>>v(n,vector<int>(n,0));
//         while(startrow<=endrow && startcol<=endcol && insert!=(n*n)+1)
//         {
//             for(int i=startcol;i<=endcol;i++)
//             {
//                 v[startrow][i]=insert;
//                 insert++;
//             }
//             startrow++;
//             for(int i=startrow;i<=endrow;i++)
//             {
//                 v[i][endcol]=insert;
//                 insert++;
//             }
//             endcol--;
//             if(endrow>=startrow)
//             {
//                 for(int i=endcol;i>=startcol;i--)
//                 {
//                     v[endrow][i]=insert;
//                     insert++;
//                 }
//                 endrow--;
//             }
//             if(endcol>=startcol)
//             {
//                 for(int i=endrow;i>=startrow;i--)
//                 {
//                     v[i][startcol]=insert;
//                     insert++;
//                 }
//                 startcol++;
//             }
//         }
//         return v;
//     }
// };