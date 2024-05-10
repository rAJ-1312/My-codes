#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
#include <algorithm>
#include <unordered_set>
// #include <bits/stdc++.h>


using namespace std;



vector<int> removeDuplicates(vector<int> arr) {
    unordered_set<int> uniqueNums;
    vector<int> result;

    for (int num : arr) {
        
        if (uniqueNums.find(num) == uniqueNums.end()) {
            uniqueNums.insert(num);
            result.push_back(num);
        }
    }

    return result;

}


int countChar(string data, char coder){
    int answer=0;

    for(int i=0;i<data.length();i++){
        if(data[i]==coder){
            answer++;
        }
    }

    return answer;
}



unsigned long long modularExponentiation(unsigned long long base, unsigned long long exponent, unsigned long long modulus) {
    unsigned long long result = 1;
    base %= modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }

    return result;
}






int findSecretCode(int secretCode, int firstKey, int secondKey){

    unsigned long long temp = modularExponentiation(secretCode, firstKey, 10);
    unsigned long long tempmod = temp % 10;
    unsigned long long encryptedCode = modularExponentiation(tempmod, secondKey, 1000000007);
    
    int answer = encryptedCode;

    return answer;

}



vector<int> funcArrange(vector<int> inputArr){

    vector<int> even;
    vector<int> odd;

    int size = inputArr.size();
    int evenidx = 0;

    for(int i=0;i<size;i++){
        if( inputArr[i] % 2 == 0){
            even.push_back(inputArr[i]);
        }
        else{
            odd.push_back(inputArr[i]);
        }
    }

    int i=0;
   
    for(i=0;i<even.size();i++){
        inputArr[i] = even[i];
    }

    
    for(int j=0;j<odd.size();j++){
        inputArr[i] = odd[j];
        i++;
    }

    return inputArr;
}




//********************************Advanced Coding Round********************************





int maxDishes(vector<int>& v, int k){

    int i=0,j=0;
    int n = v.size();

    int ans = INT_MIN;

    unordered_map<int,int> m;

    int lastPicked = -1;

    while(j<n){

        m[v[j]]++;

        if(m.size()<k){
            j++;
        }else if(m.size()==k){
            ans = max(ans, j-i+1);
            j++;
        }else{
            while(m.size()>k){
                m[v[i]]--;
                if(m[v[i]]==0) m.erase(v[i]);
                i++;
            }
            j++;
        }

    }

    return ans;

}















int main() {


    int n;
    cin>>n;

    vector<int> v(n);

    unordered_map<int,int> m;

    for(int i=0;i<n;i++){
        cin>>v[i];
        m[i+1] = v[i];
    }

    int M, c;
    cin>>M>>c;

    vector<pair<int,int>> teamPosition(M);

    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;

        teamPosition[i] = {a,b};
    }


    sort(teamPosition.begin(), teamPosition.end());

    int lastMember = teamPosition[0].second;

    int sum = m[teamPosition[0].first] + m[teamPosition[0].second];
    int ans = sum;

    for(int i=1;i<M;i++){
        if(teamPosition[i].first==lastMember){
            sum += m[teamPosition[i].second];
            ans = max(ans, sum);
            lastMember = teamPosition[i].second;
        }else{
            sum = m[teamPosition[i].first] + m[teamPosition[i].second];
            ans = max(ans, sum);
        }
    }

    cout << ans << endl;





    return 0;
}



