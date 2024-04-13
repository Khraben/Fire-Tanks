/*****Datos administrativos************************ 
 * Nombre del archivo:  Impresion.hpp
 * Tipo de archivo: hpp
 * Proyecto: 
 * Autor: Alex Sanchez, Hillary Malespin y Kevin Jimenez.
 * Empresa: 
 *****Descripción********************************** 
 *  Clase que contiene los metodos para imprimir los datos
 *  
 *****Versión************************************** 
 * ## | Fecha y hora | Autor 
 * 1.0 | 06/06/2022 | Hillary Malespin
 *     |            | Alex Sanchez
 *     |            | Kevin Jimenez
 **************************************************/ 
#ifndef IMPRESION_HPP
#define IMPRESION_HPP
#include <iostream>
#include <stdio.h>
#include <string>
#include <Windows.h>
#include "Jugador.hpp"

using namespace std;

/*****Nombre*************************************** 
 *  Impresion
 *****Descripción********************************** 
 *  La clase impresion es una clase que contiene los metodos para imprimir en pantalla. 
 *****Atributos************************************ 
 *  No posee
 *****Métodos****************************************************************************************
 *  ImpresionPantalla1  ImpresionObtenerNombres     ImpresionTanques            ImprimirParametros02
 *  CentrarCursor       ImpresionObtenerNombres2    ImpresionTanques02          ImpresionMetros
 *  CursorIzquierda     ImpresionDificultad         ImprimirInformacionTanque   ImpresionNoImpacto
 *  ImprimirTanque      ImpresionTerreno            ImprimirTurno               ImpresionImpacto
 *  ImprimirContinuar   ImpresionError01            ImprimirParametros          GameOver
 ****************************************************************************************************/ 
class Impresion {
    private:
        HANDLE aHConsole;
		COORD aSBSize;
    public:
        Impresion() {
            aHConsole=GetStdHandle(STD_OUTPUT_HANDLE);
			aSBSize=GetLargestConsoleWindowSize(aHConsole);
        }

    /*****Nombre***************************************
    *ImpresionPantalla1
    *****Descripción**********************************
    *Este método imprime en pantalla el menú principal.
    *****Retorno**************************************
    *void
    *****Entradas*************************************
    *No posee
    **************************************************/
    void ImpresionPantalla1() {
        system("cls");
        char MsgBienvenida[] = "[BIENVENIDOS A FIRE TANKS]";
		Sleep(10);
		for (int i=0;i<24;i++) cout<<"\n";
		int msg=strlen(MsgBienvenida);
		int pos=(int)(((aSBSize.X)-msg)/2);
		for(int i=0;i<pos;i++) cout<<" ";
		SetConsoleTextAttribute(aHConsole,2);
		for (int i=0;i!=msg;i++) {
			cout<<MsgBienvenida[i];
			Sleep(50);
		}
        cout<<endl<<endl<<endl;
        ImprimirTanque();
        cout<<endl;
        ImprimirContinuar();

    }

/*****Nombre***************************************
* CentrarCursor
*****Descripción**********************************
* Metodo para centrar el texto en la consola
*****Retorno**************************************
* Sin retorno
*****Entradas*************************************
* Un puntero al texto que se desea centrar
**************************************************/
	void CentrarCursor(char *a) {
		int msg=strlen(a);
		int pos=(int)(((aSBSize.X)-msg)/2);
		for(int i=0;i<pos;i++) cout<<" ";
	}

/*****Nombre***************************************
* CursorIzquierda
*****Descripción**********************************
* Metodo para mover a la izquieda el texto en la consola
*****Retorno**************************************
* Sin retorno
*****Entradas*************************************
* Un puntero al texto que se desea centrar
**************************************************/
    void CursorIzquierda(char *a) {
		int msg=strlen(a);
		int pos=(int)(((aSBSize.X)-msg)/4);
		for(int i=0;i<pos;i++) cout<<" ";
	}

    /*****Nombre***************************************
    *ImprimirTanque
    *****Descripción**********************************
    *Este método imprime en pantalla el tanque.
    *****Retorno**************************************
    *Void
    *****Entradas*************************************
    *No posee
    **************************************************/
    void ImprimirTanque() {
        char parte1[] = "    ________       ";
        char parte2[] = "        __/        \\_____________";
        char parte3[] = "              |___         _____________|=====|>";
        char parte4[] = "______|       |_________";
        char parte5[] = "|________________________|";
        char parte6[] = "\\_/\\_/\\_/\\_/\\_/\\_/\\_/\\_/";
        CentrarCursor(parte1);
        cout<<parte1<<endl;
        CentrarCursor(parte2);
        cout<<parte2<<endl;
        CentrarCursor(parte3);
        cout<<parte3<<endl;
        CentrarCursor(parte4);
        cout<<parte4<<endl;
        CentrarCursor(parte5);
        cout<<parte5<<endl;
        CentrarCursor(parte6);
        cout<<parte6<<endl;

    }

    /*****Nombre***************************************
    *ImprimirContinuar 
    *****Descripción**********************************
    *Este método imprime en pantalla el mensaje de continuar.
    *****Retorno**************************************
    *Void
    *****Entradas*************************************
    *No posee
    **************************************************/
    void ImprimirContinuar() {
        for (int i=0;i<9;i++) cout<<"\n";
        int pos=(int)(((aSBSize.X)-37)/2);
		for(int i=0;i<pos;i++) cout<<" ";
    }

    /*****Nombre***************************************
    *ImpresionObtenerNombre
    *****Descripción**********************************
    *Este método imprime en pantalla el mensaje de obtener el nombre del jugador 1.
    *****Retorno**************************************
    *void
    *****Entradas*************************************
    *No posee
    **************************************************/
    void ImpresionObtenerNombres() {
        for (int i=0;i<15;i++) cout<<"\n";
        char MsgTitulo1[] = "[INGRESE EL NOMBRE DE LOS JUGADORES]";
        CentrarCursor(MsgTitulo1);
        cout<<MsgTitulo1<<endl;
        cout<<"\n\n\n";
        char MsgJugador1[] = "[JUGADOR 1] = > ";
        CursorIzquierda(MsgJugador1);
        cout<<MsgJugador1;
    }

    /*****Nombre***************************************
    *ImpresionObtenerNombres2
    *****Descripción**********************************
    *Este método imprime en pantalla el mensaje de obtener el nombre del jugador 2.
    *****Retorno**************************************
    *void
    *****Entradas*************************************
    *No posee
    **************************************************/
    void ImpresionObtenerNombres2() {
        cout<<"\n\n\n";
        char MsgJugador2[] = "[JUGADOR 2] = > ";
        CursorIzquierda(MsgJugador2);
        cout<<MsgJugador2;
    }

    /*****Nombre***************************************
    *ImpresionDificultad
    *****Descripción**********************************
    *Este método imprime en pantalla el mensaje de escoger la dificultad.
    *****Retorno**************************************
    *void
    *****Entradas*************************************
    *No posee
    **************************************************/
    void ImpresionDificultad() {
        cout<<endl;
        char MsgDificultad[] = "[MODO DE JUEGO]";
        CentrarCursor(MsgDificultad);
        cout<<MsgDificultad<<"\n\n";
        char MsgDificultad2[] ="[FACIL]==>1         [DIFICIL]==>2";
        CentrarCursor(MsgDificultad2);
        cout<<MsgDificultad2<<"\n\n";
        char MsgDificultad3[] = "[SELECCIONE EL MODO DE JUEGO]==>";
        CentrarCursor(MsgDificultad3);
        cout<<MsgDificultad3;
    }

    /*****Nombre***************************************
    *ImpresionTerreno
    *****Descripción**********************************
    *Este método imprime en pantalla las opciones de escoger el terreno.
    *****Retorno**************************************
    *void
    *****Entradas*************************************
    *No posee
    **************************************************/
    void ImpresionTerreno() {
        cout<<endl<<endl<<endl;
        char MsgTerreno[] = "[CAMPO DE BATALLA]";
        char MsgTerreno1[] = "[1].[PANTANO VENENOSO]";
        char MsgTerreno2[] = "[2].[COLINAS DE FUEGO]";
        char MsgTerreno3[] = "[3].[DISTRITO DE MUERTE]";
        char MsgTerreno4[] = "[SELECCIONE EL TERRENO DE LA PARTIDA]===>";

        CentrarCursor(MsgTerreno);
        cout<<MsgTerreno<<"\n\n";
        CentrarCursor(MsgTerreno1);
        cout<<MsgTerreno1<<"\n\n";
        CentrarCursor(MsgTerreno2);
        cout<<MsgTerreno2<<"\n\n";
        CentrarCursor(MsgTerreno3);
        cout<<MsgTerreno3<<"\n\n";
        CentrarCursor(MsgTerreno4);
        cout<<MsgTerreno4;

    }

    /*****Nombre***************************************
    * ImpresionError01
    *****Descripción**********************************
    * Este método imprime en pantalla un mensaje de error.
    *****Retorno**************************************
    * void
    *****Entradas*************************************
    * No posee
    **************************************************/
    void ImpresionError01() {
        char MsgError01[] = "[POR FAVOR DIGITE CORRECTAMENTE UNO DE LOS MODOS DISPONIBLES]==>";
        CentrarCursor(MsgError01);
        cout<<MsgError01;
    }

    /*****Nombre***************************************
    * Impresiontanques
    *****Descripción**********************************
    * Este método imprime en pantalla las opciones de los tanques.
    *****Retorno**************************************
    * void
    *****Entradas*************************************
    * No posee
    **************************************************/
    void ImpresionTanques(Jugador *J1) {
        Jugador *J2 = new Jugador();
        char MsgTanques[] = "[SELECCIONE EL TANQUE QUE DESEA UTILIZAR]";
        for (int i=0;i<20;i++) cout<<"\n";
        CentrarCursor(MsgTanques);
        cout<<MsgTanques<<endl;
        char Tanque1[] = "[1].[T-28 SUPER TANK]===>[100 VIDA - 30 DAÑO]";
        char Tanque2[] = "[2].[T-14 ARMATA]===>[100 VIDA - 60 DAÑO]";
        char Tanque3[] = "[3].[LEOPARDO II]===>[150 VIDA - 15 DAÑO]";
        char Tanque4[] = "[4].[BLACK NIGHT]===>[100 VIDA - 25 DAÑO]";
        char InputTanque1[] = "==>";
        string nombreJ1 = J1->GetNombre();
        cout<<"\n\n";
        CursorIzquierda(Tanque1);
        printf("[1].[T-28 SUPER TANK]===>[100 VIDA - 30 DA%cO]\n",165);
        CursorIzquierda(Tanque2);
        printf("[2].[T-14 ARMATA]===>[100 VIDA - 60 DA%cO]\n",165);
        CursorIzquierda(Tanque3);
        printf("[3].[LEOPARDO II]===>[150 VIDA - 15 DA%cO]\n",165);
        CursorIzquierda(Tanque4);
        printf("[4].[BLACK NIGHT]===>[100 VIDA - 25 DA%cO]\n",165);
        CursorIzquierda(Tanque4);
        cout<<"["<<nombreJ1<<"] "<<InputTanque1;
        //imprimirInformacionTanque(InputTanque1,J2);
    }

    /*****Nombre***************************************
    * Impresiontanques
    *****Descripción**********************************
    * Este método imprime en pantalla las opciones de los tanques.
    *****Retorno**************************************
    * void
    *****Entradas*************************************
    * No posee
    **************************************************/
    void ImpresionTanques02(Jugador *J2) {
        Jugador *J1 = new Jugador();
        char Tanque4[] = "[4].[BLACK NIGHT]===>[100 VIDA - 25 DAÑO]";
        string nombreJ2 = J2->GetNombre();
        char InputTanque2[] = "==>";
        CursorIzquierda(Tanque4);
        cout<<"["<<nombreJ2<<"] "<<InputTanque2;
    }

    /*****Nombre***************************************
    * ImprimirInformacionTanque
    *****Descripción**********************************
    * Este método imprime en pantalla la información de los tanques que los jugadores eligieron
    *****Retorno**************************************
    * void
    *****Entradas*************************************
    * No posee
    **************************************************/
    void ImprimirInformacionTanque(Jugador *J1){
        for (int i=0;i<5;i++) cout<<"\n";
        char MsgTanque[] = "#=====================================[TANQUE ELEGIDO]=====================================#";
        char MsgNTanque[] = "[NOMBRE DEL TANQUE] = ";
        char MsgVida[] = "[VIDA] = ";
        char MsgDaño[] = "[DAÑO] = ";
        char MsgPosicion[] = "[POSICION] = ";

        CentrarCursor(MsgTanque);
        cout<<MsgTanque<<"\n\n";
        CursorIzquierda(MsgTanque);
        cout<<"["<<J1->GetNombre()<<"]"<<endl;
        CursorIzquierda(MsgTanque);
        cout<<MsgNTanque<<J1->GetTanque()->GetNombre()<<endl;
        CursorIzquierda(MsgTanque);
        cout<<MsgVida<<J1->GetTanque()->GetVida()<<endl;
        CursorIzquierda(MsgTanque);
        printf("[DA%cO] = ",165);
        cout<<J1->GetTanque()->GetDano()<<endl;
        CursorIzquierda(MsgTanque);
        cout<<MsgPosicion<<J1->GetTanque()->GetPosicion()<<endl;
    }

    /*****Nombre***************************************
    * ImprimirTurno
    *****Descripción**********************************
    * Este método imprime en pantalla el turno del jugador.
    *****Retorno**************************************
    * void
    *****Entradas*************************************
    * No posee
    **************************************************/
    void ImprimirTurno(Jugador *J1) {
        cout<<"\n\n\n";
        char MsgTurno[] = "[TURNO DE] = ";
        CursorIzquierda(MsgTurno);
        cout<<MsgTurno;
        cout<<J1->GetNombre();
    }

    /*****Nombre***************************************
    * ImprimirParametros
    *****Descripción**********************************
    * Este método imprime en pantalla los parametros de los tanques (La potencia).
    *****Retorno**************************************
    * void
    *****Entradas*************************************
    * No posee
    **************************************************/
    void ImprimirParametros() {
        cout<<endl;
        char MsgPotencia [] ="[POTENCIA(0-100)] = ";
        CursorIzquierda(MsgPotencia);
        cout<<MsgPotencia; 
    }

    /*****Nombre***************************************
    * ImprimirParametros02
    *****Descripción**********************************
    * Este método imprime en pantalla los parametros de los tanques (El angulo).
    *****Retorno**************************************
    * void
    *****Entradas*************************************
    * No posee
    **************************************************/
    void ImprimirParametros02() {
        cout<<endl;
        char MsgAngulo[] ="[ANGULO(30-80)] = ";
        CursorIzquierda(MsgAngulo);
        cout<<MsgAngulo; 
    }

    /*****Nombre***************************************
    * ImpresionMetros
    *****Descripción**********************************
    * Este método imprime en pantalla los metros que llega el disparo.
    *****Retorno**************************************
    * void
    *****Entradas*************************************
    * No posee
    **************************************************/
    void ImpresionMetros(int metros) {
        cout<<endl;
        char MsgMetros[] = "[EL DISPARO IMPACTO EN LA POSICION] = ";
        CursorIzquierda(MsgMetros);
        cout<<MsgMetros<<metros<<endl;
    }

    /*****Nombre***************************************
    * ImpresionNoImpacto
    *****Descripción**********************************
    * Este método imprime en pantalla que el disparo no impacto.
    *****Retorno**************************************
    * void
    *****Entradas*************************************
    * No posee
    **************************************************/
    void ImpresionNoImpacto() {
        cout<<endl;
        char Msg[] = "[NO HUBO IMPACTO]";
        CentrarCursor(Msg);
        cout<<Msg<<endl;
    }

    /*****Nombre***************************************
    * ImpresionImpacto
    *****Descripción**********************************
    * Este método imprime en pantalla que el disparo impacto.
    *****Retorno**************************************
    * void
    *****Entradas*************************************
    * No posee
    **************************************************/
    void ImpresionImpacto() {
        cout<<endl;
        char Msg[] = "[HUBO UN IMPACTO]";
        CentrarCursor(Msg);
        cout<<Msg<<endl;
    }
    
    /*****Nombre***************************************
    * GameOver
    *****Descripción**********************************
    * Este método imprime en pantalla el mensaje de game over cuando se acaba el juego.
    *****Retorno**************************************
    * void
    *****Entradas*************************************
    * No posee
    **************************************************/
    void GameOver(string nombre) {
        cout<<endl;
        char MsgGameOver[] = "[FIN DEL JUEGO]";
        char MsgGanador[] = "[GANADOR] = ";
        CentrarCursor(MsgGameOver);
        cout<<MsgGameOver<<endl;
        CentrarCursor(MsgGanador);
        cout<<MsgGanador<<nombre<<endl;
        CentrarCursor(MsgGameOver);
    }
};

#endif
