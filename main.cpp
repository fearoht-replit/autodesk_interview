#include <iostream>
#include <list>
#include <memory>
using namespace std;

class Coordenate {
public: 
  int x{0};
  int y{0};
  list<int> values;

  // por defecto
  Coordenate(void):x(10), y(20){
    cout << "Defecto" << endl;
  }

  // por parametros
  Coordenate(int _x, int _y)
  :x(_x),y(_y){
    cout << "Parametros" << endl;
  }

  // Copia
  Coordenate(const Coordenate &c){
    cout << "Copia" << endl;
    x = c.x;
    y = c.y;
  }

  // Move with rvalue &&
  Coordenate(Coordenate &&c){
    values = std::move(c.values);
    cout << "Move" << endl;
  }

  ~Coordenate(void){
    values.clear();
    cout << "cleaning values: " 
         << values.size() << endl;
  }

};

Coordenate tmp (){
  Coordenate c(23,2);
  c.values = list<int>(230,10000);
  return c;
}

void UseRawPointer(){
  // created in heap (durante la asignacion puede ser accedida desde multiples threads, es la memoria real)
  Coordenate* cord = new Coordenate(2,4); 
  cord->values = list<int>(30,12);
  delete cord;   
}

void UseSmartPointer(){
  // created in stack (memoria temporal y contigua, allocacion de memeoria es mas rapido)
  unique_ptr<Coordenate>cord(new Coordenate());
  cord->values = list<int>(30,12);
}

/*

2) Dynamic Dispatch ( y polimorfismo virtual)
  - single : escoger la funcion a llamar en base a los parametros
  - dinamyc: herarquia de clases, It is called pure virtual or abstract function and requires to be overwritten in an derived class.

4) Templates
5) Macros
  - define and ifndef

5) Para realizar llamadas HTTP en nuestros clientes Windows/iOS usamos esta librería https://github.com/Microsoft/cpprestsdk 

HTTP, de sus siglas en inglés: "Hypertext Transfer Protocol", es el nombre de un protocolo el cual nos permite realizar una petición de datos y recursos, como pueden ser documentos HTML. 

Es la base de cualquier intercambio de datos en la Web, y un protocolo de estructura cliente-servidor, esto quiere decir que una petición de datos es iniciada por el elemento que recibirá los datos (el cliente), normalmente un navegador Web. Así, una página web completa resulta de la unión de distintos sub-documentos recibidos, como, por ejemplo: un documento que especifique el estilo de maquetación de la página web (CSS), el texto, las imágenes, vídeos, scripts, etc...

Diseñado a principios de la década de 1990, HTTP es un protocolo ampliable, que ha ido evolucionando con el tiempo. Es lo que se conoce como un protocolo de la capa de aplicación, y se transmite sobre el protocolo TCP, o el protocolo encriptado TLS (en-US), aunque teóricamente podría usarse cualquier otro protocolo fiable. Gracias a que es un protocolo capaz de ampliarse, se usa no solo para transmitir documentos de hipertexto (HTML), si no que además, se usa para transmitir imágenes o vídeos, o enviar datos o contenido a los servidores, como en el caso de los formularios de datos. HTTP puede incluso ser utilizado para transmitir partes de documentos, y actualizar páginas Web en el acto.


Una petición de HTTP, está formado  por los siguientes campos:

Un método HTTP,  normalmente pueden ser un verbo, como: GET, POST o un nombre como: OPTIONS (en-US) o HEAD (en-US), que defina la operación que el cliente quiera realizar. El objetivo de un cliente, suele ser una petición de recursos, usando GET, o presentar un valor de un formulario HTML, usando POST, aunque en otras ocasiones puede hacer otros tipos de peticiones. 
La dirección del recurso pedido; la URL del recurso, sin los elementos obvios por el contexto, como pueden ser: sin el  protocolo (http://),  el dominio (aquí developer.mozilla.org), o el puerto TCP (aquí el 80). 
La versión del protocolo HTTP.
Cabeceras HTTP opcionales, que pueden aportar información adicional a los servidores.
O un cuerpo de mensaje, en algún método, como puede ser POST, en el cual envía la información para el servidor.


*/

int main() {

  UseRawPointer();
  UseSmartPointer();

  cout << endl << "Constructores & Destructores" << endl;
  Coordenate c1;
  Coordenate c2(10,23);
  Coordenate c3(c2);

  Coordenate c4(std::move(tmp()));
  cout << c4.values.size() << " -> "
       << c4.x << " - " << c4.y << endl;
  
}