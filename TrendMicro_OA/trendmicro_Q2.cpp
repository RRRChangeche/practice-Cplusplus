// you can use includes, for example:
// #include <algorithm>
#include <unordered_set>
#include <string>
#include <iostream>

using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool isPalindrome(const string &s, int l, int r)
{
    while (l < r)
    {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }

    return true;
}

int solution(string &S)
{
    // Implement your solution here
    // - check the s is palindrome or not
    // aabaa  aabbaa
    int l = 0;
    int r = S.length() - 1;

    // if S is not Palindrome, return 0;
    if (!isPalindrome(S, l, r))
    {
        return 0;
    }

    // if S is already palindrome
    unordered_set<char> used(S.begin(), S.end());
    if (used.size() == 1)
    {
        return S.length();
    }

    return 1;
}

int main()
{
    string test = "bbbb";
    int ans = solution(test);
    cout << "ans: " << ans;
    return 0;
}
