/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2019. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PRINCIPAL                        1       /* callback function: panel_principal */
#define  PRINCIPAL_GRAFICA_FFT            2       /* control type: graph, callback function: (none) */
#define  PRINCIPAL_GRAFICA                3       /* control type: graph, callback function: (none) */
#define  PRINCIPAL_FUNCION1               4       /* control type: command, callback function: pedir_muestras */
#define  PRINCIPAL_NMUESTRAS              5       /* control type: numeric, callback function: numero_de_muestras */


     /* Control Arrays: */

#define  CTRLARRAY                        1

     /* Menu Bars, Menus, and Menu Items: */

#define  MENU                             1
#define  MENU_COM                         2
#define  MENU_COM_CONFIGURAR              3       /* callback function: Configurar */
#define  MENU_COM_COMUNICACION            4       /* callback function: comunicacion_menu */
#define  MENU_INFO                        5
#define  MENU_INFO_ABOUT                  6       /* callback function: About */


     /* Callback Prototypes: */

void CVICALLBACK About(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK comunicacion_menu(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK Configurar(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK numero_de_muestras(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK panel_principal(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pedir_muestras(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
