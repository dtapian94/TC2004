//
//  Daniel Tapia Nava A01022285
//  Analisis y Modelacion de Software
//  Examen Final
//  Created by Daniel Esteban Tapia Nava on 03/05/17.
//  Copyright © 2017 Daniel Esteban Tapia Nava. All rights reserved.
//


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Colisiones
{
protected:
    Colisiones(){}
    
private:
    string nombre;
    
public:
    void notificarColision(Colisiones* otro)
    {
      if(this!=otro)
        {
            cout<<"\n -----"<<endl;
            cout<<" ** Nueva Colision ** "<<endl;
            cout<<" \n ----- "<<endl;
            cout<<this->getNombre()<< " Colisiono con "<<otro->getNombre()<<endl;
            otro->recibirColision(this);
        }
    }
    
    void recibirColision(Colisiones* otro)
    {
       cout<< this->getNombre()<<" Colisiono con "<<otro->getNombre()<<endl;
    }
    void setNombre(string _nombre)
    {
        nombre = _nombre;
    }
    string getNombre()
    {
        return nombre;
    }
};

// Creacion de naves

class Spacecraft : public Colisiones
{
protected:
    Spacecraft(){}
public:
    template <class SubClase>
    static Spacecraft* factoryMethod()
    {
        return SubClase::getInstance();
    }
};

class ExplorationShip : public Spacecraft
{
private:
    ExplorationShip(){}
    static ExplorationShip* instance;
    
public:
    static ExplorationShip* getInstance()
    {
        if(instance==NULL)
        {
            instance = new ExplorationShip;
            instance->setNombre("Nave de exploracion");
        }
        return instance;
    }
};
ExplorationShip* ExplorationShip::instance = NULL;


class ColonizationShip : public Spacecraft
{
private:
    ColonizationShip(){}
    static ColonizationShip* instance;
    
public:
    static ColonizationShip* getInstance()
    {
        if(instance==NULL)
        {
            instance = new ColonizationShip;
            instance->setNombre("Nave de colonizacion");
        }
        return instance;
    }
};

ColonizationShip* ColonizationShip::instance = NULL;

class ObservationShip : public Spacecraft
{
private:
    ObservationShip(){}
    static ObservationShip* instance;
    
public:
    static ObservationShip* getInstance()
    {
        if(instance==NULL)
        {
            instance = new ObservationShip;
            instance->setNombre("Nave de observacion");
        }
        return instance;
    }
};
ObservationShip* ObservationShip::instance = NULL;

// Creacion de asteroides

class Asteroide : public Colisiones
{
protected:
    Asteroide(){}
public:
    template <class SubClase>
    static Asteroide* factoryMethod()
    {
        return SubClase::getInstance();
    }
};

class Stony : public Asteroide
{
private:
    Stony(){}
    static Stony* instance;
    
public:
    static Stony* getInstance()
    {
        if(instance==NULL)
        {
            instance = new Stony;
            instance->setNombre("Meteorito de Piedra");
        }
        return instance;
    }
};

Stony* Stony::instance = NULL;


class Iron : public Asteroide
{
private:
    Iron(){}
    static Iron* instance;
    
public:
    static Iron* getInstance()
    {
        if(instance==NULL)
        {
            instance = new Iron;
            instance->setNombre("Meteorito de Metal");
        }
        return instance;
    }
};
Iron* Iron::instance = NULL;


// Creacion de planetas


class Planeta : public Colisiones
{
protected:
    Planeta(){}
public:
    template <class SubClase>
    static Planeta* factoryMethod()
    {
        return SubClase::getInstance();
    }
};

class Desert : public Planeta
{
private:
    Desert(){}
    static Desert* instance;
    
public:
    static Desert* getInstance()
    {
        if(instance==NULL)
        {
            instance = new Desert;
            instance->setNombre("Planeta Desierto");
        }
        return instance;
    }
};
Desert* Desert::instance = NULL;


class Earth : public Planeta
{
private:
    Earth(){}
    static Earth* instance;
    
public:
    static Earth* getInstance()
    {
        if(instance==NULL)
        {
            instance = new Earth;
            instance->setNombre("Planeta Tierra");
        }
        return instance;
    }
};
Earth* Earth::instance = NULL;



// MAIN PARA REALIZAR PRUEBAS


int main(int argc, const char * argv[]) {
    
    // Naves
    
    Spacecraft* Observacion = Spacecraft::factoryMethod<ObservationShip>();
    Spacecraft* Exploracion = Spacecraft::factoryMethod<ExplorationShip>();
    Spacecraft* Colonizacion = Spacecraft::factoryMethod<ColonizationShip>();
    
    // Asteroides
    
    Asteroide* Piedra = Asteroide::factoryMethod<Stony>();
    Asteroide* Metal = Asteroide::factoryMethod<Iron>();
  
    // Planetas
    
    Planeta* Desierto = Planeta::factoryMethod<Desert>();
    Planeta* Tierra = Planeta::factoryMethod<Earth>();
    
    vector<Colisiones*> objetos;
    objetos.push_back(Observacion);
    objetos.push_back(Exploracion);
    objetos.push_back(Colonizacion);
    objetos.push_back(Piedra);
    objetos.push_back(Metal);
    objetos.push_back(Desierto);
    objetos.push_back(Tierra);
    
    
// Simular Colision de todos contra todos
    
  for(int i=0;i<objetos.size();i++)
    {
      for(int j=0;j<objetos.size();j++)
        {
            objetos[i]->notificarColision(objetos[j]);
        }
    }
    
    cout<<endl;
    
// Borrar objetos
    
    delete Observacion;
    delete Exploracion;
    delete Colonizacion;
    delete Piedra;
    delete Metal;
    delete Desierto;
    delete Tierra;
    
    return 1;
}
