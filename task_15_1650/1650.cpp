#include <map>
#include <iostream>
#include <string>
#include <set>


using namespace std;

int main() {
    map<string, long long> man_money;
    map<string, string> man_city;  
	map<string, long long> city_money;		
	map<long long, set<string>> money_cities;	
	map<string, int> city_top;
	int n;
	cin >> n;
    
    long long money;
	string name, city;
	for (int i = 0; i < n; i++) {
		cin >> name >> city >> money;
		man_money[name] = money;
		man_city[name] = city;
		if (city_money.find(city) != city_money.end()) {
			long long sum = city_money[city]; 
			money_cities[sum].erase(city);
			if (money_cities[sum].size() == 0) money_cities.erase(sum);	
		}
		city_money[city] += money;
		money_cities[city_money[city]].insert(city);
	}

	int days, m, pred_day = 0, this_day = 0;
	cin >> days >> m;
	for (int i = 0; i < m; i++) { 
        cin >> this_day >> name >> city;

		map<long long, set<string>>:: reverse_iterator it = money_cities.rbegin();
		if (this_day != pred_day && it->second.size() == 1) city_top[*(it->second.begin())] += this_day - pred_day;

		string old_city = man_city[name];
		long long old_money = city_money[old_city];
		money_cities[old_money].erase(old_city);
		if (money_cities[old_money].size() == 0) money_cities.erase(old_money);
		city_money[old_city] -= man_money[name];
		money_cities[city_money[old_city]].insert(old_city);

		long long newMoney = city_money[city];
		money_cities[newMoney].erase(city);
		if(money_cities[newMoney].size() == 0) money_cities.erase(newMoney);
		city_money[city] += man_money[name];
		money_cities[city_money[city]].insert(city);
		man_city[name] = city;
        pred_day = this_day;
	}
    
    this_day = days;
    map<long long, set<string>>:: reverse_iterator it = money_cities.rbegin();
    if (this_day != pred_day && it->second.size() == 1) city_top[*(it->second.begin())] += this_day - pred_day;
	
    for (const auto& c: city_top) cout << c.first << " " << c.second << endl;
   	return 0;
}
