#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back //Faster && Doesn't Copy
#define fastread() ios_base :: sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0)
#define SIZE 26
 
const int M = 1e9 + 7;
 
using namespace std;

// bool cmp(pair<ll,ll> a, pair<ll,ll> b){
//     return a.first > b.first;
// }


bool help(const vector<int> &a, const vector<int> &b){
    
    if(a[1]==0 && b[1]==0){
        return true;
    }else if(a[1]!=b[1]){
        return a[1]<b[1];
    }else if(a[1]==1 && b[1]==1){
        return a[0]>b[0];
    }
    
    return true;
    
}




int main(){
 
    fastread();
 
    // freopen("_____________", "r", stdin);
    // freopen("_____________", "w", stdout);

    int n;
    cin>>n;

    int k;
    cin>>k;

    vector<vector<int>> contests(n);
    
    for (int i = 0; i < n; i++) {
        contests[i].resize(2);
        for (int j = 0; j < 2; j++) {
            cin>>contests[i][j];
        }
    }

    sort(contests.begin(), contests.end(), help);

    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cout << contests[i][j] << " ";
        }
        cout << endl;
    }



    return 0;
        
}

