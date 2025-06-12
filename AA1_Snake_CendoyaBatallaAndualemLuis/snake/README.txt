La enumeracio la he fet amb IA

enum eDireccio { PARAR = 0, DRETA, ESQUERRA, DALT, BAIX };
extern eDireccio direccioSnake;

// El movimient del cos, amb el vectors l'he fet amb IA
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