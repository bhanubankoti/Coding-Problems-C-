//https://www.codingninjas.com/studio/problems/wildcard-pattern-matching_701650?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=PROBLEM

public class Solution {
  
	private static boolean checkForStars(String s1, int m){
		for(int i=0;i<=m;i++){
			if(s1.charAt(i) != '*') return false;
		}
		return true;
	}
	private static boolean match(String s1, String s2, int m, int n, boolean[][] dp){
		if(m<0 && n<0) return true;
		else if(m<0 && n>=0) return false;
		else if(m>=0 && n<0){
			return checkForStars( s1, m);
		}

		else if(s1.charAt(m) == s2.charAt(n) || s1.charAt(m) == '?'){
			dp[m][n] = match(s1,s2,m-1,n-1,dp);
		} else if(s1.charAt(m) == '*'){
			dp[m][n] = match(s1,s2,m-1,n,dp) || match(s1, s2, m, n-1, dp); 
		}

		return dp[m][n];
	}
	public static boolean wildcardMatching(String pattern, String text) {
		int m = pattern.length();
		int n = text.length();

		boolean dp[][] = new boolean[m][n];
		match(pattern, text, m-1,n-1,dp);

		return dp[m-1][n-1];	

	}
}
