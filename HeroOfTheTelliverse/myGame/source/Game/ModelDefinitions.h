#pragma once
/*
This is a header file which is used to define
the file paths for models and textures within 
the game. 

The sole purpose of this is to make 
the process of adding models and textures faster 
and easier while (hopefully) preventing any 
user error when typing file paths.

3d models will be defined with an M 
prefixed to the beginning of the define

textures will be defined by a T 
prefixed to the beginning of the define
*/
#define MFRIDGE 
#define TFRIDGE

#define MCUBE "Content\\Models\\cube.3ds"

#define MTELLEVISION "Content\\Models\\TV.3ds"
#define MPLANE "Content\\Models\\plane.obj"

#define MPLAYER "Content\\Models\\tvAyoub.3ds" //CURRENTLY CRASHES GAME IF RENDERED
#define TPLAYER

#define MAPPLE "Content\\Models\\apple.3ds"
#define TAPPLE L"Content\\Textures\\appleD.jpg"

#define MBENCH "Content\\Models\\bench.3ds"
#define TBENCH L"Content\\Textures\\appleD.jpg"

#define TTILES L"Content\\Textures\\tiles.jpg"
#define TMISSING L"Content\\Textures\\missing.jpg"

#define MKITCHENCOUNTER "Content\\Models\\kitchenCounter.obj"
#define TKITCHENCOUNTER L"Content\\Textures\\CounterPhotoRealistic.jpg"

