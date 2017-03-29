// Daniel Tapia Nava A01022285

#include <iostream>
#include <string>

class Visitor;
class Documents;

using namespace std;

// Tipos de Impresoras

class Printers{
protected:
    string name;

public:
    virtual void accept(Visitor*, Documents* d) = 0;
    string getName() { return name; }
};

class Laser : public Printers {
public:
  Laser(){
    name = "Laser";
  }
    void accept(Visitor* pvisitor, Documents* d);
};

class Injection : public Printers {
public:
  Injection(){
    name = "Injection";
  }
    void accept(Visitor* pvisitor, Documents* d);
};

class PDF : public Printers {
public:
  PDF(){
    name = "PDF";
  }
    void accept(Visitor* pvisitor, Documents* d);
};

class Postscript : public Printers {
public:
  Postscript(){
    name = "Postscript";
  }
    void accept(Visitor* pvisitor, Documents* d);
};


class Portable : public Printers {
public:
  Portable(){
    name = "Portable";
  }
  void accept(Visitor* pvisitor, Documents* d);
};

// Funcion Visitor
class Visitor {
public:
    virtual void visit(Laser* p, Documents * d) = 0;
    virtual void visit(Injection* p, Documents * d) = 0;
    virtual void visit(PDF* p, Documents * d) = 0;
    virtual void visit(Postscript* p, Documents * d) = 0;

    virtual void visit(Portable* p, Documents* d) = 0;

    template <class T>
    static Visitor* getInstance(){
        static T instance;
        return &instance;
    }
};


class Documents{
protected:
    string name;
public:
    void printOn(Printers* p);
    string getName(){ return name; }
};

// Printing Visitor
class PrintVisitor : public Visitor {
    friend class Visitor;
private:
    PrintVisitor(){}

public:
    void visit(Laser* p, Documents* d){
        cout << "Printing: " << d->getName() << " on " << p->getName() << endl;
    }

    void visit(Injection* p, Documents* d) {
      cout << "Printing: " << d->getName() << " on " << p->getName() << endl;
    }

    void visit(PDF* p, Documents* d) {
      cout << "Printing: " << d->getName() << " on " << p->getName() << endl;
    }

    void visit(Postscript* p, Documents* d) {
      cout << "Printing: " << d->getName() << " on " << p->getName() << endl;
    }


    void visit(Portable* p, Documents* d) {
      cout << "Printing: " << d->getName() << " on " << p->getName() << endl;
    }

};

// Tipos de Documentos

void Documents::printOn(Printers* p){
  p->accept(Visitor::getInstance<PrintVisitor>(), this);
}

class SimpleText : public Documents {
public:
  SimpleText(){
    name = "SimpleText";
  }
};

class FormatText : public Documents {
public:
  FormatText(){
    name = "FormatText";
  }
};

class Image : public Documents {
public:
  Image(){
    name = "Image";
  }
};

#include "documents.h"

void Laser::accept(Visitor* pvisitor, Documents* d) {
  pvisitor->visit(this, d);
}

void Injection::accept(Visitor* pvisitor, Documents* d) {
  pvisitor->visit(this, d);
}

void PDF::accept(Visitor* pvisitor, Documents* d) {
  pvisitor->visit(this, d);
}

void Postscript::accept(Visitor* pvisitor, Documents* d) {
  pvisitor->visit(this, d);
}

void Portable::accept(Visitor* pvisitor, Documents* d) {
  pvisitor->visit(this, d);
}

class Main {
public:
    void printAllDocuments(Documents** d, int countDocs, Printers** p, int countPrinters){
        for(int i = 0; i < countDocs; i++){
            for(int j = 0; j < countPrinters; j++){
                d[i]->printOn(p[j]);
            }
        }
    }
};

// Funcion main para probar el programa

int main() {
  int colaDocs = 7;
  int cola = 7;
    Main m;
    Documents ** d = new Documents*[colaDocs];
    Printers ** p = new Printers*[cola];

    // Probamos con uno de cada uno, para revisar que funcione correctamente

    d[0] = new SimpleText();
    d[1] = new FormatText();
    d[2] = new Image();
    d[3] = new Poster();
    d[4] = new Flyer();

    p[0] = new Laser();
    p[1] = new PDF();
    p[2] = new Postscript();
    p[3] = new Portable();
    p[4] = new Injection();

    m.printAllDocuments(d, colaDocs, p, cola);

    for(int i = 0; i<colaDocs; i++){
      delete d[i];
    }
    for(int i = 0; i<cola; i++){
      delete p[i];
    }

    delete[] d;
    delete[] p;

    return 0;
}

