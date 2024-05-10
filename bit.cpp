#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define eb emplace_back  // Faster and Doesn't copy
#define fastread() ios_base :: sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) 
#define SIZE 26
#define INF 1000000000

const int M = 1e9 + 7;


using namespace std;

void printBinary(int num){
    for(int i=10;i>=0;i--){
        cout << ((num >> i) & 1) ;
    }
    cout << endl;
}



void bitManipulation(int num, int i) {

    int temp = num & (1 << i-1);

    if(temp){
        cout << 1  << " ";
    }else{
        cout << 0 << " ";
    } 
    
    
    num |= (1<<i-1);

    cout << num << " ";
    
    num &= (~(1<<i-1));
    
    cout << num << " ";
}


int maxSubarraySum(vector<int>& v){
    int n = v.size();
    int sum = 0, best = 0;

    for(int i=0;i<n;i++){
        sum = max(v[i], sum+v[i]);
        best = max(sum, best);
    }

    return best;
}




int main(){

    fastread();

    // freeopen("--------", 'r', stdin)  ;
    // freeopen("--------", 'w', stdout) ;

    int k;
    cin>>k;

    while(k--){
        
        int n;
        cin>>n;

        vector<int> v(n);

        for(int i=0;i<n;i++){
            cin>>v[i];
        }

        cout << maxSubarraySum(v) << "\n";

        


    }


}







