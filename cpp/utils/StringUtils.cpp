#include <iostream>
#include <vector>

using namespace std;

vector<string> split(string &s, char delimiter = ' ') {
    vector<string> splitted;
    vector<char> curr;

    for (char c : s) {
        if (c == delimiter) {
            splitted.push_back(string(curr.begin(), curr.end()));
            curr = {};
        } else {
            curr.push_back(c);
        }
    }
    // process last word
    splitted.push_back(string(curr.begin(), curr.end()));
    return splitted;
}
