/*
 * Tile.h
 *
 *  Created on: 24 июля 2014 г.
 *      Author: snickers
 */

#ifndef TILE_H_
#define TILE_H_

#include <SDL2/SDL.h>

enum Type 
{
	TILE_TYPE_NONE = 0,
	TILE_TYPE_WATER = 1,
	TILE_TYPE_SAND = 2,
	TILE_TYPE_GRASS = 3
};

class Tile 
{
public:
	Tile();
	virtual ~Tile();

	Uint8 tileID;
	Uint8 typeID;

	static SDL_Rect InTileSetPos(const int tile_size, const int x, const int y);

 public:
        //Initializes position and type
        Tile( int x, int y, int tileType );

        //Shows the tile
        void render( SDL_Rect& camera );

        //Get the tile type
        int getType();

        //Get the collision box
        SDL_Rect getBox();

    private:
        //The attributes of the tile
        SDL_Rect mBox;

        //The tile type
        int mType;
};

#endif /* TILE_H_ */
