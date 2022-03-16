class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, int i,int j,int r,int c){
        if(i<0||i>=r||j<0||j>=c||grid[i][j]==0){
            return;
        }
        grid[i][j]=0;
        dfs(grid,i+1,j,r,c);
        dfs(grid,i,j+1,r,c);
        dfs(grid,i-1,j,r,c);
        dfs(grid,i,j-1,r,c);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        
        for(int i=0;i<r;i++){
            if(grid[i][0] == 1){
                dfs(grid,i,0,r,c);
            }
            if(grid[i][c-1] == 1){
                dfs(grid,i,c-1,r,c);
            }
        }
        
        for(int i=0;i<c;i++){
            if(grid[0][i] == 1){
                dfs(grid,0,i,r,c);
            }
            if(grid[r-1][i] == 1){
                dfs(grid,r-1,i,r,c);
            }
        }
        
        int count = 0;
        for(auto i : grid){
            for(auto j : i){
                if(j == 1){
                    count++;
                }
            }
        }
        return count;
    }
};
