#ifndef LABYRINTH_H
#define LABYRINTH_H

#include <string>
#include <map>
#include <cstdlib>
#include <cstdio>

typedef struct LabyrinthSeed_type {
	//TODO: Terrain labels w/ probabilities here
	//      (should probably be an unordered_map)
	//      (should be read from a special terrain config file)
	//			file should have statistics like:
	//			SWAMP			 0.30
	//				PRODUCTION	-0.10
	//				......
	//				DEFENSE		-0.10
	//			MOUNTAINS		 0.20
	//				PRODUCTION	-0.10
	//				......
	//				DEFENSE		+10.00
	//		)
	long srand_seed;
	int width;
	int height;
	double water_chance;
	double impassable_chance;
	double buff_chance;
	double debuff_chance;
	int min_neighbor_override;
	std::map<std::string, double> config;
} LabyrinthSeed;

typedef struct Tile_type {
	std::string label;
	//TODO: add tile specifics, buffs, debuffs
} Tile;

class Labyrinth {
public:
	Tile **tiles;
	LabyrinthSeed ls;
	Labyrinth(LabyrinthSeed ls);
	void makeMap();
	void printMap();
};

#endif