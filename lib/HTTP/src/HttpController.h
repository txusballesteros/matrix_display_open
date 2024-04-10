#ifndef HttpController_h
#define HttpController_h

#include "ESPAsyncWebServer.h"

class HttpController {
public:
    static AsyncWebServer server;
    static void begin();
private:
    static void beginMainRouter(AsyncWebServer *httpServer);
    static void beginUpdateRouter(AsyncWebServer *httpServer);
    static void beginWrite(AsyncWebServer *httpServer);
    static void beginMatrixOn(AsyncWebServer *httpServer);
    static void beginMatrixOff(AsyncWebServer *httpServer);
};

#endif