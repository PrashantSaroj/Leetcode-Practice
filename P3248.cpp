#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int finalPositionOfSnake(int n, vector<string> &commands)
    {
        int netH = 0, netV = 0;
        for (string cmd : commands)
        {
            if (cmd == "UP")
            {
                netV -= 1;
            }
            else if (cmd == "DOWN")
            {
                netV += 1;
            }
            else if (cmd == "RIGHT")
            {
                netH += 1;
            }
            else if (cmd == "LEFT")
            {
                netH -= 1;
            }
        }
        return netV * n + netH;
    }
};

int main()
{
    vector<string> commands{"DOWN", "RIGHT", "UP"};
    int n = 3;
    cout << Solution().finalPositionOfSnake(n, commands) << endl;
    return 0;
}
