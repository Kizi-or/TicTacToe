#include "Application.h"

int main() {
    
    Application application;

    while (application.AppIsOpen()) {

        application.AppUpdate();

        application.AppRender();

    }

    return 0;
}