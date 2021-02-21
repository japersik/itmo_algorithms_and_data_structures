#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) { 

	int t,n,k;
    int team_members,team_members_r,remainder,sum;
    cin >> t;

    for (int i=0; i<t; i++){
		cin >> n >> k;
		team_members = n/k;
		team_members_r = team_members+1;
		remainder = n%k;
		sum = 0;
		for (int j=0; j<k-remainder; j++){
			n -= team_members;
			sum += n*team_members;
		}
		for (int j=0; j<remainder; j++){
			n -= team_members_r;
			sum += n*team_members_r;
		}
		cout << sum << endl;
	}
    return 0; 
}