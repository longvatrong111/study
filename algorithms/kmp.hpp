int strStr(string& t, string& p) {
    int n = t.size();
    int m = p.size();

    vector<int> v(m + 1);
    int p1 = 0, p2 = -1;
    v[0] = -1;
    while (p1 < m) {
        while (p2 >= 0 && p[p1] != p[p2]) p2 = v[p2];
        p1++;
        p2++;
        v[p1] = p2;
    }

    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j >= 0 && t[i] != p[j]) j = v[j];
        j++;
        if (j == m) return i - j + 1;
    }

    return -1;
}
