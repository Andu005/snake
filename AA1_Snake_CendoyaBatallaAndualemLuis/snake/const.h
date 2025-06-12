#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>

// Constants del joc
#define ample 20
#define altura 10
#define borde_lateral '|'
#define borde_superior '-'
#define snakeCap 'X'
#define snakeCos 'x'
#define fruita 'O'
#define fruitaPuntuacio 15
#define misatgePuntuacio "Score : "

enum eDireccio { PARAR = 0, DRETA, ESQUERRA, DALT, BAIX };
extern eDireccio direccioSnake;
extern int posicioCapX, posicioCapY, posicioFruitaX, posicioFruitaY, puntuacioTotal;
extern bool jocAcabat;
extern int segmentCosX[100], segmentCosY[100];
extern int longitudCua;