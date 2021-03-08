#include <algorithm>
#include <iostream>

using namespace std;

struct char_i {
    char c;
    int index;
};

bool sort_char_i(const char_i a, const char_i b) {return a.c < b.c;}

int main() {
    int n;
    cin >> n;
    --n;
    char c;
    char_i s[100000];
    int length = 0;
    while (cin.get(c)) {
        if (length > 0 && (c == '\n' || c == '\r')) 
            break;
        else if (isspace(c))
            continue;
        s[length] = {c, length};
        ++length;
    }

    stable_sort(s, s+length, sort_char_i);

    int j = n;
    for (int i = 0; i < length; ++i, j = s[j].index)
        cout << s[j].c;
    cout << endl;
    
    return 0;
}