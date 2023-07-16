#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int> > matrix)
 {
        for(int i = 0; i < matrix.size(); i++)
            {
                for(int j = 0; j < matrix[i].size(); j++)
                {
                    cout << matrix[i][j] << ' ';
                }
                 cout << endl;
            }
}
void multiply(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C)
 {
             int N = 4;
        for (int i = 0; i < N; i++)
         {
             for (int j = 0; j < N; j++)
            {
                    C[i][j] = 0;
                for (int k = 0; k < N; k++)
                {
                     C[i][j] += A[i][k]*B[k][j];
                }
            }
        }
}
int main()
{
    vector<vector<int>> A = {{2, 2, 3, 1},{1, 4, 1, 2},{2, 3, 1, 1}, {1, 3, 1, 2}};

    vector<vector<int>> B = {{2, 1, 2, 1},{3, 1, 2, 1},{3, 2, 1, 1}, {1, 4, 3, 2}};

    vector<vector<int>> C(4, vector<int>(4));
    multiply(A, B, C);
    print(C);
return 0;

}




