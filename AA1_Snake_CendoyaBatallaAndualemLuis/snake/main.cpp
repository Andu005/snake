#include "const.h"
#include "taulell.h"
#include "logic.h"
#include "config.h" //les capçaleres indiquen on hi ha els arxius .h
#include <iostream>
#include <Windows.h> //inclueixo les llibreries per input/output (STL: iostream) i per la APi de <windows.h>
#include <conio.h> //"conio.h" Llegeix la entra de les tecles que realitzi el jugador (awsd, basicament)

//Declaro les variables

//Aquesta de eDireccio el que faig es cridar la variable dire y la poso en estat PARAR aixi quan comença el joc esta la serp quieta
eDireccio direccioSnake = PARAR;
int posicioCapX, posicioCapY;
int posicioFruitaX, posicioFruitaY;
int puntuacioTotal;
bool jocAcabat = false;

// Variables pel cos de la serp
int segmentCosX[100], segmentCosY[100];
int longitudCua = 0;

int main()//dins aquesta funcio crido a totes les funcions per avençar en el joc
{
    ConfigurarJoc(); //Poso els valors a 0 per la posicio el cos i la puntuacio, es a dir configurat per començar.

    while (!jocAcabat) { //mentre el joc no s'ha acabat, executa les funcions seguents
        RenderitzarTaulell(); //genera el taulell i imprimeix la puntuació inicial
        ProcesarEntrada(); //rep els inputs de l'usuari
        ActualitzarLogica(); //verifica el inputs: esta en el rang correcte i es A, W, S o D
    }

    return 0; //una funcio int sempre ha de retornar un valor enter
}