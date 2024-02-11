class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
       int r = grid.size();
       int c = grid[0].size();

        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
       return solve(grid, 0, 0, c-1, r, c, dp ); 
    }

    int solve(vector<vector<int>>& grid, int i, int j1, int j2, int r, int c, vector<vector<vector<int>>>& dp){
        
        if(j1 < 0 || j2 < 0 || j1 > c-1 || j2 > c-1){
            return -1e8;
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        //base case
        if(i == r-1){
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        int maxi = -1e8;
        for(int m=-1; m<=1; m++){
            for(int n= -1; n <=1; n++){
                int value =0;
                if(j1 == j2) value = grid[i][j1];
                else
                    value = grid[i][j1] + grid[i][j2];

                value += solve(grid, i+1, j1+m, j2+n, r, c, dp );
                maxi = max(maxi, value);
            }
        }

        dp[i][j1][j2] = maxi;
        return maxi;


    }
};

//TC - O (R * C * C) * 9
//SC - O (R * C * C)
