// you can use includes, for example:
// #include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool solution(string &moves)
{
    // Implement your solution here
    // ^ > v <
    //
    // - if the moves is retangle, it must be cw or ccw
    // - it follow the order:
    // - cw: ^ > v < ^ > v <
    // - ccw: ^ < v > ^ < v >
    //
    //
    string cw = "^>v<^>v<";
    string ccw = "^<v>^<v>";

    // find first move and scond move
    // > v v v v v < < ^ ^ ^
    // i
    size_t i = 0;
    string simMoves = "";
    vector<pair<char, int>> moveCount;
    for (; i < moves.length(); i++)
    {
        int count = 1;
        char curDir = moves[i];
        simMoves += curDir;
        // skip the same directions
        while (i + 1 < moves.length() and curDir == moves[i + 1])
        {
            i++;
            count++;
        }

        moveCount.push_back({curDir, count});
    }

    cout << "simMoves: " << simMoves << '\n';
    cout << "moveCount.size(): " << moveCount.size() << '\n';
    // early return if moves cannot make a retangle
    if (moveCount.size() != 5 and moveCount.size() != 4)
    {
        cout << "cannot make a retangle\n";
        return false;
    }

    // check simMoves is cw or ccw
    int j = 0, k = 0;
    while (j < cw.length() and cw[j] != simMoves[0])
    {
        j++;
    }
    while (k < ccw.length() and ccw[k] != simMoves[0])
    {
        k++;
    }
    string direction = cw[j + 1] == simMoves[1] ? cw : ccw;
    j = (direction == cw) ? j : k;

    // check is retangle or not
    i = 0;
    for (; i < simMoves.length(); i++)
    {
        if (simMoves[i] != direction[j++])
        {
            return false;
        }
    }

    // count steps  > v < ^ >
    int stepX = moveCount[0].second + ((moveCount.size() > 4) ? moveCount[4].second : 0) - moveCount[2].second;
    int stepY = moveCount[1].second - moveCount[3].second;
    if (stepX != 0 or stepY != 0)
    {
        return false;
    }

    return true;
}

int main()
{
    string test = ">>>>vvvv<<<<^^^^";
    // string test = ">v<^>";
    cout << "originMoves: " << test << '\n';
    bool ans = solution(test);
    cout << "ans: " << ans;
    return 0;
}
