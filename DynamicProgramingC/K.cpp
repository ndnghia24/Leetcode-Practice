#include <fstream>

int josephus(int n, int k) {
    int result = 0;
    for (int i = 2; i <= n; ++i) {
        result = (result + k) % i;
    }
    return result + 1;
}

int main() {
    std::ifstream input("joseph.in");
    std::ofstream output("joseph.out");

    int n, k;
    input >> n >> k;

    int winning_number = josephus(n, k);

    output << winning_number;

    input.close();
    output.close();

    return 0;
}