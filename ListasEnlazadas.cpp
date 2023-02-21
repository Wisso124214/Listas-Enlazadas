#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct nodo{

    int dato;
    struct nodo * siguiente;

}NODO;

 NODO * CrearNodo(int dato);
 int InsertarInicio(NODO **cabeza, int dato);
 int InsertarFinal(NODO **cabeza, int dato);
 void ImprimirLista(NODO *cabeza);
 int EstaVacia(NODO *cabeza);
 int ExisteElemento(NODO *, int dato);

 
int main (){

    NODO *cabeza=NULL;
    int res;
    int i=0, cont=0;
 	char c;
	
	if(EstaVacia(cabeza))
		printf("La lista esta vacia...");
	else
		printf("La lista NO está vacia...");
		
	printf("\n\n");
	
	printf("Ingrese la cedula de identidad (unicamente los caracteres validos son los numericos. Cuando termine introduzca \"+\"):\n\n");
	
	do{	
		c=getch();
		if(c!='+'){
			i=(int)c-48;
			
//			if(InsertarFinal(&cabeza,i))
//				printf("%d",i);
			
			if(cont==0){
				InsertarInicio(&cabeza,i);
				printf("%d",i);
				cont++;
			}else{
				InsertarFinal(&cabeza,i);
				printf("%d",i);
				cont++;
			}
		}
		
	}while(c!='+');

	printf("\n\nLuis Bustos\nCI: ");
	
    ImprimirLista(cabeza);
    
    printf("\n\n");
    
    if(EstaVacia(cabeza))
		printf("La lista esta vacia...");
	else
		printf("La lista NO esta vacia...");
    
    printf("\n\nIngrese el caracter para comparar si se encuentra en la lista enlazada: ");
	scanf("%d",&i);
	

    if(ExisteElemento(cabeza, i)){
        printf("\nEl caracter esta en la lista ...");
    }else{
        printf("\nEl caracter NO esta en la lista ...");
    }

    return 0 ;
}

NODO *CrearNodo(int dato){

    NODO *nuevo=NULL;

    nuevo = (NODO*)malloc (sizeof(NODO));

    if (nuevo != NULL){
        nuevo ->dato = dato;
        nuevo ->siguiente = NULL;
    }
    
    return nuevo;
}
 int InsertarInicio(NODO **cabeza, int dato){

     NODO  *nuevo = NULL;
     nuevo = CrearNodo(dato);
     if(nuevo != NULL){
        nuevo ->siguiente = *cabeza;
        *cabeza =nuevo;
        return 1;
     }

     return 0 ;
}

void ImprimirLista(NODO *cabeza){

    NODO *nAux = cabeza;
	int cont=0;
	
    while(nAux != NULL){
        cont++;
		printf("%i", nAux ->dato);
        nAux= nAux ->siguiente;
        
        if(cont==2 || cont==5){
        	printf(".");
		}
    }
  }

int InsertarFinal(NODO **cabeza, int dato){

   NODO *nuevo = NULL;
   NODO *nAux= *cabeza;

   nuevo = CrearNodo(dato);
   if( nuevo != NULL){
        while(nAux ->siguiente!=NULL){
            nAux  = nAux ->siguiente;
        }
        nAux ->siguiente= nuevo;
        
        return 1;
   }

   return 0 ;
   }


int EstaVacia(NODO *cabeza){
    if(cabeza == NULL){
        return 1;
    }else {
        return 0;
    }
}

 int ExisteElemento(NODO * cabeza, int dato){
    NODO *nAux = cabeza;

    while(nAux != NULL){
        if(nAux ->dato== dato){
            return 1;
        }
        nAux  = nAux ->siguiente;
    }

    return 0 ;
 }