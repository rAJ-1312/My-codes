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


// vector<vector<int>> dp(n+1, vector<int> (w+1, -1)) //declaring a 2-D vector initialized with all 1's



// int knapsack(int idx, vector<int>& wt, vector<int>& value, int w, int n, vector<vector<int>>& dp){
//     if(idx==n || w==0) return 0;
    
//     if(dp[idx][w]!=-1) return dp[idx][w];
    
//     if(wt[idx]>w) return knapsack(idx+1, wt, value, w, n, dp);
    
//     int pick = value[idx] + knapsack(idx+1, wt, value, w-wt[idx], n, dp);
//     int notpick = knapsack(idx+1, wt, value, w, n, dp);
    
//     return dp[idx][w] = max(pick, notpick);
// }


// int dp[1001][1001] = {-1};


// int solve(int h, int a, int i){
//     if(h<=0 || a<=0) return 0;
    
//     if(dp[h][a]!=-1) return dp[h][a];
    
//     int x=0,y=0,z=0;
    
//     if(i!=1) x = 1 + solve(h+3, a+2, 1);
//     if(i!=2) y = 1 + solve(h-5, a-10, 2);
//     if(i!=3) z = 1 + solve(h-20, a+5, 3);
    
//     return dp[h][a] = max({x,y,z});
// }


// bool subsetSum(int idx, vector<int>& v, int n, int sum){

//     // if(sum==0) return true;

//     if(idx==n){
//         if(sum==0) return true;
//         return false;
//     }

//     if(v[idx]>sum) return false;

//     bool pick = subsetSum(idx+1, v, n, sum-v[idx]);

//     if(pick) return true;

//     bool notpick = subsetSum(idx+1, v, n, sum);

//     return pick || notpick;


// }


int countWays(int idx, int n, vector<int>& dp){
    if(idx == n){
        return 1;
    }

    if(idx>n) return 0;

    int a = countWays(idx+1, n, dp);
    int b = countWays(idx+2, n, dp);

    return dp[idx] = a+b;

}


int coinChange(int idx, int amount, vector<int>& coins, int n){
    if(amount == 0) return 1;

    if(amount<0 || idx >= n) return 0;

    return coinChange(idx, amount-coins[idx], coins, n) + coinChange(idx+1, amount, coins, n);
}







int main(){
 
    fastread();
 
    // freopen("_____________", "r", stdin);
    // freopen("_____________", "w", stdout);
    
    int t;
    cin>>t;

    while(t--){
    	
        // vector<int> dp(n+1, -1);

        int n;
        cin>>n;

        vector<int> coins(n);

        for(int i=0;i<n;i++){
            cin>>coins[i];
        }

        int amount;
        cin>>amount;

        cout << coinChange(0, amount, coins, n) << endl;
    	

    }

    return 0;

}

