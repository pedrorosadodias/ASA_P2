/********************************************
* IST ASA -> Proj 2                         *
* @autor Catarina Coelho 84706              *
* @autor Pedro Dias 84752                   *
********************************************/

#include <stdio.h>
#include <stdlib.h>


/*  struct of a node  */
typedef struct connection {
    int city1;
    int city2;
    int cost;
} *Pconnection;


int NCities;            /*number of cities*/
int NmaxAirports;       /*number max of airports*/
int NmaxRoads;          /*number max of roads*/
int TotalCost;          /*total cost*/
int NRoads;             /*number of roads -> output*/
int NAirports;          /*number of airports -> output*/
int r, l;

/*  Headers  */
Pconnection newConnection (int city1, int city2, int cost);
int cmpfunction(const void* a, const void* b);



int main (){
    /*  Initializations */
    TotalCost = 0;
    NAirports = 0;
    NRoads = 0;


    int i, j, k, city1, city2, cost;

    scanf("%d",&NCities);
    scanf("%d",&NmaxAirports);
    
    int Airports[NCities]; /*vetor dos aeroportos de cada cidade*/
    int AirCitys[NmaxAirports]; /*vetor das cidades que tem aeorportos*/
    int VecSize = ((NmaxAirports - 1) * NmaxAirports)/2;
    Pconnection* AirCosts = (Pconnection*) malloc(sizeof(struct connection) * VecSize); /*vetor dos custos de construção de aeroportos entre duas cidades*/


    for (i = 0; i < NmaxAirports; i++){
        scanf("%d %d", &city1, &cost);
        Airports[city1 - 1] = cost;
        AirCitys[i] = city1;
        /* city1-> aeroporto na cidade city1   /   cost->custo de construção do aeroporto na cidade city1*/
    }

    scanf("%d",&NmaxRoads);
    Pconnection* RoadCosts = (Pconnection*) malloc(sizeof(struct connection) * NmaxRoads);

    for (i = 0; i < NmaxRoads; i++){
        scanf("%d %d %d", &city1, &city2, &cost);
            Pconnection new = newConnection(city1, city2, cost);
            RoadCosts[i] = new;
            

       /* city1-> cidade1  /   city2-> cidade2   /   cost->custo de construção da estrada entre city1 e city2*/
    }




    if (NmaxAirports > 1){
    	k = VecSize;
    	for(i = 0; i < NmaxAirports - 1; i++){
    		for(j = i + 1; j < NmaxAirports; j++){
    			int pos1 = AirCitys[i] - 1;
    			int pos2 = AirCitys[j] - 1;
    			int cost = Airports[pos1] + Airports[pos2];
    			Pconnection new = newConnection(AirCitys[i], AirCitys[j], cost);
    			AirCosts[--k] = new;
    		}
    	}
    }

for(i=0; i<NmaxAirports; i++){
   printf("city1: %d city2: %d cost: %d\n", AirCosts[i]->city1, AirCosts[i]->city2, AirCosts[i]->cost);
}

for(i=0; i<NmaxRoads; i++){
   printf("city1: %d city2: %d cost: %d\n", RoadCosts[i]->city1, RoadCosts[i]->city2, RoadCosts[i]->cost);
}

    qsort(RoadCosts, NmaxRoads, sizeof(Pconnection), cmpfunction);
    qsort(AirCosts, NmaxAirports, sizeof(Pconnection), cmpfunction);

for(i=0; i<NmaxAirports; i++){
   printf("city1: %d city2: %d cost: %d\n", AirCosts[i]->city1, AirCosts[i]->city2, AirCosts[i]->cost);
}

for(i=0; i<NmaxRoads; i++){
   printf("city1: %d city2: %d cost: %d\n", RoadCosts[i]->city1, RoadCosts[i]->city2, RoadCosts[i]->cost);
}   




    return 0;
}


int cmpfunction(const void* a, const void* b){

	const Pconnection p1 = *(const Pconnection *)a;
	const Pconnection p2 = *(const Pconnection *)b;

	return(p1->cost - p2->cost);
}
/*  Create new connection  */
Pconnection newConnection (int city1, int city2, int cost){
    Pconnection new = (Pconnection) malloc(sizeof(struct connection));
    new->city1 = city1;
    new->city2 = city2;
    new->cost = cost;
    return new;
}




