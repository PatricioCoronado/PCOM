#ifndef __PuertoCOM_H__
#define __PuertoCOM_H__
 /*
 Fichero: PuertoCom.h
Próposito: Implementa variables y funciones para manejar fácilmente la  conexión
a un puerto COM de un instrumento con la librería para  Arduino Segainvex_scpi_Serial
o versiones superiores  (no es imprescindible).
INSTRUCCIONES DE USO:
Para utilizar este módulo hay que incluir PuertoCOM.c PuertoCOM.h en el proyecto
Instrumento conectado en un puerto COM con la librería segainvex_scpi_Seria o versión
 posterior:

La configuración del puerto serie y del instrumento debe ser la del panel de 
configuración: baudrate 115200, 8 bits de datos, 2 bits de stop,sin protocolo 
hard. ni soft. Si se conecta a través de Bluetooth el baudrate no es relevante
Si se va a conectar un instrumento que responde al comando SCPI IDN devolviendo
una cadena de identificación, lo más sencillo es rellenar la cadena de  identificación:
char IdentificacionDelInstrumento[] ="Identificación del sistema";
en el módulo principal de la aplicación y ejecutar pcom_abre_puerto_serie. Esta 
función  busca un fichero de configuración con la última configuración que funcionó 
e intenta aplicarlo. Si abre el puerto eidentifica correctamente ya está el puerto
listo para funcionar.  Si no, se carga el panel de configuración y se propone una
búsqueda manual por la lista de puertos que tiene el sistema. Este panel tiene dos
modos de funcionamiento:
El modo inicial de funcionamiento es "usuario", para que solo se puede cambiar 
"Retardo" y "Timeout" del puerto serie y el resto de controles están dimados.
Hacer doble click con el botón  derecho del ratón en el led y pasar a modo "master"
para poder cambiar  todos los controles del panel de la configuración del puerto y
igualarla a la del instrumento que tengamos conectado (configuración que tenemos
que conocer de antemano).
Para empezar directamente en modo master hay que ejecutar primero pcom_modo_pcom(0);
 y luego 	pcom_muestra_el_panel_de_configuracion().
La recepción automática está activada por defecto, por lo que al enviar un  comando 
a Arduino que provoque una respuesta del instrumento, se ejecutará la función
void pcom_datos_recibidos(void),
que tenemos que definir en el código de cada aplicación. En esta aplicación hay que
discriminar el dato que se ha recibido es y procesarlo. Los datos recibidos 
automáticamente están en char CadenaRespuesta[], esta  cadena esta terminada con 
TERMINADOR y '\0'. TERMINADOR es configurable, por defecto es '\n'. Si queremos 
enviar un dato y leer la respuesta de forma no automática, hay que desactivar la
recepción automática.

Código para enviar un comando y recibir respuesta sin modo automático:

char DatosRecibidos[256]; //Cadena para recibir datos del instrumento
//...
pcom_recepcion_automatica(NO); //Evita la recepción automática
sprintf(CadenaComando,"%s","*IDN"); //Pone el comando en la cadena de salida
ENVIAR_COMANDO_AL_SISTEMA(MOSTRAR) //Envia el comando en la cadena de salida
pcom_recibir_datos (DatosRecibidos,1);//Que rellena la cadena DatosRecibidos
pcom_recepcion_automatica(SI); //Habilita la recepción automática
//Ya podemos procesar los datos recibidos en DatosRecibidos

Al ejecutar el macro ENVIAR_COMANDO_AL_SISTEMA se envía por el puerto serie y se produce
un delay de duración"Retardo", que es un parámetro configurable.
En la ventana de mensajes, haciendo doble click con el botón derecho del ratón  se cierra 
y abre el puerto  serie. Esto debe usarse solo para depuración.
Cuando se cierra la aplicación y esta ha funcionado  con un puerto COM ,se guarda la 
configuración en un fichero:
%appdata%\PuertoCOM.dat
Cuando abra de nuevo la aplicación, esta aplicará el fichero si el instrumento está 
conectado al sistema,esto es más rápido que si la aplicación tiene que buscar el 
instrumento en el puerto.

Es necesario tener declaradas en el módulo principal las cadenas:

char IdentificacionDelInstrumento[] ="Base SPM";
char VersionDelInstrumento[64];
*/
/*************************************************************************************
							CONSTANTES EXPORTADAS
**************************************************************************************/
	
#define STRLARGO 1024 // Longitud de una cadena larga	
#define STRCORTO 64 // Longitud de una cadena corto	
#define STRMEDIO 256// Longitud de una cadena media
#define STRNORMAL 512// Longitud de una cadena media
#define PM_TOP  25		// Coordenadas para posicionar el panel de Mensajes
#define PM_LEFT 550
#define MOSTRAR 1
#define NO_MOSTRAR 0
#define SIN_PUERTO -1//Para indicar que no se ha abierto el puerto
#define QUITAR_PANELES 1
#define NO_QUITAR_PANELES 0
/*************************************************************************************
							VARIABLES EXPORTADAS
**************************************************************************************/
extern int MensajesHandle;
extern char const Identificacion[];  //Se rellena el el programa principal con el nombre del instrumento
extern char VersionDelInstrumento[];  //Se rellena el el programa principal con el nombre del instrumento
extern char IDNinstrumento[STRMEDIO];// Cadena para leer la identificación que manda el instrumento por el puerto  
//Al buscar un instrumento, la aplicación compara las dos cadenas anteriores
extern char CadenaComando[STRMEDIO];   // Aquí se pone el comando a enviar al instrumento
extern char CadenaRespuesta[STRLARGO]; // Aquí esta la respuesta del instrumento
extern float Retardo;		// Tiempo de retardo entre envío y recepción Delay(Retardo)
extern int FlagPuertoAbierto;  // Flag que indica si hay algún puerto abierto  

//*************************************************************************************
// MACROS			   
// Envía un comando err? al sistema sin mostrarlo en el control que muestra las cadenas de salida
#define	PEDIR_ERROR_AL_SISTEMA(MOSTRAR_O_NO) sprintf(CadenaComando,"%s","ERR?");\
								if(pcom_puerto_abierto())	{ \
					pcom_enviar_datos(CadenaComando,MOSTRAR_O_NO);  \
					Delay (Retardo);}
//Envía por el puerto serie lo que se haya puesto en el array de char "CadenaComano"
//sin mostrarlo en el control que muestra las cadenas de salida 
#define ENVIAR_COMANDO_AL_SISTEMA(MOSTRAR_O_NO) if(pcom_puerto_abierto()){ \
				pcom_enviar_datos(CadenaComando,MOSTRAR_O_NO);		   \
				Delay (Retardo);								   \
			}
#define ERROR 	sprintf(CadenaComando,"%s","ERR?");\
				pcom_enviar_datos(CadenaComando,1);		   
/**************************************************************************************
							FUNCIONES PUBLICAS
***************************************************************************************/

/***************************************************************************************
	ENTRADA PRINCIPAL: PARA ABRIR UN PUERTO COM CON EL INSTRUMENTO CONECTADO
	------------------------------------------------------------------------------
	BUSCA EL SISTEMA ENTRE LOS PUERTOS DEL PC Y SI LO ENCUENTRA ABRE EL PUERTO 
	SERIE Y CONFIGURA EL PROTOCOLO Y TIMEOUT.
	Intenta abrir el puerto a partir de los datos de un fichero. Si fracasa
	intenta abrir todos los puertos de 0 a 255.Con la configuración 
	del panel de configuración. Si puede abrir alguno, le envia
	un comando de identificación. Y si la cadena devuelta es la esperada, 
	Identificacion[],termina de configurar el puerto.
	DEVUELVE: El número del puerto COM abierto.Si no consigue abrir 
	un puerto devuelve -1 (SIN_PUERTO) y PuertoCOM=-1
*/
int pcom_abre_puerto_serie(void);
/**************************************************************************************
	FUNCION PARA PONER EN PANTALLA EL PANEL DE CONFIGURACION
	Muestra el panel con los parámetros de configuración del puerto
	ARGUMENTOS DE ENTRADA: el primer int es el modo del panel (ver abajo los #define)
	Los otros dos argumentos son las coordenas top y left para posicionar el panel
	Hacer doble click con el botón derecho del ratón en el led CAMBIAR ENTRE MODO MASTER
	Y USUARIO.
*/
#define PANEL_MODO_HIJO 0//Para instalar el panel de configuración del puerto modo hijo
#define PANEL_MODO_TOP 1 //Para instalar el panel de configuración del puerto modo top
void pcom_muestra_el_panel_de_configuracion(int/*PANEL_MODO_HIJO o PANEL_MODO_TOP*/,int,int);
/***************************************************************************************
	FUNCION VIRTUAL A DEFINIR EN EL PROGRAMA PRINCIPAL
	Esta función es llamada cuando se detecta "Terminador2" en el buffer de entrada.
	Se ejecuta si está activada la opción de recibir datos automáticamente.	
	Los datos recibidos están en "CadenaRespuesta". Este array de char finaliza 
	con:'\n' y '\0'.
	TERMINADOR PARA LA RECEPCIÓN AUTOMÁTICA: Serial.println() de Arduino funciona así:
	prints data to the serial port as human-readable ASCII text followed by a carriage 
	return character (ASCII 13, or '\r' or CR) and a newline character (ASCII 10, or
	'\n' or LF).
	La cadena recibida de Serial.println() termina  con "13 10" ó CR LF ó \r\n, 
	por eso la recepción automática se dispara con \n. la función que lee quita  
	\n y deja  \r que sirve para detectar el final de cadena. 
	En esta función, se busca \r en la cadena y cuando se encuentra se sustituye
	por \n y se añade \0.
*/	
	#define TERMINADOR '\n'  //es LF ó 10
	#define TERMINADOR2 '\r' //es CR ó 13
	#define TERMINADOR_CR '\r' //es CR ó 13
	#define TERMINADOR_LF '\n'  //es LF ó 10
extern void pcom_datos_recibidos(void);
/**************************************************************************************
	FUNCION QUE ACTIVA O DESACTIVA LA RECEPCION AUTOMATICA DEL PUERTO COM
	El puerto tiene que estar abierto. 
	Si se activa la recepción automática, cuando entra un dato por el 
	puerto COM con el "Terminador2" se ejecuta la función "pcom_datos_recibidos".
	Esta función la tiene que definir el usuario para que se haga lo que el quiera
	al recibir un dato. Los datos recibidos están en "CadenaRespuesta". Este array 
	de char finaliza con:'\n' y '\0'.
	ARGUMENTO DE ENTRADA: int 1 para activar o int 0 para desactivar
	DEVUELVE:El Puerto COM para el que activa la recepción automática.Si el puerto
	no está abierto devuelve el código de error -3.
*/
int pcom_recepcion_automatica(int);
/***************************************************************************************                                        
	FUNCION PARA RECIBIR DATOS                                                                                                  
	El puerto tiene que estar abierto. 
	Lee datos del buffer buscando el terminador de recepción seleccionado en el panel de
	"configuración del puerto COM" del puerto.
	ARGUMENTOS DE ENTRADA: La cadena es para que la rellene con los datos recibidos
	El segundo argumento  pone a 1 para que muestre los datos en el control de recepción
	en el panel "comunicacion" y a cero para que no.
	DEVUELVE: El número de bytes leidos o el código de error si se produce.Si el puerto
	no está abierto devuelve el código de error -3.
*/
int pcom_recibir_datos(char[],short int);
/***************************************************************************************                                        
	FUNCION PARA ENVIAR DATOS                                                                                                   
	El puerto tiene que estar abierto. 
	Envía la cadena pasada como primer argumento por el puerto serie
	Envía datos poniendo al final  el terminador de transmisión seleccionado en el panel
	de "configuración del puerto COM" del puerto.
	ARGUMENTOS DE ENTRADA: La cadena con los datos a enviar
	El segundo argumento  pone a 1 para que muestre los datos en el control de transmisión
	en el panel "comunicacion" y a cero para que no.
	DEVUELVE: El número de bytes enviados o el código de error si se produce.
	Si el puerto no está abierto devuelve el código de error -3.
*/                  
int pcom_enviar_datos (char[],int);
/*****************************************************************************************
	FUNCIONES QUE DEVUELVE 1 si el puerto está abierto y 0 si no
*/
int pcom_puerto_abierto(void);//Devuelve 1 si el puerto está abierto 0 si no
/*****************************************************************************************
	FUNCION QUE CIERRA EL PUERTO: Hay que cerrar el puerto antes de salir de la aplicación
	Si el parámetro de entrada es 1 también descarga los paneles. Si es 0 no.
*/
void pcom_cierra_puerto_serie(int);
/*****************************************************************************************
	 FUNCION QUE LIMPIA LA PILA DE ERRORES SCPI
	 Es conveniente limpiar la pila de errores al principio de la aplicación
*/
void pcom_limpia_pila_errores(void);
/*****************************************************************************************
	FUNCION PARA PONER EN PANTALLA EL PANEL DE MENSAJES
	Muestra el panel en el que se ve el tráfico del puerto serie
	ARGUMENTOS DE ENTRADA: Los argumentos son las coordenas top y left para
	posicionar el panel.
*/
void pcom_muestra_el_panel_de_mensajes(int,int);
/*****************************************************************************************      
	FUNCION PARA INICIALIZAR LAS VARIABLES Y PANELES DEL PUERTO
	pcom  por defecto está en modo USUARIO. Pero podemos inicializarlo para que empiece
	en modo MASTER ejecutando esta función.
	ARGUMENTOS DE ENTRADA: 0 para pasar a modo MASTER y 1 para modo USUARIO
	
*/                                                                                              
int pcom_modo_pcom(int short);                                       
/*****************************************************************************************      
	FUNCIONES QUE DEVUELVE: 1 cuando se produce recepción automática de cadena 
	por el puerto serie. Cada vez que se ejecuta se borra la información, si se ejecuta
	de nuevo y no ha recibido un dato automático por el puerto serie devuelve 0.
*/                                                                                              
int short com_flag_dato_recibido (void);                                                          
/******************************************************************************************/
#endif  /* ndef __PuertoCOM_H__ */  



