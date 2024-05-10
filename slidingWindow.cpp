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


//---------------------Fixed Size Sliding window--------------------------


    //************************FORMAT*****************************



// int i=0,j=0;
// while(j<n){
//     calculation;

//     if(j-i+1<k){             //Less than window size k
//         j++;
//     }else if(j-i+1==k){      //when hit the window size k
//         update answer;
//         maintain window size;

//         i++;
//         j++;
//     }
// }

// return answer;




//Q.1 Maximum sum of subarray of size k.



int maxSubarraySum(vector<int>& v, int n, int k){

    int sum = 0;
    int ans = -1;

    int i=0,j=0;

    while(j<n){

        sum+=v[j];

        if(j-i+1<k){
            j++;
        }else if(j-i+1==k){
            ans = max(ans, sum);
            sum -= v[i];
            i++;
            j++;
        }

        //Also correct

        // if(j-i+1==k){
        //     ans = max(ans, sum);
        //     sum -= v[i];
        //     i++;
        // }

        // j++;
    }

    return ans;
}


//Q.2 Find first negative number in every window of size k,



vector<int> firstNegative(vector<int>& v, int n, int k){
    vector<int> ans;
    deque<int> dq;

    int i=0,j=0;

    while(j<n){

        if(v[j]<0){
            dq.push_back(v[j]);
        }

        if(j-i+1<k){
            j++;
        }else if(j-i+1==k){
            if(dq.empty()){
                ans.push_back(0);
            }else{
                ans.push_back(dq.front());
            }

            if(v[i]==dq.front()){
                dq.pop_front();
            }
            i++;
            j++;
        }
    }

    return ans;
}


//Q.3 Count the number of anagrams.



int countAnagram(string s, string temp){

    map<char, int> m;

    for(int i=0;i<temp.length();i++){
        m[temp[i]]++;
    }

    int count = m.size();

    int i=0,j=0;

    int ans = 0;
    int n = s.length();
    int k = temp.length();

    while(j<n){

        if(m.find(s[j])!=m.end()){
            m[s[j]]--;
            if(m[s[j]]==0){
                count--;
            }
        }

        if(j-i+1<k){
            j++;
        }else if(j-i+1==k){
            if(count==0) ans++;

            if(m.find(s[i])!=m.end()){
                if(m[s[i]]==0){
                    count++;
                }
                m[s[i]]++;
            }
            i++;
            j++;
        }

    }

    return ans;

}


//Q.4 Find maximum of each subarray of size k.


vector<int> maxEachSubarray(vector<int>& v, int n, int k){
    vector<int> ans;
    deque<int> dq;

    int i=0,j=0;


    while(j<n){

        while(!dq.empty() && dq.back()<v[j]){
            dq.pop_back();
        }

        dq.push_back(v[j]);

        if(j-i+1<k){
            j++;
        }else if(j-i+1==k){
            ans.push_back(dq.front());

            if(v[i]==dq.front()){
                dq.pop_front();
            }

            i++;
            j++;
        }

    }

    return ans;
}


//----------------------Variable size Sliding Window---------------------------//

        //************************FORMAT*****************************



// int i=0,j=0;
// int var;

// while(j<n){
//     calculation;

//     if(var<cond){             //Less than given condition 
//         j++;
//     }else if(var==cond){      //when satisfies the condition
//         update answer;
//         j++;
//     }else{
//         while(var>cond && i<j){
//             decrease from start;
//             i++;
//         } 
//         j++;
//     }
// }

// return answer;
    




//Q.5 Find the longest subarray of sum k


int longestSubarrySum(vector<int>& v, int n, int sum){
    int i=0,j=0;

    int temp = 0;

    int size = 0;

    while(j<n){

        temp+=v[j];

        if(temp<sum){
            j++;
        }else if(sum==temp){
            size = max(size, j-i+1);
            j++;
        }else{
            while(temp>sum && i<j){
                temp-=v[i];
                i++;
            }
            j++;
        }


    }

    return size;
}


//Q.6 Longest substring with k unique characters.


int longestSubstrKUC(string s, int k){
    int n = s.length();

    unordered_map<char, int> m;

    int ans = INT_MIN;

    int i=0,j=0;

    while(j<n){
        m[s[j]]++;

        if(m.size()<k){
            j++;
        }else if(m.size()==k){
            ans = max(ans, j-i+1);
            j++;
        }else{
            while(m.size()>k && i<j){
                m[s[i]]--;
                if(m[s[i]]==0) m.erase(s[i]);
                i++;
            }

            j++;
        }
    }

    return ans;

}


//Q.7 Longest substring without repeating characters.


int longestSubstrWRC(string s){
    int n = s.length();
    int i=0,j=0;

    unordered_map<char, int> m;

    int ans = INT_MIN;

    while(j<n){
        m[s[j]]++;

        if(m.size()==j-i+1){
            ans = max(ans, j-i+1);
            j++;
        }else{
            while(m.size()<j-i+1 && i<j){
                m[s[i]]--;
                if(m[s[i]]==0) m.erase(s[i]);
                i++;
            }
            j++;
        }
    }

    return ans;
}


//Q.8 Pick toys - The problem states that a mother asked her son to pick toys from a shelf where 
//                number of types of toys are placed. Her son gets happy hearing that thinking he
//                can choose any number of toys. But at that moment his mom gives him two condition
//                that he must follow while picking toys.
//                (i). He can only pick 'k' different toys.
//                (ii). He must only pick toys which are consecutively placed.

// Let him help in picking maximum number of toys under the given condition.


// This problem is similar to the problem where we were finding longest substring
// with k unique characters.


int pickToys(vector<int>& v, int n, int k){

    int ans = INT_MIN;

    int i=0,j=0;

    unordered_map<int,int> m;

    while(j<n){

        m[v[j]]++;

        if(m.size()<k){
            j++;
        }else if(m.size()==k){
            ans = max(ans, j-i+1);
            j++;
        }else{
            while(m.size()>k && i<j){
                m[v[i]]--;
                if(m[v[i]]==0) m.erase(v[i]);
                i++;
            }
            j++;
        }

    }

    return ans;
}


//Q.9 Minimum Window Substring 

//Problem explanation: The problem states that we are given two strings let (s, t)
// and we have to find the minimum window substring of s such that it contains all the letters of t


int minimumWindowSubstr(string s, string t){
    int n = s.size();
    int ts = t.size();

    unordered_map<char, int> m;

    for(int i=0;i<ts;i++){
        m[t[i]]++;
    }

    int count = m.size();
    int ans = INT_MAX;

    int i=0,j=0;

    while(j<n){
        if(m.find(s[j])!=m.end()){
            m[s[j]]--;
            if(m[s[j]]==0) count--;
        }

        if(count!=0){
            j++;
        }else{
            while(count==0 && i<j){
                ans = min(ans, j-i+1);
                if(m.find(s[i])!=m.end()){
                    m[s[i]]++;
                    if(m[s[i]]>0){
                        count++;
                    }
                }
                i++;
            }
            j++;
        }
    }

    return ans;

}


//Q.10 Number of subarrays with maximum values in the given range

// The problem states that find all the subarrays whose maximum value lies in the given 
// specified range.



int subarrayMaxinRange(vector<int>& v, int n, int L, int R){

    int i=0,j=0;
    int c=0;
    int curr_window = 0;


    while(j<n){
        if(v[j]>=L && v[j]<=R){
            curr_window = j-i+1;        //If the element is in the range it will add to the answer
        }else if(v[j]>R){               //If the max element is out of range we will make window 0 
            curr_window = 0;            //if the element is smaller than L we are not checking any 
            i = j+1;                    //condition bcz the question states the max element of the
        }                               // subarray should be in the range.
        c += curr_window;
        j++;
    }
        
    return c;

}


//Q.11 Longest span in two binary arrays

// The problem states that we have to find the longest common span between two binary arrays.
//Here common means they should have equal sum in that span.


int longestSpanBinaryArray(vector<int>& a, vector<int>& b , int n){

    vector<int> help(n);

    for(int i=0;i<n;i++){
        help[i] = a[i]-b[i];
    }

    int ans = 0;

    int sum = 0;

    unordered_map<int,int> m;

    m[0] = -1;

    for(int i=0;i<n;i++){
        sum+=help[i];

        if(m.find(sum)!=m.end()){
            ans = max(ans, i-m[sum]);
        }else{
            m[sum] = i;
        }
    }

    return ans;



}



string minimumWindowSubstrTemp(string s, string t){
    int n = s.size();
    int ts = t.size();

    unordered_map<char, int> m;

    for(int i=0;i<ts;i++){
        m[t[i]]++;
    }

    int count = m.size();
    int ans = INT_MAX;

    int start = -1, end = -1;

    int i=0,j=0;

    while(j<n){
        if(m.find(s[j])!=m.end()){
            m[s[j]]--;
            if(m[s[j]]==0) count--;
        }

        if(count!=0){
            j++;
        }else{
            while(count==0 && i<j){

                if(j-i+1<ans){
                    ans = j-i+1;
                    start = i;
                    end = j+1;
                }

                // ans = min(ans, j-i+1);
                if(m.find(s[i])!=m.end()){
                    m[s[i]]++;
                    if(m[s[i]]>0){
                        count++;
                    }
                }
                i++;
            }
            j++;
        }
    }

    return s.substr(start, end);

}



int solution(int a[], int n){

    int i=0, j=0;

    unordered_map<int,int> m;

    int c = 0;

    while(j<n){
        m[a[j]]++;
       
        if(j-i+1<3){
            j++;
        }else if(j-i+1==3){
            if(m.size()==2) c++;
            
            if(m.find(a[i])!=m.end()){
                m[a[i]]--;
                if(m[a[i]]==0){
                    m.erase(a[i]);
                }
            }
            i++;
            j++;
        }
    }


    return c;

}











int main(){
 
    fastread();
 
    // freopen("_____________", "r", stdin);
    // freopen("_____________", "w", stdout);
    
    int t;
    cin>>t;

    while(t--){
    	
    	int n;
        cin>>n;

        int a[n];

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        cout << solution(a, n) << endl;
    	
    }
    

    return 0;
        

}

