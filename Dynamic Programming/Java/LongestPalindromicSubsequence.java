import java.util.* ;
import java.io.*; 
public class Solution {
	public static int longestPalindromeSubsequence(String s) {
		int len = s.length();
		int [][]dp = new int[len][len];

		for(int i=0;i<len;i++){
			dp[i][i] = 1;
		}

		for(int k=2; k<=len; k++){
			for(int i=0; i<len-k+1; i++){
				int j=i+k-1;

				if(s.charAt(i) == s.charAt(j)){
					if(k == 2) dp[i][j] = 2;
					else dp[i][j] = 2+dp[i+1][j-1]; 
				} else{
					dp[i][j] = Math.max(dp[i][j-1] , dp[i+1][j]);
				}
			}
		}
		return dp[0][len-1];
	}
}
