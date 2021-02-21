#include <iostream>
#include <cmath>
using namespace std;

int main(){ 
    
    int n, sum = 0;
    cin >> n;
    int array[n];
    for (int i  = 0; i<n; i++){
        cin>>array[i];
        sum += array[i];
    }
    int answer = sum;
    int max_n_mask = pow(2,n)-1;
    int temp_sum; 
    int delta;
    for (int i = 0; i < max_n_mask; i++){
        temp_sum = 0;
        for (int j  = 0; j<n; j++){
            if(i & (1 << j)) temp_sum += array[j];
            delta = abs(sum-temp_sum*2);
            if (delta<answer) answer = delta;
        }
    }
    cout << answer << endl;
    return 0; 
}