/*
 * constants.h
 *
 *  Created on: 24 июля 2014 г.
 *      Author: Admin
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <string>
#include <SDL2/SDL.h>

#include "GUI/colors.h"
//---------Константы---------

const bool MAX_FPS = false;//false;

const int LOGIC_WIN_WIDTH = 640;
const int LOGIC_WIN_HEIGHT = 480;

const int MAP_WIDTH = 1280;
const int MAP_HEIGHT = 960;

//Tile constants
const int TILE_WIDTH = 80;
const int TILE_HEIGHT = 80;
const int TOTAL_TILES = 192;
const int TOTAL_TILE_SPRITES = 12;

//The different tile sprites
const int TILE_RED = 0;
const int TILE_GREEN = 1;
const int TILE_BLUE = 2;
const int TILE_CENTER = 3;
const int TILE_TOP = 4;
const int TILE_TOPRIGHT = 5;
const int TILE_RIGHT = 6;
const int TILE_BOTTOMRIGHT = 7;
const int TILE_BOTTOM = 8;
const int TILE_BOTTOMLEFT = 9;
const int TILE_LEFT = 10;
const int TILE_TOPLEFT = 11;

// const int TILE_SHEET_SIZE = 16;
// const int TILE_SIZE = 1;

const std::string SPRITES_PATH = "../Data/Sprites/";
const std::string FONTS_PATH = "../Data/Fonts/";
const std::string SOUNDS_PATH = "../Data/Sounds/";

const SDL_Color BACKGROUND_COLOR = COLOR_GRAY;

const std::string DEFAULT_FONT = "PressStart2P.ttf";
const int DEFAULT_PTSIZE = 9;
//---------------------------
#endif /* CONSTANTS_H_ */

