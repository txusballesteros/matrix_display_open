#include "MatrixController.h"

LedMatrix MatrixControllerClass::matrix { LedMatrix(NUMBER_OF_DEVICES, CLK_PIN, MISO_PIN, MOSI_PIN, CS_PIN) };
int MatrixControllerClass::speedDelay { INITIAL_SPEED };

void MatrixControllerClass::loop(void *parameters) {
    while(1) {
        MatrixControllerClass::matrix.clear();
        MatrixControllerClass::matrix.scrollTextLeft();
        MatrixControllerClass::matrix.drawText();
        MatrixControllerClass::matrix.commit();
        vTaskDelay(MatrixControllerClass::speedDelay / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}