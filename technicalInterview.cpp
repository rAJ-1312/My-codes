#include <bits/stdc++.h>

using namespace std;


int main(){
	vector <int> input = {5,3,1,2,4,6};

	int n = input.size();

	// cout << -1 ;

	// for(int i=1;i<n;i++){
	// 	for(int j=i-1;j>=0;j)
	// }


	stack<int> s;
	vector<int> ans;


	for(int i=0;i<n;i++){
		if(s.empty()){
			ans.push_back(-1);
		}else{
			while(!s.empty() && s.top()>=input[i]){
				s.pop();
			}
			if(s.empty()){
				ans.push_back(-1);
			}else{
				ans.push_back(s.top());
			}
		}
		s.push(input[i]);
	}


	for(int &ele : ans){
		cout << ele << " " ;
	}
	cout << endl;


}