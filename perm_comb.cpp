// nPnの順列に対して処理を実行する
void foreach_permutation(int n, function<void(int *)> f) {
    int indexes[n];
    REP(i, n) indexes[i] = i;
    do {
        f(indexes);
    } while (next_permutation(indexes, indexes + n));
}

void recursive_comb(int *indexes, int s, int rest, function<void(int *)> f) {
    if (rest == 0) {
        f(indexes);
    } else {
        if (s < 0) return;
        recursive_comb(indexes, s - 1, rest, f);
        indexes[rest - 1] = s;
        recursive_comb(indexes, s - 1, rest - 1, f);
    }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, function<void(int *)> f) {
    int indexes[k];
    recursive_comb(indexes, n - 1, k, f);
}

// nPkの順列に対して処理を実行する
void foreach_permutation(int n, int k, function<void(int *)> f) {
    foreach_comb(n, k, [&](int *c_indexes) {
        foreach_permutation(k, [&](int *p_indexes) {
            int indexes[k];
            for (int i = 0; i < k; i++) {
                indexes[i] = c_indexes[p_indexes[i]];
            }
            f(indexes);
        });
    });
}

int main() {
    foreach_permutation(3, [](int *indexes) {
        cout << indexes[0] << ',' << indexes[1] << ',' << indexes[2] << endl;
    });

    foreach_comb(5, 3, [](int *indexes) {
        cout << indexes[0] << ',' << indexes[1] << ',' << indexes[2] << endl;
    });

    foreach_permutation(4, 2, [](int *indexes) {
        cout << indexes[0] << ',' << indexes[1] << endl;
    });
}
