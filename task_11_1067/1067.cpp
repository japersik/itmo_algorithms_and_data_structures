#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct directory{
    map<string, directory *> children;
};

void getOrder(directory* const parent, string tab_current) {
    string tab = " ";
    tab += tab_current;

    map<string, directory *> sorted_children(parent->children.begin(), parent->children.end());
    map<string, directory *>::iterator it;

        for (it = sorted_children.begin(); it != sorted_children.end(); it++) {
            cout << tab_current << it->first << endl;
            getOrder(it->second,tab);     
        }
}

directory *get_directory(string const name, directory* const parent) {
        if ((parent->children).find(name) != parent->children.end()) {
            return parent->children[name];
        } else {
            parent->children[name] = new directory{};
            return parent->children[name];
        }
    }

int main() {
    int count;
    cin >> count;
    directory * root = new directory{};
    string s;

    for (int i = 0; i <= count; i++) {
        getline(cin, s);
        stringstream path(s);

        directory *current = root;
        while (getline(path, s, '\\')) {
            current = get_directory(s,current);
        }
    }
    getOrder(root,"");
    return 0;
}

