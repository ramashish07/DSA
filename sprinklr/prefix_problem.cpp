#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> calculateZArray(const string& str) {
    int n = str.length();
    vector<int> Z(n, 0);
    int left = 0, right = 0;

    for (int i = 1; i < n; i++) {
        if (i > right) {
            left = right = i;
            while (right < n && str[right - left] == str[right]) {
                right++;
            }
            Z[i] = right - left;
            right--;
        } else {
            int k = i - left;
            if (Z[k] < right - i + 1) {
                Z[i] = Z[k];
            } else {
                left = i;
                while (right < n && str[right - left] == str[right]) {
                    right++;
                }
                Z[i] = right - left;
                right--;
            }
        }
    }

    return Z;
}

void compareSubstrings(const string& input) {
    int n = input.length();
    vector<int> Z = calculateZArray(input);

    for (int prefixLen = 1; prefixLen < n; prefixLen++) {
        int greaterCount = 0, smallerCount = 0, equalCount = 0;

        for (int i = prefixLen; i < n; i++) {
            int zValue = Z[i];

            if (zValue == prefixLen) {
                equalCount++;
            } else if (input[i] < input[zValue]) {
                smallerCount++;
            } else {
                greaterCount++;
            }
        }

        cout << "Prefix of length " << prefixLen << ": ";
        cout << "Greater: " << greaterCount << ", Smaller: " << smallerCount << ", Equal: " << equalCount << endl;
    }
}

int main() {
    string input;
    // cout << "Enter the input string: ";
    cin >> input;

    compareSubstrings(input);

    return 0;
}
