#include <iostream>
#include <vector>
#include "info.h"
using namespace std;
int main()
{
	vector<INFO> v;
	INFO o;
	setter obj;
	environment object;
	bool in=0;
	cout << "Enter 1 to create a new fighter or 0 to stop adding fighters : ";
	cin >> in;
	while (in == true)
	{
		o.name_f();
		o.h_w_a_f();
		obj.cal_health(o);
		o.health_f();
		obj.cal_atk_dmg(o);
		o.atk_damage_f();
		v.push_back(o);
		cout << "Enter 1 to create a new fighter or 0 to stop adding fighters : ";
		cin >> in;
	}
	//object.time_tick_f(v);
	object.compare(v);
	object.winner(v);
	return 0;
}