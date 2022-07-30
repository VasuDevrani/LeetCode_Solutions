class Solution {
public:
//     dfs solution
    
    void fillColor(vector<vector<int>>& image, int sr, int sc, int color, int pre_color, int n, int m)
    {
        if(sr >= 0 && sc >= 0 && sr < n && sc < m && image[sr][sc] == pre_color)
        {
            image[sr][sc] = color;
            fillColor(image, sr-1, sc, color, pre_color, n, m);
            fillColor(image, sr+1, sc, color, pre_color, n, m);
            fillColor(image, sr, sc-1, color, pre_color, n, m);
            fillColor(image, sr, sc+1, color, pre_color, n, m);
        }
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color)
            return image;
        
        int pre_color = image[sr][sc];
        
        int n = image.size(), m = image[0].size();
        
        fillColor(image, sr, sc, color, pre_color, n, m);
        
        return image;
    }
};