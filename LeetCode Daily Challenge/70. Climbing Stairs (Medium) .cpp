class Solution {

private:

    int climbDP(int n, vector<int> & dp){
        if(n <= 1) return 1;
        if(dp[n] != -1) return dp[n];

        return dp[n] = climbDP(n-1, dp) + climbDP(n-2, dp);
    }
public:

    int climbStairs(int n) {
        
         vector<int> dp(n+1, -1);    

        return climbDP(n,dp);
    }

};

//TC - O(N)
//SC - O(N)
