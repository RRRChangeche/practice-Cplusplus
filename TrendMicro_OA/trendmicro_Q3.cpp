// you can use includes, for example:
// #include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

string solution(string &S)
{
    // Implement your solution here
    // aababbaa
    //
    // a?bb
    //  i
    // - check both side i-2 ~ i+2
    //

    vector<char> chars = {'a', 'b'};
    for (auto i = 0u; i < S.length(); i++)
    {
        if (S[i] != '?')
        {
            continue;
        }

        for (auto c : chars)
        {
            int l = max(0, (int)i - 2);
            int r = min((int)S.length() - 1, (int)i + 2);
            S[i] = c;
            int countAL = 0, countAR = 0;
            int countBL = 0, countBR = 0;
            while (l <= i)
            {
                countAL += S[l] == 'a';
                countBL += S[l] == 'b';
                l++;
            }
            while (i <= r)
            {
                countAR += S[r] == 'a';
                countBR += S[r] == 'b';
                r--;
            }

            if (max(countAL, countBL) < 3 and max(countAR, countBR) < 3)
            {
                break;
            }
        }
    }

    return S;
}

int main()
{
    string test;
    test = "a?bba";
    test = "a??????bba";
    string ans = solution(test);
    cout << "ans: " << ans;

    return 0;
}
