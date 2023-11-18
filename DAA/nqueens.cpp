#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void printBoard(const vector<vector< bool > > &board)
{
    for (size_t i = 0; i < board.size(); ++i)
    {
        for (size_t j = 0; j < board[i].size(); ++j)
        {
            cout << (board[i][j] ? "1 " : "0 ");
        }
        cout << endl;
    }
}

void solve(vector< vector< bool > > &board, size_t row, vector< bool> &cols, vector< bool > &ndiag, vector< bool > &rdiag, size_t skp)
{
    if (row == skp)
    {
        solve(board, row + 1, cols, ndiag, rdiag, skp);
    }
    if (row == board.size())
    {
        printBoard(board);
        return;
    }

    for (size_t col = 0; col < cols.size(); ++col)
    {
        if ((cols[col] == false) && (ndiag[row + col] == false) && (rdiag[row - col + board.size() - 1] == false))
        {
            board[row][col] = true;
            cols[col] = true;
            ndiag[row + col] = true;
            rdiag[row - col + board.size() - 1] = true;
            solve(board, row + 1, cols, ndiag, rdiag, skp);
            board[row][col] = false;
            cols[col] = false;
            ndiag[row + col] = false;
            rdiag[row - col + board.size() - 1] = false;
        }
    }
}

size_t estimateSpaceComplexity(const vector<vector< bool > > &board, const vector< bool > &cols, const vector< bool > &ndiag, const vector< bool > &rdiag)
{
    size_t space_used = 0;
    space_used += sizeof(bool) * board.size() * board[0].size(); // Board
    space_used += sizeof(bool) * cols.size();                   // cols vector
    space_used += sizeof(bool) * ndiag.size();                   // ndiag vector
    space_used += sizeof(bool) * rdiag.size();                   // rdiag vector
    return space_used;
}

int main()
{
    size_t n;
    cout << "Enter n: ";
    cin >> n;

    vector<vector< bool > > board(n, vector< bool >(n, false));
    vector<bool> cols(n);
    vector<bool> ndiag(2 * n - 1, false);
    vector<bool> rdiag(2 * n - 1, false);

    cout << "Enter a row and col to keep the first queen as true: ";
    size_t r, c;
    cin >> r >> c;

    board[r][c] = true;
    cols[c] = true;
    ndiag[r + c] = true;
    rdiag[r - c + n - 1] = true;

    chrono::high_resolution_clock::time_point start_time = chrono::high_resolution_clock::now();
    solve(board, 0, cols, ndiag, rdiag, r);
    chrono::high_resolution_clock::time_point stop_time = chrono::high_resolution_clock::now();
    chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(stop_time - start_time);

    size_t space_used = estimateSpaceComplexity(board, cols, ndiag, rdiag);

    cout << "Time taken: " << duration.count() << " microseconds\n";
    cout << "Space used: " << space_used << " bytes\n";

    return 0;
}
