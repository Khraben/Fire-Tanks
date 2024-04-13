/*****Datos administrativos************************ 
 * Nombre del archivo:  Main.cpp
 * Tipo de archivo: cpp
 * Proyecto: 
 * Autor: Alex Sanchez, Hillary Malespin y Kevin Jimenez.
 * Empresa: 
 *****Descripción********************************** 
 *  Clase principal del proyecto.
 *  
 *****Versión************************************** 
 * ## | Fecha y hora | Autor 
 * 1.0 | 06/06/2022 | Hillary Malespin
 *     |            | Alex Sanchez
 *     |            | Kevin Jimenez
 **************************************************/ 

#include <ctime> 
#include <iostream>
#include <string>
#include <windows.h>
#include <math.h>
#include "Impresion.hpp"
#include "Jugador.hpp"
#include "Tanque.hpp"
#define PI 3.14159265
using namespace std;


Impresion *gImpresion = new Impresion();
Jugador *gJugador1 = nullptr;
Jugador *gJugador2 = nullptr;
Tanque *tEnemigo = nullptr;
int gDificultad = 0;
int gTurno = 0;
int gCiclos = 0;
//Variables globales para impresion
HANDLE gHOut=GetStdHandle(STD_OUTPUT_HANDLE);
COORD gSBSize=GetLargestConsoleWindowSize(gHOut);

void Inicio();
void Menu();
void Menu02();
void Menu02_2();
void Menu03();
void Menu03_2();
void Menu03_3();
void Menu04();
void Menu04_2();
void Turnos();
void NoImpacto();
void SoyJ1(int metros, int posicion, Jugador *J);
void DisparoJ1(int metros, int posicion2, int dano, int vidaEnemigo, int especial);
void DisparoJ2(int metros, int posicion2, int dano, int vidaEnemigo, int especial);
void Impacto(int dano);
void SetEspecialJ1(int especial);
void SetEspecialJ2(int especial);
void SoyJ2(int metros, int posicion, Jugador *J);
void GameOverJ1();
void GameOverJ2();

int END();
void Disparo(Jugador *J1);

int VerificarNumero();

unsigned t0, t1;

int main() {

	t0=clock();

    system("cls");
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE),CONSOLE_FULLSCREEN_MODE,0);
    Inicio();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "Execution Time: " << time << endl;
    END();
    return 0;
}

/*****Nombre***************************************
* Inicio
*****Descripción**********************************
* Función que se encarga de iniciar el juego.
*****Retorno**************************************
* void
*****Entradas*************************************
* void
**************************************************/
void Inicio() {
    gImpresion->ImpresionPantalla1();
    system("cls");
    Menu();
}

/*****Nombre***************************************
* Menu
*****Descripción**********************************
* Funcion que se encarga de mostrar el nombre de los jugadores y muestra las opciones de dificultad.
*****Retorno**************************************
* void
*****Entradas*************************************
* void
**************************************************/
void Menu() {
    gJugador1 = new Jugador();
    gJugador2 = new Jugador();
    gImpresion->ImpresionObtenerNombres();
    string nombre1 = "Alex";
    gJugador1->SetNombre(nombre1);
    gImpresion->ImpresionObtenerNombres2();
    string nombre2 = "Kevin";
    gJugador2->SetNombre(nombre2);
    gImpresion->ImpresionDificultad();
    Menu02();
    
}

/*****Nombre***************************************
* Menu02
*****Descripción**********************************
* Funcion que se encarga de verificar las entradas de dificultad.
*****Retorno**************************************
* void
*****Entradas*************************************
* void
**************************************************/
void Menu02() {
    gDificultad = 1;
    switch(gDificultad) {
        case 1:
            gDificultad = 1;
            break;
        case 2:
            gDificultad = 2;
            Menu02_2();
            break;
        default:
            gImpresion->ImpresionError01();
            Menu02();
    }
    Menu03();
}

/*****Nombre***************************************
* Menu02_2
*****Descripción**********************************
* Funcion que se encarga de verificar y muestra las opciones de terrena.
*****Retorno**************************************
* void
*****Entradas*************************************
* no posee
**************************************************/
void Menu02_2() {
    gImpresion->ImpresionTerreno();
    int terreno = 1;
    if (terreno>3 || terreno<1) {
        gImpresion->ImpresionError01();
        Menu02_2();
    }
}

/*****Nombre***************************************
* Menu03
*****Descripción**********************************
* Funcion que se encarga de mostrar los tanques.
*****Retorno**************************************
* void
*****Entradas*************************************
* no posee
**************************************************/
void Menu03() {
    system("cls");
    gImpresion->ImpresionTanques(gJugador1);
    
    Menu03_2();
}

/*****Nombre***************************************
* Menu03_2
*****Descripción**********************************
* Funcion que se encarga de verificar las entradas de los tanques.
*****Retorno**************************************
* void
*****Entradas*************************************
* no posee
**************************************************/
void Menu03_2() {
    int TJ1 = 2;
    Tanque *TanqueJ1 = nullptr;
    switch (TJ1) {
        case 1:
            TanqueJ1 = new Tanque("T-28 Super Tank",100,30);
            gJugador1->SetTanque(TanqueJ1);
            break;
        case 2:
            TanqueJ1 = new Tanque("T-14 Armata",100,60);
            gJugador1->SetTanque(TanqueJ1);
            break;
        case 3:
            TanqueJ1 = new Tanque("Leopardo II",150,15);
            gJugador1->SetTanque(TanqueJ1);
            break;
        case 4:
            TanqueJ1 = new Tanque("Black Night",100,25);
            TanqueJ1->SetEspecial(1);
            gJugador1->SetEspecial(1);
            gJugador1->SetTanque(TanqueJ1);
            break;
        default:
            gImpresion->ImpresionError01();
            Menu03_2();
    }

    gImpresion->ImpresionTanques02(gJugador2);
  
    Menu03_3();

}

/*****Nombre***************************************
* Menu03_3
*****Descripción**********************************
* Funcion que se encarga de verificar las entradas de los tanques del jugador 2.
*****Retorno**************************************
* void
*****Entradas*************************************
* no posee
**************************************************/
void Menu03_3() {
    int TJ2 = 3;
    Tanque *TanqueJ2 = nullptr;
    switch (TJ2) {
        case 1:
            TanqueJ2 = new Tanque("T-28 Super Tank",100,30);
            gJugador2->SetTanque(TanqueJ2);
            break;
        case 2:
            TanqueJ2 = new Tanque("T-14 Armata",100,60);
            gJugador2->SetTanque(TanqueJ2);
            break;
        case 3:
            TanqueJ2 = new Tanque("Leopardo II",150,15);
            gJugador2->SetTanque(TanqueJ2);
            break;
        case 4:
            TanqueJ2 = new Tanque("Black Night",100,25);
            TanqueJ2->SetEspecial(1);
            gJugador2->SetEspecial(1);
            gJugador2->SetTanque(TanqueJ2);
            break;
        default:
            gImpresion->ImpresionError01();
            Menu03_3();
    }
    Menu04();
}

/*****Nombre***************************************
* Menu04
*****Descripción**********************************
* Funcion que se encarga de posicionar los tanques.
*****Retorno**************************************
* void
*****Entradas*************************************
* no posee
**************************************************/
void Menu04(){
    system("cls");
    int posicionTanque1=0;
    int posicionTanque2=0;
    for (int i=0;i<2;i++) {
        posicionTanque1 = rand() % 100 + 1;
        posicionTanque2 = rand() % 801+200;
    }
    gJugador1->GetTanque()->SetPosicion(posicionTanque1);
    gJugador2->GetTanque()->SetPosicion(posicionTanque2);
    Menu04_2();
}

/*****Nombre***************************************
* Menu04_2
*****Descripción**********************************
* Funcion que se encarga de imprimir la posicion de los tanques.
*****Retorno**************************************
* void
*****Entradas*************************************
* no posee
**************************************************/
void Menu04_2() {
    if (gCiclos == 150) { //MODIFICAR PARA DIFERENTES MEDICIONES
        END();
    }
    gImpresion->ImprimirInformacionTanque(gJugador1);
    gImpresion->ImprimirInformacionTanque(gJugador2);
    gCiclos++;
    Turnos();
}

/*****Nombre***************************************
* Turnos
*****Descripción**********************************
* Funcion que se encarga de realizar los turnos.
*****Retorno**************************************
* void
*****Entradas*************************************
* no posee
**************************************************/
void Turnos() {
    switch(gTurno) {
        case 0:
            gImpresion->ImprimirTurno(gJugador1);
            Disparo(gJugador1);
            break;
        case 1:
            gImpresion->ImprimirTurno(gJugador2);
            Disparo(gJugador2);
        default:
            break;
    }
    Menu04_2();
}

/*****Nombre***************************************
* Disparo
*****Descripción**********************************
* Funcion que se encarga de realizar el disparo.
*****Retorno**************************************
* void
*****Entradas*************************************
* no posee
**************************************************/
void Disparo(Jugador *J){
    gImpresion->ImprimirParametros();
    int potencia = 80;
    if (potencia<0 || potencia>100) {
        cout<<endl;
        gImpresion->ImpresionError01();
        Disparo(J);
    }
    gImpresion->ImprimirParametros02();
    int angulo = 33;
    if (angulo<30 || angulo>80) {
        cout<<endl;
        gImpresion->ImpresionError01();
        Disparo(J);
    }

    int metros = (pow(potencia,2)*sin(2*angulo*PI/180))/9.8;
    int posicion = J->GetTanque()->GetPosicion();

    if (posicion<=200) {SoyJ1(metros, posicion, J);}
    else {SoyJ2(metros, posicion, J);}
}

void SoyJ1(int metros, int posicion, Jugador *J){
    tEnemigo = gJugador2->GetTanque();
    metros+=posicion;
    gImpresion->ImpresionMetros(metros);
    int posicion2 = tEnemigo->GetPosicion();
    int dano = J->GetTanque()->GetDano();
    int vidaEnemigo = tEnemigo->GetVida();
    int especial = J->GetEspecial();
    DisparoJ1(metros,posicion2,dano,vidaEnemigo,especial);
}
void DisparoJ1(int metros, int posicion2, int dano, int vidaEnemigo, int especial) {
    if (metros == posicion2 || metros>=(posicion2-10) & metros<=(posicion2+10)) {
        Impacto(dano);
    }
    else { NoImpacto(); }
    if (vidaEnemigo<=0) {
        GameOverJ1();
    }
    if (metros>=(posicion2-30) & metros<=(posicion2+30) & especial == 1) {
        if (especial == 1) {
            SetEspecialJ1(1);
        }
        else {
            SetEspecialJ1(0);
        }
            Menu04_2();
    }
    else {
        gTurno = 1;
        Menu04_2();
    }
}

void GameOverJ1() {
    gImpresion->GameOver(gJugador1->GetNombre());
    END();
}
void SetEspecialJ1(int especial) {
    gJugador1->GetTanque()->SetEspecial(especial);
}

void SoyJ2(int metros, int posicion, Jugador *J) {
    metros = posicion - metros;
    tEnemigo = gJugador1->GetTanque();
    gImpresion->ImpresionMetros(metros);
    int posicion2 = tEnemigo->GetPosicion();
    int dano = J->GetTanque()->GetDano();
    int vidaEnemigo = tEnemigo->GetVida();
    int especial = J->GetEspecial();
    DisparoJ2(metros,posicion2,dano,vidaEnemigo,especial);
}

void DisparoJ2(int metros, int posicion2, int dano, int vidaEnemigo, int especial){
    if (metros == posicion2 || metros>=(posicion2-10) & metros<=(posicion2+10)) {
        Impacto(dano);
    }
    else {
        NoImpacto();
    }
    if (vidaEnemigo<=0) {
        GameOverJ2();
    }
    if (metros>=(posicion2-30) & metros<=(posicion2+30) & especial == 1) {
        if (especial == 1) {
            SetEspecialJ2(1);
        }
        else {
            SetEspecialJ2(0);
        }
        Menu04_2();
    }
    else {
        gTurno = 0;
        Menu04_2();
    }
}


void GameOverJ2() {
    gImpresion->GameOver(gJugador2->GetNombre());
    END();
}

void SetEspecialJ2(int especial) {
    gJugador2->GetTanque()->SetEspecial(especial);
}


void Impacto(int dano) {
    tEnemigo->SetVida(tEnemigo->GetVida()-dano);
    gImpresion->ImpresionImpacto();
}
void NoImpacto() {
    gImpresion->ImpresionNoImpacto();
}


/*****Nombre***************************************
* VerificarNumero
*****Descripción**********************************
* Metodo para verificar si el usuario ingresa un numero
*****Retorno**************************************
* Un numero entero
*****Entradas*************************************
* Sin entradas
**************************************************/
int VerificarNumero() {
	int numero;
	while (!(cin>>numero)) {
		cin.clear();
		cin.ignore(10000,'\n');
        gImpresion->ImpresionError01();
	}
	return numero;
}

int END() {
    cout<<"\n\n\n";
    
    //Para sacar el tiempo de ejecución
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "Tiempo de Ejecucion en Segundos: " << time << endl;

    char msg[] = "Presione una tecla para continuar . . .";
    gImpresion->CentrarCursor(msg);
    system("pause");
    cout<<"\n\n\n";
    exit(-1);
}
