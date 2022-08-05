#pragma once
#include<iostream>
enum class Skills {
	CA = 1,
	HONG = 2,
	DONG = 3,
	HONGHONG = 4,
	DONGDONG = 6,
	WICA = 10,

	FANG = 100,
	GANG = 101,
};
class SkillBase {
public:
	SkillBase(int player_id)
		:player_id_(player_id) {

	}

	int player_id_;
	std::tuple<int, int>returnStatus;
	virtual std::tuple<int, int> damage() {
		return std::make_tuple(-1, -1);
	};
	virtual std::tuple<int, int> defend() {
		return std::make_tuple(-1, -1);


	};
	virtual std::tuple<int, int> Qi() {
		return std::make_tuple(-1, -1);


	};
};


class CA :public SkillBase {
public:
	CA(int player_id) :SkillBase(player_id)
	{

	}
	std::tuple<int, int> damage() override
	{
		returnStatus = std::make_tuple(0, 1);
		//player_->setattack(1);
		std::cout << "Player " << player_id_ << "put skill:" << "CA" << std::endl;
		return returnStatus;
	}
};
class Skill {
public:
	Skill(int player_id)
		:player_id_(player_id)
	{

	}
	void chooseSkill(Skills skills) {
		SkillBase* skill;
		switch (skills)
		{
		case Skills::CA:skill = new CA(player_id_);
			skill->damage();
			break;
		case Skills::HONG: break;
		case Skills::DONG: break;
		case Skills::HONGHONG: break;
		case Skills::DONGDONG: break;
		case Skills::WICA: break;
		case Skills::FANG: break;
		case Skills::GANG: break;
		default:
			break;
		}
	}
private:
	int player_id_;
};


