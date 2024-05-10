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


// ***************************************************** STACK ****************************************************


// Q.1 Given an expression consisting of only brackets, check whether it is valid or not.


bool isValid(string str){
    stack<char> s;

    for(int i=0;i<str.length();i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            s.push(str[i]);
        }else{
            if(!s.empty()){
                if(str[i]==')' && s.top()=='(') s.pop();
                else if(str[i]=='}' && s.top()=='{') s.pop();
                else if(str[i]==']' && s.top()=='[') s.pop();
                else return false;
            }else{
                return false;
            }
        }
    }

    if(s.empty()){
        return true;
    }

    return false;
}




// Q.1 Given an expression consisting of only brackets, check whether it is valid or not.


bool isValid(string str){
    stack<char> s;

    for(int i=0;i<str.length();i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            s.push(str[i]);
        }else{
            if(str[i]==')' && s.top()=='(' || str[i]=='}' && s.top()=='{' || str[i]==']' && s.top()=='['){
                s.pop();
            }else{
                s.push(str[i]);
            }
        }
    }

    return s.empty()
}







// Q.1 Next greater element to left : return a list of elements that shows the next greater element in left for each element.


vector<int> ngl(vector<int>& v, int n){
    stack<int> s;
    vector<int> ans;

    for(int i=0;i<n;i++){
        if(s.empty()){
            ans.push_back(-1);
        }else{
            while(!s.empty() && s.top()<=v[i]){
                s.pop();
            }

            if(s.empty()){
                ans.push_back(-1);
            }else{
                ans.push_back(s.top());
            }
        }
        s.push(v[i]);
    }

    return ans;
}



// Q.2 Next smaller element to left : return a list of elements that shows the next smaller element in left for each element.


vector<int> nsl(vector<int>& v, int n){
    stack<int> s;
    vector<int> ans;

    for(int i=0;i<n;i++){
        if(s.empty()){
            ans.push_back(-1);
        }else{
            while(!s.empty() && s.top()>=v[i]){
                s.pop();
            }

            if(s.empty()){
                ans.push_back(-1);
            }else{
                ans.push_back(s.top());
            }
        }
        s.push(v[i]);
    }

    return ans;
}



// Q.3 Next greater element to right : return a list of elements that shows the next greater element in right for each element.


vector<int> ngr(vector<int>& v, int n){
    stack<int> s;
    vector<int> ans;

    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            ans.push_back(-1);
        }else{
            while(!s.empty() && s.top()<=v[i]){
                s.pop();
            }

            if(s.empty()){
                ans.push_back(-1);
            }else{
                ans.push_back(s.top());
            }
        }
        s.push(v[i]);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}


// Q.4 Next smaller element to right : return a list of elements that shows the next smaller element in right for each element.


vector<int> nsr(vector<int>& v, int n){
    stack<int> s;
    vector<int> ans;

    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            ans.push_back(-1);
        }else{
            while(!s.empty() && s.top()>=v[i]){
                s.pop();
            }

            if(s.empty()){
                ans.push_back(-1);
            }else{
                ans.push_back(s.top());
            }
        }
        s.push(v[i]);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}


// Q.5 Stock span probelm : in this basically we have to return the number of consecutive smaller elements in left of every element.


vector<int> stockspan(vector<int>& v, int n){
    
    vector<int> ans;
    stack<pair<int,int>> s;


    for(int i=0;i<n;i++){
        if(s.empty()){
            ans.push_back(i+1);
        }else{
            while(!s.empty() && s.top().first<=v[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(i+1);
            }else{
                ans.push_back(i-(s.top().second));
            }
        }
        s.push({v[i],i});
    }

    return ans;

}



// Q.6 Maximum area of histogram : we are given a list of integers which are basically representing the heights of bar in a histogram. We have to find the maximum area we can acheive using these.


vector<int> nsl_Histogram(vector<int>& v, int n){
    stack<pair<int,int>> s;
    vector<int> ans;

    for(int i=0;i<n;i++){
        if(s.empty()){
            ans.push_back(-1);
        }else{
            while(!s.empty() && s.top().first>=v[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(-1);
            }else{
                ans.push_back(s.top().second);
            }
        }
        s.push({v[i], i});
    }

    return ans;
}


vector<int> nsr_Histogram(vector<int>& v, int n){
    stack<pair<int,int>> s;
    vector<int> ans;

    for(int i=n-1;i>=0;i--){
        if(s.empty()){
            ans.push_back(n);
        }else{
            while(!s.empty() && s.top().first>=v[i]){
                s.pop();
            }
            if(s.empty()){
                ans.push_back(n);
            }else{
                ans.push_back(s.top().second);
            }
        }
        s.push({v[i], i});
    }

    reverse(ans.begin(), ans.end());

    return ans;
}



int maxAreaHistogram(vector<int>& v, int n){
    
    vector<int> nsl_index = nsl_Histogram(v, n);
    vector<int> nsr_index = nsr_Histogram(v, n);

    int ans = 0;

    for(int i=0;i<n;i++){
        int width = nsr_index[i] - nsl_index[i] - 1;
        int length = v[i];

        ans = max(ans, width*length);
    }

    return ans;

}





// Q.7 Rain water trapping : we are given a list of integers which are basically representing the heights of buildings. We have to find the amount of water that can get trapped among these buildings. There are two approach to solve this problem one is using prefix_max and suffix_max. Another approach is just using a single traversal without any extra space.


vector<int> max_left(vector<int>& v, int n){
    vector<int> temp(n);

    temp[0] = v[0];

    for(int i=1;i<n;i++){
        temp[i] = max(temp[i-1], v[i]);
    }

    return temp;
}


vector<int> max_right(vector<int>& v, int n){
    vector<int> temp(n);

    temp[n-1] = v[n-1];

    for(int i=n-2;i>=0;i--){
        temp[i] = max(temp[i+1], v[i]);
    }

    return temp;
}


int rainWaterTrapping(vector<int>& v, int n){
    
    vector<int> max_in_left = max_left(v, n);
    vector<int> max_in_right = max_right(v, n);

    int ans = 0;

    for(int i=0;i<n;i++){
        ans += min(max_in_left[i], max_in_right[i]) - v[i];
    }

    return ans;

}


int rainWaterTrapping(vector<int>& v, int n){
    
    int ans = 0;
    int leftMax = 0, rightMax = 0;
    int left = 0, right = n-1;

    while(left<=right){
        if(v[left]<=v[right]){
            if(v[left]>leftMax) leftMax = v[left];
            else ans += leftMax - v[left];
            left++;
        }else{
            if(v[right]>rightMax) rightMax = v[right];
            else ans += rightMax - v[right]
            right--;
        }
    }

    return ans;

}











int main(){
 
    fastread();
    cin.tie(NULL);
 
    // freopen("_____________", "r", stdin);
    // freopen("_____________", "w", stdout);
    
    int t;
    cin>>t;
    // cin.ignore();

    while(t--){
        
        int n;
        cin>>n;

        vector<int> v(n);

        for(int i=0;i<n;i++){
            cin>>v[i];
        }


        cout << rainWaterTrapping(v, n) << endl;



        	
    }

    return 0;

}

