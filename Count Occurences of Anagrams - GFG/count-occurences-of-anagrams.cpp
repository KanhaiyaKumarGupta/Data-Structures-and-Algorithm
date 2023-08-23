//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	int k = pat.size();
    int n = txt.size();
    
    int i = 0;
    int j = 0;
    int cnt = 0;
    vector<int> a1(26,0);
    for(auto it : pat)
    {
        a1[it-'a']++;
    }
    vector<int> a2(26,0);
    
    while (j < n) {
        
        
       a2[txt[j]-'a']++;
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k) 
        {
           
           bool swapped = true;
           for(int k = 0;k<26;k++)
           {
               if(a1[k]!=a2[k])
               {
                   swapped = false;
                   break;
               }
               else
               {
                   continue;
               }
           }
           if(swapped==true)
           {
               cnt++;
           }
           a2[txt[i]-'a']--;
            i++;
            j++;
        }
    }
    return cnt;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends