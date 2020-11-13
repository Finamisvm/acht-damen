#include <iostream>
using namespace std;

void placeQueen(bool[8][8]);
bool isValid(bool[8][8], int, int);

int main()
{

    bool Schachbrett[8][8];

    for (int i{0}; i < 8; i++)
    {
        for (int j{0}; j < 8; j++)
        {
            Schachbrett[i][j] = false;
        }
    }

    placeQueen(Schachbrett);

    for (int i{0}; i < 8; i++)
    {
        cout << endl;
        for (int j{0}; j < 8; j++)
        {
            cout << Schachbrett[i][j] << " ";
        }
    }
    cout << endl
         << endl;

    return 0;
}

void placeQueen(bool Schachbrett[8][8])
{
    int noOfQueens{0};
    int i{0};
    int j{0};
    int lastQRow{};
    int lastQCol{};
    int counter{};
    {
        // if (noOfQueens > 0)
        // {
        //     cout << endl
        //          << "Invalid at: " << i << " " << j
        //          << " - " << noOfQueens;
        //     Schachbrett[lastQRow][lastQCol] = 0;
        //     noOfQueens--;
        // }
        for (; i < 8; i++)
        {
            if (j == 8)
                j = 0;
            for (; j < 8; j++)
            {
                if (isValid(Schachbrett, i, j))
                {
                    cout << endl
                         << " + " << noOfQueens;
                    Schachbrett[i][j] = 1;
                    lastQRow = i;
                    lastQCol = j;
                    noOfQueens++;
                    j = 0;
                    break;
                }
                else if (j < 7)
                {
                    continue;
                }
                else
                {
                    for (int r{i}; r >= 0; r--)
                    {
                        for (int c{j}; c >= 0; c--)
                        {
                            if (Schachbrett[r][c] == 1)
                            {
                                lastQRow = r;
                                lastQCol = c;
                                r = 0;
                                break;
                            }
                        }
                    }
                    cout << endl
                         << "Invalid at: " << i << " " << j
                         << " - " << noOfQueens;
                    Schachbrett[lastQRow][lastQCol] = 0;
                    noOfQueens--;
                    j = lastQCol;
                    i = lastQRow;
                }
            }
            if (i == 7 && noOfQueens < 8)
            {
                counter++;
                cout << endl << endl <<  "OXO ---- try number: " << (counter + 1) << endl;
                for (int g{0}; g < 8; g++)
                {
                    for (int h{0}; h < 8; h++)
                    {
                        Schachbrett[g][h] = false;
                    }
                }
                i = -1;
                j = counter;
                noOfQueens = 0;
            }
        }
    }
}

bool isValid(bool Schachbrett[8][8], int row, int col)
{
    int i{row};
    int j{col};

    for (int x = 0; x < 8; x++)
    {
        if (Schachbrett[x][col] == 1)
            return false;
    }

    for (int y{0}; y < 8; y++)
    {
        if (Schachbrett[row][y] == 1)
            return false;
    }

    while (i >= 0 && j >= 0)
    {
        if (Schachbrett[i][j] == 0)
        {
            i--;
            j--;
        }
        else
            return false;
    }
    i = row;
    j = col;

    while (i >= 0 && j < 8)
    {
        if (Schachbrett[i][j] == 0)
        {
            i--;
            j++;
        }
        else
            return false;
    }
    cout << endl
         << "Valid " << row << " " << col << endl;
    return true;
}