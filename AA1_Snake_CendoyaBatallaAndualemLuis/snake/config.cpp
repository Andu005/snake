#include "taulell.h"
#include "const.h"
#include "logic.h"
#include <iostream>
#include <ctime>  // Para time()

void ConfigurarJoc() {
    //Mentre el joc estoigui en marxa gameover sera falç
    jocAcabat = false;

    //Partim d'una puntuacio 0
    puntuacioTotal = 0;

    //Desconec el tema dels vectors
    longitudCua = 0;

    //Asigno a la variable direccioSnake com a PARAR es a dir, al començar el joc estra aturat
    direccioSnake = PARAR;

    //Perque es posicioni el mig l'amplada i l'allargada han de ser la meitat del taulell
    posicioCapX = ample / 2;
    posicioCapY = altura / 2;

    //coloquem la friuta en una posicio aleatoria
    posicioFruitaX = rand() % ample;
    posicioFruitaY = rand() % altura;

    // Inicialització de la llavor pels números aleatoris
    srand(time(NULL));
}