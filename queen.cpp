#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int x[20], count = 0;

int place(int k, int i)
{
    for (int j = 1; j <= k - 1; j++)
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return 0;
    }
    return 1;
}

void NQueens(int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (place(k, i))
        {
            x[k] = i;
            if (k == n)
            {
                count++;
                cout << "Solution " << count << ":" << endl;
                for (int j = 1; j <= n; j++)
                {
                    for (int l = 1; l <= n; l++)
                    {
                        if (x[j] == l)
                            cout << "Q ";
                        else
                            cout << "- ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            else
            {
                NQueens(k + 1, n);
            }
        }
    }
}

void main()
{
    clrscr();
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;

    if (n < 4)
    {
        cout << "No solutions exist for N < 4." << endl;
        getch();
        return;
    }

    NQueens(1, n);
    cout << "Total solutions: " << count << endl;
    getch();
}
