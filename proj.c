/********************************************
* IST ASA -> Proj 2                         *
* @autor Catarina Coelho 84706              *
* @autor Pedro Dias 84752                   *
********************************************/

#include <stdio.h>
#include <stdlib.h>

#define BASE 0

/*  struct of a connection  */
typedef struct connection {
    int city1;
    int city2;
    int cost;
} *Pconnection;


int NCities;            /*number of cities*/
int NRoads;             /*number of roads -> output*/
int NAirports;          /*number of airports -> output*/
int TotalCost;          /*total cost*/


/*  Headers  */
Pconnection newConnection (int city1, int city2, int cost);
int cmpfunction(const void* a, const void* b);



int main (){

    /*  Initializations */
    NRoads = 0;
    NAirports = 0;
    TotalCost = 0;

    int NmaxAirports;       /*number max of airports*/
    int NmaxRoads;          /*number max of roads*/
    int i, city1, city2, cost;

    scanf("%d",&NCities);
    scanf("%d",&NmaxAirports);

    Pconnection *airportsData = (Pconnection*) malloc(sizeof(struct connection) * NmaxAirports);

    for (i = 0; i < NmaxAirports; i++){
        scanf("%d %d", &city1, &cost);
        Pconnection new = newConnection(BASE, city1, cost);
        airportsData[i] = new;
    }


    scanf("%d",&NmaxRoads);
    Pconnection *data = (Pconnection*) malloc(sizeof(struct connection) * (NmaxAirports + NmaxRoads));

    for (i = 0; i < NmaxRoads; i++){
        scanf("%d %d %d", &city1, &city2, &cost);
        Pconnection new = newConnection(city1, city2, cost);
        data[i] = new;
    }

    /*  copy information of airportsData to data    */
    for (i = NmaxRoads; i < (NmaxAirports + NmaxRoads); i++){
        data[i] = airportsData[i - NmaxRoads];
        airportsData[i - NmaxRoads] = NULL;
    }
    free(airportsData);



    /*      DEBUGING    */
    for(i = 0; i < (NmaxAirports + NmaxRoads); i++){
        printf("city1: %d city2: %d cost: %d\n", data[i]->city1, data[i]->city2, data[i]->cost);
    }
    puts("---------------------------");
    /*  Sort vector data based on the cost   */
    qsort(data, NmaxAirports + NmaxRoads, sizeof(Pconnection), cmpfunction);


    /*      DEBUGING    */
    for(i = 0; i < (NmaxAirports + NmaxRoads); i++){
        printf("city1: %d city2: %d cost: %d\n", data[i]->city1, data[i]->city2, data[i]->cost);
    }

    return 0;
}


int cmpfunction(const void* a, const void* b){

	const Pconnection p1 = *(const Pconnection *)a;
	const Pconnection p2 = *(const Pconnection *)b;

	return (p1->cost - p2->cost);
}



/*  Create new connection  */
Pconnection newConnection (int city1, int city2, int cost){
    Pconnection new = (Pconnection) malloc(sizeof(struct connection));
    new->city1 = city1;
    new->city2 = city2;
    new->cost = cost;
    return new;
}
