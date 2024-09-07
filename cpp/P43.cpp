#include <bits/stdc++.h>

using namespace std;

class Solution {
    int char2Int(char c) {
        return c - '0';
    }

    char int2Char(int i) {
        return char(i + '0');
    }

    pair<int, int> addChars(char c1, char c2, int carry) {
        int result = char2Int(c1) + char2Int(c2) + carry;
        return {result / 10, result % 10};
    }

    pair<int, int> multiply(char c1, char c2, int carry) {
        int result = char2Int(c1) * char2Int(c2) + carry;
        return {result / 10, result % 10};
    }

    vector<char> multiply(string &num1, char c) {
        vector<char> result;
        int carry = 0;

        for (int i = num1.size() - 1; i >= 0; i--) {
            pair<int, int> tmp = multiply(num1[i], c, carry);
            carry = tmp.first;
            result.push_back(int2Char(tmp.second));
        }

        if (carry > 0) {
            result.push_back(int2Char(carry));
        }

        reverse(result.begin(), result.end());
        return result;
    }

    vector<char> add(vector<char> &num1, vector<char> &num2) {
        vector<char> result;

        int i1 = num1.size() - 1, i2 = num2.size() - 1, carry = 0;
        while (i1 >= 0 && i2 >= 0) {
            pair<int, int> tmp = addChars(num1[i1], num2[i2], carry);
            carry = tmp.first;
            result.push_back(int2Char(tmp.second));
            i1--;
            i2--;
        }

        while (i1 >= 0) {
            pair<int, int> tmp = addChars(num1[i1], '0', carry);
            carry = tmp.first;
            result.push_back(int2Char(tmp.second));
            i1--;
        }

        while (i2 >= 0) {
            pair<int, int> tmp = addChars('0', num2[i2], carry);
            carry = tmp.first;
            result.push_back(int2Char(tmp.second));
            i2--;
        }

        if (carry > 0) {
            result.push_back(int2Char(carry));
        }

        reverse(result.begin(), result.end());
        return result;
    }

   public:
    string multiply(string num1, string num2) {
        vector<char> result = {'0'};

        int placeValue = num2.size() - 1;
        for (char c2 : num2) {
            vector<char> curResult = multiply(num1, c2);
            for (int i = 0; i < placeValue; i++) {
                curResult.push_back('0');
            }
            placeValue--;

            result = add(curResult, result);
        }

        return string(result.begin(), result.end());
    }
};

int main() {
    Solution sol;

    cout << sol.multiply("123", "456") << endl;

    return 0;
}
