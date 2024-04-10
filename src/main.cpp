#include "WiFiController.h"
#include "HttpController.h"
#include "MatrixController.h"

void setup() {
  Serial.begin(115200);
  WiFiController.begin();
  MatrixController.begin();
}

void loop() { }