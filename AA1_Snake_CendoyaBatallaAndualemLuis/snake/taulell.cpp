#include "taulell.h"
#include "const.h"
#include "config.h"
#include <iostream>

void RenderitzarTaulell() {
    system("cls"); //netejem la pantalla

    // Puntuació
    std::cout << misatgePuntuacio << puntuacioTotal << std::endl;

    // borde_lateral superior
    for (int i = 0; i < ample + 2; i++) {
        std::cout << borde_superior; //imprimeix la linea lateral del borde
    }
    std::cout << std::endl; //salt de linea

    // Contingut del taulell
    for (int fila = 0; fila < altura; fila++) {
        for (int columna = 0; columna < ample; columna++) {
            if (columna == 0) //si es la primera columna introduim el marge "|"
                std::cout << borde_lateral;

            if (columna == posicioCapX && fila == posicioCapY)
                std::cout << snakeCap; //imprimeixo el cap de la serp a on s'hagui mogut
            else if (columna == posicioFruitaX && fila == posicioFruitaY)
                std::cout << fruita; //imprimeix la fruita a on s'ha randomitzat
            else {
                bool dibuixarCos = false;
                for (int i = 0; i < longitudCua; i++) { //pel cos comprovo la posicio i dibuixo la "x"
                    if (segmentCosX[i] == columna && segmentCosY[i] == fila) {
                        std::cout << snakeCos;
                        dibuixarCos = true;
                    }
                }
                if (!dibuixarCos)
                    std::cout << " "; //sino, imprimeix un espai en blanc
            }

            if (columna == ample - 1)
                std::cout << borde_lateral; //si es la ultima columna introduim el marge "|"
        }
        std::cout << std::endl; //salt de linea
    }

    // borde_lateral inferior
    for (int i = 0; i < ample + 2; i++) {
        std::cout << borde_superior; //despres, aquest bucle dibuixará la ultima linea amb "-"
    }

    
}