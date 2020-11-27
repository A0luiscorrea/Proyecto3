//
//  Material.h
//  Proyecto3
//
//  Created by Luis Alejandro Correa Vargas on 14/11/20.
//

#include <iostream>
#include <iomanip>
#pragma once

using namespace std;
/*----------------------CLASE MATERIAL----------------------*/
class Material
{
public: //Métodos
    Material();
    Material(int i,string t,int c);
    void setIDMaterial(int i){idMaterial = i;};
    int getIDMaterial() {return idMaterial;};
    void setTitulo(string t) {titulo=t;};
    string getTitulo() {return titulo;};
    void setCantidadDias(int c) {cantidadDias = c;};
    int getCantidadDias(){return cantidadDias;};
    virtual void muestraDatos()=0;
    virtual int cantidadDiasPrestamo()=0;
protected: //Atributos
    int idMaterial,cantidadDias;
    string titulo;
};

Material::Material() 
{
    idMaterial = 0;
    titulo = " ";
    cantidadDias = 0;
}

Material::Material(int i,string t,int c)
{
    idMaterial = i;
    titulo = t;
    cantidadDias = c;
}

/*----------------------CLASE LIBRO----------------------*/

class Libro : public Material
{
public: //Métodos
    Libro();
    Libro(int n,string a);
    void setNumPag(int n) {numPag = n;};
    int getNumPag() {return numPag;};
    void setAutor(string a) {autor = a;};
    string getAutor() {return autor;};
    void muestraDatos();
    int cantidadDiasPrestamo();
private: //Atributos
    int numPag;
    string autor;
};

Libro::Libro() : Material()
{
    numPag = 1;
    autor = " ";
}

Libro::Libro(int n,string a) : Material()
{
    numPag = n;
    autor = a;
}

void Libro::muestraDatos()
{
    cout << "--------------------------------------"<<endl;
    cout << "Material tipo LIBRO" << endl;
    cout << "ID Material: " << idMaterial << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Número de páginas: " << numPag << endl;
    cout << "Autor: " << autor << endl;
}
int Libro::cantidadDiasPrestamo()
{
    int cant;
    cant=5;
    cantidadDias=cant;
    return cantidadDias;
}
/*----------------------CLASE DISCO----------------------*/

class Disco : public Material
{
public: //Metodos
    Disco();
    Disco(int d,string g);
    void setDuracion(int d) {duracion = d;};
    int getDuracion() {return duracion;};
    void setGenero(string g) {genero = g;};
    string getGenero() {return genero;};
    void muestraDatos();
    int cantidadDiasPrestamo();
private: //Atributos
    int duracion;
    string genero;
};

Disco::Disco() : Material()
{
    duracion = 0;
    genero = " ";
}

Disco::Disco(int d, string g) : Material()
{
    duracion = d;
    genero = g;
}

void Disco::muestraDatos()
{
    cout << "--------------------------------------"<<endl;
    cout << "Material tipo DISCO" << endl;
    cout << "ID Material: " << idMaterial << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Duración: " << duracion << endl;
    cout << "Genero: " << genero << endl;
}
int Disco::cantidadDiasPrestamo()
{
    int cant;
    cant=3;
    cantidadDias=cant;
    return cantidadDias;
}
/*----------------------CLASE SOFTWARE----------------------*/

class Software : public Material
{
public: //Metodos
    Software();
    Software(int v,string so);
    void setVersion(int v) {version = v;};
    int getVersion() {return version;};
    void setSistOp(string so) {SO = so;};
    string getSistOp() {return SO;};
    void muestraDatos();
    int cantidadDiasPrestamo();
private: //Atributos
    int version;
    string SO;
};

Software::Software() : Material()
{
    version = 0;
    SO = " ";
}
Software::Software(int v,string so) : Material()
{
    version = v;
    SO = so;
}
void Software::muestraDatos()
{
    cout << "--------------------------------------"<<endl;
    cout << "Material tipo SOFTWARE" << endl;
    cout << "ID Material: " << idMaterial << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Versión: " << version << endl;
    cout << "Sistema Operativo: " << SO << endl;
}
int Software::cantidadDiasPrestamo()
{
    int cant;
    cant=1;
    cantidadDias=cant;
    return cantidadDias;
}
