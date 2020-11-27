//
//  main.cpp
//  Proyecto3
//
//  Created by Luis Alejandro Correa Vargas on 14/11/20.
//

#include <iostream>
#include "Material.h"
#include "Fecha.h"
#include <string>
#include <fstream>

int main()
{
    int cont=0;
    Software arrSoftware[30];
    Disco arrDisco[30];
    Libro arrLibro[30];
    Material* M1;
    M1 = &arrDisco[30];
    M1 = &arrLibro[30];
    M1 = &arrSoftware[30];
    Fecha F[60];
    Reserva Reservaciones[60]; // Se llama Fecha por que en este archivo esta clase Reserva
    ifstream archEntMaterial;
    int id_material,version,numpag,dur,pos1=0;
    archEntMaterial.open("Material.txt");
    string linea,titulo,autor,sistop,genero,temp[30],varTemp[30];
    while (getline(archEntMaterial,linea))
    {
        //GUARDA EL ID MATERIAL EN CADA OBJETO ANTES DE BUSCARLO
        id_material=stod(linea.substr(0,3));
        arrSoftware[cont].setIDMaterial(id_material);
        arrLibro[cont].setIDMaterial(id_material);
        arrDisco[cont].setIDMaterial(id_material);
        linea.erase(0,4);
        
        //GUARDA LOS TITULOS EN UN ARREGLO TEMPORAL
        pos1 = linea.find(' ');
        temp[cont]=linea.substr(0,pos1);
        linea.erase(0,pos1+1);
        //GUARDA TITULOS EN CLASES RESPECTVIAS
        if(linea[0]=='L')
        {
            titulo=temp[cont];
            arrLibro[cont].setTitulo(titulo);
        }
        if(linea[0]=='D')
        {
            titulo=temp[cont];
            arrDisco[cont].setTitulo(titulo);
        }
        if(linea[0]=='S')
        {
            titulo=temp[cont];
            arrSoftware[cont].setTitulo(titulo);
        }
        //GUARDA EL IDENTIFICADOR EN UN ARREGLO TEMPORAL
        varTemp[cont]=linea[0];
        linea.erase(0,2);
        //GUARDA VALORES EN CLASES RESPECTIVAS
        if(varTemp[cont]=="L")
        {
            pos1=linea.find(' ');
            numpag=stod(linea.substr(0,pos1));
            arrLibro[cont].setNumPag(numpag);
            linea.erase(0,pos1+1);
            pos1=linea.find(' ');
            autor=linea.substr(0,pos1);
            arrLibro[cont].setAutor(autor);
            //arrLibro[cont].muestraDatos();
        }
        /*if(arrLibro[cont].getTitulo()!=" ")
        {
        arrLibro[cont].muestraDatos();
        }*/
        
        if(varTemp[cont]=="D")
        {
            pos1=linea.find(' ');
            dur=stod(linea.substr(0,pos1));
            arrDisco[cont].setDuracion(dur);
            linea.erase(0,pos1+1);
            pos1=linea.find(' ');
            genero=linea.substr(0,pos1);
            arrDisco[cont].setGenero(genero);
            //arrDisco[cont].muestraDatos();
        }
        
        if(varTemp[cont]=="S")
        {
            pos1=linea.find(' ');
            version=stod(linea.substr(0,pos1));
            arrSoftware[cont].setVersion(version);
            linea.erase(0,pos1+1);
            pos1=linea.find(' ');
            sistop=linea.substr(0,pos1);
            arrSoftware[cont].setSistOp(sistop);
            //arrSoftware[cont].muestraDatos();
        }
        cont++;
    }
    archEntMaterial.close();
    /*---------ARCHIVO RESERVAS---------*/
    ifstream archEntRes;
    archEntRes.open("Reserva.txt");
    string linea1;
    int dia,mes,anio,id_mat,id_cliente,pos=0,cont1=0;
    while (getline(archEntRes,linea1))
    {
        //GUARDA EL DIA
        pos = linea1.find(' ');
        dia=stod(linea1.substr(0,pos));
        Reservaciones[cont1].setDia(dia);
        linea1.erase(0,pos+1);
        
        //GUARDA EL MES
        pos = linea1.find(' ');
        mes = stod(linea1.substr(0,pos));
        Reservaciones[cont1].setMes(mes);
        linea1.erase(0,pos+1);
        //GUARDA EL AÑO
        anio = stod(linea1.substr(0,4));
        Reservaciones[cont1].setAnio(anio);
        linea1.erase(0,5);
        //Reservaciones[cont].getAnio();
        
        //GUARDA ID MATERIAL
        id_mat=stod(linea1.substr(0,3));
        Reservaciones[cont1].setidMaterial(id_mat);
        linea1.erase(0,4);
        
        //GUARDA ID CLIENTE
        id_cliente=stod(linea1.substr(0,5));
        Reservaciones[cont1].setidCliente(id_cliente);
        linea.erase(0,6);
        //Reservaciones[cont1].muestra();
        cont1++;
    }
    archEntRes.close();
    //Fecha F1;
    //F1.setFecha();
    /*Material* M1;
    M1 = new Libro;
    M1->muestraDatos();
    Material* M1;
    M1 = new Software;
    M1->muestraDatos();*/
    char op;
    while(op!='f')
    {
    cout << "a) Consultar lista de materiales." << endl;
    cout << "b) Consultar lista de reservaciones" << endl;
    cout << "c) Consultar las reservaciones de un material dado" << endl;
    cout << "d) Consultar las reservaciones de una fecha dada" << endl;
    cout << "e) Hacer una reservación" << endl;
    cout << "f) Salir" << endl;
    cout << "Seleccione una opción para continuar: ";
    cin >> op;
        
        if(op=='a')
        {
            for(int i=0;i<=29;i++)
            {
                arrLibro[i].muestraDatos();
                arrDisco[i].muestraDatos();
                arrSoftware[i].muestraDatos();
            }
        }
        if(op=='b')
        {
            cout << "-----Reservaciones-----" << endl;
            for(int i=0;i<=59;i++)
            {
                if(arrDisco[i].getIDMaterial()==Reservaciones[i].getIdMaterial())
                    
                Reservaciones[i].muestra();
            }
        }
        if(op=='c')
        {
            string material;
            cout << "Ingrese el nombre del material: ";
            cin >> material;
            if(material=="disco")
            {
                for(int i=0;i<=29;i++)
                {
                    if(arrDisco[i].getTitulo()!=" ")
                    {
                        arrDisco[i].muestraDatos();
                        Reservaciones[i].muestraF();
                        cout << "Fecha final 3 días despues de la fecha inicial" << endl;
                    }
                }
            }
            if(material=="libro")
            {
                for(int i=0;i<=29;i++)
                {
                    if(arrLibro[i].getTitulo()!=" ")
                    {
                        arrLibro[i].muestraDatos();
                        Reservaciones[i].muestraF();
                        cout << "Fecha final 5 días despues de la fecha inicial" << endl;
                    }
                }
            }
            if(material=="software")
            {
                for(int i=0;i<=29;i++)
                {
                    if(arrSoftware[i].getTitulo()!=" ")
                    {
                        arrSoftware[i].muestraDatos();
                        Reservaciones[i].muestraF();
                        cout << "Fecha final 1 días despues de la fecha inicial" << endl;
                    }
                }
            }
        }
        if(op=='d')
        {
            int dia;
            cout << "Ingrese el día que desea comprobar: " ;
            cin >> dia;
            for(int i=0;i<=59;i++)
            {
                if(dia==Reservaciones[i].getDia())
                {
                    cout << "ID Cliente: " << Reservaciones[i].getIdCliente() << endl;
                    cout << "ID Material: " << Reservaciones[i].getIdMaterial() << endl;
                }
            }
        }
        if(op=='e')
        {
            ofstream archSalida;
            archSalida.open("Reservaciones.txt");
            int id_cl,id_mt,op;
            Fecha F1,F2;
            cout << "Ingrese el ID del cliente: " ;
            cin >> id_cl;
            cout << "Ingrese el ID del material: ";
            cin >> id_mt;
            for(int i=0;i<=60;i++)
            {
                if((id_cl==Reservaciones[i].getIdCliente()) && (id_mt==Reservaciones[i].getIdMaterial()))
                {
                    cout << "Material disponible" << endl;
                    cout << "Desea hacer una reservación?" << endl;
                    cout << "1 = si  2 = no " << endl;
                    cin >> op;
                    if(op==1)
                    {
                        archSalida << "Cliente   Material" << endl;
                        archSalida << Reservaciones[i].getIdCliente()<< "     ";
                        archSalida << Reservaciones[i].getIdMaterial();
                        Reservaciones[i].setidCliente(0);
                        Reservaciones[i].setidMaterial(0);
                        cout << "Reservación exitosa" << endl;
                    }
                }
            }
            archSalida.close();
        }
    }
    return 0;
}
