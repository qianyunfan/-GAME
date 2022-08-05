#pragma once
#include"skill.h"
class Status
{
public:
	int blood = 0;
	int Qi = 0;
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
		skill->chooseSkill(Skills::CA);
	};
	void receiveSkill() {
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
	void init()
	{
		status.blood = 1;
		status.Qi = 0;
		status.attack = 0;
		status.defend = 0;
		skill = new Skill(id_);
	}

};
