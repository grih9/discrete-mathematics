#include <iostream>
#include <vector>

int main() {
    std::cout << "Enter degree of polynom1" << std::endl;
    int deg1;
    std::cin >> deg1;
    if (!std::cin.good()) {
        std::cerr << "Input error";
        return 1;
    }

    if (deg1 < 0) {
        std::cerr << "Inappropriate number";
        return 1;
    }

    std::vector<int> polynom1(deg1 + 1);
    std::cout << "Enter the coefficients of polynom1 starting with the lowest degree"
              << std::endl;
    for (auto& it : polynom1) {
        std::cin >> it;
        if (!std::cin.good()) {
            std::cerr << "Input error";
            return 1;
        }
        if (!(it == 1 || it == 0)) {
            std::cerr << "Only 1 and 0 are available ";
            return 1;
        }
    }

    if (polynom1[deg1] != 1 && deg1 != 0) {
        std::cout << "\nTHE COEFFICIENT FOR THE HIGHEST DEGREE MUST BE 1. IT WILL BE CHANGED FROM 0 TO 1\n\n";
        polynom1[deg1] = 1;
    }

    std::cout << "You have entered: ";
    for (size_t i = 0; i < polynom1.size(); ++i) {
        if (polynom1[i] != 0 && deg1 != 0) {
            std::cout << polynom1[i] << "*X" << i;
            if ((i + 1) < polynom1.size()) {
                std::cout << " + ";
            }
        }
    }

    std::cout << "\n\nEnter degree of polynom2\n";
    int deg2;
    std::cin >> deg2;
    if (!std::cin.good()) {
        std::cerr << "Input error";
        return 1;
    }
    if (deg2 < 0) {
        std::cerr << "Inappropriate number";
        return 1;
    }

    std::vector<int> polynom2(deg2 + 1);
    std::cout << "Enter the coefficients of polynom2 starting with the lowest degree"
              << std::endl;
    if (deg2 > 0) {
        for (auto &it : polynom2) {
            std::cin >> it;
            if (!std::cin.good()) {
                std::cout << "Input error";
                return 1;
            }
            if (!(it == 1 || it == 0)) {
                std::cerr << "Only 1 and 0 are available ";
                return 1;
            }
        }

        if (polynom2[deg2] != 1) {
            std::cout << "\nTHE COEFFICIENT FOR THE HIGHEST DEGREE MUST BE 1. IT WILL BE CHANGED FROM 0 TO 1\n\n";
            polynom2[deg2] = 1;
        }
    } else {
        polynom2[0] = 1;
    }

    std::cout << "You have entered: ";
    for (size_t i = 0; i < polynom2.size(); ++i) {
        if (polynom2[i] != 0) {
            std::cout << polynom2[i] << "*X" << i;
            if ((i + 1) < polynom2.size()) {
                std::cout << " + ";
            }
        }
    }

    if (deg2 > deg1) {
        std::vector<int> q(1, 0);
        const std::vector<int> & r(polynom1);

        std::cout << std::endl;
        std::cout << "RESULT: \n";
        std::cout << "q = " << q[0];
        std::cout << "\np = ";
        for (size_t i = 0; i < r.size(); ++i) {
            std::cout << r[i] << "*X" << i;
            if ((i + 1) < r.size()) {
                std::cout << " + ";
            }
        }
    } else {
        std::vector<int> p(deg1);
        std::vector<int> q(deg1 + deg2 + 1);
        std::vector<int> r(deg2 + 1);

        for (auto& it : q) {
            it = 0;
        }

        int degp = deg1;

        for (int k = 0; k <= deg1 - deg2; ++k) {
            q[degp - deg2] = 1;

            std::vector<int> tmp(degp + deg2 + 1);
            for (auto& it : tmp) {
                it = 0;
            }

            for (int i = 0; i <= degp - deg2; ++i) {
                for (int j = 0; j <= deg2; ++j) {
                    tmp[i + j] = tmp[i + j] ^ (q[i] * polynom2[j]);
                }
            }
            int max = 0;
            for (int i = 0; i <= degp; ++i) {
                polynom1[i] ^= tmp[i];
                if ((polynom1[i] == 1) && (max < i)) {
                    max = i;
                }
            }
            degp = max;
            std::cout << "degp " << degp << std::endl;
            if (degp < deg2) {
                break;
            }
        }

        std::cout << std::endl;
        std::cout << "\nRESULT: ";
        std::cout << "\nq = ";
        for (size_t i = 0; i < q.size(); ++i) {
            if (q[i] != 0) {
                std::cout << q[i] << "*X" << i;
                if (i < deg1 - deg2) {
                    std::cout << " + ";
                }
            }
        }
        std::cout << "\np = ";
        if (degp == deg2) {
            std::cout << 0;
        } else {
            for (size_t i = 0; i < polynom1.size(); ++i) {
                if (polynom1[i] != 0) {
                    std::cout << polynom1[i] << "*X" << i;
                    if (i < degp) {
                        std::cout << " + ";
                    }
                }
            }
        }
//        for (size_t i = 0; i < res.size(); ++i) {
//            if (res[i] != 0) {
//                std::cout << res[i] << "*X" << i;
//                if ((i + 1) < res.size()) {
//                    std::cout << " + ";
//                }
//            }
//        }

    }
    return 0;
}
