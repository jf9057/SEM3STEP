#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void parseInventoryRecord(string csvLine) {
    string product, sku, quantity;
    stringstream ss(csvLine);

    getline(ss, product, ',');
    getline(ss, sku, ',');
    getline(ss, quantity, ',');

    string extra;

    if (product == "" || sku == "" || quantity == "" ||
        getline(ss, extra, ',')) {
        cout << "Invalid Record" << endl;
    } else {
        cout << "Product: " << product
             << " | SKU: " << sku
             << " | Qty: " << quantity << endl;
    }
}

int main() {
    string csvLine;

    cout << "Enter record: ";
    getline(cin, csvLine);

    parseInventoryRecord(csvLine);

    return 0;
}