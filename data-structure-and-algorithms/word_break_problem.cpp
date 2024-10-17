#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool canBreak(string s, unordered_set<string> &dict)
{
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end())
            {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}

int main()
{
    unordered_set<string> dict = {"apple", "pen", "applepen", "pine", "pineapple"};
    string s = "pineapplepenapple";

    if (canBreak(s, dict))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
