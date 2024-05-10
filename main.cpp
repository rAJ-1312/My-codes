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

// bool cmp(const pair<int,int> &a, const pair<int,int> &b){

// 	// return a.first > b.first;

// 	if(a.first!=b.first)
//     	return a.first > b.first;
//     else
//     	return a.second > b.second;
// }

void print(vector<int> temp){
	for(int i=0;i<temp.size();i++){
		if(i==temp.size()-1) cout << temp[i] << ",";
		else cout << temp[i] << " ";
	}
}



void generate(int idx, vector<int> &v, int n, vector<int> &temp){
	if(idx==n){
		print(temp);
		return;
	}

	temp.push_back(v[idx]);

	generate(idx+1, v, n, temp);

	temp.pop_back();

	generate(idx+1, v, n, temp);

} 






int main(){
 
    fastread();
    cin.tie(NULL);
 
    // freopen("_____________", "r", stdin);
    // freopen("_____________", "w", stdout);
    
    int t;
    cin>>t;
    cin.ignore();

    while(t--){
    	
    	int n;
    	cin>>n;

    	vector<int> v(n);

    	for(int i=0;i<n;i++){
    		cin>>v[i];
    	}

    	vector<int> temp;

    	generate(0, v, n, temp);
    	
    }

    return 0;

}

