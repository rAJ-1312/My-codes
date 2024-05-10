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




int maxSubarraySum(int arr[], int size){
    int sum = 0;
    int best = 0;

    for(int i=0;i<size;i++){
        sum = max(arr[i],sum+arr[i]);
        best = max(best,sum);
    }

    return best;
}


int binarySearch(vector<int> v, int target){
    int n = v.size();
    int i=0,j=n-1;

    while(i<=j){
        int mid = i + (j-i)/2;

        if(v[mid]==target){
            return mid;
        }else if(v[mid]>target){
            j = mid - 1;
        }else{
            i = mid + 1;
        }
    }

    return -1;
}


int firstOccurence(vector<int> v, int n, int k){
    int low = 0, high = n-1;

    int idx = -1;

    while(low<=high){
        int mid = low + (high - low)/2;

        if(v[mid]==k){
            idx = mid;
            high = mid-1;
        }else if(v[mid] < k){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return idx;
}


int lastOccurence(vector<int> v, int n, int k){
    int low = 0, high = n-1;

    int idx = -1;

    while(low<=high){
        int mid = low + (high - low)/2;

        if(v[mid]==k){
            idx = mid;
            low = mid+1;
        }else if(v[mid] < k){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    return idx;
}


/

int numberOfRotations(vector<int> v, int n){
    int l = 0, h = n-1;

    if(v[l]<=v[h]) return l;

    int c = -1;

    while(l<=h){
        int  mid = l + (h-l)/2;

        if(v[mid]<v[(mid+1)%n] && v[mid]<v[(mid+n-1)%n]){
            c = mid;
            break;
        }else if(v[0]<=v[mid]){
            l = mid+1;
        }else{
            h = mid-1;
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
    cin.ignore();

    while(t--){

        string s;
        getline(cin, s);

        cout << s ;

        // int n;
        // cin>>n;

        // vector<int> v(n);

        // for(int i=0;i<n;i++){
        //     cin>>v[i];
        // }

        // cout << solve(n, v) << endl;

    }


    return 0;
        
}




