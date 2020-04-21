/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2020. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  CONFIG                           1       /* callback function: panel_configuracion */
#define  CONFIG_PUERTOCOM                 2       /* control type: numeric, callback function: (none) */
#define  CONFIG_VELOCIDADPUERTO           3       /* control type: ring, callback function: (none) */
#define  CONFIG_BITSTOP                   4       /* control type: slide, callback function: (none) */
#define  CONFIG_BITDATOS                  5       /* control type: slide, callback function: (none) */
#define  CONFIG_TERMINADORESCRITURA       6       /* control type: ring, callback function: (none) */
#define  CONFIG_PARIDAD                   7       /* control type: slide, callback function: (none) */
#define  CONFIG_RINGCOM                   8       /* control type: ring, callback function: seleciona_un_puerto_de_la_lista */
#define  CONFIG_COLASALIDA                9       /* control type: numeric, callback function: (none) */
#define  CONFIG_TIMEOUT_MSG1_3            10      /* control type: textMsg, callback function: (none) */
#define  CONFIG_COLAENTRADA               11      /* control type: numeric, callback function: (none) */
#define  CONFIG_TERMINADORLECTURA         12      /* control type: ring, callback function: (none) */
#define  CONFIG_MODOCTS                   13      /* control type: binary, callback function: (none) */
#define  CONFIG_TIMEOUT_MSG1_4            14      /* control type: textMsg, callback function: (none) */
#define  CONFIG_MODOXONOFF                15      /* control type: binary, callback function: (none) */
#define  CONFIG_TIMEOUT_MSG1_6            16      /* control type: textMsg, callback function: (none) */
#define  CONFIG_TIMEOUT_MSG1_5            17      /* control type: textMsg, callback function: (none) */
#define  CONFIG_TIMEOUT_MSG1_2            18      /* control type: textMsg, callback function: (none) */
#define  CONFIG_RETARDO                   19      /* control type: numeric, callback function: (none) */
#define  CONFIG_TIMEOUT                   20      /* control type: numeric, callback function: (none) */
#define  CONFIG_DECORATION_2              21      /* control type: deco, callback function: (none) */
#define  CONFIG_BUSCARSISTEMA             22      /* control type: command, callback function: buscar_instrumento */
#define  CONFIG_BUSCARPUERTOS             23      /* control type: command, callback function: buscar_puertos_serie */
#define  CONFIG_SALIRCONFIG               24      /* control type: command, callback function: cerrar_configuracion */
#define  CONFIG_CERRARPUERTO              25      /* control type: command, callback function: CerrarPuertoCallback */
#define  CONFIG_APLICAR_TR                26      /* control type: command, callback function: aplicar_retardo_timeout */
#define  CONFIG_ABRIRPUERTO               27      /* control type: command, callback function: AplicarConfigCallback */
#define  CONFIG_DECORATION_7              28      /* control type: deco, callback function: (none) */
#define  CONFIG_DECORATION_4              29      /* control type: deco, callback function: (none) */
#define  CONFIG_DECORATION_5              30      /* control type: deco, callback function: (none) */
#define  CONFIG_DECORATION_6              31      /* control type: deco, callback function: (none) */
#define  CONFIG_IDENTIFICACION            32      /* control type: string, callback function: texto_identificacion */
#define  CONFIG_LEDCONFIG                 33      /* control type: LED, callback function: cambiar_de_modo */

#define  ESTATUS                          2
#define  ESTATUS_ERROR                    2       /* control type: command, callback function: pcom_muestra_error */
#define  ESTATUS_COMSTATUS                3       /* control type: command, callback function: pcom_muestra_status */
#define  ESTATUS_GETOUTQ                  4       /* control type: command, callback function: pcom_longitud_cola_salida */
#define  ESTATUS_CLOSE_ESTATUS            5       /* control type: command, callback function: cierra_panel_status */
#define  ESTATUS_GETINQ                   6       /* control type: command, callback function: pcom_longitud_cola_entrada */
#define  ESTATUS_FLUSHOUTQ                7       /* control type: command, callback function: pcom_borra_cola_salida */
#define  ESTATUS_FLUSHINQ                 8       /* control type: command, callback function: pcom_borra_cola_entrada */

#define  MENSAJES                         3       /* callback function: panel_mensajes */
#define  MENSAJES_LIMPIAR_RECIBIDO_2      2       /* control type: command, callback function: LimpiarEnviar */
#define  MENSAJES_RECIBIR                 3       /* control type: command, callback function: leer_buffer_entrada */
#define  MENSAJES_LIMPIAR_RECIBIDO        4       /* control type: command, callback function: LimpiarRecibir */
#define  MENSAJES_LEDCOM                  5       /* control type: LED, callback function: abre_cierra_com */
#define  MENSAJES_CADENA_ENVIAR           6       /* control type: textBox, callback function: (none) */
#define  MENSAJES_CADENA_RECIBIDA         7       /* control type: textBox, callback function: (none) */
#define  MENSAJES_X_POS                   8       /* control type: numeric, callback function: (none) */
#define  MENSAJES_Y_POS                   9       /* control type: numeric, callback function: (none) */
#define  MENSAJES_TEXTMSG_10              10      /* control type: textMsg, callback function: (none) */
#define  MENSAJES_COMANDO                 11      /* control type: string, callback function: enviar_comando */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

#define  MENUSCPI                         1
#define  MENUSCPI_COM                     2       /* callback function: Estatus */
#define  MENUSCPI_Configuracion           3       /* callback function: configuracion */
#define  MENUSCPI_MENUERROR               4       /* callback function: error_scpi */
#define  MENUSCPI_IDN                     5       /* callback function: version_scpi */
#define  MENUSCPI_MENUCLS                 6       /* callback function: cls_scpi */
#define  MENUSCPI_ABOUT                   7       /* callback function: about */


     /* Callback Prototypes: */

void CVICALLBACK about(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK abre_cierra_com(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK aplicar_retardo_timeout(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK AplicarConfigCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK buscar_instrumento(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK buscar_puertos_serie(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK cambiar_de_modo(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK cerrar_configuracion(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK CerrarPuertoCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK cierra_panel_status(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK cls_scpi(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK configuracion(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK enviar_comando(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK error_scpi(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK Estatus(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK leer_buffer_entrada(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK LimpiarEnviar(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK LimpiarRecibir(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK panel_configuracion(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK panel_mensajes(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pcom_borra_cola_entrada(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pcom_borra_cola_salida(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pcom_longitud_cola_entrada(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pcom_longitud_cola_salida(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pcom_muestra_error(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK pcom_muestra_status(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK seleciona_un_puerto_de_la_lista(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK texto_identificacion(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK version_scpi(int menubar, int menuItem, void *callbackData, int panel);


#ifdef __cplusplus
    }
#endif
