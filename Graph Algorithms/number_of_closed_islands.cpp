class Solution {
public:
    
    void dfs(vector<vector<int>>& grid, int i,int j, int r,int c){
        if(i<0 || i>=r|| j <0 || j>=c || grid[i][j] == 1){
            return;
        }
        
        grid[i][j] = 1;
        dfs(grid,i+1,j,r,c);
        dfs(grid,i,j+1,r,c);
        dfs(grid,i-1,j,r,c);
        dfs(grid,i,j-1,r,c);
        
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int r = grid.size(),c = grid[0].size();
        
        // Boundary 0's => 1's(using dfs)
        for(int i = 0 ; i < r; i++){
            if(grid[i][0] == 0){
                dfs(grid,i,0,r,c);
            }
            
            if(grid[i][c-1] == 0){
                 dfs(grid,i,c-1,r,c);
            }
        }
        
        for(int i = 0 ; i < c; i++){
            if(grid[0][i] == 0){
                dfs(grid,0,i,r,c);
            }
            
            if(grid[r-1][i] == 0){
                 dfs(grid,r-1,i,r,c);
            }
        }
        
        int count = 0;
        for(int i=1;i<r-1;i++){
            for(int j=1;j<c-1;j++){
                if(grid[i][j] == 0){
                    count++;
                    dfs(grid,i,j,r,c);
                }
            }
        }
        return count;
    }
};
