#include <iostream>
#include <iomanip>

int main() {
    const int n = 8;
    const int inf = 100000; // в качестве бесконечности используем число, в несколько раз превышающее веса ребер

    int P[n][n] = {
            { 1, 0, 3, 0, 5, 6, 7, 0 },
            { 0, 2, 0, 4, 5, 0, 7, 0 },
            { 1, 0, 3, 0, 0, 6, 7, 0 },
            { 0, 2, 0, 4, 0, 6, 0, 8 },
            { 1, 2, 0, 0, 5, 0, 7, 0 },
            { 1, 0, 3, 4, 0, 6, 0, 8 },
            { 1, 2, 0, 0, 5, 0, 7, 8 },
            { 0, 0, 0, 4, 0, 6, 7, 8 },
    };

    int L[n][n] = {
            { 0, inf, 24, inf, 15, 27, 30, inf },
            { inf, 0, inf, 6, 17, inf, 23, inf },
            { 24, inf, 0, inf, inf, 2, inf, inf },
            { inf, 6, inf, 0, inf, 26, inf, 11 },
            { 15, 17, inf, inf, 0, inf, 18, inf },
            { 27, inf, 2, 26, inf, 0, inf, 12 },
            { 30, 23, inf, inf, 18, inf, 0, 1 },
            { inf, inf, inf, 11, inf, 12, 1, 0 }
    };

    int T = 0;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {

            /* не имеет смысла проверять возможность улучшения, если i == k или L[i][k] - бесконечность */

            if ((i != k) && (L[i][k] != inf)) {
                for (int j = 0; j < n; ++j) {

                    /* аналогично для столбца */

                    if ((j != k) && (j != i) && (L[k][j] != inf)) {

                        T = L[k][j] + L[i][k];
                        /* если текущая ячейка - бесконечность или новое значение меньше, то обновляем */
                        if ((L[i][j] == inf) || (T < L[i][j])) {
                            L[i][j] = T;
                            /* берём из k-го столбца вершину */
                            P[i][j] = P[i][k];
                        }

                    }
                }
            }
        }
        /* вывод после каждого шага */

        std::cout <<  "\nk = " << k + 1 << "\n\n";

        for (auto & i : L) {
            for (double j : i) {
                if (j == inf) {
                    std::cout << std::setw(3) << "inf" << " ";
                } else {
                    std::cout << std::setw(3) << j << " ";
                }
            }
            std::cout << '\n';
        }

        std::cout << '\n';

        for (auto & i : P) {
            for (int j : i) {
                std::cout << std::setw(1) << j << " ";
            }
            std::cout << '\n';
        }
    }

    return 0;
}