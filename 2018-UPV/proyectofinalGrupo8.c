#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX 30
//cantidad máxima de caracteres de cualquier nombre
#define MAX_CAT 6
//cantidad máxima de categorías
#define MAX_CORR 5000
//cantidad máxima de corredores
#define MAXTRACKPOINTS 10000
//cantidad de tracks
// ESTRUCTURAS
typedef struct{
	char nombre[MAX];
	char sexo;
	int edadmin;
	int edadmax;
	float precio;
}categoria;

typedef struct{
	char nombre[MAX];
	char apellido1[MAX];
	char apellido2[MAX];
	int edad;
	int dorsal;
	char club[MAX];
	char sexo;
	char nom_categoria[MAX];
	int posicion_total;
	int posicion_categoria;
	int horas;
	int minutos;
	int segundos;
}corredor;

//funcion cargar categorias
int cargar_categorias(categoria t_categorias[])
{
	int i;
	FILE* fich_categoria;
	if ((fich_categoria = fopen("categorias.txt", "r")) == NULL) 
	{ 
	printf ( " Error en la apertura. Es posible que el fichero no exista. \n");
	}
	i=0;
	while(fscanf(fich_categoria,"%s %c %d %d %f",t_categorias[i].nombre,
	&t_categorias[i].sexo,&t_categorias[i].edadmin,&t_categorias[i].edadmax,&t_categorias[i].precio)==5)
	{
		i++;
	}
	fclose(fich_categoria);
	return(i);
}
//funcion cargar corredores
int cargar_corredores(corredor t_corredores[],int numCategorias,categoria t_categorias[])
{
	int i,j;
	FILE* fich_corredor;
	if ((fich_corredor = fopen("corredores_5000.txt", "r")) == NULL) 
	{ 
	printf ( " Error en la apertura. Es posible que el fichero no exista. \n");
	}
	i=0; 
	while(fscanf(fich_corredor,"%s %s %s %d %d %s %c %d %d %d ",t_corredores[i].nombre,t_corredores[i].apellido1,
	t_corredores[i].apellido2,&t_corredores[i].edad,&t_corredores[i].dorsal,t_corredores[i].club,
	&t_corredores[i].sexo,&t_corredores[i].horas,&t_corredores[i].minutos,&t_corredores[i].segundos)==10)
	{
	for (j=0;j<numCategorias;j++)
	{
	
		if (t_corredores[i].edad>=t_categorias[j].edadmin&&t_corredores[i].edad<=t_categorias[j].edadmax&&t_corredores[i].sexo==t_categorias[j].sexo)//corregir edad max >= y sexo 5/12
			{
				strcpy(t_corredores[i].nom_categoria, t_categorias[j].nombre);
			}
			
	}
	i++;
	}
	fclose(fich_corredor);
	
	return(i); 
}
//funcion cargar tracks

int cargar_tracks(int numDorsal,float latitudes[],float longitudes[],int alturas[])
{
	int i=0;
	char charDorsal[10];
	sprintf(charDorsal,"%d",numDorsal);
	FILE* fich_tracks;
	if ((fich_tracks = fopen(charDorsal, "r")) == NULL) 
	{ 
	printf ( " Error en la apertura. Es posible que el fichero no exista. \n");
	}
	while(fscanf(fich_tracks,"%f %f %d",&latitudes[i],&longitudes[i],&alturas[i])==3)
	{
		i++;
	}
	fclose(fich_tracks);
	
	return (i);
}
//funcion menu
int menu()
{
	int accion,i;
	accion=-1;
	while (accion!=10)
	{
		printf("-----------------------------------------------------------------------------------\n"
	       "-------------------------------------MENU------------------------------------------\n"
		   "-----------------------------------------------------------------------------------\n"
		   "\n"
		   "1. Informacion de un corredor.\n"
		   "2. Eliminar un corredor.\n"
		   "3. Distancia recorrida y velocidad media de un corredor.\n"
		   "4. Exportar el recorrido de un corredor a formato KML.\n"
		   "5. Gestionar el transporte de los corredores de un club.\n"
		   "6. Coste de las inscripciones de un club.\n"
		   "7. Mostrar los corredores que han abandonado la carrera.\n"
		   "8. Clasificacion total.\n"
		   "9. Clasificacion de una categoria.\n"
		   "10. Salir.\n"
		   "             OPCION DESEADA: ");
			scanf("%d",&accion);
		if(accion>0&&accion<10)
		{
			return (accion)	;
		}
		else if(accion!=10)
		{
			printf("Opcion no valida\n");
		}
		
	}
}
// funcion buscar corredor
int buscar_corredor_por_dorsal(corredor t_corredores[],int numCorredores,int numDorsal)
{
	int i,encontrado;
	encontrado=-1;
	for (i=0;i<numCorredores;i++)
	{
		if(t_corredores[i].dorsal==numDorsal)
		{
		encontrado=i;
		}
	}
	if (encontrado!=-1)
	{
		return (encontrado);
	}
	else
	{
		return(-1);
	}
	
}

// funcion buscar categoria


//mostrar informacion de corredor opcion 1
void mostrar_informacion_corredor(corredor t_corredores[],int numCorredores,int numDorsal)
{
	int i;
	i=buscar_corredor_por_dorsal(t_corredores,numCorredores,numDorsal);
	if(i!=-1)
	{
	
	printf("Nombre: %s\nApellidos: %s %s\nEdad: %d\nClub: %s\nSexo: %c\nCategoria: %s",t_corredores[i].nombre,t_corredores[i].apellido1,t_corredores[i].apellido2,t_corredores[i].edad,t_corredores[i].club,t_corredores[i].sexo,t_corredores[i].nom_categoria);
	}
	else
	{
		printf("Error\n");
	}

}

float calcular_distancia(int numDorsal,float latitudes[],float longitudes[],float lat1,float lon1,float lat2,float lon2,int numTracks)
{
	float deg2radMultiplier = PI / 180,dist,distanciaTotal=0;
	int i;
	for(i=0;i<numTracks-1;i++)
		{
			lat1=latitudes[i];lat2=latitudes[i+1];lon1=longitudes[i];lon2=longitudes[i+1];
			lat1 = lat1 * deg2radMultiplier;
			lon1 = lon1 * deg2radMultiplier;
			lat2 = lat2 * deg2radMultiplier;
			lon2 = lon2 * deg2radMultiplier;
			float radius = 6378.137;
			float dlon = lon2 - lon1;
			float distance = acos( sin(lat1) * sin(lat2)+  cos(lat1) * cos(lat2) * cos(dlon)) * radius; 
			distanciaTotal=distance+distanciaTotal;
		}
			return(distanciaTotal);
}
float calcular_tiempo(corredor t_corredores[],int numDorsal,int numCorredores);

void mostrar_distancia_y_media(float lat1, float lon1, float lat2, float lon2,int numDorsal, float latitudes[], float longitudes[], corredor t_corredores[],int numCorredores,int numTracks)
{ 
float distancia,tiempo,media;
distancia=calcular_distancia(numDorsal,latitudes,longitudes,lat1,lon1,lat2,lon2,numTracks);
tiempo=calcular_tiempo(t_corredores,numDorsal,numCorredores);
printf("\nLa distancia recorrida es %f \n",distancia);
if(tiempo==0)
{
	printf("El corredor no ha finalizado la carrera\n");
}
else
{
	printf("El tiempo invertido es %f\n",tiempo);
	media=distancia/tiempo;
	printf("La velocidad media es %f km/h\n",media);
}

}
//calcular tiempo prueba
float calcular_tiempo(corredor t_corredores[],int numDorsal,int numCorredores)
{
	int posicion;
	float minutos,segundos,tiempo;
	posicion=buscar_corredor_por_dorsal(t_corredores,numCorredores,numDorsal);
	minutos=t_corredores[posicion].minutos;
	segundos=t_corredores[posicion].segundos;
	printf("la posicion es %d \n",posicion);
	tiempo=t_corredores[posicion].horas+((minutos)/60)+((segundos)/3600);

	return(tiempo);
}
//funcion 5
int numero_corredores_club(corredor t_corredores[],int numCorredores,char nombreClub[])
{
	int i=0,contador=0;
	while(i<numCorredores)
	{
		if(strcmp(t_corredores[i].club,nombreClub)==0)
		{
			contador++;
			i++;
		}
		else
		{
			i++;
		}
	}
	return(contador);
}

void gestionar_transporte(corredor t_corredores[],int numCorredores)
{
	int numCorredoresClub,autobus=0,minibus=0,coche=0;
	float numCorr;
	char nombreClub[MAX];
	printf("Introduce el nombre de un club:");
	fflush(stdin);
	gets(nombreClub);
	numCorredoresClub=numero_corredores_club(t_corredores,numCorredores,nombreClub);
	if(numCorredoresClub!=0)
	{
		numCorr=numCorredoresClub;
	if (numCorr/50>1){
		autobus=numCorr/50;
		numCorr=fmod(numCorr,50);
		if(numCorr/20>1){
			minibus=numCorr/20;
			numCorr=fmod(numCorr,20);
			if(numCorr/5>1)
			{
				coche=numCorr/5;
				coche=coche+1;
			}
		}
		
		
	}
	else
	{
		if(numCorr/20>1){
			minibus=numCorr/20;
			numCorr=fmod(numCorr,20);
			if(numCorr/5>1)
			{
				coche=numCorr/5;
				coche=coche+1;
			}
		}
		else
		{
			if(numCorr/5>1)
			{
				coche=numCorr/5;
				coche=coche+1;
			}
			else
			{
				coche=1;
			}
		}
	}
	
	printf("Autobuses %d Minibus %d Coches %d \n",autobus,minibus,coche);
	}
	else
	{
		printf("Error\n");
	}
	
 
}

//eliminar corredor
int eliminar_corredor(corredor t_corredores[], int numCorredores, int numDorsal)
{
	int posicion,i;
	  // solo necesitamos almacenar una estructura no un array de estructuras
	posicion= buscar_corredor_por_dorsal( t_corredores, numCorredores, numDorsal);
	if (posicion==-1)
	 {
	 	printf("No existe ningun corredor con el dorsal %d",numDorsal);
	 }
	 else
	 {
	 
	for(i=posicion;i<numCorredores;i++) // el ultimo numero en testear deberia ser uno antes del final del array, el signo debe ser < no <=
	{
		t_corredores[i]=t_corredores[i+1]; // copiamos en una estructura no en un array de estructuras
		
	}
printf("Se ha borrado el corredor con el dorsal %d \n",numDorsal);
}
return(numCorredores-1);
system("pause");
}

//ordenar tabla de clasificacion

void ordenar_tabla(corredor t_corredores[], int numCorredores)
{
	int i,j,dorsal1,dorsal2;
	float tiempo1,tiempo2,minutos1,minutos2,segundos1,segundos2;
	corredor aux;
	for(i=0;i<numCorredores;i++)
	{
		for(j=0;j<numCorredores-1;j++)
		{
			
			minutos1=t_corredores[j].minutos;
			segundos1=t_corredores[j].segundos;
			tiempo1=t_corredores[j].horas+((minutos1)/60)+((segundos1)/3600);
			minutos2=t_corredores[j+1].minutos;
			segundos2=t_corredores[j+1].segundos;
			tiempo2=t_corredores[j+1].horas+((minutos2)/60)+((segundos2)/3600);
			if(tiempo2<tiempo1)
			{
  				aux=t_corredores[j];
  				t_corredores[j]=t_corredores[j+1];
  				t_corredores[j+1]=aux;
  			}
  			if (tiempo1==tiempo2)
  			{
  				if(t_corredores[j+1].dorsal<t_corredores[j].dorsal)
  				{
  					aux=t_corredores[j];
  					t_corredores[j]=t_corredores[j+1];
  					t_corredores[j+1]=aux;
				}
			}
		}
	}
	for(j=0;j<numCorredores-1;j++){
	if(t_corredores[0].horas==0){
	
	aux=t_corredores[0];
	for(i=0;i<numCorredores-1;i++)
	{
		t_corredores[i]=t_corredores[i+1];
			
	}
		t_corredores[numCorredores-1]=aux;
	}
	}
	
	for(i=0;i<numCorredores;i++)
	{
		printf("\n%s,%d,%d:%d:%d",t_corredores[i].nombre,t_corredores[i].dorsal,t_corredores[i].horas,t_corredores[i].minutos,t_corredores[i].segundos);
	}
}

//exportar el recorrido de un corredor
void exportar_a_KML(corredor t_corredores[],int numDorsal,float latitudes[],float longitudes[],int alturas[],int numCorredores)
{
	int dorsal,num,entrada,i;
	char numDorsalString[100];
	sprintf(numDorsalString,"%d",numDorsal);
	strcat(numDorsalString,".kml");
	dorsal=cargar_tracks(numDorsal,latitudes,longitudes,alturas);
	num=buscar_corredor_por_dorsal(t_corredores,numCorredores,numDorsal);
	
	if(num!=-1){
		
		
		
		FILE*entrada;
		entrada=fopen (numDorsalString,"w");
		
		fprintf(entrada,"<?xml version=”1.0? encoding=”UTF-8??>\n"
						"<Placemark>\n"
						"<name>Recorrido de: ");
		fclose(entrada);
		entrada=fopen (numDorsalString,"a");				
		fprintf(entrada,"%s %s %s",t_corredores[num].nombre,t_corredores[num].apellido1,t_corredores[num].apellido2);
		fclose(entrada);
		entrada=fopen (numDorsalString,"a");				
		fprintf(entrada,"</name>\n"
						"<description>Recorrido del corredor %s %s %s durante la\n"
						"Bilbao Night Marathon 2018</description>\n"
						"<Style><LineStyle><color>ff0000FF</color><width>3</width></LineStyle></Style>\n"
						"<LineString>\n"
						"<coordinates>\n",t_corredores[num].nombre,t_corredores[num].apellido1,t_corredores[num].apellido2);
		fclose(entrada);
		for(i=0;i<dorsal;i++)								
		{
			entrada=fopen (numDorsalString,"a");				
			fprintf(entrada,"%f %f %d\n",latitudes[i],longitudes[i],alturas[i]);
			fclose(entrada);
		}
		entrada=fopen (numDorsalString,"a");
		
		fprintf(entrada,"</coordinates>\n"
						"</LineString>\n"	
						"</Placemark>\n");
		fclose(entrada);
		printf("\nSe ha generado el fichero %d.kml\n ",numDorsal);
				
		}
	else{
		
		printf("El corredor no existe");
	}
}
//funcion 6
// funcion buscar categoria
int buscar_categoria (categoria t_categorias[],int numCategorias,char nombreCategoria[])
{
	int i=0,esIgual;
	esIgual=-1;
	while(i<numCategorias&&esIgual!=0)
	{
		esIgual=strcmp(t_categorias[i].nombre,nombreCategoria);
		i++;
	}
	if(esIgual==0){
	return(i-1);
	}
	else
	{
		return NULL; 
	}
	
		
}

//calcular precio
float coste_inscripciones_club(categoria t_categorias[],int numCategorias,corredor t_corredores[],int numCorredores){
	char nombreClub[MAX],nombreCategoria[MAX];
	float precio = 0,z;
	int i,parecido;
	printf("Introduce el nombre de un club: ");
	fflush(stdin);
	scanf("%s",nombreClub);
	for(i=0;i<numCorredores;i++){
		parecido = strcmp(nombreClub,t_corredores[i].club);
		if(parecido==0){
			strcpy(nombreCategoria, t_corredores[i].nom_categoria);
			z=t_categorias[buscar_categoria(t_categorias,numCategorias,nombreCategoria)].precio;
			precio=precio+z;
		}
	}
	if(precio != 0){
	printf("El precio total del club %s es %.2f\n",nombreClub,precio);
	}
	else{
		printf("ERROR el club introducido no existe\n");
	}
}

//para funcion 9

int filtrar_corredores(corredor t_corredores[], int numCorredores, corredor t_adecuados[],char nombreCategoria[])
{
	int i,j=0;
	for (i=0;i<numCorredores;i++)
	{
		if(strcmp(t_corredores[i].nom_categoria,nombreCategoria)==0)
		{
			t_adecuados[j]=t_corredores[i];
			j++;
		}

	}
	return (j);
	
}
//funcion 7
void mostrar_abandonos(corredor t_corredores[], int numCorredores)
{
	int i,numAbandonos=0;
	float minutos,segundos,tiempo;
	printf("Han abandonado los siguientes corredores: \n");
	for(i=0;i<numCorredores;i++)
	{
		minutos=t_corredores[i].minutos;
		segundos=t_corredores[i].segundos;
		tiempo=t_corredores[i].horas+((minutos)/60)+((segundos)/3600);
		if(tiempo==0)
		{
			printf("%s %s %s (dorsal %d)\n",t_corredores[i].nombre,t_corredores[i].apellido1,t_corredores[i].apellido2,t_corredores[i].dorsal);
			numAbandonos++;
		}
	}
	printf("En total han habido %d abandonos\n",numAbandonos);
}


//funcion 9
void clasificacion_categoria(corredor t_corredores[], int numCorredores)
{
	int numAptos,i,j;
	char nombreCategoria[MAX];
	float minutos1,segundos1,tiempo1,minutos2,segundos2,tiempo2;
	corredor t_adecuados[MAX_CORR], aux;
	FILE* fich_categoria;
	printf("Ingrese la categoria de la que desea ver su clasificacion: ");
	fflush(stdin);
	gets(nombreCategoria);
	numAptos=filtrar_corredores(t_corredores,numCorredores,t_adecuados,nombreCategoria);
	for(i=0;i<numAptos;i++)
	{
		for(j=0;j<numAptos-1;j++)
		{
			
			minutos1=t_adecuados[j].minutos;
			segundos1=t_adecuados[j].segundos;
			tiempo1=t_adecuados[j].horas+((minutos1)/60)+((segundos1)/3600);
			minutos2=t_adecuados[j+1].minutos;
			segundos2=t_adecuados[j+1].segundos;
			tiempo2=t_adecuados[j+1].horas+((minutos2)/60)+((segundos2)/3600);
			if(tiempo2<tiempo1)
			{
  				aux=t_adecuados[j];
  				t_adecuados[j]=t_adecuados[j+1];
  				t_adecuados[j+1]=aux;
  			}
  			if (tiempo1==tiempo2)
  			{
  				if(t_adecuados[j+1].dorsal<t_adecuados[j].dorsal)
  				{
  					aux=t_adecuados[j];
  					t_adecuados[j]=t_adecuados[j+1];
  					t_adecuados[j+1]=aux;
				}
			}
		}
	}
	for(j=0;j<numAptos-1;j++){
	if(t_adecuados[0].horas==0){
	
	aux=t_adecuados[0];
	for(i=0;i<numAptos-1;i++)
	{
		t_adecuados[i]=t_adecuados[i+1];
			
	}
		t_adecuados[numAptos-1]=aux;
	}
	}
		
	strcat(nombreCategoria,".txt");
	fich_categoria = fopen(nombreCategoria, "w");
	for(i=0;i<numAptos;i++)
	{
	fprintf(fich_categoria,"%s %d %d %d %d\n",t_adecuados[i].nombre,t_adecuados[i].dorsal,t_adecuados[i].horas,t_adecuados[i].minutos,t_adecuados[i].segundos);
	}	
	fclose(fich_categoria);
}

int main(void)
{
	int numCategorias,numCorredores,numMenu,numDorsal,alturas[MAXTRACKPOINTS],numTracks,i;
	categoria t_categorias[MAX_CAT];
	corredor t_corredores[MAX_CORR];
	numCategorias=cargar_categorias(t_categorias);
	numCorredores= cargar_corredores(t_corredores,numCategorias,t_categorias);
	float longitudes[MAXTRACKPOINTS],latitudes[MAXTRACKPOINTS],dist,distanciaTotal=0,tiempo,lat1,lon1,lat2,lon2;
	do
	{
	numMenu=menu();
	if(numMenu==1)
	{
		printf("Introduce el dorsal del corredor que deseas ver: ");
		scanf("%d",&numDorsal);
		mostrar_informacion_corredor(t_corredores,numCorredores,numDorsal);
		printf("\n");
		system("pause");
	}
	if (numMenu==2)
	{
		printf("Introduce el numero del dorsal del jugador que desea eliminar:");
	    scanf("%d",&numDorsal);
	    eliminar_corredor(t_corredores,numCorredores,numDorsal);
	    printf("\n");
		system("pause");
	}
	if(numMenu==3)
	{
		printf("Introduce el dorsal : ");
		scanf("%d",&numDorsal);
		numTracks=cargar_tracks(numDorsal,latitudes,longitudes,alturas);
		mostrar_distancia_y_media(lat1,lon1,lat2,lon2,numDorsal,latitudes,longitudes,t_corredores,numCorredores,numTracks);
		system("pause");
	}
	if(numMenu==4)
	{
		printf("Introduce el dorsal : ");
		scanf("%d",&numDorsal);
		exportar_a_KML(t_corredores,numDorsal,latitudes,longitudes,alturas,numCorredores);
		system("pause");
	}
	if(numMenu==5)
	{
		gestionar_transporte(t_corredores,numCorredores);
			
		system("pause");
	}
	if(numMenu==6){
		char nombreCategoria[MAX];
		coste_inscripciones_club(t_categorias,numCategorias,t_corredores,numCorredores);
		system("pause");
	}
	if(numMenu==7)
	{
		mostrar_abandonos(t_corredores,numCorredores);
		system("pause");
	}
		if(numMenu==8)
	{
		ordenar_tabla(t_corredores,numCorredores);
		system("pause");
	}
	if(numMenu==9)
	{
		clasificacion_categoria(t_corredores,numCorredores);
		system("pause");
	}
	}
	while(numMenu!=10&&numMenu>0&&numMenu<10);
}
