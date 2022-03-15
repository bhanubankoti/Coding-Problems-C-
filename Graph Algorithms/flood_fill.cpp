class Solution {
public:
    
    
    void flood_fill(vector<vector<int>> &img , int x , int y , int sc ,int nc)
    {
        if(x < 0 || x >= img.size() || y < 0 || y >= img[0].size() || img[x][y] == nc )
            return ;
        else if(img[x][y] == sc)
        {
        img[x][y] = nc;
        flood_fill(img , x-1,y,sc,nc);
        flood_fill(img , x+1,y,sc,nc);
        flood_fill(img , x,y-1,sc,nc);
        flood_fill(img , x,y+1,sc,nc);
        }
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int source_color = image[sr][sc];
        flood_fill(image , sr,sc ,source_color, newColor);
        return image;
    }
};
