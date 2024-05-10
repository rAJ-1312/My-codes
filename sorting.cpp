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




int countingSort(vector<int>& costs, int coins) {

    int maxi = *max_element(costs.begin(), costs.end());

    int n = costs.size();

    vector<int> countArray(maxi+1, 0);

    for(int &ele : costs){
        countArray[ele]++;
    }

    for (int i = 1; i <= maxi; i++)
        countArray[i] += countArray[i - 1];

    vector<int> outputArray(n);

    for(int i=n-1;i>=0;i--){
        outputArray[countArray[costs[i]]-1] = costs[i]; 
        countArray[costs[i]]--;
    }

    int c = 0;
    int i=0;

    while(coins>0 && i<n){
        if(coins>=outputArray[i]){
            c++;
            coins -= outputArray[i];
        }else break;
        if(coins==0) break;
        i++;
    }

    return c;
    
}





void insert(int arr[], int i){

	int curr = arr[i];
	int j=i-1;

	while(j>=0 && arr[j]>curr){
		arr[j+1] = arr[j];
		j--;
	}

	arr[j+1] = curr;

}


void insertionSort(int arr[], int size){


	for(int i=1;i<size;i++){
		insert(arr, i);
	}

}





 void merge(int low, int mid, int high, vector<int> &nums) {
    if (low >= high) 
    return;
    int l = low, r = mid + 1, k = 0, size = high - low + 1;
    vector<int> sorted(size, 0);
    while (l <= mid and r <= high)
        sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
    while (l <= mid) 
        sorted[k++] = nums[l++];
    while (r <= high) 
        sorted[k++] = nums[r++];
    for (k = 0; k < size; k++)
        nums[k + low] = sorted[k];
}

void mergeSort(vector<int>& nums, int start, int end){
    if(start < end){
        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(start, mid, end, nums);
    }
}





vector<int> ngr(int arr[], int n){
	stack<int> s;
	vector<int> ans;

	for(int i=0;i<n;i++){
		if(s.empty()){
			ans.push_back(-1);
		}else{
			if(s.top()>arr[i]){
				ans.push_back(s.top());
			}else{
				while(!s.empty() && s.top()<=arr[i] ){
					s.pop();
				}
				if(s.empty()){
					ans.push_back(-1);
				}else{
					ans.push_back(s.top());
				}
			}
		}
		s.push(arr[i]);
	}

	// reverse(ans.begin(), ans.end());


	return ans;
}


vector<int> nsl(int arr[], int n){
	vector<int> ans;
	stack<int> s;

	for(int i=0;i<n;i++){
		if(s.empty()){
			ans.push_back(-1);
		}else{
			if(s.top()<arr[i]){
				ans.push_back(s.top());
			}else{
				while(!s.empty() && s.top()>=arr[i]){
					s.pop();
				}
				if(s.empty()){
					ans.push_back(-1);
				}else{
					ans.push_back(s.top());
				}
			}
		}
		s.push(arr[i]);
	}

	return ans;
}



int main(){
 
    fastread();
 
    // freopen("_____________", "r", stdin);
    // freopen("_____________", "w", stdout);
    
    int t;
    cin>>t;

    while(t--){

    	string s;	
    	
    }

    return 0;

}

