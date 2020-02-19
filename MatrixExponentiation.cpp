#include <bits/stdc++.h>

using namespace std;

#define ll long long

void multiply(ll matA[2][2], ll matB[2][2]) {
    ll temp[2][2];
    int i, j, k;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            temp[i][j] = 0;
            for (k = 0; k < 2; k++)
                temp[i][j] += (matA[i][k] % 1000000007 * matB[k][j] % 1000000007) % 1000000007;
        }
    }
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            matA[i][j] = temp[i][j];

}

void power(ll matrix[2][2], ll term, ll first, ll second) {
    ll temp_matrix[2][2] = {{1, 1},
                            {1, 0}};
    if (term == 0) {
        matrix[0][0] = 1;
        matrix[0][1] = 0;
        matrix[1][0] = 0;
        matrix[1][1] = 1;
        return;
    }
    power(matrix, term / 2, first, second);
    multiply(matrix, matrix);
    if (term & 1)
        multiply(matrix, temp_matrix);
}

ll ExponentFunction(ll term, ll first, ll second) {
    ll matrix[2][2] = {{1, 1},
                       {1, 0}};
    if (term == 0)
        return first;
    if (term == 1)
        return second;
    power(matrix, term - 1, first, second);
    return ((matrix[0][0] % 1000000007 * second % 1000000007) % 1000000007 +
            (matrix[0][1] % 1000000007 * first % 1000000007) % 1000000007) % 1000000007;

}

int main() {
    ll test_case, first, second, term;
    cin >> test_case;
    while (test_case--) {
        cin >> first >> second >> term;
        cout << ExponentFunction(term, first, second) << endl;
    }
    return 0;
}