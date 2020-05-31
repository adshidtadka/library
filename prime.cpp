// 素数判定
bool is_prime(LL n) {
    for (LL i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// 約数の列挙
vector<LL> divisor(LL n) {
    vector<LL> res;
    for (LL i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) {
                res.push_back(n / i);
            }
        }
    }
    return res;
}

// 素因数分解
map<LL, int> prime_factor(LL n) {
    map<LL, int> res;
    for (LL i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) {
        res[n] = 1;
    }
    return res;
}


