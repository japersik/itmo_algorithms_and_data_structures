#include <iostream>

using namespace std;

int main(){ 
    
    int k, sum = 0;
    cin >> k;
    int array[k];
    for (int i = 0; i < k; i++) {
        cin >> array[i];
        sum += array[i];
    }
    int last_index = -1;
    int max_temp_index;
    for (int i = 0; i < sum; i++){ 
        max_temp_index = 0;
        if(last_index == 0) max_temp_index = 1;
        for (int j = 1; j < k; j++){
            if(last_index != j && array[j] >= array[max_temp_index])
            max_temp_index = j;
        }
        if (array[max_temp_index] == 0)
            max_temp_index = last_index;
        array[max_temp_index] -= 1;
        last_index = max_temp_index;
        cout << max_temp_index + 1 << ' ';
    }
}
