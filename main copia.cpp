//
//  main.cpp
//  PruebasAyMdeSoftware
//
//  Created by Daniel Esteban Tapia Nava on 11/01/17.
//  Copyright © 2017 Daniel Esteban Tapia Nava. All rights reserved.
//

#include <iostream>
#include <ctime> // Biblioteca para importar los archivos de fecha y hora

using namespace std;

int main(int argc, const char * argv[]) {
    
    
    // Obtenemos la fecha y hora
    time_t now = time(0);
    
    // Convertimos a string
    tm *ltm = localtime(&now);
   
    
    cout << "La hora actual es: " << endl;
   
    cout << "Time: "<< 1 + ltm->tm_hour << ":";
    cout << 1 + ltm->tm_min << ":";
    cout << 1 + ltm->tm_sec << endl;
    
    
    return 0;
}
