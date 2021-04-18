#include <stdio.h>
#include <vector>

int main() {
    int n, k;
    scanf("%d %d",&n,&k);
    short used[n];
    std::vector<int> actually_list;
    for (int i = 0; i < n; i++)
        actually_list.push_back(i);
    k = k-1;
    int queue = k;
    for (--n; n > 0; n--){
        printf("%d ",actually_list[queue]+1);
        actually_list.erase(actually_list.begin() + queue);
        queue = (queue + k) % (n);
    }
    printf("%d ",actually_list[0]+1);
    return 0; 
}