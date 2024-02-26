public class Solution {
    public static int lcs(String s, String t){
        // Write your code here.
        int m,n;
        m = s.length();
        n = t.length();

        int [][]dp = new int[m+1][n+1];

        int maxSubstringLen = -1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(s.charAt(i) == t.charAt(j)){
                    dp[i+1][j+1] = 1 + dp[i][j];
                    maxSubstringLen = Math.max(maxSubstringLen, dp[i+1][j+1]);
                }
            }
        }

        return maxSubstringLen;
    }
}
