#include "Arduino.h"
#include "HttpController.h"
#include "ESPAsyncWebServer.h"
#include "Config.h"
#include "HttpContent.h"
#include "MatrixController.h"

#define HTTP_PORT 80
#define ROUTE_MAIN          "/"
#define ROUTE_WRITE         "/write"
#define ROUTE_MATRIX_ON     "/on"
#define ROUTE_MATRIX_OFF    "/off"
#define CONTENT_TYPE_HTML   "text/html"

AsyncWebServer HttpController::server { AsyncWebServer(HTTP_PORT) };

void HttpController::begin() {
    Serial.println("HTTP -> Initializing Http");

    HttpController::beginMainRouter(&HttpController::server);
    HttpController::beginWrite(&HttpController::server);
    HttpController::beginMatrixOn(&HttpController::server);
    HttpController::beginMatrixOff(&HttpController::server);

    HttpController::server.begin();
    Serial.println("\t -> Http Server Ready");
}

void HttpController::beginMainRouter(AsyncWebServer *httpServer) {
    httpServer->on(ROUTE_MAIN, HTTP_GET, [](AsyncWebServerRequest *request) { 
        AsyncWebServerResponse *response = request->beginResponse(200, CONTENT_TYPE_HTML, HttpContent::mainPage);
        response->addHeader("Connection", "close");
        request->send(response);
    });
}

void HttpController::beginMatrixOn(AsyncWebServer *httpServer) {
    httpServer->on(ROUTE_MATRIX_ON, HTTP_GET, [](AsyncWebServerRequest *request) { 
        MatrixController.on();
        AsyncWebServerResponse *response = request->beginResponse(200, CONTENT_TYPE_HTML, HttpContent::mainPage);
        response->addHeader("Connection", "close");
        request->send(response);
    });
}

void HttpController::beginMatrixOff(AsyncWebServer *httpServer) {
    httpServer->on(ROUTE_MATRIX_OFF, HTTP_GET, [](AsyncWebServerRequest *request) { 
        MatrixController.off();
        AsyncWebServerResponse *response = request->beginResponse(200, CONTENT_TYPE_HTML, HttpContent::mainPage);
        response->addHeader("Connection", "close");
        request->send(response);
    });
}

void HttpController::beginWrite(AsyncWebServer *httpServer) {
    httpServer->on(ROUTE_WRITE, HTTP_GET, [](AsyncWebServerRequest *request) { 
        for(int index = 0; index < request->params(); index++) {
            AsyncWebParameter* parameter = request->getParam(index);
            if (parameter->name() == "text") {
                String text = parameter->value();
                MatrixController.write(text);
            }
            if (parameter->name() == "speed") {
                int speed = parameter->value().toInt();
                MatrixController.speed(speed);
            }
        }
        AsyncWebServerResponse *response = request->beginResponse(200, CONTENT_TYPE_HTML, HttpContent::mainPage);
        response->addHeader("Connection", "close");
        request->send(response);
    });
}
