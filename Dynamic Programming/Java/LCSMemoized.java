import java.util.Arrays;

public class Solution {

	private static int lcsHelper(String s, String t, int m, int n, int[][] dp){
		if(m<0 || n<0) return 0;
		else if(dp[m][n] != -1){
			return dp[m][n];
		}
		
		else if(s.charAt(m) == t.charAt(n)){
			dp[m][n] = 1 + lcsHelper(s,t,m-1,n-1,dp);
		} else{
			dp[m][n] = Math.max(lcsHelper(s, t, m-1, n, dp), lcsHelper(s, t, m, n-1, dp));
		}

		return dp[m][n];
	}

	public static int lcs(String s, String t) {
		//Your code goes here
		int m = s.length();
		int n = t.length();

		int [][]dp = new int[m][n];

		for(int[] r: dp){
			Arrays.fill(r, -1);
		}

		lcsHelper(s, t, m-1, n-1, dp);
		return dp[m-1][n-1];

    }
}
