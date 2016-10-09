#include "Labyrinth.h"

Labyrinth::Labyrinth(LabyrinthSeed ls){
	this->ls = ls;
	makeMap();
}

void Labyrinth::printMap(){
	for(int i = 0; i < ls.width; i++){
		for(int j = 0; j < ls.height; j++){
			printf("%s", tiles[i][j].label.c_str());
		}
		printf("\n");
	}
}
void Labyrinth::makeMap(){
	//allocate 2d tile array
	tiles = new Tile*[ls.width];
	for(int i = 0; i < ls.width; i++){
		tiles[i] = new Tile[ls.height];
	}
	srand(ls.srand_seed);
	//first pass?
	for(int i = 0; i < ls.width; i++){
		for(int j = 0; j < ls.height; j++){

			//TODO: simple map generator; make cooler
			//		use all LabyrinthSeed fields
			//		use special terrain properties file
			int isWater = rand() % 100;
			if(isWater <= ls.water_chance * 100){
				tiles[i][j].label = " ";
			}else{
				tiles[i][j].label = "M";
			}
		}
	}
}