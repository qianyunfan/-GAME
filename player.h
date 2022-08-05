#pragma once
#include"skill.h"
class Status
{
public:
	int blood = 0;
	static int Qi;
	int attack = 0;
	int defend = 0;
};
class Player
{
public:
	Player(int id) :
		id_(id)
	{
		init();
	}
public:
	int id_;
	Status status;
	Skill* skill;
	void putSkill() {
		auto tuple = skill->chooseSkill(Skills::CA);
		int type = std::get<0>(tuple);
		int value = std::get<1>(tuple);
		switch (type)
		{
		case 0: status.Qi += value; break;
		case 1: status.defend += value; break;
		case 2: status.attack += value; break;
		default: {
			exception e;
			throw(e);
			break;
		}
		}
	};
	void receiveSkill()
	{
	};
public:
	void setdefend(int def)
	{
		status.defend = def;
	};
	void setattack(int att)
	{
		status.attack = att;
	};
private:
	//每回合结束后重置一些属性
	void resetAttribute()
	{
		status.attack = 0;
		status.defend = 0;
	}
	void init()
	{
		status.blood = 1;
		status.Qi = 0;
		status.attack = 0;
		status.defend = 0;
		skill = new Skill(id_);
	}

};
