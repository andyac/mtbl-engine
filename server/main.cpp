#include "Labyrinth.h"
#include <cstdio>
#include <cstdlib>
#include <string>

#define		CONFIG_FILE		"data/default.config"

using namespace std;

LabyrinthSeed parseConfig();
void fail(string mesg);
void setRequiredProperty(double *member, map<string, double> config, string prop);

int main(int argc, char *argv[]){
	LabyrinthSeed ls = parseConfig();
	fprintf(stderr, "Config loaded.  Seed is %ld.\n", ls.srand_seed);
	Labyrinth l(ls);
	//TODO: just printing map for now
	//	need to:
	//		rollcall for players
	//		distribute campaign config and statistic files
	//		sync and wait for turn endings
	//		process turns
	l.printMap();
}

LabyrinthSeed parseConfig(){
	FILE *cFile = fopen(CONFIG_FILE, "r");

	if(cFile == NULL){
		fail("Config file not found at " + string(CONFIG_FILE));
	}

	char *key;
	double value;

	LabyrinthSeed ls;

	while(fscanf(cFile, "%ms %lf", &key, &value) != EOF){
		ls.config[key] = value;
	}

	//checks if these required config keywords exist
	//put them in LabyrinthSeed for quick access

	if(ls.config.count("SRANDSEED")){
		ls.srand_seed = ls.config["SRANDSEED"];
	}else{
		fail("No SRANDSEED found in config");
	}
	if(ls.config.count("WIDTH")){
		ls.width = ls.config["WIDTH"];
	}else{
		fail("No WIDTH found in config");
	}
	if(ls.config.count("HEIGHT")){
		ls.height = ls.config["HEIGHT"];
	}else{
		fail("No HEIGHT found in config");
	}
	if(ls.config.count("WATERCHANCE")){
		ls.water_chance = ls.config["WATERCHANCE"];
	}else{
		fail("No WATERCHANCE found in config");
	}
	if(ls.config.count("IMPASSABLECHANCE")){
		ls.impassable_chance = ls.config["IMPASSABLECHANCE"];
	}else{
		fail("No IMPASSABLECHANCE found in config");
	}
	if(ls.config.count("BUFFCHANCE")){
		ls.buff_chance = ls.config["BUFFCHANCE"];
	}else{
		fail("No BUFFCHANCE found in config");
	}
	if(ls.config.count("DEBUFFCHANCE")){
		ls.debuff_chance = ls.config["DEBUFFCHANCE"];
	}else{
		fail("No DEBUFFCHANCE found in config");
	}
	if(ls.config.count("MINNEIGHBOR")){
		ls.min_neighbor_override = ls.config["MINNEIGHBOR"];
	}else{
		fail("No MINNEIGHBOR found in config");
	}
	return ls;
}

void fail(string mesg){
	fprintf(stderr, "%s\n", mesg.c_str());
	exit(0);
}