#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void checkTypingAccuracy(string original, string typed) {
    int n = original.length();
    int matched = 0;
    int firstMismatch = -1;

    for (int i = 0; i < n; i++) {
        if (original[i] == typed[i]) {
            matched++;
        } else if (firstMismatch == -1) {
            firstMismatch = i;
        }
    }

    double accuracy = (double)matched / n * 100;

    cout << "Matched: " << matched << "/" << n;
    cout << " | Accuracy: " << fixed << setprecision(2)
         << accuracy << "%";

    if (firstMismatch == -1) {
        cout << " | No Mismatches" << endl;
    } else {
        cout << " | First Mismatch at position "
             << firstMismatch + 1 << " ('"
             << original[firstMismatch] << "' vs '"
             << typed[firstMismatch] << "')" << endl;
    }
}

int main() {
    string original, typed;

    cout << "Enter original passage: ";
    getline(cin, original);

    cout << "Enter typed passage: ";
    getline(cin, typed);

    if (original.length() != typed.length()) {
        cout << "Error: Strings must be of equal length." << endl;
        return 0;
    }

    checkTypingAccuracy(original, typed);

    return 0;
}