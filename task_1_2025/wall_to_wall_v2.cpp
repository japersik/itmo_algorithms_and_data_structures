#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) { 

	int t,n,k;
    int team_members,team_members_r,remainder,sum;
    cin >> t;

    for (int i=0; i<t; i++){
		cin >> n >> k;
		team_members = n/k;
		remainder = n%k;
		sum = n*(n-1)/2 - (k-remainder)*team_members*(team_members-1)/2 - (remainder)*team_members*(team_members+1)/2;
		cout << sum << endl;
	
	}
    return 0; 
}