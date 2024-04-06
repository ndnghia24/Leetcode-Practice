#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::freopen("lepus.in", "r", stdin);
    std::freopen("lepus.out", "w", stdout);

    int cells_count;
    std::string cells_description;
    std::cin >> cells_count >> cells_description;

    const char kSwamp = 'w';
    const char kEmpty = '.';
    const char kGrass = '"';

    std::vector<int> point(cells_count,-1);
    point[0] = 0;

    for (int i = 1; i < point.size(); i++) {

        if (cells_description[i] == kSwamp) {
            continue;
        }

        int p1 = -1;
        int p3 = -1;
        int p5 = -1;

        if (i-1 >= 0 && cells_description[i-1] != kSwamp) {
            p1 = point[i-1];
        }

        if (i-3 >= 0 && cells_description[i-3] != kSwamp) {
            p3 = point[i-3];
        }

        if (i-5 >= 0 && cells_description[i-5] != kSwamp) {
            p5 = point[i-5];
        }

        if (p1 == -1 && p3 == -1 && p5 == -1) {
            continue;
        }

        if (cells_description[i] == kEmpty) {
            point[i] = std::max(p1, std::max(p3, p5));
        } else if (cells_description[i] == kGrass) {
            point[i] = std::max(p1, std::max(p3, p5)) + 1;
        }
    }

    // for (int i = 0; i < point.size(); i++) {
    //     std::cout << point[i] << " ";
    // }
    // cout << endl;

    std::cout << point[cells_count-1] << std::endl;
}