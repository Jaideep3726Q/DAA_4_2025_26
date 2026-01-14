#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

long long operations = 0;
int max_depth = 0;

void complexRec(int n, int depth) {
    max_depth = max(max_depth, depth);
    if (n <= 2) {
        operations++;
        return;
    }
    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            operations++;
        }
        p >>= 1;
        operations++;
    }
    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        operations++;
    }
    if (n % 3 == 0) {
        reverse(small.begin(), small.end());
        operations++;
    } else {
        reverse(small.begin(), small.end());
    }
    operations += n;
    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
}

int main() {
    vector<int> test_n = {4, 8, 16, 32, 64, 128, 256, 512, 1024};
    for (int n : test_n) {
        operations = 0;
        max_depth = 0;
        auto start = high_resolution_clock::now();
        complexRec(n, 0);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << "n=" << n << " operations=" << operations << " depth=" << max_depth << " time=" << duration.count() << "ms" << endl;
    }
    return 0;
}