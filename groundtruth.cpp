#include <iostream>
#include <cstring>

using namespace std;

char shift_char(char c, int shift) {
    // Shift a character 'c' by 'shift' units to the right
    // The shift is circular, so 'z' shifted by 1 unit becomes 'a'
    return char(((c - 'a' + shift) % 26) + 'a');
}

bool can_convert(char C[], char F[], int N, int length) {
    for (int i = 0; i < length; ++i) {
        // Calculate the number of units needed to shift from C to F
        int shift = (F[i] - C[i] + 26) % 26;

        // Check if it's possible to shift in N seconds
        if (shift > N) {
            return false;
        }

        // Update N after each shift
        N -= shift;
    }

    return true;
}

int main() {
    char C[100], F[100];
    int N;

    // Read input
    cin >> C;
    cin >> F;
    cin >> N;

    // Get the length of the character arrays
    int length = strlen(C);

    // Check if the conversion is possible and print the result
    if (can_convert(C, F, N, length)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
