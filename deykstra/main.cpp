#include <iostream>
#include <iomanip>

int main() {
    const int n = 8;
    const int inf = 100000; // в качестве бесконечности используем число, в несколько раз превышающее веса ребер

    int W[n][n] = {
            {0,   inf, 24,  inf, 15,  27,  30,  inf},
            {inf, 0,   inf, 6,   17,  inf, 23,  inf},
            {24,  inf, 0,   inf, inf, 2,   inf, inf},
            {inf, 6,   inf, 0,   inf, 26,  inf, 11},
            {15,  17,  inf, inf, 0,   inf, 18,  inf},
            {27,  inf, 2,   26,  inf, 0,   inf, 12},
            {30,  23,  inf, inf, 18,  inf, 0,   1},
            {inf, inf, inf, 11,  inf, 12,  1,   0}
    };
    int b = 3;
    int t = 8;
    int L[n], C[n], P[n];

/* задаем начальные условия */
    int mk = b;

    for (int i = 0; i < n; ++i) {
        if (i == b - 1) {
            L[i] = 0;
            C[i] = 1;
        } else {
            L[i] = inf;
            C[i] = 0;
        }
        P[i] = 0;
    }
/* для красивого вывода*/
    std::cout << std::setw(1) << "k " << std::setw(4) << "T(k)";
    for (int j = 0; j < n; ++j) {
        std::cout << std::setw(3) << j + 1 << ' ';
    }
    std::cout << "\n";
/* бесконечный цикл с подсчетом числа итераций */
    for (int k = 1;;++k) {

        int min = inf;
        int newMk = 0;

        for (int i = 0; i < n; ++i) {
            if (C[i] == 0) {
                if (L[mk - 1] + W[mk - 1][i] < L[i]) {
                    L[i] = L[mk - 1] + W[mk - 1][i];
                    P[i] = mk;
                }

                if (L[i] < min) {
                    min = L[i];
                    newMk = i + 1;
                }
            }
        }

/* если не обновилось, то либо конец, либо изолированная вершина */
        if ((min == inf) or (newMk == 0))  {
            break;
        }

        mk = newMk;
        C[mk - 1] = 1;

/* вывод данного шага */
        std::cout << k << " L : ";
        for (int i : L) {
            if (i == inf) {
                std::cout << std::setw(3) << "inf" << " ";
            } else {
                std::cout << std::setw(3) << i << " ";
            }
        }
        std::cout << "\n";

        std::cout << k << " P : ";
        for (int i : P) {
            std::cout << std::setw(3) << i << " ";
        }
        std::cout << "\n";

        std::cout << k << " C : ";
        for (int i : C) {
            std::cout << std::setw(3) << i << " ";
        }
        std::cout << "\n";
        std::cout << std::setw(18) << "mk = " << mk << "\n";
    }

    return 0;
}
