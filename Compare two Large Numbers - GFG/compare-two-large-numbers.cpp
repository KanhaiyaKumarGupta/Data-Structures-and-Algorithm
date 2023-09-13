//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int check(string a,string b);
int main(){
    int t;
    cin>>t;
    while(t--)
    {
       string a, b;
    cin >> a >> b;
    cout<<check(a,b)<<'\n';


    }

    return 0;
}

// } Driver Code Ends


int check(string a, string b) {
    int i = 0;
    if (a[i] == '0') {
        while (a[i] == '0') {
            i++;
        }
        
        string s_a = ""; // Rename to s_a to avoid naming conflict
        for (int k = i; k < a.size(); k++) {
            s_a += a[k]; // Use a[k] instead of a[i]
        }
        a = s_a;
    }
    
    int j = 0; // Use a separate variable for position in b
    if (b[j] == '0') {
        while (b[j] == '0') {
            j++;
        }
        
        string s_b = ""; // Rename to s_b to avoid naming conflict
        for (int k = j; k < b.size(); k++) {
            s_b += b[k]; // Use b[k] instead of b[j]
        }
        b= s_b;
    }

    int n1 = a.size();
    int n2 = b.size();

    if (n1 > n2) {
        return 2;
    } else if (n2 > n1) {
        return 1;
    } else {
        for (int i = 0; i < n1; i++) {
            if (a[i] > b[i]) {
                return 2;
            } else if (a[i] < b[i]) {
                return 1;
            }
        }
    }
    return 3;
}
