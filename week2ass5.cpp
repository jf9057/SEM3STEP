#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

void printFilteredWordFrequency(string feedback) {
    string stopWords[] = {"the", "was", "and", "a", "is"};

    for (int i = 0; i < feedback.length(); i++) {
        if (ispunct(feedback[i])) {
            feedback[i] = ' ';
        } else {
            feedback[i] = tolower(feedback[i]);
        }
    }

    stringstream ss(feedback);
    string word;
    map<string, int> frequency;

    while (ss >> word) {
        bool isStopWord = false;

        for (int i = 0; i < 5; i++) {
            if (word == stopWords[i]) {
                isStopWord = true;
                break;
            }
        }

        if (!isStopWord) {
            frequency[word]++;
        }
    }

    vector<pair<string, int>> words(
        frequency.begin(), frequency.end()
    );

    sort(words.begin(), words.end(),
         [](pair<string, int> a, pair<string, int> b) {
             return a.second > b.second;
         });

    for (auto word : words) {
        cout << word.first << ": "
             << word.second << endl;
    }
}

int main() {
    string feedback;

    cout << "Enter feedback: ";
    getline(cin, feedback);

    printFilteredWordFrequency(feedback);

    return 0;
}