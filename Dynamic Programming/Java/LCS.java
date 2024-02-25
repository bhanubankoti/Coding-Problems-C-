// Tabulation

public class Solution {
  
	public static int lcs(String s, String t) {
		int m = s.length();
		int n = t.length();

		int [][]dp = new int[m+1][n+1];
    
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(s.charAt(i) == t.charAt(j)){
					dp[i+1][j+1] = 1 + dp[i][j];
				} else{
					dp[i+1][j+1] = Math.max(dp[i+1][j], dp[i][j+1]);
				}
			}
		}

		return dp[m][n];

    }
}
