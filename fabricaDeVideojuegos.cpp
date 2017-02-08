//
//  main.cpp
//  FabricadeVideojuegosAS
//
//  Created by Daniel Esteban Tapia Nava A01022285 on 08/02/17.
//  Copyright © 2017 Daniel Esteban Tapia Nava. All rights reserved.
//

#include <iostream>
#include <cstdlib>

using namespace std;

class Videojuego
{
public:
    
    virtual Videojuego* clonar() = 0;
};


template <class SubClase>
class ClonVideojuego : public Videojuego
{
public:
    virtual Videojuego* clonar()
    {
        return new SubClase(dynamic_cast<SubClase&>(*this));
    }
};



class Estrategia : public ClonVideojuego<Estrategia>
{
public:
    
    string nombre;
    int numSerie;
    double precio;
    int numjugadores;
    string modoOnline;
    
    
    void concepcion();
    void planifiacion();
    void pruebasDeAceptacion();
    void diseño();
    void produccion()
    {
        cout << "El videojuego de Estrategia se creo correctamente" << endl;
    }
};


class Aventura : public ClonVideojuego<Aventura>
{
public:
    
    string nombre;
    int numSerie;
    double precio;
    int numjugadores;
    string modoOnline;
    
    void concepcion();
    void planificacion();
    void pruebasDeAceptacion();
    void diseño();
    void produccion()
    {
        cout << "El videojuego de Aventura se creo correctamente" << endl;
    }
};

class Aprendizaje : public ClonVideojuego<Aprendizaje>
{
public:
    
    string nombre;
    int numSerie;
    double precio;
    int numjugadores;
    string modoOnline;
    
    void concepcion();
    void planificacion();
    void pruebasDeAceptacion();
    void diseño();
    void produccion()
    {
        cout << "El videojuego de Aprendizaje se creo correctamente" << endl;
    }
};






////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

int main(int argc, const char * argv[]) {
    
    int op;
    
    while (1)
        
    {
        cout<< "Bienvenido al Menu interactivo y del Almacen, de Chell A.S " <<endl<<endl;
        cout<< "Menu: "<<endl;
        
        cout<<" Opcion 1) Crear Nuevo videojuego " <<endl;
        cout<<" Opcion 2) Agregar un videojuego al inventario "<<endl;
        cout<<" Opcion 3) Eliminar un videojuego del inventario"<<endl;
        cout<<" Opcion 4) Ordenar los videojuegos que se tienen en inventario (Por precio)"<<endl;
        cout<<" Opcion 5) Buscar un videojuego dentro del inventario"<<endl;
        cout<<" Opcion 6) Obtener el numero total de videojuegos en inventario"<<endl;
        cout<<" Opcion 7) Salir del Sistema"<<endl;
        
        cout<<" Porfavor seleccione una de las opciones anteriores: "<<endl;
        cin>> op;
        
        switch (op)
        {
            case 1:
                
                
                
               // NuevoUsuario();
                
                
                break;
                
                
            case 2:
                //Transaccion();
                
                break;
                
                
                
            case 3:
                //verUsuario();
                break;
                
            case 4:
               // verTodos();
                break;
                
            case 5:
                
                break;
            case 6:
                
                cout<< " Gracias por utilizar el sistema de creacion y administracion de Videojuegos, Hasta pronto"<<endl;
                exit(0);
                break;
        }
    }
    return 0;

}
