#include <bits/stdc++.h>
typedef long long ll;  // typedef data_type str --- data_type will be read as str
typedef unsigned long long ull; //typedef ends with a semicolon :/
#define pb push_back // #define short longstr --- short will be read as longstr
#define eb emplace_back //Faster && Doesn't Copy
#define fastread() ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0)
#define SIZE 26
#define INF 1000000000
 
const int M = 1e9 + 7;
 
using namespace std;




string base26(int num){
	if (num <= 0) {
        return "";
    }

    string result = "";

    while (num > 0) {
        int remainder = (num - 1) % 26; // Map 1-26 to A-Z
        char digit = 'A' + remainder;
        result = digit + result;
        num = (num - 1) / 26;
    }

    // while (num > 0) {
    //     int remainder = (num % 27); // Map 1-26 to A-Z
    //     char digit = 64 + remainder;
    //     result = digit + result;
    //     num = num / 26;
    // }

    return result;

}





int findmid(int n){
	string s = to_string(n);

	int t = s.size();

	t = (t+1)/2;

	int mid = -1;

	while(t--){
		mid = n%10;
		n/=10;
	}

	return mid;
}




bool comp(const int& a, const int& b){
	int mida = findmid(a);
	int midb = findmid(b);

	if(mida!=midb){
		return mida < midb;
	}else{
		return a < b;
	}
}


bool autobiographical(int n){
	string s = to_string(n);

	unordered_map<int, int> m1;
	unordered_map<int,int> m2;

	for(int i=0;i<s.size();i++){
		if(s[i]-'0' != 0)
			m1[i] = s[i]-'0';
	}

	for(int i=0;i<s.size();i++){
		m2[s[i]-'0']++;
	}

	// for(auto &p : m1){
	// 	cout << p.first  << " " << p.second << endl;
	// }

	// cout << endl;

	// for(auto &p : m2){
	// 	cout << p.first  << " " << p.second << endl;
	// }


	if(m1==m2) return true;

	return false;

}


int amazonaws(vector<int>& v, int n){
	unordered_map<int,int> m;

    for(int i=0;i<n;i++){
    	if(m.find(v[i])==m.end()){
    		m[v[i]] = -1;
    	}
    }

    int ans = 0;

    for(int i=0;i<n;i++){

    	if(m[v[i]]==-1) {
    		ans+=v[i];
    		int curr = v[i];
	    	int new_val = ceil(v[i]*1.0/2);

	    	m[curr] = new_val;

	    	// cout << m[curr] << " " << new_val << endl;
    	}
	    else{
    		ans += m[v[i]];

    		// cout << v[i] <<  " " << m[v[i]] << endl;
	    }
    }

   
    return ans;
}



string longestPalindromicSubstring(const string &s) {
    int n = s.length();
    if (n == 0) {
        return "";
    }

    bool dp[n][n] = {{false}};

    int start = 0;
    int maxLength = 1;

    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for (int length = 3; length <= n; ++length) {
        for (int i = 0; i < n - length + 1; ++i) {
            int j = i + length - 1;
            if (dp[i + 1][j - 1] && s[i] == s[j]) {
                dp[i][j] = true;
                if (length > maxLength) {
                    start = i;
                    maxLength = length;
                }
            }
        }
    }

    return s.substr(start, maxLength);
}

int i=1;

int lcs(string s1, string s2, int idx1, int idx2, vector<vector<int>> &dp){

	cout << "Call " << i << endl;
	i++;

	if(idx1<0 || idx2<0) return 0;

	if(dp[idx1][idx2]!= -1 ) return dp[idx1][idx2];

	if(s1[idx1]==s2[idx2]){
		return dp[idx1][idx2]=1 + lcs(s1, s2, idx1-1, idx2-1,dp);
	}

	return dp[idx1][idx2] = max(lcs(s1,s2,idx1-1,idx2,dp), lcs(s1,s2,idx1,idx2-1,dp));
}



int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        int ans = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(S1[i-1]==S2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    ans = max(ans, dp[i][j]);
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return ans;
    }







int main(){
 
    fastread();
    cin.tie(NULL);
 
    // freopen("_____________", "r", stdin);
    // freopen("_____________", "w", stdout);
    

    int t;
    cin>>t;

    while(t--){
    	
    	string s1,s2;
    	cin>>s1 >>s2;

    	int n1 = s1.length();
    	int n2 = s2.length();

    	vector<vector<int>> dp( n1 , vector<int> (n2, -1)); 

    	cout << lcs(s1, s2, n1-1, n2-1, dp);



	}


    return 0;

}

