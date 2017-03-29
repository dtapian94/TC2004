//Tipos de Documentos

 class Poster : public Documents {
 public:
   Poster(){
     name = "Triptico";
   }
 };

 class Flyer : public Documents {
 public:
   Flyer(){
     name = "Cartel";
   }
 };