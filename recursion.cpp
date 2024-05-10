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


void solveTOH(int n, int s, int h, int d, long long &count){
    count++;

    if(n==1){
        // cout << "Move plate " << n << " from " << s << " to " << d << endl;
        return;
    }

    solveTOH(n-1, s, d, h, count);
    // cout << "Move plate " << n << " from " << s << " to " << d  << endl;
    solveTOH(n-1, h, d, s, count);
}


void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        std::cout << "Move disk 1 from " << source << " to " << destination << std::endl;
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    std::cout << "Move disk " << n << " from " << source << " to " << destination << std::endl;
    towerOfHanoi(n - 1, auxiliary, destination, source);
}





unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}


int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

void printFibonacciNumbers(int n) {
    std::cout << "First " << n << " Fibonacci numbers: ";
    for (int i = 0; i < n; i++) {
        std::cout << fibonacci(i) << " ";
    }
    std::cout << std::endl;
}


int sumOfDigits(int n) {
    if (n < 10) {
        return n;
    } else {
        return n % 10 + sumOfDigits(n / 10);
    }
}



void reverseString(std::string& str, int start, int end) {
    if (start >= end) {
        return;
    }
    std::swap(str[start], str[end]);
    reverseString(str, start + 1, end - 1);
}



double power(double base, int exponent) {
    if (exponent == 0) {
        return 1.0;
    } else if (exponent > 0) {
        return base * power(base, exponent - 1);
    } else {
        return 1.0 / (base * power(base, -exponent - 1));
    }
}



int arraySum(int arr[], int size) {
    if (size == 0) {
        return 0;
    } else {
        return arr[size - 1] + arraySum(arr, size - 1);
    }
}



bool isPalindrome(std::string& str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}



void generateSubsets(std::vector<int>& nums, std::vector<int>& subset, int index) {
    if (index == nums.size()) {
        // Process the subset
        // ...
        return;
    }
    // Exclude the current element
    generateSubsets(nums, subset, index + 1);
    // Include the current element
    subset.push_back(nums[index]);
    generateSubsets(nums, subset, index + 1);
    subset.pop_back();  // Backtrack
}


void permutations(std::string& str, int start, int end) {
    if (start == end) {
        std::cout << str << std::endl;
        return;
    }
    for (int i = start; i <= end; i++) {
        std::swap(str[start], str[i]);
        permutations(str, start + 1, end);
        std::swap(str[start], str[i]);  // Backtrack
    }
}



void print(int n){
    if(n==0) return;

    cout << n << " ";
    print(n-1);
    // cout << n << " ";
}




struct Cell {
    int row, col;
    Cell(int r, int c) : row(r), col(c) {}
};

// Function to find all available paths and feasible paths
void findPaths(vector<vector<int>>& matrix, int row, int col, int oxygen, int M, int n,
               vector<vector<bool>>& visited, vector<Cell>& path, vector<pair<vector<Cell>, int>>& feasiblePaths,
               vector<string>& availablePaths) {
    // Base case: If current cell is destination
    if ((row == 0 && col == n - 1) || (row == n - 1 && col == n - 1)) {
        availablePaths.push_back("");
        for (auto& cell : path) {
            availablePaths.back() += (cell.row > row ? 'D' : (cell.row < row ? 'U' : (cell.col > col ? 'R' : 'L')));
            availablePaths.back() += ' ';
        }
        return;
    }

    // Mark current cell as visited
    visited[row][col] = true;

    // Define possible moves: right, down, up, left
    int dr[] = {0, 1, -1, 0};
    int dc[] = {1, 0, 0, -1};

    for (int i = 0; i < 4; ++i) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];

        // Check if new position is within bounds and not visited
        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && !visited[newRow][newCol] && matrix[newRow][newCol] != 0) {
            int newOxygen = oxygen - (matrix[row][col] + matrix[newRow][newCol]);

            // Check if oxygen is sufficient or if it's an oxygen refilling pump
            if (newOxygen >= 0 || matrix[newRow][newCol] == 9) {
                path.push_back(Cell(newRow, newCol));
                if (matrix[newRow][newCol] == 9)
                    newOxygen = M;  // Refill oxygen at pump
                findPaths(matrix, newRow, newCol, newOxygen, M, n, visited, path, feasiblePaths, availablePaths);
                path.pop_back();
            }
        }
    }

    // Mark current cell as unvisited for other paths
    visited[row][col] = false;
}

// Function to print all available paths and feasible paths with remaining oxygen levels
void scubaDiving(vector<vector<int>>& matrix, int M) {
    int n = matrix.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<pair<vector<Cell>, int>> feasiblePaths;
    vector<Cell> path;
    vector<string> availablePaths;
    path.push_back(Cell(0, 0));
    findPaths(matrix, 0, 0, M, M, n, visited, path, feasiblePaths, availablePaths);

    if (availablePaths.empty()) {
        cout << "No path available to reach the destination" << endl;
    } else {
        cout << "The available paths are" << endl;
        for (const string& path : availablePaths) {
            cout << path << endl;
        }

        if (feasiblePaths.empty()) {
            cout << "No feasible path" << endl;
        } else {
            cout << "The feasible paths with remaining oxygen levels are" << endl;
            for (auto& p : feasiblePaths) {
                cout << path[0].row << path[0].col << " ";
                for (auto& cell : p.first) {
                    cout << "(" << cell.row << ", " << cell.col << ") ";
                }
                cout << p.second << endl;
            }
        }
    }
}






int main(){

    fastread();

    // freeopen("--------", 'r', stdin)  ;
    // freeopen("--------", 'w', stdout) ;

    int t;
    cin>>t;

    while(t--){
        int n, M;
        // cout << "Enter the size of the matrix: ";
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n));
        // cout << "Enter the matrix:" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }
        // cout << "Enter the oxygen capacity: ";
        cin >> M;

        scubaDiving(matrix, M);


        return 0;


    }


}