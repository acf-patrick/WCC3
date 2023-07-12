// https://app.codesignal.com/challenge/hm4ejj3X2dgeLZJe8

string solution(string s) {
    string vowel("aeiou");
    string reversed;
    string found;
    for (auto c: s)
        if (vowel.find(c) != vowel.npos) found.push_back(c);
    for (auto c: s) {
        if (vowel.find(c) != vowel.npos) {
            reversed.push_back(found.back());
            found.pop_back();
        } else reversed.push_back(c);
    }
    return reversed;
}
