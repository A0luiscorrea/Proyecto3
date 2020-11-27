//
//  Fecha.h
//  Proyecto3
//
//  Created by Luis Alejandro Correa Vargas on 14/11/20.
//

#include <iostream>
#include <iomanip>


using namespace std;

class Fecha
{
public: //Metodos
    Fecha();
    Fecha(int dd,int mm,int aa);
    void setDia(int dd) {dia = dd;};
    int getDia() {return dia;};
    void setMes(int mm) {mes = mm;};
    int getMes() {return mes;};
    void setAnio(int aa) {anio = aa;};
    int getAnio() {return anio;};
    void muestraFecha();
    int cantidadDiasPrestamo();
    friend Fecha operator+(Fecha F1);
    friend istream& operator>>(istream&, Fecha&);
    friend ostream& operator<<(ostream&, Fecha);
    
protected: //Atributos
    int dia,mes,anio;
    string nombreMes;
};

Fecha::Fecha()
{
    dia = 00;
    mes = 00;
    anio = 0000;
}

Fecha::Fecha(int dd,int mm,int aa)
{
    dia = dd;
    mes = mm;
    anio = aa;
}
void Fecha::muestraFecha() //Para comprobar que se guarde la fecha
{
    cout << "Fecha: " <<dia <<"-"<< mes <<"-"<< anio <<endl;
}
Fecha operator+(Fecha F1)
{
    int d,m,a;
    d = F1.dia;
    a=F1.anio;
    if(d>30)
    {
        d=1;
        if(F1.mes==12)
        {
            m=F1.mes = 1;
            a=F1.anio + 1;
        }
    }
    Fecha F(d,m,a);
    return F;
}
istream& operator>>(istream &ins, Fecha &Fecha1){
  int iD,iM,iA;
  cout << "Dia: " << endl;
  ins >> Fecha1.dia;
  cout << "Mes: " << endl;
  ins >> Fecha1.mes;
  cout << "Año: " << endl;
  ins >> Fecha1.anio;
  return ins;
}

ostream& operator << (ostream &out, Fecha Fecha1){
  out << "Dia: " << Fecha1.dia << endl;
  out << "Mes: " << Fecha1.mes << endl;
  out << "Año: " << Fecha1.anio << endl;
  return out;
}
/*----------------------CLASE RESERVA----------------------*/
class Reserva : public Fecha
{
public: //Metodos
    Reserva();
    Reserva(int i,int i1,Fecha F);
    void setidCliente(int i) {idCliente = i;};
    int getIdCliente() {return idCliente;};
    void setidMaterial(int i1) {idMaterial = i1;};
    int getIdMaterial() {return idMaterial;};
    void setFecha(Fecha F);
    Fecha getFecha() {return fechaReservacion;};
    int cantidadDiasPrestamo();
    void muestra();
    void muestraF();
    void calculaFechaFinReserva();
private: //Atributos
    Fecha fechaReservacion;
    int idCliente,idMaterial;
};

Reserva::Reserva() : Fecha()
{
    idCliente = 0;
    idMaterial = 0;
    Fecha F[60];
    fechaReservacion = F[59];
}
Reserva::Reserva(int i,int i1,Fecha F) : Fecha()
{
    idMaterial = i1;
    idCliente = i;
}

void Reserva::muestra() //Para comprobar que se guarde la fecha
{
    cout << "ID Cliennte: " << idCliente << endl;
    cout << "ID Material: " << idMaterial << endl;
    cout << "Fecha Inicial: " <<dia <<"-"<< mes <<"-"<< anio <<endl;
    cout << "Fecha Final: " << endl;
}
void Reserva::muestraF()
{
    cout << "Fecha inicial: " <<dia <<"-"<< mes <<"-"<< anio <<endl;
}
void Reserva::calculaFechaFinReserva()
{
    int dia_final;
    dia_final = dia;
    if(dia_final<=30)
    {
        cout << "Su fecha de entrega es el día " << dia_final << " del mes " << mes << " del año " << anio << endl;
    }
}


