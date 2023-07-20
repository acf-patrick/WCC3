// https://app.codesignal.com/challenge/iLenaG3PbbnK8Cscf

int solution(vector<int> duration, vector<int> l, vector<int> r, vector<int> freetime) {
    // safety check
    auto len = duration.size();
    for (int i = 0; i < l.size(); ++i) {
        if (l[i] >= len || r[i] >= len) return 0;
    }
    
    auto it = max_element(freetime.begin(), freetime.end());
    auto d_max = *it;
    
    vector<vector<int>> lookup;
    for (int i = 0; i <= len; ++i)
        lookup.emplace_back(d_max + 2, -1);
    
    for (int i = 0; i < len; ++i) {
        auto d = duration[i];
        for (int j = 0; j <= d_max; ++j) {
            auto found = lookup[i][j];
            auto& c = lookup[i + 1][j];
            if (j < d) c = found;
            else c = max(found, lookup[i][j - d]);
        }
        
        lookup[i + 1][d] = i;
    }
    
    int res = 0;
    for (int i = 0; i < l.size(); ++i) {
        if (lookup[r[i] + 1][freetime[i]] >= l[i])
            res++;
    }
    
    return res;
}
