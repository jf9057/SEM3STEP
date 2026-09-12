#include <iostream>
using namespace std;

void analyzeInventory(int sectionA[], int sectionB[], int n) {
    int totalA = 0, totalB = 0;
    int highest = sectionA[0];
    int section = 1;
    int index = 0;

    for (int i = 0; i < n; i++) {
        totalA += sectionA[i];
        totalB += sectionB[i];

        if (sectionA[i] > highest) {
            highest = sectionA[i];
            section = 1;
            index = i;
        }

        if (sectionB[i] > highest) {
            highest = sectionB[i];
            section = 2;
            index = i;
        }
    }

    cout << "Section A Total: " << totalA << endl;
    cout << "Section B Total: " << totalB << endl;

    if (totalA == totalB) {
        cout << "Status: Balanced" << endl;
    } else {
        cout << "Status: Not Balanced" << endl;
    }

    cout << "Highest Quantity: " << highest
         << " (Section " << (section == 1 ? "A" : "B")
         << ", Item " << index + 1 << ")" << endl;
}

int main() {
    int n;

    cout << "Enter number of items: ";
    cin >> n;

    int sectionA[n], sectionB[n];

    cout << "Enter quantities for Section A: ";
    for (int i = 0; i < n; i++) {
        cin >> sectionA[i];
    }

    cout << "Enter quantities for Section B: ";
    for (int i = 0; i < n; i++) {
        cin >> sectionB[i];
    }

    analyzeInventory(sectionA, sectionB, n);

    return 0;
}