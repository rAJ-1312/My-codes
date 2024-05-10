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


// ****************************************  Binary Search  ************************************
// *****************************************                ************************************



// Q.1 Check if an element is present in the array or not.


int binarySearch(vector<int>& v, int n, int k){

	int idx = -1;

	int low = 0;
	int high = n-1;

	while(low<=high){
		int mid = low + (high-low)/2;

		if(v[mid]==k){
			idx = mid;
			break;
		}else if(v[mid]<k){
			low = mid+1;
		}else{
			high = mid-1;
		}
	}

	return idx;

}


// Q.2 Find the first and last occurences of an element in an sorted array.



int firstOccurence(vector<int>& v, int n, int k){
	int idx = -1;

	int l = 0;
	int h = n-1;

	while(l<=h){
		int mid = l + (h-l)/2;

		if(v[mid]==k){
			idx = mid;
			h = mid-1;
		}else if(v[mid]<k){
			l = mid+1;
		}else{
			h = mid-1;
		}
	}

	return idx;


}


int lastOccurence(vector<int>& v, int n, int k){
	int idx = -1;

	int l = 0;
	int h = n-1;

	while(l<=h){
		int mid = l + (h-l)/2;

		if(v[mid]==k){
			idx = mid;
			l = mid+1;
		}else if(v[mid]<k){
			l = mid+1;
		}else{
			h = mid-1;
		}
	}

	return idx;


}






vector<int> firstLastOccurence(vector<int>& v, int n, int k){

	vector<int> ans;

	int fo = firstOccurence(v, n, k);
	int lo = lastOccurence(v, n, k);

	ans.push_back(fo);
	ans.push_back(lo);

	return ans;


}



// Q.3 A sorted array was rotated. We have to find the number of rotations it went through.

// This question is similar to finding the index of minimum element in a rotated array. That will also be  the count of the rotations.



int rotationCount(vector<int>& v){

	int n = v.size();

	int l = 0;
	int h = n-1;

	if(v[l] < v[h]) return l;

	int c = -1;

	while(l<=h){
		int mid = l + (h-l)/2;

		if(v[mid]<v[(mid+1)%n] && v[mid]<v[(mid+n-1)%n]){
			c = mid;
			break; 
		}else if(v[0]<=v[mid]){  //indicating left side is sorted
			l = mid+1;
		}else{
			c = mid;
			h = mid-1;
		}
	}

	return c;

}


// Q.4 Find an element in a rotated sorted array.

// -> First we can use above concept of finding the number of rotations of a rotated sorted array i.e., the index of the minimum element.
// -> Then we will have two sorted arrays one starting from 0 to minIdx - 1 and another starting from minIdx to size - 1;
// -> We can apply binary search for both parts and find the required element index.


int peakElement(vector<int>& v){
	int l = 0;
	int n = v.size();
	int h = n-1;

	int ans = -1;

	while(l<=h){
		int mid = l + (h-l)/2;

		if(mid>0 && mid<n-1){
			if(v[mid]>v[mid-1] && v[mid]>v[mid+1]){
				return v[mid];
			}else if(v[mid-1]>v[mid]){
				h = mid-1;
			}else{
				l = mid+1;
			}
		}else if(mid==0){
			if(v[0]>v[1]){
				return v[0];
			}else{
				return v[1];
			}
		}else{
			if(v[mid]>v[mid-1]){
				return v[mid];
			}else{
				return v[mid-1];
			}
		}
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
    	int n;
    	cin>>n;

    	vector<int> v(n);

    	for(int i=0;i<n;i++){
    		cin>>v[i];
    	}

    	// int k;
    	// cin>>k;

    	// vector<int> ans = firstLastOccurence(v, n, k);

    	// for(auto i : ans){
    	// 	cout << i << " ";
    	// }
    	// cout << "\n";

    	// int count;

    	// if(ans[0]==-1) count = 0;
    	// else count = ans[1]-ans[0]+1;

    	// cout << "Count of " << k << " is " << count;

    	cout << peakElement(v) << "\n";



    }




}