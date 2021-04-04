#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cable {
    unsigned short a, b;
    unsigned l;
};

bool compare(cable a, cable b) {
    return a.l < b.l;
}

int main() {
    
    unsigned short n, m;

    cin >> n >> m;
    vector<cable> v;
    
    unsigned short a, b;
    unsigned l;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> l;
        v.push_back((cable){a-1, b-1, l});
    }

    sort(v.begin(), v.end(), compare);
    
    short used_points[n];
    short used_vectors[m];

    fill_n(used_points, n, -1);
    fill_n(used_vectors, m, 0);
    
    unsigned group_number = 0;
    unsigned max = 0;
    unsigned counter = 0; 
    for (unsigned short i = 0; i < m; i++){
            if (used_points[v[i].a] != -1 && used_points[v[i].a] == used_points[v[i].b]) continue;
            else if(used_points[v[i].a] == -1 && used_points[v[i].b] == -1 ){
                ++group_number;
                used_points[v[i].a] = group_number;
                used_points[v[i].b] = group_number;
            }else if ((used_points[v[i].a] != -1 && used_points[v[i].b] == -1 )||(used_points[v[i].a] == -1 && used_points[v[i].b] != -1 )){
                int groupnubmer = used_points[v[i].a]+used_points[v[i].b]+1;
                used_points[v[i].a] = groupnubmer;
                used_points[v[i].b] = groupnubmer;
            }else{
                int mingroupnubmer; 
                int maxgroupnubmer; 
                if(used_points[v[i].b]>used_points[v[i].a]) {
                    mingroupnubmer = used_points[v[i].a];
                    maxgroupnubmer = used_points[v[i].b];
                    } else {
                    mingroupnubmer = used_points[v[i].b];
                    maxgroupnubmer = used_points[v[i].a];
                }
                for (unsigned short j = 0; j < n; j++)
                    if(used_points[j] == maxgroupnubmer) used_points[j] = mingroupnubmer;
            }
            used_vectors[i] = 1;
            max = v[i].l;
            ++counter;
    }

    cout << max << endl << counter << endl;

    for (unsigned short j = 0; j < m; j++) 
            if (used_vectors[j])
                cout << v[j].a+1<< " " << v[j].b+1 << endl;
    return 0;
}
