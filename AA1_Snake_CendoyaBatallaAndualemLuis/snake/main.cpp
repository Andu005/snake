#include "const.h"
#include "taulell.h"
#include "logic.h"
#include "config.h" //les capçaleres indiquen on hi ha els arxius .h
#include <iostream>
#include <Windows.h> //inclueixo les llibreries per input/output (STL: iostream) i per la APi de <windows.h>
#include <conio.h> //"conio.h" Llegeix la entra de les tecles que realitzi el jugador (awsd, basicament)

//Declaro les variables

// Aquesta de eDireccio el que faig es cridar la variable dire y la poso en estat PARAR aixi quan comença el joc esta la serp quieta
eDireccio direccioSnake = PARAR;
int posicioCapX, posicioCapY;
int posicioFruitaX, posicioFruitaY;
int puntuacioTotal;
bool jocAcabat = false;

//Clau de prova
std::string fake_secret = "AKIAIMNOEXISTE1234567A";

// Variables pel cos de la serp
int segmentCosX[100], segmentCosY[100];
int longitudCua = 0;

// ===========================================================================
// VULNERABILIDADES INYECTADAS PARA PROBAR CODEQL
// ===========================================================================
void MenuDepuracionVulnerable() {
    // 1. Vulnerabilidad: Desbordamiento de búfer usando 'strcpy' (C++ sí la compila)
    // CodeQL detectará que copiamos un texto largo en un espacio de solo 5 caracteres.
    char bufferInseguro[5];
    const char* textoLargo = "EsteTextoEsDemasiadoLargoYVaAromperLaMemoria";
    strcpy(bufferInseguro, textoLargo); 

    // 2. Vulnerabilidad: Uso de variable local no inicializada
    int multiplicador;
    if (puntuacioTotal > 100) {
        multiplicador = 2;
    }
    puntuacioTotal = puntuacioTotal * multiplicador; 
}
// ============================================================================

int main()//dins aquesta funcio crido a totes les funcions per avençar en el joc
{
    ConfigurarJoc(); //Poso els valors a 0 per la posicio el cos i la puntuacio, es a dir configurat per començar.

    // Forzamos la ejecución del código vulnerable para asegurarnos de que se compile
    MenuDepuracionVulnerable();

    while (!jocAcabat) { //mentre el joc no s'ha acabat, executa les funcions seguents
        RenderitzarTaulell(); //genera el taulell i imprimeix la puntuació inicial
        ProcesarEntrada(); //rep els inputs de l'usuari
        ActualitzarLogica(); //verifica el inputs: esta en el rang correcte i es A, W, S o D
    }

    return 0; //una funcio int sempre ha de retornar un valor enter
}
