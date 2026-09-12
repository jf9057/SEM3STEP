#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string normalizeCode(string raw) {
    string code = "";

    for (int i = 0; i < raw.length(); i++) {
        if (raw[i] != ' ') {
            code += raw[i];
        }
    }

    for (int i = 0; i < 3 && i < code.length(); i++) {
        code[i] = toupper(code[i]);
    }

    return code;
}

string validateAndFormat(string code) {
    if (code.length() != 13) {
        return "Invalid: Wrong length";
    }

    for (int i = 0; i < 3; i++) {
        if (!isalpha(code[i])) {
            return "Invalid: Non-letter publisher code";
        }
    }

    for (int i = 3; i < 13; i++) {
        if (!isdigit(code[i])) {
            return "Invalid: Non-digit body";
        }
    }

    string publisher = code.substr(0, 3);
    string year = code.substr(3, 4);
    string catalog = code.substr(7, 6);

    return "[" + publisher + "] YEAR: " + year +
           " | CATALOG: " + catalog;
}

int main() {
    string raw;

    cout << "Enter code: ";
    getline(cin, raw);

    string code = normalizeCode(raw);

    cout << validateAndFormat(code) << endl;

    return 0;
}