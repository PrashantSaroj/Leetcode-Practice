#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int b5 = 0, b10 = 0, b20 = 0;
        for (int b : bills)
        {
            switch (b)
            {
            case 5:
                b5 += 1;
                break;
            case 10:
                b10 += 1;
                if (b5)
                {
                    b5 -= 1;
                }
                else
                {
                    return false;
                }
                break;
            case 20:
                b20 += 1;
                if (b10 && b5)
                {
                    b5 -= 1;
                    b10 -= 1;
                }
                else if (b5 >= 3)
                {
                    b5 -= 3;
                }
                else
                {
                    return false;
                }
                break;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> bills1{5, 5, 5, 10, 20};
    vector<int> bills2{5, 5, 10, 10, 20};
    Solution sol;
    cout << sol.lemonadeChange(bills1) << endl
         << sol.lemonadeChange(bills2);
    return 0;
}
