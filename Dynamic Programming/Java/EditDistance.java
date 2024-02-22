// https://leetcode.com/problems/edit-distance/

class Solution {
    
    private int editDistance(String word1, String word2, int m, int n, int[][] dp){
        if(m<0 && n<0) return 0;
        else if(m>=0 && n<0) return m+1; // insert
        else if(n>=0 && m<0) return n+1; // delete
        else if(dp[m][n] != - 1){
            return dp[m][n];
        }

        else if(word1.charAt(m) == word2.charAt(n)){
            dp[m][n] = editDistance(word1, word2, m-1, n-1, dp);
        } else{
            dp[m][n] = 1+Math.min(editDistance(word1, word2, m-1, n-1, dp), //update
            Math.min(editDistance(word1, word2, m, n-1, dp), // insert
            editDistance(word1, word2, m-1, n, dp))); // delete
        }

        return dp[m][n];
    }
    
    public int minDistance(String word1, String word2) {
        int m, n;
        m = word1.length();
        n = word2.length();
        if(m == 0) return n;
        if(n == 0) return m;
        int[][] dp = new int[m][n];
        for(int[] r: dp){
            Arrays.fill(r,-1);
        }
        
        editDistance(word1, word2, m-1, n-1, dp);
        
        return dp[m-1][n-1];
    }
}
