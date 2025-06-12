#include "taulell.h"
#include "const.h"
#include "config.h"
#include "keyboard.h"
#include <iostream>

void ProcesarEntrada() { 
    if (IsAPressed() || IsWPressed() || IsSPressed() || IsDPressed()) {
        if (IsAPressed()) {
            direccioSnake = ESQUERRA; // Moviment a l'esquerra
        }
        else if (IsWPressed()) {
            direccioSnake = DALT; // Moviment a dalt
        }
        else if (IsSPressed()) {
            direccioSnake = BAIX; // Moviment a baix
        }
        else if (IsDPressed()) {
            direccioSnake = DRETA; // Moviment a la dreta
        }
    }
}

void ActualitzarLogica() {
    Sleep(100);

    // Movimient del cos
    int tempX = segmentCosX[0];
    int tempY = segmentCosY[0];
    segmentCosX[0] = posicioCapX;
    segmentCosY[0] = posicioCapY;

    for (int i = 1; i < longitudCua; i++) {
        int tempX2 = segmentCosX[i];
        int tempY2 = segmentCosY[i];
        segmentCosX[i] = tempX;
        segmentCosY[i] = tempY;
        tempX = tempX2;
        tempY = tempY2;
    }//**


    //En funcio del valor de la direccioSnake fem un moviment
    if (direccioSnake == ESQUERRA)
    {
        posicioCapX--; // Moviment a l'esquerra
    }
    else if (direccioSnake == DRETA)
    {
        posicioCapX++; // Moviment a la dreta
    }
    else if (direccioSnake == DALT)
    {
        posicioCapY--; // Moviment a dalt
    }
    else if (direccioSnake == BAIX)
    {
        posicioCapY++; // Moviment a baix
    }

    // Colisiona borde_laterals
    if (posicioCapX >= ample || posicioCapX < 0 || //la posicio del cap a d'esta en el (0 - ample) dins el taulell.
        posicioCapY >= altura || posicioCapY < 0) { //la posicio del cap a d'esta en el (0 - alt) dins el taulell.
        jocAcabat = true; //sino esta dins el taulell el joc s'acaba
        return;
    }

    // Colisió entre el propi cos
    for (int i = 0; i < longitudCua; i++) {
        if (segmentCosX[i] == posicioCapX && 
            segmentCosY[i] == posicioCapY) {
            jocAcabat = true;// si alguna part del cos coincideix en l'eix x o y amb el cap tambe s'acaba el joc
        }
    }

    // Pillar fruita
    if (posicioCapX == posicioFruitaX && posicioCapY == posicioFruitaY) { //si la posicio del cap en els dos eixos coincidexi amb una fruita
        puntuacioTotal += fruitaPuntuacio; //la puntuacio augmentara en 15 punts (fruitaPuntuacio)
        posicioFruitaX = rand() % ample;
        posicioFruitaY = rand() % altura; //coloquem la fruita en un lloc random del taulell de nou
        longitudCua++; //la serp augmenta en un la seva cua
    }
}