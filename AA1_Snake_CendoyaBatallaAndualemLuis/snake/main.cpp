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

// ============================================================================
// VULNERABILIDADES INYECTADAS PARA PROBAR CODEQL
// ============================================================================
void MenuDepuracionVulnerable() {
    // 1. Vulnerabilidad: Función altamente insegura (Buffer Overflow)
    // CodeQL detectará el uso de 'gets' porque no controla el límite del búfer.
    char bufferNombre[10];
    std::cout << "\n[DEBUG] Introduce tu nombre de tester: ";
    gets(bufferNombre); 

    // 2. Vulnerabilidad: Uso de variable local no inicializada
    // CodeQL detectará que 'multiplicador' se usa en el cálculo sin tener valor.
    int multiplicador;
    if (puntuacioTotal > 100) {
        multiplicador = 2;
    }
    // Si la puntuación es <= 100, multiplicador tendrá basura de la memoria
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
