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

struct Node{
    int data;
    Node* left;
    Node* right;
};

struct Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------




void inorder(Node* root, vector<int>& ans){
    
    if(root==NULL) return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);

}


void levelOrderTraversal(Node* root, vector<int>& v){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){

        int size = q.size();

        for(int i=0;i<size;i++){
            v.push_back(q.front()->data);
            
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);

            q.pop();
        }

    }
}


bool rootToNode(Node* root, int &x, vector<int>& v){

    if(!root) return false;

    v.push_back(root->data);

    if(root->data == x) return true;

    if(rootToNode(root->left, x, v) || rootToNode(root->right, x, v)) return true;

    v.pop_back();

    return false;

}

bool isLeaf(Node* root){
    return root->left == NULL && root->right==NULL;
}


void rootToLeaf(Node* root, vector<int>& temp, vector<vector<int>>& ans){

    temp.push_back(root->data);

    if(isLeaf(root)){
        ans.push_back(temp);
        temp.pop_back();
        return;
    }

    if(root->left) rootToLeaf(root->left, temp, ans);
    if(root->right) rootToLeaf(root->right, temp, ans);

    temp.pop_back();

}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q){
    if(root==NULL || root==p || root==q){
        return root;
    }

    Node* left = lowestCommonAncestor(root->left, p, q);
    Node* right = lowestCommonAncestor(root->right, p, q);

    if(left == NULL) return right;
    else if(right == NULL) return left;
    else return root;
}


int maxWidth(Node* root){
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    int maxi = 0;

    while(!q.empty()){
        int size = q.size();
        int minIdx = q.front().second;

        int first, last;

        for(int i=0;i<size;i++){
            Node* temp = q.front().first;
            int curIdx = q.front().second-minIdx;

            q.pop();

            if(i==0) first = curIdx;
            if(i==size-1) last = curIdx;

            if(temp->left) q.push({temp->left, 2*curIdx+1});
            if(temp->right) q.push({temp->right, 2*curIdx+2});
        }

        maxi = max(maxi, last-first+1);
    }

    return maxi;

}

//Morris Inorder Traversal

vector<int> Minorder(Node* root){

    vector<int> ans;

    if(root==NULL) return ans;

    Node* curr = root;

    while(curr){
        if(curr->left==NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        }else{
            Node* prev = curr->left;
            while(prev->right && prev->right!=curr){
                prev = prev->right;
            }

            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }else{
                prev->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }

            
        }
    }

    return ans;
}



//Kth largest using Morris traversal


int kthsmallest(Node* root, int& c, int& k){

    int ans = -1;

    if(root==NULL) return ans;

    Node* curr = root;

    while(curr){
        if(curr->left==NULL){
            c++;
            if(c==k){
                ans = curr->data;
                break;
            }
            curr = curr->right;
        }else{
            Node* prev = curr->left;
            while(prev->right && prev->right!=curr){
                prev = prev->right;
            }

            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }else{
                prev->right = NULL;
                c++;
                if(c==k){
                    ans = curr->data;
                    break;
                }
                curr = curr->right;
            }
        }
    }   

    return ans;
}

















int kthSmallest(Node* root, int k) {

    if(root==NULL) return -1;

    int ans = -1;
    int c = 0;

    while(root){
        if(root->left==NULL){
            c++;
            if(c==k){
                ans = root->data;
                break;
            }
            root = root->right;
        }else{
            Node* curr = root->left;
            while(curr->right && curr->right!=root){
                curr = curr->right;
            }

            if(curr->right == NULL){
                curr->right = root;
                root = root->left;
            }else{
                curr->right = NULL;
                c++;
                if(c==k){
                    ans = root->data;
                    break;
                }
                root = root->right;
            }
        }
    }

    return ans;
}


class BSTIterator{
    stack<Node*> s;
    bool reverse = true;
    //reverse == true -> before();
    //reverse == false-> next();

    private:

        void help(Node* root){
            Node* curr = root;
            while(curr){
                s.push(curr);
                if(reverse){
                    curr = curr->right;
                }
                else{
                    curr = curr->left;
                }
            }
        }

    public:

        BSTIterator(Node* root, bool isReverse){
            reverse = isReverse;
            help(root);
        }

        bool hasNext(){
            return !s.empty();
        }

        int next(){
            Node* temp = s.top();
            s.pop();
            if(reverse){
                help(temp->left);
            }else{
                help(temp->right);
            }

            return temp->data;
        }
};




bool twoSum(Node* root, int k){

    BSTIterator forward(root, false);
    BSTIterator backward(root, true);

    int i = forward.next();
    int j = backward.next();

    while(i<j){
        if(i+j==k){
            return true;
        }else if(i+j<k) i = forward.next();
        else j = backward.next();
    }

    return false;

}









int main(){
 
    fastread();
 
    // freopen("_____________", "r", stdin);
    // freopen("_____________", "w", stdout);


 //        5
 //      /   \
 //     3     9
 //    / \   / \
 //   2   4 7   10
 //  /     / \
 // 1     6   8

    Node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(9);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->left = newNode(7);
    root->right->right = newNode(10);
    root->left->left->left = newNode(1);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(8);



    cout << twoSum(root, 3) << endl;





    //---------------------------------------------------------

    // levelOrderTraversal(root, ans);

    // vector<int> ans;
    // int x = 8;

    // rootToNode(root, x, ans);

    // for( int &i : ans){
    //     cout << i << " ";
    // }
    // cout << endl;

    //----------------------------------------------------------

    // vector<int> temp;
    // vector<vector<int>> ans;

    // rootToLeaf(root, temp, ans);

    // int sum = 0;

    // for( auto &v : ans){
    //     int factor = 1;
    //     int num = 0;
    //     for(int i=v.size()-1;i>=0;i--){
    //         num = num + v[i]*factor;
    //         factor*=10;
    //     }
    //     sum += num;
    // }

    // cout << sum << endl;

    //----------------------------------------------

    // Node* p = root->left->right->left;
    // Node* q = root->right->left;


    // Node* ans = lowestCommonAncestor(root, p, q);
    // cout << ans->data << endl;

    //-----------------------------------------------

    // cout << maxWidth(root) << endl;


    //-----------------------------------------------


    // vector<int> ans = Minorder(root);


    // for( auto &i : ans){
    //     cout << i << " ";
    // }
    // cout << "\n";


    //-----------------------------------------------

    // int c = 0;
    // int k = 7;

    // int ans = kthSmallest(root, 6);

    // cout << ans << endl;






    return 0;
        
}