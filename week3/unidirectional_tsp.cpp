#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cassert>
using namespace std;

int m, n;
int matrix[15][105];
int minPath[15][105];
int nextRow[15][105];

void printAnswerPath(int a, int c)
{
    if (nextRow[a][c] == -1) {
        cout << a + 1 << endl;
        return;
    }
    
    cout << a + 1 << ' ';
    printAnswerPath(nextRow[a][c], c + 1);
}

void printAnswer()
{
    int tmpMin = minPath[0][0];
    int answerRow = 0;
    for (int i = 1; i < m; i++) {
        if (tmpMin > minPath[i][0]) {
            tmpMin = minPath[i][0];
            answerRow = i;
        }
    }
    
    printAnswerPath(answerRow, 0);
    cout << minPath[answerRow][0] << endl;
}

int main()
{
    int i, j, k;
    while (cin >> m >> n) {
        /* 行列の情報を格納 */
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        
        /* minPathの最後の列はその位置の値そのものを代入 */
        for (i = 0; i < m; i++) {
            minPath[i][n - 1] = matrix[i][n - 1];
            nextRow[i][n - 1] = -1;
        }
        
        /* 列の数が1のとき */
        if (m == 1) {
            for (i = n - 2; i >= 0; i--) {
                minPath[0][i] = minPath[0][i + 1] + matrix[0][i];
                nextRow[0][i] = 0;
            }
        } else {
            /* 各要素について、そこまでの最短経路の重さを計算する */
            int tmp;
            int tmpNext[3];
            for (j = n - 2; j >= 0 ; j--) {
                for (i = 0; i < m; i++) {
                    if (i == 0) {
                        tmpNext[0] = 0;
                        tmpNext[1] = 1;
                        tmpNext[2] = m - 1;
                    } else if (i == m - 1) {
                        tmpNext[0] = 0;
                        tmpNext[1] = m - 2;
                        tmpNext[2] = m - 1;
                    } else {
                        tmpNext[0] = i - 1;
                        tmpNext[1] = i;
                        tmpNext[2] = i + 1;
                    }
                    for (k = 0; k < 3; k++) {
                        tmp = minPath[tmpNext[k]][j + 1] + matrix[i][j];
                        if (tmp < minPath[i][j] || k == 0) {
                            minPath[i][j] = tmp;
                            nextRow[i][j] = tmpNext[k];
                        }
                    }
                }
            }
        }
        
        printAnswer();
    }
    
    return EXIT_SUCCESS;
}
