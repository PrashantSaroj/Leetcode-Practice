#include <bits/stdc++.h>
using namespace std;

class Solution {
    map<char, vector<vector<char>>> charMap = {
        {'2', {{'a'}, {'b'}, {'c'}}},
        {'3', {{'d'}, {'e'}, {'f'}}},
        {'4', {{'g'}, {'h'}, {'i'}}},
        {'5', {{'j'}, {'k'}, {'l'}}},
        {'6', {{'m'}, {'n'}, {'o'}}},
        {'7', {{'p'}, {'q'}, {'r'}, {'s'}}},
        {'8', {{'t'}, {'u'}, {'v'}}},
        {'9', {{'w'}, {'x'}, {'y'}, {'z'}}}};

    /**
     * s1 = {{'a}, {'b'}}
     * s2 = {{'c'}, {'d}}
     * s1 x s2 = {{'a', 'c'}, {'a', 'd'}...}
     */
    vector<vector<char>> crossProduct(vector<vector<char>> &s1, vector<vector<char>> &s2) {
        vector<vector<char>> product;
        for (vector<char> &c1 : s1) {
            for (vector<char> &c2 : s2) {
                vector<char> currRes(c1.begin(), c1.end());
                currRes.insert(currRes.end(), c2.begin(), c2.end());
                product.push_back(currRes);
            }
        }
        return product;
    }

    vector<string> vecToString(vector<vector<char>> &s) {
        vector<string> res;
        for (vector<char> v : s) {
            res.push_back(string(v.begin(), v.end()));
        }
        return res;
    }

   public:
    vector<string> letterCombinations(string digits) {
        int N = digits.size();

        if (N == 0) {
            return vector<string>{};
        }

        if (N == 1) {
            return vecToString(charMap[digits[0]]);
        }

        vector<vector<vector<char>>> crossProductStrs(N);
        for (int i = 0; i < N; i++) {
            crossProductStrs[i] = charMap[digits[i]];
        }

        vector<vector<char>> vecResult = crossProduct(crossProductStrs[0], crossProductStrs[1]);
        for (int i = 2; i < N; i++) {
            vecResult = crossProduct(vecResult, crossProductStrs[i]);
        }

        return vecToString(vecResult);
    }
};

int main() {
    string testCases[] = {"234", "2", ""};
    Solution sol;

    for (string &tc : testCases) {
        vector<string> combinations = sol.letterCombinations(tc);
        for (string &comb : combinations) {
            cout << comb << " ";
        }
        cout << endl;
    }

    return 0;
}
