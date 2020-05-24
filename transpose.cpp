VVI transposeInt(VVI v) {
    int p = 0;
    VVI rlt;

    int row = v.size();
    int col = v[0].size();

    rlt.resize(col);
    for (int i = 0; col > i; i++) rlt[i].resize(row);

    for (int i = 0; row > i; i++) {
        for (int j = 0; col > j; j++) {
            int d = v[i][j];
            int x = p % col;
            int y = p / col;
            rlt[x][y] = d;
            p++;
        }
    }
    return rlt;
}

vector<vector<char>> transposeChar(vector<vector<char>> v) {
    int p = 0;
    vector<vector<char>> rlt;

    int row = v.size();
    int col = v[0].size();

    rlt.resize(col);
    for (int i = 0; col > i; i++) rlt[i].resize(row);

    for (int i = 0; row > i; i++)
        for (int j = 0; col > j; j++) {
            int d = v[i][j];
            int x = p % col;
            int y = p / col;
            rlt[x][y] = d;
            p++;
        }
    return rlt;
}


