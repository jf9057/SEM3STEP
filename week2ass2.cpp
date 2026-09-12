#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string reverseEachWord(string sentence) {
    stringstream ss(sentence);
    string word, result;

    while (ss >> word) {
        string reversed = "";

        for (int i = word.length() - 1; i >= 0; i--) {
            reversed += word[i];
        }

        if (result != "") {
            result += " ";
        }

        result += reversed;
    }

    return result;
}

int main() {
    string sentence;

    cout << "Enter sentence: ";
    getline(cin, sentence);

    cout << reverseEachWord(sentence) << endl;

    return 0;
}