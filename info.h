#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class INFO
{
public:
	string name;
	float height=0, weight=0, health=100, atk_damage=10,time_tick=0;
	int age=0;
public: 
	void name_f()
	{
		cout << "Enter the name of the Fighter : " << endl;
		cin >> name;
	}
	void h_w_a_f()
	{
		cout << "Enter height(in foot), weight(in kg) and age(in yrs) of the Fighter : " << endl;
		cin >> height;
		cin >> weight;
		cin >> age;
	}
	void health_f()
	{
		cout << "The health of your character is : " << health << endl;
	}
	void atk_damage_f()
	{
		cout << "Attack Damage of of your character is : " << atk_damage << endl;
	}
};
class setter
{
public:
	void cal_health(INFO&);
	void cal_atk_dmg(INFO&);
};
void setter::cal_atk_dmg(INFO &o)
{
	if (o.weight >= 45)
	{
		o.atk_damage = 10 + (o.weight / 10);
	}
	else
	{
		o.atk_damage = 10 + (o.weight / 25);
	}
	if (o.age >= 17 && o.age <= 50)
	{
		o.atk_damage = o.atk_damage + (o.age / 10);
	}
	else
	{
		o.atk_damage = o.atk_damage + (o.age / 20);
	}
}
void setter::cal_health(INFO &o)
{
	int adv = 0;
	int disadv = 0;
	if (o.height >= 5.6 && o.height <= 7.6)
	{
		++adv;
	}
	else
	{
		++disadv;
	}
	if (o.weight >= 45 && o.weight <= 60)
	{
		++adv;
	}
	else
	{
		++disadv;
	}
	if (o.age >= 18 && o.age <= 45)
	{
		++adv;
	}
	else
	{
		++disadv;
	}
	o.health = 100 + (10 * (adv - disadv));
}
class environment
{
public:
	//void time_tick_f(vector<INFO>& v)
	//{
	//	for (int i = 0; i < v.size(); i++)
	//	{
	//		v[i].time_tick = v[i+1].health / v[i].atk_damage;
	//	}
	//}
	void compare(vector<INFO>& v)
	{
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < (v.size() - 1); j++)
			{
				v[j].time_tick = v[j + 1].health / v[j].atk_damage;
				v[j+1].time_tick = v[j].health / v[j+1].atk_damage;
				if (v[j].time_tick > v[j + 1].time_tick)
				{
					swap(v[j], v[j + 1]);
				}
			}
		}
	}
	void winner(vector<INFO>& v)
	{
		cout << "The scoreboard is : " << endl;
		for (int n = 0; n < v.size(); n++)
		{
			cout << (n+1) << ". " << v[n].name << endl;
		}
		cout << "\t\t" << v[0].name << " is the !!WINNER!!.\t\t";
	}
};
