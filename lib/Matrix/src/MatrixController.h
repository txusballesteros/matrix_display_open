#ifndef MatrixController_h
#define MatrixController_h

#include "Arduino.h"
#include "MatrixController.h"
#include "SPI.h"
#include <LedMatrix.h>

#define NUMBER_OF_DEVICES 4 //number of led matrix connect in series
#define CS_PIN 15
#define CLK_PIN 14
#define MISO_PIN 2          //we do not use this pin just fill to match constructor
#define MOSI_PIN 12
#define INITIAL_MESSAGE "Hello!"
#define INITIAL_SPEED 20

class MatrixControllerClass {
    public:
        void begin() {
            MatrixControllerClass::matrix.init();
            MatrixControllerClass::matrix.setText(INITIAL_MESSAGE);

            xTaskCreate(&MatrixControllerClass::loop, "Led Matrix Job", 1024, NULL, 1, NULL);
        }
        
        void write(String text) {
            MatrixControllerClass::matrix.setText(text);
        }

        void speed(int speed) {
            MatrixControllerClass::speedDelay = speed;
        }

        void on() {
            write(INITIAL_MESSAGE);
        }

        void off() {
            write("");
        }
        
    private:
        static LedMatrix matrix;
        static int speedDelay;
        static void loop(void *parameters);
};

extern MatrixControllerClass MatrixController;
#endif