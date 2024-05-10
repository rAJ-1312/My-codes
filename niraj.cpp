#include <iostream>
#include <vector>
#include <climits>
#include <typeinfo>
#include <algorithm>
#include <cstring>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int MOD = 1e9 + 7;




int baseFiveNum(string s){
    int ans = 0;
    int p = 1;

    for(int i=s.size()-1;i>=0;i--){
        int digit = s[i] - 'A' + 1;
        ans = ans + p*digit;
        p *= 5;
    }

    return ans;
}


int stringtonumber(string s){
    
    int num = 0;

    int p = 1;

    for(int i=s.size()-1;i>=0;i--){
        int digit = s[i] - '0' ;
        num = num + p * digit;
        p *= 10;
    }

    return num;

}

int reverseNumber(string s){
    int num = stringtonumber(s);

    int rev = 0;

    while(num>0){
        int r = num%10;
        rev = rev*10 + r;
        num/=10;
    }

    return rev;
}


void helper(vector<int>& v, int n){
    if(v[n-1]<9){
        v[n-1]++;
        return ;
    }

    int sum = 0;
    int carry = 1;

    int c = n;

    int i = n-1;

    while(c--){
        if(v[i]+carry>9){
            v[i] = 0;
            carry = 1;
        }else{
            v[i]++;
            carry = 0;
            break;
        }
        i--;
    }

    if(carry){
        v.insert(v.begin(), carry);
    }

    return;

}



vector<int> prodDelivery (vector<int> orderID){


    vector<int> ans;

    int sum;

    int n = orderID.size();

    for(int i=0;i<n;i++){
        int temp = orderID[i];

        sum = 0;

        while(temp>0){
            sum += temp%10;
            temp/=10;
        }

        ans.push_back(sum);
    }


    return ans;


}


vector<int> funcBouquet(vector<int> flowerStem, int random){
    vector<int> answer = flowerStem;

    sort(answer.begin(), answer.begin()+random);
    sort(answer.begin()+random, answer.end());

    reverse(answer.begin()+random, answer.end());


    return answer;
}



vector<int> arrangeZero(vector<int> v, int n){


    int idx = 0;

    for(int i=0;i<n;i++){
        if(v[i]!=0){
            swap(v[i], v[idx]);
            idx++;
        }
    }

    return v;
}


int trap(vector<int> &v, int n){
    int left = 0, right = n-1;
    int leftMax = 0, rightMax = 0;
    int ans = 0;

    while(left<=right){
        if(v[left]<=v[right]){
            if(v[left]>leftMax) leftMax = v[left];
            else ans += leftMax - v[left];
            left++;
        }else{
            if(v[right]>rightMax) rightMax = v[right];
            else ans += rightMax - v[right];
            right--;
        }
    }

    return ans;
}


int base26(string s){
    int ans = 0;

    int p = 1;

    for(int i=s.length()-1;i>=0;i--){
        int x = s[i] - 64;
        ans += p*x;
        p *= 26;
    }

    return ans;
}

string LPsubstring(string s){
    int n = s.length();

    if(s=="") return "";

    vector<vector<bool>> dp(n, vector<bool> (n, false));

    for(int i=0;i<n;i++){
        dp[i][i] = true;
    }

    int start = 0;
    int maxLength = 1;

    // Check for palindromes of length 2
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1; // Ending index of current substring

            // Check if the current substring is a palindrome and the characters at the ends match
            if (dp[i + 1][j - 1] && s[i] == s[j]) {
                dp[i][j] = true;
                if (len > maxLength) {
                    start = i;
                    maxLength = len;
                }
            }
        }

    }

    return s.substr(start, maxLength);


}



int start = 0;
int maxlength = 0;


void expandpalindrome(string s, int n, int left, int right){
    while(left>=0 && right<n && s[left]==s[right]){
        left--;
        right++;
    }

    if(maxlength<right-left-1){
        maxlength = right - left - 1;
        start = left + 1;
    }

    return ;
}




int countGoodSubsequences(const string& s) {
    unordered_map<char, int> count_dict;
    int total_count = 0;

    for (char ch : s) {
        // Update the count for the current character
        count_dict[ch] = (total_count + 1) % MOD;

        // Update the total count by doubling it and adding 1
        total_count = (total_count * 2 + 1) % MOD;
    }

    // Return the total count of good subsequences
    return total_count;
}






int main() {
    int t;
    cin>>t;

    while(t--){
        // int n;
        // cin>>n;

        // vector<int> v(n);

        // for(int i=0;i<n;i++){
        //     cin>>v[i];
        // }

        // cout << trap(v, n) << endl;

        // string s;
        // cin>>s;

        // cout << base26(s) << endl;

        string s;
        cin>>s;

        // int n = s.length();

        // if(n<2) cout << s;

        // for(int i=0;i<n;i++){
        //     expandpalindrome(s, n, i, i);
        //     expandpalindrome(s, n, i, i+1);
        // }

        // cout << start << endl;
        // cout << maxlength << endl;

        // string ans = s.substr(start, start+maxlength);

        // cout << ans << endl;

        cout << countGoodSubsequences(s) << endl;

    }
    
    return 0;
}





