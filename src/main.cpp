#include <iostream>

#include "Board.cpp"

using namespace std;

template <size_t N>
void test(array<array<int, N>, N> x) {
    cout << x[0].size() << endl;
}

int main() {
    vector< vector<int> > testBoardArr = {{
        {{0, 0, 0, 0, 3}},
        {{0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0}},
        {{3, 0, 0, 0, 1}}
    }};

    vector< vector<char> > cH = {{
        {{'>', 0, 0, 0}},
        {{0, 0, 0, '<'}},
        {{0, 0, '<', 0}},
        {{0, 0, 0, 0}},
        {{0, 0, 0, 0}}
    }};

    vector< vector<char> > cV = {{
        {{0, 0, 'v', 'v', 0}},
        {{0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, '^'}},
        {{'v', 0, 'v', 0, 0}}
    }};

    // cout << testBoardArr[0].size() << endl;

    // test(testBoardArr);
    // int* testBoardArr[5];
    // for (int i = 0; i < 5; i++) {
    //     testBoardArr[i] = board[i];
    // }

    Board b(testBoardArr, cH, cV);
    cout << b << endl;

}