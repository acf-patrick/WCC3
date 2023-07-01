int solution(string str) {
    int n = str.length();
    int maxLength = 0, i = 0, j = 0;
    unordered_set<char> charSet;

    while (i < n && j < n) {
        if (charSet.find(str[j]) == charSet.end()) {
            charSet.insert(str[j++]);
            maxLength = max(maxLength, j - i);
        } else {
            charSet.erase(str[i++]);
        }
    }

    return maxLength;
}
