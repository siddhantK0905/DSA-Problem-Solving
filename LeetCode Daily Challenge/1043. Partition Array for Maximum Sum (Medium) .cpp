#include<bits/stdc++.h>
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size()+1, -1);
        int ansSum = INT_MIN;
        return getSum(0, arr, k,dp);
    }

    int getSum(int index, vector<int> &arr, int k, vector<int> &dp){

        int n = arr.size();
        if(index == n){
            return 0;
        }

        if(dp[index] != -1) return dp[index];

        int maxi = INT_MIN;
        int maxSum = INT_MIN;
        int len = 0;
        for(int j=index; j < min(n, index+k); j++){

            len++;
            maxi = max(maxi , arr[j]);
            int sum = maxi * len + getSum(j+1, arr, k, dp);

            maxSum = max(maxSum, sum);
        }

        return dp[index] = maxSum;
    }
};
