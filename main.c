/********************************************************************************************
	FICHERO: main.c                                                   
	
	Por Patricio Coronado Collado.17/07/2017
	
	Para comunicar con el puerto COM se utilizan funciones y variables exportadas de 
	PuertoCom.h
*********************************************************************************************/
																								
/*********************************************************************************************
	Copyright © 2017 Patricio Coronado
	
	This file is part of PCOM proyect

    CPCOM is free software: you can redistribute it and/or 
	modify it under the terms of the GNU General Public License as published 
	by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    PCOM is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with PCOM  If not, see <http://www.gnu.org/licenses/>

*********************************************************************************************/	
/*
	Esta cadena es la respuesta que tiene que dar el sistema que queremos controlar
	al recibir un comando SCPI *IDN.
	Obligatorio rellenar la cadena IdentificacionDelInstrumento que debe conincidir con 
	NOMBRE_DEL_SISTEMA_64B(identifiacion del instrumento) en la aplicación de Arduino
*/
//------------------------------------------------------------------------------------------
// Ficheros include                                                          
//------------------------------------------------------------------------------------------
#include <ansi_c.h>
#include <cvirte.h>
#include <userint.h>
#include <rs232.h>
//#include <utility.h>
#include <formatio.h>
#include <string.h>
//#include <analysis.h>
#include "PuertoCOM.h"
//------------------------------------------------------------------------------------------
// Constantes
//------------------------------------------------------------------------------------------
#define PP_TOP  60	  
#define PP_LEFT 60	
//------------------------------------------------------------------------------------------
// Variables globales
//------------------------------------------------------------------------------------------
char const Identificacion[]="Monitor de red";
/*********************************************************************************************
		                   FUNCION PRINCIPAL                                     
**********************************************************************************************/
 int main (int argc, char *argv[])
{
	short int PuertoAbierto=-1;
	if (InitCVIRTE (0, argv, 0) == 0) return -1;
	PuertoAbierto=pcom_abre_puerto_serie();
	pcom_muestra_el_panel_de_mensajes(PP_TOP,PP_LEFT);//Muestra el tráfico por el puerto
	pcom_modo_pcom(0);//Para poner los paneles en modo master
	DisplayPanel (MensajesHandle);
	// Si no se abre un puerto automáticamente, muestra el panel de configuración
	//if(PuertoAbierto==-1)pcom_muestra_el_panel_de_configuracion(PANEL_MODO_HIJO,100,300);
	RunUserInterface (); 
	return 0;
}
 //Por compatibilidad
 void pcom_datos_recibidos(void){}//Función que se ejecuta cuando se recibe un dato automáticamente
/**********************************************************************************************/
