
#include "hoard_loot.h"
#include <algorithm> //for sort function
#include <fstream>  //art and gems load from a file
#include "random_gen.h" //lots of that random gen

using namespace std;

void Hoard_Loot::GenerateHoardTreasureCR_0_4() {
	vector<Gear> tmplist;
	int copper(0), silver(0), gold(0);
	for (int i(0); i < 6; i++) copper += rolld6(mgen);
	for (int i(0); i < 3; i++) silver += rolld6(mgen);
	for (int i(0); i < 2; i++) gold += rolld6(mgen);
	copper *= 100;
	silver *= 100;
	gold *= 10;
	Gear copgear(copper, "cp");
	Gear silvgear(silver, "sp");
	Gear goldgear(gold, "gp");
	tmplist.push_back(copgear);
	tmplist.push_back(silvgear);
	tmplist.push_back(goldgear);
	int mr = 0;
	mr = rolld100(mgen);
	if (mr <= 6) {
		// THE DMG SAYS YOU GET NOTHING
	} else if (mr <= 16) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 10)));
		tmplist.push_back(gear);
	} else if (mr <= 26) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 25)));
		tmplist.push_back(gear);
	} else if (mr <= 36) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 50)));
		tmplist.push_back(gear);
	} else if (mr <= 44) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 10)));
		tmplist.push_back(gear);
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableA());
	} else if (mr <= 52) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 25)));
		tmplist.push_back(gear);
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableA());
	} else if (mr <= 60) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 50)));
		tmplist.push_back(gear);
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableA());
	} else if (mr <= 65) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 10)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableB());
	} else if (mr <= 70) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 25)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableB());
	} else if (mr <= 75) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 50)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableB());
	} else if (mr <= 78) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 10)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableC());
	} else if (mr <= 80) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 25)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableC());
	} else if (mr <= 85) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 50)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableC());
	} else if (mr <= 92) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 25)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableF());
	} else if (mr <= 97) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 50)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableF());
	} else if (mr <= 99) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 25)));
		tmplist.push_back(gear);
		tmplist.push_back(TableG());
	} else {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 50)));
		tmplist.push_back(gear);
		tmplist.push_back(TableG());
	}
	full_gear_list = tmplist;
}

void Hoard_Loot::GenerateHoardTreasureCR_5_10() {
	vector<Gear> tmplist;
	int copper(0), silver(0), gold(0), plat(0);
	for (int i(0); i < 2; i++) copper += rolld6(mgen);
	for (int i(0); i < 2; i++) silver += rolld6(mgen);
	for (int i(0); i < 6; i++) gold += rolld6(mgen);
	for (int i(0); i < 3; i++) plat += rolld6(mgen);
	copper *= 100;
	silver *= 1000;
	gold *= 100;
	plat *= 10;
	Gear copgear(copper, "cp");
	Gear silvgear(silver, "sp");
	Gear goldgear(gold, "gp");
	Gear platgear(plat, "pp");
	tmplist.push_back(copgear);
	tmplist.push_back(silvgear);
	tmplist.push_back(goldgear);
	tmplist.push_back(platgear);
	int mr = 0;
	mr = rolld100(mgen);
	if (mr <= 4) {
		// THE DMG SAYS YOU GET NOTHING
	} else if (mr <= 10) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 25)));
		tmplist.push_back(gear);
	} else if (mr <= 16) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 50)));
		tmplist.push_back(gear);
	} else if (mr <= 22) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 100)));
		tmplist.push_back(gear);
	} else if (mr <= 28) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 250)));
		tmplist.push_back(gear);
	} else if (mr <= 32) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 25)));
		tmplist.push_back(gear);
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableA());
	} else if (mr <= 36) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 50)));
		tmplist.push_back(gear);
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableA());
	} else if (mr <= 40) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 100)));
		tmplist.push_back(gear);
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableA());
	} else if (mr <= 44) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 250)));
		tmplist.push_back(gear);
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableA());
	} else if (mr <= 49) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 25)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableB());
	} else if (mr <= 54) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 50)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableB());
	} else if (mr <= 59) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 100)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableB());
	} else if (mr <= 63) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 250)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableB());
	} else if (mr <= 66) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 25)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableC());
	} else if (mr <= 69) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 50)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableC());
	} else if (mr <= 72) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 100)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableC());
	} else if (mr <= 74) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 250)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableC());
	} else if (mr <= 76) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 25)));
		tmplist.push_back(gear);
		tmplist.push_back(TableD());
	} else if (mr <= 78) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 50)));
		tmplist.push_back(gear);
		tmplist.push_back(TableD());
	} else if (mr <= 79) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 100)));
		tmplist.push_back(gear);
		tmplist.push_back(TableD());
	} else if (mr <= 80) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 250)));
		tmplist.push_back(gear);
		tmplist.push_back(TableD());;
	} else if (mr <= 84) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 25)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableF());
	} else if (mr <= 88) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 50)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableF());
	} else if (mr <= 91) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 100)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableF());
	} else if (mr <= 94) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 250)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableF());
	} else if (mr <= 96) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 100)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableG());
	} else if (mr <= 98) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 250)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableG());
	} else if (mr <= 99) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 100)));
		tmplist.push_back(gear);
		tmplist.push_back(TableH());
	} else {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 250)));
		tmplist.push_back(gear);
		tmplist.push_back(TableH());
	}
	full_gear_list = tmplist;
}

void Hoard_Loot::GenerateHoardTreasureCR_11_16() {
	vector<Gear> tmplist;
	int gold(0), plat(0);
	for (int i(0); i < 4; i++) gold += rolld6(mgen);
	for (int i(0); i < 5; i++) plat += rolld6(mgen);
	gold *= 1000;
	plat *= 100;
	Gear goldgear(gold, "gp");
	Gear platgear(plat, "pp");
	tmplist.push_back(goldgear);
	tmplist.push_back(platgear);
	int mr = 0;
	mr = rolld100(mgen);
	if (mr <= 3) {
		// A PLAYER'S WORST NIGHTMARE. NO LOOT.
	} else if (mr <= 6) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 250)));
		tmplist.push_back(gear);
	} else if (mr <= 9) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 750)));
		tmplist.push_back(gear);
	} else if (mr <= 12) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 500)));
		tmplist.push_back(gear);
	} else if (mr <= 15) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 1000)));
		tmplist.push_back(gear);
	} else if (mr <= 19) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 250)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableA());
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableB());
	} else if (mr <= 23) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 750)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableA());
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableB());
	} else if (mr <= 26) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 500)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableA());
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableB());
	} else if (mr <= 29) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 1000)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableA());
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableB());
	} else if (mr <= 35) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 250)));
		tmplist.push_back(gear);
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableC());
	} else if (mr <= 40) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 750)));
		tmplist.push_back(gear);
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableC());
	} else if (mr <= 45) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 500)));
		tmplist.push_back(gear);
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableC());
	} else if (mr <= 50) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 1000)));
		tmplist.push_back(gear);
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableC());
	} else if (mr <= 54) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 250)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableD());
	} else if (mr <= 58) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 750)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableD());
	} else if (mr <= 62) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 500)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableD());
	} else if (mr <= 66) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 1000)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableD());
	} else if (mr <= 68) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 250)));
		tmplist.push_back(gear);
		tmplist.push_back(TableE());
	} else if (mr <= 70) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 750)));
		tmplist.push_back(gear);
		tmplist.push_back(TableE());
	} else if (mr <= 72) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 500)));
		tmplist.push_back(gear);
		tmplist.push_back(TableE());
	} else if (mr <= 74) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 1000)));
		tmplist.push_back(gear);
		tmplist.push_back(TableE());;
	} else if (mr <= 76) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 250)));
		tmplist.push_back(gear);
		tmplist.push_back(TableF());
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableG());
	} else if (mr <= 78) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 750)));
		tmplist.push_back(gear);
		tmplist.push_back(TableF());
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableG());
	} else if (mr <= 80) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 500)));
		tmplist.push_back(gear);
		tmplist.push_back(TableF());
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableG());
	} else if (mr <= 82) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 1000)));
		tmplist.push_back(gear);
		tmplist.push_back(TableF());
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableG());
	} else if (mr <= 85) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 250)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableH());
	} else if (mr <= 88) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 750)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableH());
	} else if (mr <= 90) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 500)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableH());
	} else if (mr <= 92) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 1000)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableH());
	} else if (mr <= 94) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 250)));
		tmplist.push_back(gear);
		tmplist.push_back(TableI());
	} else if (mr <= 96) {
		int c = 0;
		for (int i(0); i < 2; i++) c += rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 750)));
		tmplist.push_back(gear);
		tmplist.push_back(TableI());
	} else if (mr <= 98) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 500)));
		tmplist.push_back(gear);
		tmplist.push_back(TableI());
	} else {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 1000)));
		tmplist.push_back(gear);
		tmplist.push_back(TableI());
	}
	full_gear_list = tmplist;

}

void Hoard_Loot::GenerateHoardTreasureCR_17() {
	vector<Gear> tmplist;
	int gold(0), plat(0);
	for (int i(0); i < 12; i++) gold += rolld6(mgen);
	for (int i(0); i < 8; i++) plat += rolld6(mgen);
	gold *= 1000;
	plat *= 1000;
	Gear goldgear(gold, "gp");
	Gear platgear(plat, "pp");
	tmplist.push_back(goldgear);
	tmplist.push_back(platgear);
	int mr = 0;
	mr = rolld100(mgen);
	if (mr <= 2) {
		//NOTHING? REALLY DMG, NOTHING?
	} else if (mr <= 5) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 1000)));
		tmplist.push_back(gear);
		c = rolld8(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableC());
	} else if (mr <= 8) {
		int c = rolld10(mgen);
		Gear gear(c, (GenerateArt(c, 2500)));
		tmplist.push_back(gear);
		c = rolld8(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableC());
	} else if (mr <= 11) {
		int c = rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 7500)));
		tmplist.push_back(gear);
		c = rolld8(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableC());
	} else if (mr <= 14) {
		int c = rolld8(mgen);
		Gear gear(c, (GenerateGemstone(c, 5000)));
		tmplist.push_back(gear);
		c = rolld8(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableC());
	} else if (mr <= 22) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 1000)));
		tmplist.push_back(gear);
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableD());
	} else if (mr <= 30) {
		int c = rolld10(mgen);
		Gear gear(c, (GenerateArt(c, 2500)));
		tmplist.push_back(gear);
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableD());
	} else if (mr <= 38) {
		int c = rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 7500)));
		tmplist.push_back(gear);
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableD());
	} else if (mr <= 46) {
		int c = rolld8(mgen);
		Gear gear(c, (GenerateGemstone(c, 5000)));
		tmplist.push_back(gear);
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableD());
	} else if (mr <= 52) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 1000)));
		tmplist.push_back(gear);
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableE());
	} else if (mr <= 58) {
		int c = rolld10(mgen);
		Gear gear(c, (GenerateArt(c, 2500)));
		tmplist.push_back(gear);
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableE());
	} else if (mr <= 63) {
		int c = rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 7500)));
		tmplist.push_back(gear);
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableE());
	} else if (mr <= 68) {
		int c = rolld8(mgen);
		Gear gear(c, (GenerateGemstone(c, 5000)));
		tmplist.push_back(gear);
		c = rolld6(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableE());
	} else if (mr <= 69) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 1000)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableG());
	} else if (mr <= 70) {
		int c = rolld10(mgen);
		Gear gear(c, (GenerateArt(c, 2500)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableG());
	} else if (mr <= 71) {
		int c = rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 7500)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableG());
	} else if (mr <= 72) {
		int c = rolld8(mgen);
		Gear gear(c, (GenerateGemstone(c, 5000)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableG());
	} else if (mr <= 74) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 1000)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableH());
	} else if (mr <= 76) {
		int c = rolld10(mgen);
		Gear gear(c, (GenerateArt(c, 2500)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableH());
	} else if (mr <= 78) {
		int c = rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 7500)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableH());
	} else if (mr <= 80) {
		int c = rolld8(mgen);
		Gear gear(c, (GenerateGemstone(c, 5000)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableH());
	} else if (mr <= 85) {
		int c = 0;
		for (int i(0); i < 3; i++) c += rolld6(mgen);
		Gear gear(c, (GenerateGemstone(c, 1000)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableI());
	} else if (mr <= 90) {
		int c = rolld10(mgen);
		Gear gear(c, (GenerateArt(c, 2500)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableI());
	} else if (mr <= 95) {
		int c = rolld4(mgen);
		Gear gear(c, (GenerateArt(c, 7500)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableI());
	} else {
		int c = rolld8(mgen);
		Gear gear(c, (GenerateGemstone(c, 5000)));
		tmplist.push_back(gear);
		c = rolld4(mgen);
		for (int i(0); i < c; i++) tmplist.push_back(TableI());
	}
	full_gear_list = tmplist;

}

Gear Hoard_Loot::TableA() {
	int roll = 0;
	roll = rolld100(mgen);
	if (roll <= 50) {
		Gear gear(1, "Potion of Healing");
		return gear;
	} else if (roll <= 60) { //was cantrip changed to 1st lvl
		string scroll = GenerateScroll(1);
		Gear gear(1, scroll);
		return gear;
	} else if (roll <= 70) {
		Gear gear(1, "Potion of Climbing");
		return gear;
	} else if (roll <= 90) {
		string scroll = GenerateScroll(1);
		Gear gear(1, scroll);;
		return gear;
	} else if (roll <= 94) {
		string scroll = GenerateScroll(2);
		Gear gear(1, scroll);;
		return gear;
	} else if (roll <= 99) {
		Gear gear(1, "Bag of holding");
		return gear;
	} else {
		Gear gear(1, "Driftglobe");
		return gear;
	}
}

Gear Hoard_Loot::TableB() {
	int roll = 0;
	roll = rolld100(mgen);
	if (roll <= 15) {
		Gear gear(1, "Potion of greater healing");
		return gear;
	} else if (roll <= 22) {
		Gear gear(1, "Potion of fire breath");
		return gear;
	} else if (roll <= 29) {
		Gear gear(1, "Potion of resistance");
		return gear;
	} else if (roll <= 34) {
		Gear gear(1, "Ammunition, +1");
		return gear;
	} else if (roll <= 39) {
		Gear gear(1, "Potion of animal friendship");
		return gear;
	} else if (roll <= 44) {
		Gear gear(1, "Potion of hill giant strength");
		return gear;
	} else if (roll <= 49) {
		Gear gear(1, "Potion of growth");
		return gear;
	} else if (roll <= 54) {
		Gear gear(1, "Potion of water breathing");
		return gear;
	} else if (roll <= 59) {
		string scroll = GenerateScroll(2);
		Gear gear(1, scroll);
		return gear;
	} else if (roll <= 64) {
		string scroll = GenerateScroll(3);
		Gear gear(1, scroll);
		return gear;
	} else if (roll <= 67) {
		Gear gear(1, "Bag of holding");
		return gear;
	} else if (roll <= 70) {
		Gear gear(1, "Keoghtom's ointment");
		return gear;
	} else if (roll <= 73) {
		Gear gear(1, "Oil of slipperiness");
		return gear;
	} else if (roll <= 75) {
		Gear gear(1, "Dust of disappearance");
		return gear;
	} else if (roll <= 77) {
		Gear gear(1, "Dust of dryness");
		return gear;
	} else if (roll <= 79) {
		Gear gear(1, "Dust of sneezing and choking");
		return gear;
	} else if (roll <= 81) {
		string loader = "Elemental Gem";
		int quaalvar = rolld100(mgen);
		if (quaalvar < 26) {
			loader += "(Blue sapphire)";
		} else if (quaalvar < 51) {
			loader += "(Yellow Diamond)";
		} else if (quaalvar < 76) {
			loader += "(Red corundum)";
		} else {
			loader += "(Emerald)";
		}
		Gear gear(1, loader);
		return gear;
	} else if (roll <= 83) {
		Gear gear(1, "Philter of love");
		return gear;
	} else if (roll <= 84) {
		Gear gear(1, "Alchemy jug");
		return gear;
	} else if (roll <= 85) {
		Gear gear(1, "Cap of water breathing");
		return gear;
	} else if (roll <= 86) {
		Gear gear(1, "Cloak of the manta ray");
		return gear;
	} else if (roll <= 87) {
		Gear gear(1, "Driftglobe");
		return gear;
	} else if (roll <= 88) {
		Gear gear(1, "Goggles of night");
		return gear;
	} else if (roll <= 89) {
		Gear gear(1, "Helm of comprehending languages");
		return gear;
	} else if (roll <= 90) {
		Gear gear(1, "Immovable rod");
		return gear;
	} else if (roll <= 91) {
		Gear gear(1, "lantern of revealing");
		return gear;
	} else if (roll <= 92) {
		Gear gear(1, "Mariner's armor");
		return gear;
	} else if (roll <= 93) {
		Gear gear(1, "Mithral armor");
		return gear;
	} else if (roll <= 94) {
		Gear gear(1, "Potion of poison");
		return gear;
	} else if (roll <= 95) {
		Gear gear(1, "Ring of swimming");
		return gear;
	} else if (roll <= 96) {
		Gear gear(1, "Robe of useful items");
		return gear;
	} else if (roll <= 97) {
		Gear gear(1, "Ring of climbing");
		return gear;
	} else if (roll <= 98) {
		Gear gear(1, "Saddle of the cavalier");
		return gear;
	} else if (roll <= 99) {
		Gear gear(1, "Wand of magic detection");
		return gear;
	} else {
		Gear gear(1, "Wand of secrets");
		return gear;
	}
}

Gear Hoard_Loot::TableC() {
	int roll = 0;
	roll = rolld100(mgen);
	if (roll <= 15) {
		Gear gear(1, "Potion of superior healing");
		return gear;
	} else if (roll <= 22) {
		string scroll = GenerateScroll(4);
		Gear gear(1, scroll);
		return gear;
	} else if (roll <= 27) {
		Gear gear(1, "Ammunition, +2");
		return gear;
	} else if (roll <= 32) {
		Gear gear(1, "Potion of clairvoyance");
		return gear;
	} else if (roll <= 37) {
		Gear gear(1, "Potion of diminution");
		return gear;
	} else if (roll <= 42) {
		Gear gear(1, "Potion of gaseous form");
		return gear;
	} else if (roll <= 47) {
		Gear gear(1, "Potion of frost giant strength");
		return gear;
	} else if (roll <= 52) {
		Gear gear(1, "Potion of stone giant strength");
		return gear;
	} else if (roll <= 57) {
		Gear gear(1, "Potion of Heroism");
		return gear;
	} else if (roll <= 62) {
		Gear gear(1, "Potion of invulnerability");
		return gear;
	} else if (roll <= 67) {
		Gear gear(1, "Potion of mind reading");
		return gear;
	} else if (roll <= 72) {
		string scroll = GenerateScroll(5);
		Gear gear(1, scroll);
		return gear;
	} else if (roll <= 75) {
		Gear gear(1, "Elixir of health");
		return gear;
	} else if (roll <= 78) {
		Gear gear(1, "Oil of etherealness");
		return gear;
	} else if (roll <= 81) {
		Gear gear(1, "Potion of fire giant strength");
		return gear;
	} else if (roll <= 84) {
		string loader = "Quaal's Feather Token";
		int quaalvar = rolld100(mgen);
		if (quaalvar < 21) {
			loader += "(Anchor)";
		} else if (quaalvar < 36) {
			loader += "(Bird)";
		} else if (quaalvar < 51) {
			loader += "(Fan)";
		} else if (quaalvar < 66) {
			loader += "(Swan Boat)";
		} else if (quaalvar < 91) {
			loader += "(Tree)";
		} else {
			loader += "(Whip)";
		}
		Gear gear(1, loader);
		return gear;
	} else if (roll <= 87) {
		Gear gear(1, "Scroll of Protection");
		return gear;
	} else if (roll <= 89) {
		Gear gear(1, "Bag of beans");
		return gear;
	} else if (roll <= 91) {
		Gear gear(1, "Bead of force");
		return gear;
	} else if (roll <= 92) {
		Gear gear(1, "Chime of opening");
		return gear;
	} else if (roll <= 93) {
		Gear gear(1, "Decanter of endless water");
		return gear;
	} else if (roll <= 94) {
		Gear gear(1, "Eyes of minute seeing");
		return gear;
	} else if (roll <= 95) {
		Gear gear(1, "Folding boat");
		return gear;
	} else if (roll <= 96) {
		Gear gear(1, "Heward's handy haversack");
		return gear;
	} else if (roll <= 97) {
		Gear gear(1, "Horseshoes of speed");
		return gear;
	} else if (roll <= 98) {
		Gear gear(1, "Neckalace of fireballs");
		return gear;
	} else if (roll <= 99) {
		Gear gear(1, "Periapt of health");
		return gear;
	} else {
		Gear gear(1, "Sending stones");
		return gear;
	}
}

Gear Hoard_Loot::TableD() {
	int roll = 0;
	roll = rolld100(mgen);
	if (roll <= 20) {
		Gear gear(1, "Potion of supreme healing");
		return gear;
	} else if (roll <= 30) {
		Gear gear(1, "Potion of invisibility");
		return gear;
	} else if (roll <= 40) {
		Gear gear(1, "Potion of speed");
		return gear;
	} else if (roll <= 50) {
		string scroll = GenerateScroll(6);
		Gear gear(1, scroll);
		return gear;
	} else if (roll <= 57) {
		string scroll = GenerateScroll(7);
		Gear gear(1, scroll);
		return gear;
	} else if (roll <= 62) {
		Gear gear(1, "Ammunition, +3");
		return gear;
	} else if (roll <= 67) {
		Gear gear(1, "Oil of sharpness");
		return gear;
	} else if (roll <= 72) {
		Gear gear(1, "Potion of flying");
		return gear;
	} else if (roll <= 77) {
		Gear gear(1, "Potion of cloud giant strength");
		return gear;
	} else if (roll <= 82) {
		Gear gear(1, "Potion of longevity");
		return gear;
	} else if (roll <= 87) {
		Gear gear(1, "Potion of vitality");
		return gear;
	} else if (roll <= 92) {
		string scroll = GenerateScroll(8);
		Gear gear(1, scroll);
		return gear;
	} else if (roll <= 95) {
		Gear gear(1, "Horseshoes of a zephyr");
		return gear;
	} else if (roll <= 98) {
		Gear gear(1, "Nolzur's marvelous pigments");
		return gear;
	} else if (roll <= 99) {
		Gear gear(1, "Bag of devouring");
		return gear;
	} else {
		Gear gear(1, "PorTable hole");
		return gear;
	}
}

Gear Hoard_Loot::TableE() {
	int roll = 0;
	roll = rolld100(mgen);
	if (roll <= 30) {
		string scroll = GenerateScroll(8);
		Gear gear(1, scroll);
		return gear;
	} else if (roll <= 55) {
		Gear gear(1, "Potion of storm giant strength");
		return gear;
	} else if (roll <= 70) {
		Gear gear(1, "Potion of supreme healing");
		return gear;
	} else if (roll <= 85) {
		string scroll = GenerateScroll(9);
		Gear gear(1, scroll);
		return gear;
	} else if (roll <= 93) {
		Gear gear(1, "Universal solvent");
		return gear;
	} else if (roll <= 98) {
		Gear gear(1, "Arrow of slaying");
		return gear;
	} else {
		Gear gear(1, "Sovereign glue");
		return gear;
	}
}

Gear Hoard_Loot::TableF() {
	int roll = 0;
	roll = rolld100(mgen);
	if (roll <= 15) {
		Gear gear(1, "Weapon, +1");
		return gear;
	} else if (roll <= 18) {
		Gear gear(1, "Shield, +1");
		return gear;
	} else if (roll <= 21) {
		Gear gear(1, "Sentinel Shield");
		return gear;
	} else if (roll <= 23) {
		Gear gear(1, "Amulet of proof against detection and location");
		return gear;
	} else if (roll <= 25) {
		Gear gear(1, "Boots of elvenkind");
		return gear;
	} else if (roll <= 27) {
		Gear gear(1, "Boots of striding of springing");
		return gear;
	} else if (roll <= 29) {
		Gear gear(1, "Bracers of archery");
		return gear;
	} else if (roll <= 31) {
		Gear gear(1, "Brooch of shielding");
		return gear;
	} else if (roll <= 33) {
		Gear gear(1, "Broom of flying");
		return gear;
	} else if (roll <= 35) {
		Gear gear(1, "Cloak of elvenkind");
		return gear;
	} else if (roll <= 37) {
		Gear gear(1, "Cloak of protection");
		return gear;
	} else if (roll <= 39) {
		Gear gear(1, "Gauntlets of ogre power");
		return gear;
	} else if (roll <= 41) {
		Gear gear(1, "Hat of disguise");
		return gear;
	} else if (roll <= 43) {
		Gear gear(1, "Javelin of lightning");
		return gear;
	} else if (roll <= 45) {
		Gear gear(1, "Pearl of power");
		return gear;
	} else if (roll <= 47) {
		Gear gear(1, "Rod of the pact keeper, +1");
		return gear;
	} else if (roll <= 49) {
		Gear gear(1, "Slippers of spider climbing");
		return gear;
	} else if (roll <= 51) {
		Gear gear(1, "Staff of the adder");
		return gear;
	} else if (roll <= 53) {
		Gear gear(1, "Staff of the python");
		return gear;
	} else if (roll <= 55) {
		Gear gear(1, "Sword of vengeance");
		return gear;
	} else if (roll <= 57) {
		Gear gear(1, "Trident of fish command");
		return gear;
	} else if (roll <= 59) {
		Gear gear(1, "Wand of magic missles");
		return gear;
	} else if (roll <= 61) {
		Gear gear(1, "Wand of the war mage, +1");
		return gear;
	} else if (roll <= 63) {
		Gear gear(1, "Wand of web");
		return gear;
	} else if (roll <= 65) {
		Gear gear(1, "Weapon of warning");
		return gear;
	} else if (roll <= 66) {
		Gear gear(1, "Adamantine armor(chain mail)");
		return gear;
	} else if (roll <= 67) {
		Gear gear(1, "Adamantine armor(chain shirt)");
		return gear;
	} else if (roll <= 68) {
		Gear gear(1, "Adamantine armor(scale mail)");
		return gear;
	} else if (roll <= 69) {
		Gear gear(1, "Bag of tricks(grey)");
		return gear;
	} else if (roll <= 70) {
		Gear gear(1, "Bag of tricks(rust)");
		return gear;
	} else if (roll <= 71) {
		Gear gear(1, "Bag of tricks(tan)");
		return gear;
	} else if (roll <= 72) {
		Gear gear(1, "Boots of the winterlands");
		return gear;
	} else if (roll <= 73) {
		Gear gear(1, "Circlet of blasting");
		return gear;
	} else if (roll <= 74) {
		Gear gear(1, "Deck of illusions");
		return gear;
	} else if (roll <= 75) {
		Gear gear(1, "Eversmoking bottle");
		return gear;
	} else if (roll <= 76) {
		Gear gear(1, "Eyes of charming");
		return gear;
	} else if (roll <= 77) {
		Gear gear(1, "Eyes of the eagle");
		return gear;
	} else if (roll <= 78) {
		Gear gear(1, "Figurine of wondrous power(silver raven)");
		return gear;
	} else if (roll <= 79) {
		Gear gear(1, "Gem of brightness");
		return gear;
	} else if (roll <= 80) {
		Gear gear(1, "Gem of missile snaring");
		return gear;
	} else if (roll <= 81) {
		Gear gear(1, "Gloves of swimming and climbing");
		return gear;
	} else if (roll <= 82) {
		Gear gear(1, "Gloves of thievery");
		return gear;
	} else if (roll <= 83) {
		Gear gear(1, "Headband of intellect");
		return gear;
	} else if (roll <= 84) {
		Gear gear(1, "Helm of telepathy");
		return gear;
	} else if (roll <= 85) {
		Gear gear(1, "Instrument of the bards(Doss lute)");
		return gear;
	} else if (roll <= 86) {
		Gear gear(1, "Instrument of the bards(Fochlucan bandore)");
		return gear;
	} else if (roll <= 87) {
		Gear gear(1, "Instrument of the bards(Mac-Fuimidh cittern)");
		return gear;
	} else if (roll <= 88) {
		Gear gear(1, "Medallion of thoughts");
		return gear;
	} else if (roll <= 89) {
		Gear gear(1, "Necklace of adaptation");
		return gear;
	} else if (roll <= 90) {
		Gear gear(1, "Periapt of wound closure");
		return gear;
	} else if (roll <= 91) {
		Gear gear(1, "Pipes of haunting");
		return gear;
	} else if (roll <= 92) {
		Gear gear(1, "Pipes of the sewers");
		return gear;
	} else if (roll <= 93) {
		Gear gear(1, "Ring of jumping");
		return gear;
	} else if (roll <= 94) {
		Gear gear(1, "Ring of mind shielding");
		return gear;
	} else if (roll <= 95) {
		Gear gear(1, "Ring of warmth");
		return gear;
	} else if (roll <= 96) {
		Gear gear(1, "Ring of water walking");
		return gear;
	} else if (roll <= 97) {
		Gear gear(1, "Quiver of Ehlonna");
		return gear;
	} else if (roll <= 98) {
		Gear gear(1, "Stone of good luck");
		return gear;
	} else if (roll <= 99) {
		Gear gear(1, "Wind fan");
		return gear;
	} else {
		Gear gear(1, "Winged boots");
		return gear;
	}
}

Gear Hoard_Loot::TableG() {
	int roll = 0;
	roll = rolld100(mgen);
	if (roll <= 11) {
		Gear gear(1, "Weapon, +2");
		return gear;
	} else if (roll <= 14) {
		string loader = "Figurine of wonderous power";
		int d8 = rolld8(mgen);
		if (d8 == 1) {
			loader += "(Bronze griffon)";
			Gear gear(1, loader);
			return gear;
		} else if (d8 == 2) {
			loader += "(Ebony fly)";
			Gear gear(1, loader);
			return gear;
		} else if (d8 == 3) {
			loader += "(Golden lions)";
			Gear gear(1, loader);
			return gear;
		} else if (d8 == 4) {
			loader += "(Ivory goats)";
			Gear gear(1, loader);
			return gear;
		} else if (d8 == 5) {
			loader += "(Marble elephant)";
			Gear gear(1, loader);
			return gear;
		} else if (d8 <= 7) {
			loader += "(Onyx dog)";
			Gear gear(1, loader);
			return gear;
		} else {
			loader += "(Serpentine owl)";
			Gear gear(1, loader);
			return gear;
		}
	} else if (roll <= 15) {
		Gear gear(1, "Adamantine armor(breastplate)");
		return gear;
	} else if (roll <= 16) {
		Gear gear(1, "Adamantine armor(splint)");
		return gear;
	} else if (roll <= 17) {
		Gear gear(1, "Amulet of health");
		return gear;
	} else if (roll <= 18) {
		Gear gear(1, "Armor of vulnerability");
		return gear;
	} else if (roll <= 19) {
		Gear gear(1, "Arrow-catching shield");
		return gear;
	} else if (roll <= 20) {
		Gear gear(1, "Belt of dwarvenkind");
		return gear;
	} else if (roll <= 21) {
		Gear gear(1, "Belt of hill giant strength");
		return gear;
	} else if (roll <= 22) {
		Gear gear(1, "Berserker axe");
		return gear;
	} else if (roll <= 23) {
		Gear gear(1, "Boots of levitation");
		return gear;
	} else if (roll <= 24) {
		Gear gear(1, "Boots of speed");
		return gear;
	} else if (roll <= 25) {
		Gear gear(1, "Bowl of commanding water elementals");
		return gear;
	} else if (roll <= 26) {
		Gear gear(1, "Bracers of defense");
		return gear;
	} else if (roll <= 27) {
		Gear gear(1, "Brazier of commanding fire elementals");
		return gear;
	} else if (roll <= 28) {
		Gear gear(1, "Cape of the mountebank");
		return gear;
	} else if (roll <= 29) {
		Gear gear(1, "Censer of controlling air elementals");
		return gear;
	} else if (roll <= 30) {
		Gear gear(1, "Armor, +1 chain mail");
		return gear;
	} else if (roll <= 31) {
		Gear gear(1, "Armor of resistance(chain mail)");
		return gear;
	} else if (roll <= 32) {
		Gear gear(1, "Armor, +1 chain shirt");
		return gear;
	} else if (roll <= 33) {
		Gear gear(1, "Armor of resistance(chain shirt)");
		return gear;
	} else if (roll <= 34) {
		Gear gear(1, "Cloak of displacement");
		return gear;
	} else if (roll <= 35) {
		Gear gear(1, "Cloak of the bat");
		return gear;
	} else if (roll <= 36) {
		Gear gear(1, "Cube of force");
		return gear;
	} else if (roll <= 37) {
		Gear gear(1, "Daern's instant fortress");
		return gear;
	} else if (roll <= 38) {
		Gear gear(1, "Dagger of venom");
		return gear;
	} else if (roll <= 39) {
		Gear gear(1, "Dimensional shackles");
		return gear;
	} else if (roll <= 40) {
		Gear gear(1, "Dragon slayer");
		return gear;
	} else if (roll <= 41) {
		Gear gear(1, "Elven chain");
		return gear;
	} else if (roll <= 42) {
		Gear gear(1, "Flame tongue");
		return gear;
	} else if (roll <= 43) {
		Gear gear(1, "Gem of seeing");
		return gear;
	} else if (roll <= 44) {
		Gear gear(1, "Giant slayer");
		return gear;
	} else if (roll <= 45) {
		Gear gear(1, "Glammoured studded leather");
		return gear;
	} else if (roll <= 46) {
		Gear gear(1, "Helm of teleportation");
		return gear;
	} else if (roll <= 47) {
		Gear gear(1, "Horn of blasting");
		return gear;
	} else if (roll <= 48) {
		Gear gear(1, "Horn of Valhalla(silver or brass)");
		return gear;
	} else if (roll <= 49) {
		Gear gear(1, "Instrument of the bards(Canaith Mandolin");
		return gear;
	} else if (roll <= 50) {
		Gear gear(1, "Instrument of the bards(Cli lyre)");
		return gear;
	} else if (roll <= 51) {
		Gear gear(1, "Ioun stone(awareness)");
		return gear;
	} else if (roll <= 52) {
		Gear gear(1, "Ioun stone(protection)");
		return gear;
	} else if (roll <= 53) {
		Gear gear(1, "Ioun stone(reverse)");
		return gear;
	} else if (roll <= 54) {
		Gear gear(1, "Ioun stone(sustenance)");
		return gear;
	} else if (roll <= 55) {
		Gear gear(1, "Iron bands of Bilarro");
		return gear;
	} else if (roll <= 56) {
		Gear gear(1, "Armor, +1 leather");
		return gear;
	} else if (roll <= 57) {
		Gear gear(1, "Armor of resistance(leather)");
		return gear;
	} else if (roll <= 58) {
		Gear gear(1, "Mace of disruption");
		return gear;
	} else if (roll <= 59) {
		Gear gear(1, "Mace of smiting");
		return gear;
	} else if (roll <= 60) {
		Gear gear(1, "Mace of terror");
		return gear;
	} else if (roll <= 61) {
		Gear gear(1, "Mantle of spell resistance");
		return gear;
	} else if (roll <= 62) {
		Gear gear(1, "Necklace of prayer beads");
		return gear;
	} else if (roll <= 63) {
		Gear gear(1, "Periapt of proof against poison");
		return gear;
	} else if (roll <= 64) {
		Gear gear(1, "Ring of animal influence");
		return gear;
	} else if (roll <= 65) {
		Gear gear(1, "Ring of evasion");
		return gear;
	} else if (roll <= 66) {
		Gear gear(1, "Ring of feather falling");
		return gear;
	} else if (roll <= 67) {
		Gear gear(1, "Ring of free action");
		return gear;
	} else if (roll <= 68) {
		Gear gear(1, "Ring of protection");
		return gear;
	} else if (roll <= 69) {
		Gear gear(1, "Ring of resistance");
		return gear;
	} else if (roll <= 70) {
		Gear gear(1, "Ring of spell storing");
		return gear;
	} else if (roll <= 71) {
		Gear gear(1, "Ring of the ram");
		return gear;
	} else if (roll <= 72) {
		Gear gear(1, "Ring of X-ray vision");
		return gear;
	} else if (roll <= 73) {
		Gear gear(1, "Robe of eyes");
		return gear;
	} else if (roll <= 74) {
		Gear gear(1, "Rod of rulership");
		return gear;
	} else if (roll <= 75) {
		Gear gear(1, "Rod of the pact keeper, +2");
		return gear;
	} else if (roll <= 76) {
		Gear gear(1, "Rope of entanglement");
		return gear;
	} else if (roll <= 77) {
		Gear gear(1, "Armor, +1 scale mail");
		return gear;
	} else if (roll <= 78) {
		Gear gear(1, "Armor of resistance(scale mail)");
		return gear;
	} else if (roll <= 79) {
		Gear gear(1, "Shield, +2");
		return gear;
	} else if (roll <= 80) {
		Gear gear(1, "Shield of missle attraction");
		return gear;
	} else if (roll <= 81) {
		Gear gear(1, "Staff of charming");
		return gear;
	} else if (roll <= 82) {
		Gear gear(1, "Staff of healing");
		return gear;
	} else if (roll <= 83) {
		Gear gear(1, "Staff of swarming insects");
		return gear;
	} else if (roll <= 84) {
		Gear gear(1, "Staff of the woodlands");
		return gear;
	} else if (roll <= 85) {
		Gear gear(1, "Staff of the withering");
		return gear;
	} else if (roll <= 86) {
		Gear gear(1, "Stone of controlling earth elementals");
		return gear;
	} else if (roll <= 87) {
		Gear gear(1, "Sun blade");
		return gear;
	} else if (roll <= 88) {
		Gear gear(1, "Sword of life stealing");
		return gear;
	} else if (roll <= 89) {
		Gear gear(1, "Sword of wounding");
		return gear;
	} else if (roll <= 90) {
		Gear gear(1, "Tentacle rod");
		return gear;
	} else if (roll <= 91) {
		Gear gear(1, "Vicious weapon");
		return gear;
	} else if (roll <= 92) {
		Gear gear(1, "Wand of binding");
		return gear;
	} else if (roll <= 93) {
		Gear gear(1, "Wand of enemy detection");
		return gear;
	} else if (roll <= 94) {
		Gear gear(1, "Wand of fear");
		return gear;
	} else if (roll <= 95) {
		Gear gear(1, "Wand of fireballs");
		return gear;
	} else if (roll <= 96) {
		Gear gear(1, "Wand of lightning bolts");
		return gear;
	} else if (roll <= 97) {
		Gear gear(1, "Wand of paralysis");
		return gear;
	} else if (roll <= 98) {
		Gear gear(1, "Wand of the war mage, +2");
		return gear;
	} else if (roll <= 99) {
		Gear gear(1, "Wand of wonder");
		return gear;
	} else {
		Gear gear(1, "Wings of flying");
		return gear;
	}
}

Gear Hoard_Loot::TableH() {
	int roll = 0;
	roll = rolld100(mgen);
	if (roll <= 10) {
		Gear gear(1, "Weapon, +3");
		return gear;
	} else if (roll <= 12) {
		Gear gear(1, "Amulet of the planes");
		return gear;
	} else if (roll <= 14) {
		Gear gear(1, "Carpet of flying");
		return gear;
	} else if (roll <= 16) {
		Gear gear(1, "Crystal ball(very rare version)");
		return gear;
	} else if (roll <= 18) {
		Gear gear(1, "Ring of regeneration");
		return gear;
	} else if (roll <= 20) {
		Gear gear(1, "Ring of shooting stars");
		return gear;
	} else if (roll <= 22) {
		Gear gear(1, "Ring of telekinesis");
		return gear;
	} else if (roll <= 24) {
		Gear gear(1, "Robe of scintillating colors");
		return gear;
	} else if (roll <= 26) {
		Gear gear(1, "Robe of stars");
		return gear;
	} else if (roll <= 28) {
		Gear gear(1, "Rod of absorption");
		return gear;
	} else if (roll <= 30) {
		Gear gear(1, "Rod of alertness");
		return gear;
	} else if (roll <= 32) {
		Gear gear(1, "Rod of security");
		return gear;
	} else if (roll <= 34) {
		Gear gear(1, "Rod of the pact keeper, +3");
		return gear;
	} else if (roll <= 36) {
		Gear gear(1, "Scimitar of speed");
		return gear;
	} else if (roll <= 38) {
		Gear gear(1, "Shield, +3");
		return gear;
	} else if (roll <= 40) {
		Gear gear(1, "Staff of fire");
		return gear;
	} else if (roll <= 42) {
		Gear gear(1, "Staff of frost");
		return gear;
	} else if (roll <= 44) {
		Gear gear(1, "Staff of power");
		return gear;
	} else if (roll <= 46) {
		Gear gear(1, "Staff of striking");
		return gear;
	} else if (roll <= 48) {
		Gear gear(1, "Staff of thunder and lightning");
		return gear;
	} else if (roll <= 50) {
		Gear gear(1, "Sword of sharpness");
		return gear;
	} else if (roll <= 52) {
		Gear gear(1, "Wand of polymorph");
		return gear;
	} else if (roll <= 54) {
		Gear gear(1, "Wand of the war mage, +3");
		return gear;
	} else if (roll <= 55) {
		Gear gear(1, "Adamantine armor(half plate)");
		return gear;
	} else if (roll <= 56) {
		Gear gear(1, "Adamantine armor(plate)");
		return gear;
	} else if (roll <= 57) {
		Gear gear(1, "Animated shield");
		return gear;
	} else if (roll <= 58) {
		Gear gear(1, "Belt of fire giant strength");
		return gear;
	} else if (roll <= 59) {
		Gear gear(1, "Belt of stone giant strength");
		return gear;
	} else if (roll <= 60) {
		Gear gear(1, "Armor, +1 breastplate");
		return gear;
	} else if (roll <= 61) {
		Gear gear(1, "Armor of resistance(breastplate)");
		return gear;
	} else if (roll <= 62) {
		Gear gear(1, "Candle of invocation");
		return gear;
	} else if (roll <= 63) {
		Gear gear(1, "Armor, +2 chain mail");
		return gear;
	} else if (roll <= 64) {
		Gear gear(1, "Armor, +2 chain shirt");
		return gear;
	} else if (roll <= 65) {
		Gear gear(1, "Cloak of arachnida");
		return gear;
	} else if (roll <= 66) {
		Gear gear(1, "Dancing sword");
		return gear;
	} else if (roll <= 67) {
		Gear gear(1, "Demon armor");
		return gear;
	} else if (roll <= 68) {
		Gear gear(1, "Dragon scale mail");
		return gear;
	} else if (roll <= 69) {
		Gear gear(1, "Dwarven plate");
		return gear;
	} else if (roll <= 70) {
		Gear gear(1, "Dwarven thrower");
		return gear;
	} else if (roll <= 71) {
		Gear gear(1, "Efreeti bottle");
		return gear;
	} else if (roll <= 72) {
		Gear gear(1, "Figurine of wondrous power(obsidian steed)");
		return gear;
	} else if (roll <= 73) {
		Gear gear(1, "Frost brand");
		return gear;
	} else if (roll <= 74) {
		Gear gear(1, "Helm of brilliance");
		return gear;
	} else if (roll <= 75) {
		Gear gear(1, "Horn of Valhalla(bronze)");
		return gear;
	} else if (roll <= 76) {
		Gear gear(1, "Instrument of the bards(Anstruth harp)");
		return gear;
	} else if (roll <= 77) {
		Gear gear(1, "Ioun stone(absorption)");
		return gear;
	} else if (roll <= 78) {
		Gear gear(1, "Ioun stone(agility)");
		return gear;
	} else if (roll <= 79) {
		Gear gear(1, "Ioun stone(fortitude)");
		return gear;
	} else if (roll <= 80) {
		Gear gear(1, "Ioun stone(insight)");
		return gear;
	} else if (roll <= 81) {
		Gear gear(1, "Ioun stone(intellect)");
		return gear;
	} else if (roll <= 82) {
		Gear gear(1, "Ioun stone(leadership)");
		return gear;
	} else if (roll <= 83) {
		Gear gear(1, "Ioun stone(strength)");
		return gear;
	} else if (roll <= 84) {
		Gear gear(1, "Armor, +2 leather");
		return gear;
	} else if (roll <= 85) {
		Gear gear(1, "Manual of bodily health");
		return gear;
	} else if (roll <= 86) {
		Gear gear(1, "Manual of gainful exercise");
		return gear;
	} else if (roll <= 87) {
		Gear gear(1, "Manual of golems");
		return gear;
	} else if (roll <= 88) {
		Gear gear(1, "Manual of quickness of action");
		return gear;
	} else if (roll <= 89) {
		Gear gear(1, "Mirror of life trapping");
		return gear;
	} else if (roll <= 90) {
		Gear gear(1, "Nine lives stealer");
		return gear;
	} else if (roll <= 91) {
		Gear gear(1, "Oathbow");
		return gear;
	} else if (roll <= 92) {
		Gear gear(1, "Armor, +2 scale mail");
		return gear;
	} else if (roll <= 93) {
		Gear gear(1, "Spellguard shield");
		return gear;
	} else if (roll <= 94) {
		Gear gear(1, "Armor, +1 splint");
		return gear;
	} else if (roll <= 95) {
		Gear gear(1, "Armor of resistance(splint)");
		return gear;
	} else if (roll <= 96) {
		Gear gear(1, "Armor, +1 studded leather");
		return gear;
	} else if (roll <= 97) {
		Gear gear(1, "Armor of resistance(studded leather)");
		return gear;
	} else if (roll <= 98) {
		Gear gear(1, "Tome of clear thought");
		return gear;
	} else if (roll <= 99) {
		Gear gear(1, "Tome of leadership and influecne");
		return gear;
	} else {
		Gear gear(1, "Tome of understanding");
		return gear;
	}
}

Gear Hoard_Loot::TableI() {
	int roll = 0;
	roll = rolld100(mgen);
	if (roll <= 5) {
		Gear gear(1, "Defender");
		return gear;
	} else if (roll <= 10) {
		Gear gear(1, "Hammer of thunderbolts");
		return gear;
	} else if (roll <= 15) {
		Gear gear(1, "Luck blade");
		return gear;
	} else if (roll <= 20) {
		Gear gear(1, "Sword of answering");
		return gear;
	} else if (roll <= 23) {
		Gear gear(1, "Holy Avenger");
		return gear;
	} else if (roll <= 26) {
		Gear gear(1, "Ring of djinni summoning");
		return gear;
	} else if (roll <= 29) {
		Gear gear(1, "Ring of invisibility");
		return gear;
	} else if (roll <= 32) {
		Gear gear(1, "Ring of spell turning");
		return gear;
	} else if (roll <= 35) {
		Gear gear(1, "Rod of lordly might");
		return gear;
	} else if (roll <= 38) {
		Gear gear(1, "Staff of the magi");
		return gear;
	} else if (roll <= 41) {
		Gear gear(1, "Vorpal sword");
		return gear;
	} else if (roll <= 43) {
		Gear gear(1, "Belt of cloud giant strength");
		return gear;
	} else if (roll <= 45) {
		Gear gear(1, "Armor, +2 breastplate");
		return gear;
	} else if (roll <= 47) {
		Gear gear(1, "Armor, +3 chain mail");
		return gear;
	} else if (roll <= 49) {
		Gear gear(1, "Armor, +3 chain shirt");
		return gear;
	} else if (roll <= 51) {
		Gear gear(1, "Cloak of invisibility");
		return gear;
	} else if (roll <= 53) {
		Gear gear(1, "Crystal ball(legendary version)");
		return gear;
	} else if (roll <= 55) {
		Gear gear(1, "Armor, +1 half plate");
		return gear;
	} else if (roll <= 57) {
		Gear gear(1, "Iron flask");
		return gear;
	} else if (roll <= 59) {
		Gear gear(1, "Armor, +3 leather");
		return gear;
	} else if (roll <= 61) {
		Gear gear(1, "Armor, +1 plate");
		return gear;
	} else if (roll <= 63) {
		Gear gear(1, "Robe of the archmagi");
		return gear;
	} else if (roll <= 65) {
		Gear gear(1, "Rod of resurrection");
		return gear;
	} else if (roll <= 67) {
		Gear gear(1, "Armor, +1 scale mail");
		return gear;
	} else if (roll <= 69) {
		Gear gear(1, "Scarab of protection");
		return gear;
	} else if (roll <= 71) {
		Gear gear(1, "Armor, +2 splint");
		return gear;
	} else if (roll <= 73) {
		Gear gear(1, "Armor, +2 studded leather");
		return gear;
	} else if (roll <= 75) {
		Gear gear(1, "Well of many worlds");
		return gear;
	} else if (roll <= 76) {
		string loader = "Armor, ";
		int d12 = rolld12(mgen);
		if (d12 <= 2) {
			loader += "+2 half plate";
			Gear gear(1, loader);
			return gear;
		} else if (d12 <= 4) {
			loader += "+2 plate";
			Gear gear(1, loader);
			return gear;
		} else if (d12 <= 6) {
			loader += "+3 studded leather";
			Gear gear(1, loader);
			return gear;
		} else if (d12 == 8) {
			loader += "+3 breastplate";
			Gear gear(1, loader);
			return gear;
		} else if (d12 == 10) {
			loader += "+3 splint";
			Gear gear(1, loader);
			return gear;
		} else if (d12 <= 11) {
			loader += "+3 half plate";
			Gear gear(1, loader);
			return gear;
		} else {
			loader += "+3 plate";
			Gear gear(1, loader);
			return gear;
		}
	} else if (roll <= 77) {
		Gear gear(1, "Apparatus of Kwalish");
		return gear;
	} else if (roll <= 78) {
		Gear gear(1, "Amor of invulnerability");
		return gear;
	} else if (roll <= 79) {
		Gear gear(1, "Belt of storm giant strength");
		return gear;
	} else if (roll <= 80) {
		Gear gear(1, "Cubic gate");
		return gear;
	} else if (roll <= 81) {
		Gear gear(1, "Deck of many things");
		return gear;
	} else if (roll <= 82) {
		Gear gear(1, "Efreeti chain");
		return gear;
	} else if (roll <= 83) {
		Gear gear(1, "Armor of resistance(half plate)");
		return gear;
	} else if (roll <= 84) {
		Gear gear(1, "Horn of Valhalla(iron)");
		return gear;
	} else if (roll <= 85) {
		Gear gear(1, "Instrument of the bards(Ollamh harp)");
		return gear;
	} else if (roll <= 86) {
		Gear gear(1, "Ioun stone(greater absorption)");
		return gear;
	} else if (roll <= 87) {
		Gear gear(1, "Ioun stone(mastery)");
		return gear;
	} else if (roll <= 88) {
		Gear gear(1, "Ioun stone(regeneration)");
		return gear;
	} else if (roll <= 89) {
		Gear gear(1, "Plate armor of etherealness");
		return gear;
	} else if (roll <= 90) {
		Gear gear(1, "Plate armor of resistance");
		return gear;
	} else if (roll <= 91) {
		Gear gear(1, "Ring of air elemetnal command");
		return gear;
	} else if (roll <= 93) {
		Gear gear(1, "Ring of fire elemental command");
		return gear;
	} else if (roll <= 94) {
		Gear gear(1, "Ring of three wishes");
		return gear;
	} else if (roll <= 95) {
		Gear gear(1, "Ring of water elemental command");
		return gear;
	} else if (roll <= 96) {
		Gear gear(1, "Sphere of Annihilation");
		return gear;
	} else if (roll <= 97) {
		Gear gear(1, "Talisman of Pure Good");
		return gear;
	} else if (roll <= 98) {
		Gear gear(1, "Talisman of the Sphere");
		return gear;
	} else if (roll <= 99) {
		Gear gear(1, "Talisman of Ultimate Evil");
		return gear;
	} else {
		Gear gear(1, "Tome of Stilled Tongue");
		return gear;
	}
}

string Hoard_Loot::GenerateScroll(const int &lvl) const {
	int ss = 0;
	string scroll;
	switch (lvl) {
		case 1:
			scroll = "Level 1 Scroll of ";
			ss = randomNumber(1, 61);
			switch (ss) {
				case 1:
					scroll += "Alarm (ranger, wizard)";
					break;
				case 2:
					scroll += "Animal Friendship (bard, druid, ranger)";
					break;
				case 3:
					scroll += "Armor of Agathys (warlock)";
					break;
				case 4:
					scroll += "Arms of Hadar (warlock)";
					break;
				case 5:
					scroll += "Bane (bard, cleric)";
					break;
				case 6:
					scroll += "Bless (cleric, paladin)";
					break;
				case 7:
					scroll += "Burning Hands (sorcerer, wizard)";
					break;
				case 8:
					scroll += "Charm Person (bard, druid, sorcerer, warlock, wizard)";
					break;
				case 9:
					scroll += "Color Spray (sorcerer, wizard)";
					break;
				case 10:
					scroll += "Command (cleric, paladin)";
					break;
				case 11:
					scroll += "Compelled Duel (paladin)";
					break;
				case 12:
					scroll += "Comprehend Languages (bard, sorcerer, warlock, wizard)";
					break;
				case 13:
					scroll += "Create or Destroy Water (cleric, druid)";
					break;
				case 14:
					scroll += "Cure Wounds (bard, cleric, druid, paladin, ranger)";
					break;
				case 15:
					scroll += "Detect Evil and Good (cleric, paladin)";
					break;
				case 16:
					scroll += "Detect Magic (bard, cleric, druid, paladin, ranger, sorcerer, wizard)";
					break;
				case 17:
					scroll += "Detect Poison and Disease (cleric, druid, paladin, ranger)";
					break;
				case 18:
					scroll += "Disguise Self (bard, sorcerer, wizard)";
					break;
				case 19:
					scroll += "Dissonant Whispers (bard)";
					break;
				case 20:
					scroll += "Divine Favor (paladin)";
					break;
				case 21:
					scroll += "Ensnaring Strike (ranger)";
					break;
				case 22:
					scroll += "Entangle (druid)";
					break;
				case 23:
					scroll += "Expeditious Retreat (sorcerer, warlock, wizard)";
					break;
				case 24:
					scroll += "False Life (sorcerer, wizard)";
					break;
				case 25:
					scroll += "Faerie Fire (bard, druid)";
					break;
				case 26:
					scroll += "Feather Fall (bard, sorcerer, wizard)";
					break;
				case 27:
					scroll += "Find Familiar (wizard)";
					break;
				case 28:
					scroll += "Fog Cloud (druid, ranger, sorcerer, wizard)";
					break;
				case 29:
					scroll += "Goodberry (druid, ranger)";
					break;
				case 30:
					scroll += "Grease (wizard)";
					break;
				case 31:
					scroll += "Guiding Bolt (cleric)";
					break;
				case 32:
					scroll += "Hail of Thorns (ranger)";
					break;
				case 33:
					scroll += "Healing Word (bard, cleric, druid)";
					break;
				case 34:
					scroll += "Hellish Rebuke (warlock)";
					break;
				case 35:
					scroll += "Heroism (bard, paladin)";
					break;
				case 36:
					scroll += "Hex (warlock)";
					break;
				case 37:
					scroll += "Hunter's Mark (ranger)";
					break;
				case 38:
					scroll += "Identify (bard, wizard)";
					break;
				case 39:
					scroll += "Illusory Script (bard, warlock, wizard)";
					break;
				case 40:
					scroll += "Inflict Wounds (cleric)";
					break;
				case 41:
					scroll += "Jump (druid, ranger, sorcerer, wizard)";
					break;
				case 42:
					scroll += "Longstrider (bard, druid, ranger, wizard)";
					break;
				case 43:
					scroll += "Mage Armor (sorcerer, wizard)";
					break;
				case 44:
					scroll += "Magic Missle (sorcerer, wizard)";
					break;
				case 45:
					scroll += "Protection from Evil and Good (cleric, paladin, warlock, wizard)";
					break;
				case 46:
					scroll += "Purify Food and Drink (cleric, druid, paladin)";
					break;
				case 47:
					scroll += "Ray of Sickness (sorcerer, wizard)";
					break;
				case 48:
					scroll += "Searing Smite (paladin)";
					break;
				case 49:
					scroll += "Sanctuary (cleric)";
					break;
				case 50:
					scroll += "Shield (sorcerer, wizard)";
					break;
				case 51:
					scroll += "Shield of Faith (cleric, paladin)";
					break;
				case 52:
					scroll += "Silent Image (bard, sorcerer, wizard)";
					break;
				case 53:
					scroll += "Sleep (bard, sorcerer, wizard)";
					break;
				case 54:
					scroll += "Speak with Animals (bard, druid, ranger)";
					break;
				case 55:
					scroll += "Tasha's Hideous Laughter (bard, wizard)";
					break;
				case 56:
					scroll += "Tensor's Floating Disk (wizard)";
					break;
				case 57:
					scroll += "Thunderous Smite (paladin)";
					break;
				case 58:
					scroll += "Thunderwave (bard, druid, sorcerer, wizard)";
					break;
				case 59:
					scroll += "Unseen Servant (bard, warlock, wizard)";
					break;
				case 60:
					scroll += "Witch Bolt (sorcerer, warlock, wizard)";
					break;
				case 61:
					scroll += "Wrathful Smite (paladin)";
					break;
			}
			break;
		case 2:
			scroll = "Level 2 Scroll of ";
			ss = randomNumber(1, 59);
			switch (ss) {
				case 1:
					scroll += "Aid (cleric, paladin)";
					break;
				case 2:
					scroll += "Alter Self (sorcerer, wizard)";
					break;
				case 3:
					scroll += "Animal Messenger (bard, druid, ranger)";
					break;
				case 4:
					scroll += "Arcane Lock (wizard)";
					break;
				case 5:
					scroll += "Augury (cleric)";
					break;
				case 6:
					scroll += "Barkskin (druid, ranger)";
					break;
				case 7:
					scroll += "Beast Sense (druid, ranger)";
					break;
				case 8:
					scroll += "Blindness/Deafness (bard, cleric, sorcerer, wizard)";
					break;
				case 9:
					scroll += "Blur (sorcerer, wizard)";
					break;
				case 10:
					scroll += "Branding Smite (paladin)";
					break;
				case 11:
					scroll += "Calm Emotions (bard, cleric)";
					break;
				case 12:
					scroll += "Cloud of Daggers (bard, sorcerer, warlock, wizard)";
					break;
				case 13:
					scroll += "Continual Flame (cleric, wizard)";
					break;
				case 14:
					scroll += "Cordon of Arrows (ranger)";
					break;
				case 15:
					scroll += "Crown of Madness (bard, sorcerer, warlock, wizard)";
					break;
				case 16:
					scroll += "Darkness (sorcerer, warlock, wizard)";
					break;
				case 17:
					scroll += "Darkvision (druid, ranger, sorcerer, wizard)";
					break;
				case 18:
					scroll += "Detect Thoughts (bard, sorcerer, wizard)";
					break;
				case 19:
					scroll += "Enhance Ability (bard, cleric, druid, sorcerer)";
					break;
				case 20:
					scroll += "Enlarge/Reduce (sorcerer, wizard)";
					break;
				case 21:
					scroll += "Enthrall (bard, warlock)";
					break;
				case 22:
					scroll += "Find Steed (paladin)";
					break;
				case 23:
					scroll += "Find Traps (cleric, druid, ranger)";
					break;
				case 24:
					scroll += "Flame Blade (druid)";
					break;
				case 25:
					scroll += "Flaming Sphere (druid, wizard)";
					break;
				case 26:
					scroll += "Heat Metal (bard, druid)";
					break;
				case 27:
					scroll += "Hold Person (bard, druid, sorcerer, warlock)";
					break;
				case 28:
					scroll += "Gentle Repose (cleric)";
					break;
				case 29:
					scroll += "Gust of Wind (druid, sorcerer)";
					break;
				case 30:
					scroll += "Invisibility (bard, sorcerer, warlock, wizard)";
					break;
				case 31:
					scroll += "Knock (bard, sorcerer, wizard)";
					break;
				case 32:
					scroll += "Lesser Restoration (bard, cleric, druid, paladin, ranger)";
					break;
				case 33:
					scroll += "Levitate (sorcerer, wizard)";
					break;
				case 34:
					scroll += "Locate Animals or Plants (bard, druid, ranger)";
					break;
				case 35:
					scroll += "Locate Object (bard, cleric, druid, paladin, ranger, wizard)";
					break;
				case 36:
					scroll += "Magic Mouth (bard, wizard)";
					break;
				case 37:
					scroll += "Magic Weapon (paladin, wizard)";
					break;
				case 38:
					scroll += "Melf's Acid Arrow (wizard)";
					break;
				case 39:
					scroll += "Mirror Image (sorcerer, warlock, wizard)";
					break;
				case 40:
					scroll += "Misty Step (sorcerer, warlock, wizard)";
					break;
				case 41:
					scroll += "Moonbeam (druid)";
					break;
				case 42:
					scroll += "Nystul's Magic Aura (wizard)";
					break;
				case 43:
					scroll += "Pass without Trace (druid, ranger)";
					break;
				case 44:
					scroll += "Phantasmal Force (bard, sorcerer, wizard)";
					break;
				case 45:
					scroll += "Prayer of Healing (cleric)";
					break;
				case 46:
					scroll += "Protection of Poison (cleric, druid, poison, ranger)";
					break;
				case 47:
					scroll += "Ray of Enfeeblement (warlock, wizard)";
					break;
				case 48:
					scroll += "Rope Trick (wizard)";
					break;
				case 49:
					scroll += "Scorching Ray (sorcerer, wizard)";
					break;
				case 50:
					scroll += "See Invisibility (bard, sorcerer, wizard)";
					break;
				case 51:
					scroll += "Silence (bard, cleric, ranger)";
					break;
				case 52:
					scroll += "Silent Image (bard, sorcerer, wizard)";
					break;
				case 53:
					scroll += "Spider Climb (sorcerer, warlock, wizard)";
					break;
				case 54:
					scroll += "Spike Growth (druid, ranger)";
					break;
				case 55:
					scroll += "Spiritual Weapon (cleric)";
					break;
				case 56:
					scroll += "Suggestion (bard, sorcerer, warlock, wizard)";
					break;
				case 57:
					scroll += "Warding Bond (cleric)";
					break;
				case 58:
					scroll += "Web (sorcerer, wizard)";
					break;
				case 59:
					scroll += "Zone of Truth (bard, cleric, paladin)";
					break;
			}
			break;
		case 3:
			scroll = "Level 3 Scroll of ";
			ss = randomNumber(1, 50);
			switch (ss) {
				case 1:
					scroll += "Animate Dead (cleric, wizard)";
					break;
				case 2:
					scroll += "Aura of Vitality (paladin)";
					break;
				case 3:
					scroll += "Beacon of Hope (cleric)";
					break;
				case 4:
					scroll += "Bestow Curse (bard, cleric, wizard)";
					break;
				case 5:
					scroll += "Blinding Smite (paladin)";
					break;
				case 6:
					scroll += "Blink (sorcerer, wizard)";
					break;
				case 7:
					scroll += "Call Lightning (druid)";
					break;
				case 8:
					scroll += "Clairvoyance (bard, cleric, sorcerer, wizard)";
					break;
				case 9:
					scroll += "Conjure Animals (druid, ranger)";
					break;
				case 10:
					scroll += "Conjure Barrage (ranger)";
					break;
				case 11:
					scroll += "Counterspell (sorcerer, warlock, wizard)";
					break;
				case 12:
					scroll += "Create Food and Water (cleric, paladin)";
					break;
				case 13:
					scroll += "Crusader's Mantle (paladin)";
					break;
				case 14:
					scroll += "Daylight (cleric, druid, paladin, ranger, sorcerer)";
					break;
				case 15:
					scroll += "Dispel Magic (bard, cleric, druid, paladin, sorcerer, warlock, wizard)";
					break;
				case 16:
					scroll += "Elemental Weapon (paladin)";
					break;
				case 17:
					scroll += "Fear (bard, sorcerer, warlock, wizard)";
					break;
				case 18:
					scroll += "Feign Death (bard, cleric, druid, wizard)";
					break;
				case 19:
					scroll += "Fireball (sorcerer, wizard)";
					break;
				case 20:
					scroll += "Fly (sorcerer, warlock)";
					break;
				case 21:
					scroll += "Gaseous Form (sorcerer, warlock, wizard)";
					break;
				case 22:
					scroll += "Glyph of Warding (bard, cleric, wizard)";
					break;
				case 23:
					scroll += "Haste (sorcerer, wizard)";
					break;
				case 24:
					scroll += "Hunger of Hadar (warlock)";
					break;
				case 25:
					scroll += "Hypnotic Pattern (bard, sorcerer, warlock, wizard)";
					break;
				case 26:
					scroll += "Leomund's Tiny Hut (bard, wizard)";
					break;
				case 27:
					scroll += "Lightning Arrow (ranger)";
					break;
				case 28:
					scroll += "Lightning Bolt (sorcerer, wizard)";
					break;
				case 29:
					scroll += "Magic Circle (cleric, paladin, warlock, wizard)";
					break;
				case 30:
					scroll += "Major Image (bard, sorcerer, warlock, wizard)";
					break;
				case 31:
					scroll += "Mass Healing Word (cleric)";
					break;
				case 32:
					scroll += "Meld Into Stone (cleric, druid)";
					break;
				case 33:
					scroll += "Nondetection (bard, ranger, wizard)";
					break;
				case 34:
					scroll += "Phantom Steed (wizard)";
					break;
				case 35:
					scroll += "Plant Growth (bard, druid, ranger)";
					break;
				case 36:
					scroll += "Protection from Energy (cleric, druid, ranger, sorcerer, wizard)";
					break;
				case 37:
					scroll += "Remove Curse (cleric, paladin, warlock)";
					break;
				case 38:
					scroll += "Revivify (cleric, paladin)";
					break;
				case 39:
					scroll += "Sending (bard, cleric, wizard)";
					break;
				case 40:
					scroll += "Sleet Storm (druid, sorcerer, wizard)";
					break;
				case 41:
					scroll += "Slow (sorcerer, wizard)";
					break;
				case 42:
					scroll += "Speak with Dead (bard, cleric)";
					break;
				case 43:
					scroll += "Speak with Plants (bard, druid, ranger)";
					break;
				case 44:
					scroll += "Spirit Guardians (cleric)";
					break;
				case 45:
					scroll += "Stinking Cloud (bard, sorcerer, wizard)";
					break;
				case 46:
					scroll += "Tongues (bard, cleric, sorcerer, warlock, wizard)";
					break;
				case 47:
					scroll += "Vampiric Touch (warlock, wizard)";
					break;
				case 48:
					scroll += "Water Breathing (druid, ranger, sorcerer, wizard)";
					break;
				case 49:
					scroll += "Water Walk (cleric, druid, ranger, sorcerer)";
					break;
				case 50:
					scroll += "Wind Wall (druid, ranger)";
					break;
			}
			break;
		case 4:
			scroll = "Level 4 Scroll of ";
			ss = randomNumber(1, 34);
			switch (ss) {
				case 1:
					scroll += "Aura of Life (paladin)";
					break;
				case 2:
					scroll += "Aura of Purify (paladin)";
					break;
				case 3:
					scroll += "Arcane Eye (wizard)";
					break;
				case 4:
					scroll += "Banishment (cleric, paladin, sorcerer, warlock, wizard)";
					break;
				case 5:
					scroll += "Blight (druid, sorcerer, warlock, wizard)";
					break;
				case 6:
					scroll += "Compulsion (bard)";
					break;
				case 7:
					scroll += "Confusion (bard, druid, sorcerer, wizard)";
					break;
				case 8:
					scroll += "Conjure Minor Elementals (druid, wizard)";
					break;
				case 9:
					scroll += "Conjure Woodland Beings (druid, ranger)";
					break;
				case 10:
					scroll += "Control Water (druid, wizard)";
					break;
				case 11:
					scroll += "Control Weather (cleric)";
					break;
				case 12:
					scroll += "Death Ward (cleric)";
					break;
				case 13:
					scroll += "Dimension Door (bard, warlock, wizard)";
					break;
				case 14:
					scroll += "Divination (cleric)";
					break;
				case 15:
					scroll += "Dominate Beast (druid, sorcerer)";
					break;
				case 16:
					scroll += "Evard's Black Tentacles (wizard)";
					break;
				case 17:
					scroll += "Fabricate (wizard)";
					break;
				case 18:
					scroll += "Fire Shield (wizard)";
					break;
				case 19:
					scroll += "Grasping Vine (druid, ranger)";
					break;
				case 20:
					scroll += "Greater Invisibility (bard, sorcerer, wizard)";
					break;
				case 21:
					scroll += "Guardian of Faith (cleric)";
					break;
				case 22:
					scroll += "Hallucinatory Terrain (bard, druid, warlock, wizard)";
					break;
				case 23:
					scroll += "Ice Storm (druid, sorcerer, wizard)";
					break;
				case 24:
					scroll += "Leomund's Secret Chest (wizard)";
					break;
				case 25:
					scroll += "Locate Creature (bard, cleric, druid, paladin, ranger, wizard)";
					break;
				case 26:
					scroll += "Mordenkainen's Faithful Hound (wizard)";
					break;
				case 27:
					scroll += "Mordenkainen's Private Sanctum (wizard)";
					break;
				case 28:
					scroll += "Otiluke's Resilient Sphere (wizard)";
					break;
				case 29:
					scroll += "Phantasmal Killer (wizard)";
					break;
				case 30:
					scroll += "Polymorph (bard, sorcerer, wizard)";
					break;
				case 31:
					scroll += "Staggering Smite (paladin)";
					break;
				case 32:
					scroll += "Stone Shape (cleric, druid, wizard)";
					break;
				case 33:
					scroll += "Stoneskin (druid, ranger, sorcerer, wizard)";
					break;
				case 34:
					scroll += "Wall of Fire (druid, sorcerer, wizard)";
					break;
			}
			break;
		case 5:
			scroll = "Level 5 Scroll of ";
			ss = randomNumber(1, 42);
			switch (ss) {
				case 1:
					scroll += "Animate Objects (bard, sorcerer, wizard)";
					break;
				case 2:
					scroll += "Antilife Shell (druid)";
					break;
				case 3:
					scroll += "Awaken (bard, druid)";
					break;
				case 4:
					scroll += "Banishing Smite (paladin)";
					break;
				case 5:
					scroll += "Bigby's Hand (wizard)";
					break;
				case 6:
					scroll += "Circle of Power (paladin)";
					break;
				case 7:
					scroll += "Cloudkill (sorcerer, wizard)";
					break;
				case 8:
					scroll += "Commune (cleric)";
					break;
				case 9:
					scroll += "Commune with Nature (druid, ranger)";
					break;
				case 10:
					scroll += "Cone of Cold (sorcerer, wizard)";
					break;
				case 11:
					scroll += "Conjure ELemental (druid, wizard)";
					break;
				case 12:
					scroll += "Conjure Volley (ranger)";
					break;
				case 13:
					scroll += "Contact Other Plane (warlock, wizard)";
					break;
				case 14:
					scroll += "Contagion (cleric, druid)";
					break;
				case 15:
					scroll += "Creation (sorcerer, wizard)";
					break;
				case 16:
					scroll += "Destructive Smite (paladin)";
					break;
				case 17:
					scroll += "Dispel Evil and Good (cleric, paladin)";
					break;
				case 18:
					scroll += "Dominate Person (bard, sorcerer, wizard)";
					break;
				case 19:
					scroll += "Dream (bard, warlock, wizard)";
					break;
				case 20:
					scroll += "Flame Strike (cleric)";
					break;
				case 21:
					scroll += "Geas (bard, cleric, druid, paladin, wizard)";
					break;
				case 22:
					scroll += "Greater Restoration (bard, cleric, druid)";
					break;
				case 23:
					scroll += "Hallow (cleric)";
					break;
				case 24:
					scroll += "Hold Monster (bard, sorcerer, warlock, wizard)";
					break;
				case 25:
					scroll += "Insect Plague (cleric, druid, sorcerer)";
					break;
				case 26:
					scroll += "Legend Lore (bard, cleric, wizard)";
					break;
				case 27:
					scroll += "Mass Cure Wounds (bard, cleric)";
					break;
				case 28:
					scroll += "Mislead (bard, wizard)";
					break;
				case 29:
					scroll += "Modify Memory (bard, wizard)";
					break;
				case 30:
					scroll += "Passwall (wizard)";
					break;
				case 31:
					scroll += "Planar Binding (bard, cleric, druid, wizard)";
					break;
				case 32:
					scroll += "Raise Dead (bard, cleric, paladin)";
					break;
				case 33:
					scroll += "Rary's Telepathic Bond (wizard)";
					break;
				case 34:
					scroll += "Reincarnate (druid)";
					break;
				case 35:
					scroll += "Scrying (bard, cleric, druid, warlock, wizard)";
					break;
				case 36:
					scroll += "Seeming (bard, sorcerer, wizard)";
					break;
				case 37:
					scroll += "Swift Quiver (ranger)";
					break;
				case 38:
					scroll += "Telekinesis (sorcerer, wizard)";
					break;
				case 39:
					scroll += "Teleportation Circle (bard, sorcerer, wizard)";
					break;
				case 40:
					scroll += "Tree Stride (druid, ranger)";
					break;
				case 41:
					scroll += "Wall of Force (wizard)";
					break;
				case 42:
					scroll += "Wall of Stone (druid, sorcerer, wizard)";
					break;
			}
			break;
		case 6:
			scroll = "Level 6 Scroll of ";
			ss = randomNumber(1, 32);
			switch (ss) {
				case 1:
					scroll += "Arcane Gate (sorcerer, warlock, wizard)";
					break;
				case 2:
					scroll += "Blade Barrier (cleric)";
					break;
				case 3:
					scroll += "Chain Lightning (sorcerer, wizard)";
					break;
				case 4:
					scroll += "Circle of Death (sorcerer, warlock, wizard)";
					break;
				case 5:
					scroll += "Conjure Fey (druid, warlock)";
					break;
				case 6:
					scroll += "Contingency (wizard)";
					break;
				case 7:
					scroll += "Create Undead (cleric, warlock, wizard)";
					break;
				case 8:
					scroll += "Disintegrate (sorcerer, wizard)";
					break;
				case 9:
					scroll += "Drawmij's Instant Summons (wizard)";
					break;
				case 10:
					scroll += "Eyebit (bard, sorcerer, warlock, wizard)";
					break;
				case 11:
					scroll += "Find the Path (bard, cleric, druid)";
					break;
				case 12:
					scroll += "Flesh to Stone (warlock, wizard)";
					break;
				case 13:
					scroll += "Forbiddance (cleric)";
					break;
				case 14:
					scroll += "Globe of Invulnerability (sorcerer, wizard)";
					break;
				case 15:
					scroll += "Guards and Wards (bard, wizard)";
					break;
				case 16:
					scroll += "Harm (cleric)";
					break;
				case 17:
					scroll += "Heal (cleric, druid)";
					break;
				case 18:
					scroll += "Heroes' Feast (cleric, druid)";
					break;
				case 19:
					scroll += "Magic Jar (wizard)";
					break;
				case 20:
					scroll += "Mass Suggestion (bard, sorcerer, warlock, wizard)";
					break;
				case 21:
					scroll += "Move Earth (druid, sorcerer, wizard)";
					break;
				case 22:
					scroll += "Otiluke's Freezing Sphere (wizard)";
					break;
				case 23:
					scroll += "Otto's Irresistible Dance (bard, wizard)";
					break;
				case 24:
					scroll += "Planar Ally (cleric)";
					break;
				case 25:
					scroll += "Programmed Illusion (bard, wizard)";
					break;
				case 26:
					scroll += "Sunbeam (druid, sorcerer, wizard)";
					break;
				case 27:
					scroll += "Transport via Plants (druid)";
					break;
				case 28:
					scroll += "True Seeing (bard, cleric, sorcerer, warlock, wizard)";
					break;
				case 29:
					scroll += "Wall of Ice (wizard)";
					break;
				case 30:
					scroll += "Wall of Thorns (druid)";
					break;
				case 31:
					scroll += "Wind Walk (druid)";
					break;
				case 32:
					scroll += "Word of Recall (cleric)";
					break;
			}
			break;
		case 7:
			scroll = "Level 7 Scroll of ";
			ss = randomNumber(1, 20);
			switch (ss) {
				case 1:
					scroll += "Conjure Celestial (cleric)";
					break;
				case 2:
					scroll += "Delayed Blast Fireball (sorcerer, wizard)";
					break;
				case 3:
					scroll += "Divine Word (cleric)";
					break;
				case 4:
					scroll += "Etherealness (bard, cleric, sorcerer, wizard)";
					break;
				case 5:
					scroll += "Finger of Death (sorcerer, wizard)";
					break;
				case 6:
					scroll += "Fire Storm (cleric, druid, sorcerer)";
					break;
				case 7:
					scroll += "Forcecage (bard, wizard)";
					break;
				case 8:
					scroll += "Mirage Arcane (bard, druid, wizard)";
					break;
				case 9:
					scroll += "Mordenkainen's Magnificent Mansion (bard, wizard)";
					break;
				case 10:
					scroll += "Mordenkainen's Sword (bard, wizard)";
					break;
				case 11:
					scroll += "Plane Shift (cleric, druid, sorcerer, wizard)";
					break;
				case 12:
					scroll += "Prismatic Spray (sorcerer, wizard)";
					break;
				case 13:
					scroll += "Project Image (bard, wizard)";
					break;
				case 14:
					scroll += "Regenerate (bard, cleric, druid)";
					break;
				case 15:
					scroll += "Resurrection (bard, cleric)";
					break;
				case 16:
					scroll += "Reverse Gravity (druid, sorcerer, wizard)";
					break;
				case 17:
					scroll += "Sequester (wizard)";
					break;
				case 18:
					scroll += "Simulacrum (wizard)";
					break;
				case 19:
					scroll += "Symbol (bard, cleric, wizard)";
					break;
				case 20:
					scroll += "Teleport (bard, sorcerer, wizard)";
					break;
			}
			break;
		case 8:
			scroll = "Level 8 Scroll of ";
			ss = randomNumber(1, 19);
			switch (ss) {
				case 1:
					scroll += "Animal Shapes (druid)";
					break;
				case 2:
					scroll += "Antimagic Field (cleric, wizard)";
					break;
				case 3:
					scroll += "Antipathy/Sympathy (druid, wizard)";
					break;
				case 4:
					scroll += "Clone (wizard)";
					break;
				case 5:
					scroll += "Control Weather (cleric, druid, wizard)";
					break;
				case 6:
					scroll += "Demiplane (warlock, wizard)";
					break;
				case 7:
					scroll += "Dominate Monster (bard, sorcerer, warlock, wizard)";
					break;
				case 8:
					scroll += "Earthquake (cleric, druid, sorcerer)";
					break;
				case 9:
					scroll += "Feeblemind (bard, druid, warlock, wizard)";
					break;
				case 10:
					scroll += "Glibness (bard, warlock)";
					break;
				case 11:
					scroll += "Holy Aura (cleric)";
					break;
				case 12:
					scroll += "Incendiary Cloud (sorcerer, wizard)";
					break;
				case 13:
					scroll += "Maze (wizard)";
					break;
				case 14:
					scroll += "Mind Blank (bard, wizard)";
					break;
				case 15:
					scroll += "Power Word Stun (bard, sorcerer, warlock, wizard)";
					break;
				case 16:
					scroll += "Sunburst (druid, sorcerer, wizard)";
					break;
				case 17:
					scroll += "Telepathy (wizard)";
					break;
				case 18:
					scroll += "Trap the Soul (wizard)";
					break;
				case 19:
					scroll += "Tsunami (druid)";
					break;
			}
			break;
		case 9:
			scroll = "Level 9 Scroll of ";
			ss = randomNumber(1, 16);
			switch (ss) {
				case 1:
					scroll += "Astral Projection (cleric, warlock, wizard)";
					break;
				case 2:
					scroll += "Foresight (bard, druid, warlock, wizard)";
					break;
				case 3:
					scroll += "Gate (cleric, sorcerer, wizard)";
					break;
				case 4:
					scroll += "Imprisonment (warlock, wizard)";
					break;
				case 5:
					scroll += "Mass Heal (cleric)";
					break;
				case 6:
					scroll += "Meteor Swarm (sorcerer, wizard)";
					break;
				case 7:
					scroll += "Power Word Heal (bard)";
					break;
				case 8:
					scroll += "Power Word Kill (bard, sorcerer, warlock, wizard)";
					break;
				case 9:
					scroll += "Prismatic Wall (wizard)";
					break;
				case 10:
					scroll += "Shapechange (druid, wizard)";
					break;
				case 11:
					scroll += "Storm of Vengeance (druid)";
					break;
				case 12:
					scroll += "Time Stop (sorcerer, wizard)";
					break;
				case 13:
					scroll += "True Polymorph (bard, warlock, wizard)";
					break;
				case 14:
					scroll += "True Resurrection (cleric, druid)";
					break;
				case 15:
					scroll += "Weird (wizard)";
					break;
				case 16:
					scroll += "Wish (sorcerer, wizard)";
					break;
			}
			break;
	}
	return scroll;
}

string Hoard_Loot::GenerateGemstone(const int &amount, const int &value) const {
	string gemstring = "error: check src or gemfile";
	ifstream fileOfGems;
	fileOfGems.open("../res/data/gems.dat");
	if (fileOfGems.is_open()) {
		string tmpName;
		tmpName = "";
		bool setvalue = false;
		auto chosenSeed = 0;
		for (int i = 0; i < amount; i++) {  //go down into file appropriate amount
			if (value == 10) {
				chosenSeed = randomNumber(0, 11);
				if (!setvalue) {
					fileOfGems.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			} else if (value == 50) {
				chosenSeed = randomNumber(0, 16);
				if (!setvalue) {
					for (int j = 0; j < 3; j++) {
						fileOfGems.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
			} else if (value == 100) {
				chosenSeed = randomNumber(0, 15);
				if (!setvalue) {
					for (int j = 0; j < 5; j++) {
						fileOfGems.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
			} else if (value == 500) {
				chosenSeed = randomNumber(0, 5);
				if (!setvalue) {
					for (int j = 0; j < 7; j++) {
						fileOfGems.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
			} else if (value == 1000) {
				chosenSeed = randomNumber(0, 9);
				if (!setvalue) {
					for (int j = 0; j < 9; j++) {
						fileOfGems.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
			} else if (value == 5000) {
				chosenSeed = randomNumber(0, 6);
				if (!setvalue) {
					for (int j = 0; j < 11; j++) {
						fileOfGems.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
			}

			setvalue = true;
			int len = static_cast<int>(fileOfGems.tellg());   //get current position - snapshot of place in file
			for (auto item = 0; item < chosenSeed; item++) { //go over to the proper gem rolled based on seed
				fileOfGems.ignore(numeric_limits<streamsize>::max(), ';');
			}
			getline(fileOfGems, tmpName, ';');
			fileOfGems.seekg(len, ios_base::beg);  //return to position - return to snapshot of place in file
			if (i == 0) {           //very first gem case
				gemstring = std::to_string(value) + "gp Gems:" + tmpName;
			} else {
				size_t find_position = gemstring.find(tmpName + ",");
				if (find_position != string::npos) { //found first duplicate gemname on the list - not last item either
					gemstring.insert(find_position + tmpName.size(), " x2");
				} else {
					find_position = gemstring.find(tmpName);
					if (find_position == string::npos) {
						gemstring += ("," + tmpName); //add the new gem
					} else {
						if (gemstring.substr(find_position, tmpName.length() + 3) == tmpName) {
							gemstring.insert(find_position + tmpName.length(), " x2");
						} else {
							size_t gotx2 = gemstring.find(tmpName + " x2");
							if (gotx2 != string::npos) {   //if x2 exists
								gemstring.replace(gotx2 + tmpName.size(), 3, " x3");
							} else {
								size_t gotx3 = gemstring.find(tmpName + " x3");
								if (gotx3 != string::npos) {  //if x3 exists
									gemstring.replace(gotx3 + tmpName.size(), 3, " x4");
								} else {
									size_t gotx4 = gemstring.find(tmpName + " x4");
									if (gotx4 != string::npos) { //if x4 exists
										gemstring.replace(gotx4 + tmpName.size(), 3, " x5");
									} else {
										gemstring.insert(find_position + tmpName.size(), " x2");
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return gemstring;
}


string Hoard_Loot::GenerateArt(const int &amount, const int &value) const {
	string artstring = "error: check src or artfile";
	ifstream fileOfArt;
	fileOfArt.open("../res/data/artObjects.dat");
	if (fileOfArt.is_open()) {
		string tmpName;
		tmpName = "";
		bool setvalue = false;
		auto chosenSeed = 0;
		for (int i = 0; i < amount; i++) {  //go down into file appropriate amount and choose a proper seed
			if (value == 25) {
				chosenSeed = randomNumber(0, 9);
				if (!setvalue) {
					fileOfArt.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			} else if (value == 250) {
				chosenSeed = randomNumber(0, 9);
				if (!setvalue) {
					for (int j = 0; j < 3; j++) {
						fileOfArt.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
			} else if (value == 750) {
				chosenSeed = randomNumber(0, 9);
				if (!setvalue) {
					for (int j = 0; j < 5; j++) {
						fileOfArt.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
			} else if (value == 2500) {
				chosenSeed = randomNumber(0, 9);
				if (!setvalue) {
					for (int j = 0; j < 7; j++) {
						fileOfArt.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
			} else if (value == 7500) {
				chosenSeed = randomNumber(0, 7);
				if (!setvalue) {
					for (int j = 0; j < 9; j++) {
						fileOfArt.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
			}
			setvalue = true;
			int len = static_cast<int>(fileOfArt.tellg());   //get current position  //snapshot of place in file
			for (auto item = 0; item < chosenSeed; item++) { //go over to the proper Art rolled
				fileOfArt.ignore(numeric_limits<streamsize>::max(), ';');
			}
			getline(fileOfArt, tmpName, ';');
			fileOfArt.seekg(len, ios_base::beg);  //return to position//return to snapshot of place in file
			if (i == 0) {  //first time through
				artstring = (std::to_string(value) + "gp Art Objects:" + tmpName);
			} else {
				size_t find_position = artstring.find(tmpName + ",");
				if (find_position != string::npos) { //found first duplicate Artname on the list - not last item either
					artstring.insert(find_position + tmpName.size(), " x2");
				} else {
					find_position = artstring.find(tmpName);
					if (find_position == string::npos) {
						artstring += ("," + tmpName); //add the new Art
					} else {
						if (artstring.substr(find_position, tmpName.length() + 3) == tmpName) {
							artstring.insert(find_position + tmpName.length(), " x2");
						} else {
							size_t gotx2 = artstring.find(tmpName + " x2");
							if (gotx2 != string::npos) {   //if x2 exists
								artstring.replace(gotx2 + tmpName.size(), 3, " x3");
							} else {
								size_t gotx3 = artstring.find(tmpName + " x3");
								if (gotx3 != string::npos) {  //if x3 exists
									artstring.replace(gotx3 + tmpName.size(), 3, " x4");
								} else {
									size_t gotx4 = artstring.find(tmpName + " x4");
									if (gotx4 != string::npos) { //if x4 exists
										artstring.replace(gotx4 + tmpName.size(), 3, " x5");
									} else {
										artstring.insert(find_position + tmpName.size(), " x2");
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return artstring;
}

