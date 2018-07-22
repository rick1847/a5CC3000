#ifndef STATS_H
#define STATS_H
//combat, items will change affect characters by affecting values of this object

const int minHP = 0;
const int minATK = 0;
const int minDEF = 0;

class Stats {
	int attack;
	int defence;
	int HP;
	int maxHP;
	int gold;
public:
	Stats(int hp = 125, int mhp = 125, int a = 25, int d = 25);
	Stats(Stats &s);
	int getHP();
	int getMaxHP();
	int getATK();
	int getDEF();
	int getGold();
	void addHP(int amt);
	void addATK(int amt);
	void addDEF(int amt);
	void addGold(int amt);
};


#endif
