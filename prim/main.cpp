#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    const int n = 8;
    const int inf = 100000; // в качестве бесконечности используем число, в несколько раз превышающее веса ребер

    /* список помеченных вершин(строк) */
    std::vector<int> markedVertexes;
    /* список невычеркнутых вершин(столбцов) */
    std::vector<int> vertexes = { 1, 2, 3, 4, 5, 6, 7, 8 };

    int W[n][n] = {
            { 0, inf, 24, inf, 15, 27, 30, inf },
            { inf, 0, inf, 6, 17, inf, 23, inf },
            { 24, inf, 0, inf, inf, 2, inf, inf },
            { inf, 6, inf, 0, inf, 26, inf, 11 },
            { 15, 17, inf, inf, 0, inf, 18, inf },
            { 27, inf, 2, 26, inf, 0, inf, 12 },
            { 30, 23, inf, inf, 18, inf, 0, 1 },
            { inf, inf, inf, 11, inf, 12, 1, 0 }
    };

    /* начинаем с вершины v1 */
    markedVertexes.push_back(1);
    vertexes.erase(vertexes.cbegin());
    std::cout << "Шаг " << 0 <<". v1" << ". Вес " << 0 << '\n';

    int sum = 0;
    for (int k = 0;; ++k) {

        int min[2] = { markedVertexes[0], vertexes[0] }; // строка и столбец в которой находится минимальный элемент

        for (auto &&i : markedVertexes) {
            for (auto &&j : vertexes) {
                if (W[i - 1][j - 1] < W[min[0] - 1][min[1] - 1]) {
                    min[0] = i;
                    min[1] = j;
                }
            }
        }

        /* помечаем вершину(строку) */
        markedVertexes.push_back(min[1]);

        /* вычеркиваем вершину(столбец) */
        vertexes.erase(std::remove(vertexes.begin(), vertexes.end(), min[1]), vertexes.end());
        std::cout << "Шаг " << k + 1 <<". v" << min[0] << "v" << min[1]
                  << ". Вес " <<  W[min[0] - 1][min[1] - 1] << ".\n";
        sum += W[min[0] - 1][min[1] - 1];

        /* если все столбцы вычеркнуты */
        if (vertexes.empty()) {
            break;
        }
    }

    std::cout << "Вес остова = " << sum;
    return 0;
}
