class Solution {
public:
    
    void dfs(vector<vector<int>> &grid, int sr, int sc, int r, int c, int &local_area){
        if(sr>=0&&sr<r&&sc>=0&&sc<c&&grid[sr][sc] == 1){
            local_area++;
            grid[sr][sc]=0;
            
            dfs(grid,sr+1,sc,r,c,local_area);
            dfs(grid,sr,sc+1,r,c,local_area);
            dfs(grid,sr-1,sc,r,c,local_area);
            dfs(grid,sr,sc-1,r,c,local_area);
        }
        
        else
            return;
        
        
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int max_area=0,local_area;
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 1){
                    local_area=0;
                    dfs(grid,i,j,r,c,local_area);
                    if(local_area>max_area){
                        max_area=local_area;
                    }
                }
            }
        }
        return max_area;
    }
};
