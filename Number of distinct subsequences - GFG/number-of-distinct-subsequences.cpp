//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s) {
    int n = s.size();

    // Create a DP array to store the count of distinct subsequences.
    vector<long long> dp(n + 1, 0);

    // Initialize dp[0] to 1, as there is one empty subsequence.
    dp[0] = 1;

    // Create a map to store the last index where each character appeared.
    unordered_map<char, int> lastSeen;

    for (int i = 1; i <= n; i++) {
        dp[i] = (2 * dp[i - 1]) % 1000000007;

        // If the current character has appeared before, subtract the count of
        // subsequences that end with its last occurrence.
        if (lastSeen.find(s[i - 1]) != lastSeen.end()) {
            dp[i] -= dp[lastSeen[s[i - 1]] - 1];
        }

        // Update the last index of the current character.
        lastSeen[s[i - 1]] = i;
        
        // Ensure that dp[i] is non-negative.
        dp[i] = (dp[i] + 1000000007) % 1000000007;
    }

    // Subtract 1 to exclude the empty subsequence.
    return static_cast<int>(dp[n] - 1)+1;
}

};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends