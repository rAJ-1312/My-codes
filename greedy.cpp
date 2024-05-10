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

bool numberOFMeetings_customSort(pair<int,int> &p1, pair<int,int> &p2){
	if(p2.second != p1.second){
		return p1.second < p2.second;
	}else{
		return p1.first < p2.first;
	}
}


int numberOFMeetings(vector<int> start, vector<int> end){
	vector<pair<int,int>> vp;

	int n = start.size();

	for(int i=0;i<n;i++){
		vp.push_back({start[i], end[i]});
	}

	sort(vp.begin(), vp.end(), numberOFMeetings_customSort);

	int c = 1;

	int last_end = vp[0].second;

	for(int i=1;i<n;i++){
		if(vp[i].first > last_end){
			c++;
			last_end = vp[i].second;
		}
	}

	return c;
}



int minimumPlatforms(vector<int> arrival, vector<int> departure){
	int n = arrival.size();
	sort(arrival.begin(), arrival.end());
	sort(departure.begin(), departure.end());

	int p = 1;
	int j = 0;
	int i = 1;
	int ans = 1;

	while(i<n && j<n){
		if(arrival[i] <= departure[j]){
			p++;
			i++;
		}else if(arrival[i] > departure[j]){
			p--;
			j++;
		}

		ans = max(ans, p);
	}

	return ans;
}


int minimumCroakingFrogs(string croaking){
	const string word = "croak";

	int c=0, r=0, o=0, a=0, k=0;
	int ans = INT_MIN;

	int frog = 0;

	for (char ch : croaking){
		switch (ch){
			case 'c':
				frog++;
				c++;
				break;
			case 'r':
				r++;
				break;
			case 'o':
				o++;
				break;
			case 'a':
				a++;
				break;
			case 'k':
				frog--;
				k++;
				break;
		}

		ans = max(frog, ans);
		if(c<r || r<o || o<a || a<k) return -1;

	}

	return frog==0 ? ans : -1 ;
}


int maximum69Number (int num) {

    int idx = -1;

    string s = to_string(num);

    cout << "To-string: " << s << endl;

    for(int i=0;i<s.length();i++){
    	cout << s[i] << endl;
        if(s[i]=='6'){
            idx = i;
            break;
        }
    }

    cout << idx << endl;

    if(idx==-1) return num;
    else {
        s[idx] = '9';
        num = stoi(s) ;
        return num;
    }
    
}


bool JobScheduling_cmp(Job j1, Job j2){
    return j1.profit > j2.profit;
}




vector<int> JobScheduling(Job arr[], int n) 
{ 
    sort(arr, arr+n, JobScheduling_cmp);
    
    int maxi = 0;
    
    for(int i=0;i<n;i++){
        if(arr[i].dead > maxi) maxi = arr[i].dead;
    }
    
    bool deadline[maxi] = {false};
    
    int jobs = 0;
    int profit = 0;
    
    for(int i=0;i<n;i++){
        
        int cd = arr[i].dead;
        cd = cd -1;
        while(cd >=0 ){
            if(!deadline[cd]){
                profit += arr[i].profit;
                jobs++;
                deadline[cd] = true;
                break;
            }
            cd--;
        }
    }
    
    vector<int> ans = {jobs, profit};
    
    return ans;
    
} 


bool fractionalKnapsack_cmp(Item a, Item b){
    if(a.weight==b.weight) return a.value>b.value;
    else return (a.value*1.0)/a.weight > (b.value*1.0)/b.weight;
}




double fractionalKnapsack(int W, Item arr[], int n)
{
    
    sort(arr, arr+n, fractionalKnapsack_cmp);
    
    double ans = 0;
    
    for(int i=0;i<n;i++){
        if(arr[i].weight<=W){
            W -= arr[i].weight;
            ans += arr[i].value;
        }else{
            if(W==0) break;
            else{
                ans += (arr[i].value*W*1.0)/arr[i].weight;
                break;
            }
        }
    }
    
    return ans;
}


int minimumCoins(int p)
{
	vector<int> coins = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 };

	int c = 0;

	for(int i=coins.size()-1;i>=0;i--){
	    if(p>=coins[i]){
	        int temp = p/coins[i];
	        c += temp;
	        p -= temp*coins[i];
	        if(p==0) break;
	    }
	}

	return 
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

    	string s;
    	cin>>s;

    	cout << minimumCroakingFrogs(s) << endl;
    	
    	// int n;
    	// cin>>n;

    	// cout << maximum69Number(n) ;

    	// vector<int> start(n);
    	// vector<int> end(n);

    	// for(int i=0;i<n;i++){
    	// 	cin>>start[i];
    	// }

    	// for(int i=0;i<n;i++){
    	// 	cin>>end[i];
    	// }

    	// cout << numberOFMeetings(start, end);

    	// cout << minimumPlatforms(start, end);
    }

    return 0;

}

