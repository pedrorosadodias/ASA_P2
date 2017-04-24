/********************************************
* IST ASA -> Proj 2                         *
* @autor Catarina Coelho 84706              *
* @autor Pedro Dias 84752                   *
********************************************/

#include <stdio.h>
#include <stdlib.h>


/*  struct of a node  */
typedef struct city {
    
} *Pcity;


static Pcity *graph;    /*pointer for the table of cities*/
int NCities;            /*number of cities*/
int NmaxAirports;       /*number max of airports*/
int NmaxRoads;          /*number max of roads*/
int TotalCost;          /*total cost*/
int NRoads;             /*number of roads -> output*/
int NAirports;          /*number of airports -> output*/
int Airports[];

/*  Headers  */



int main (){
    /*  Initializations */
    TotalCost = 0;
    NAirports = 0;
    NRoads = 0;


    int i, city1, city2, cost;

    scanf("%d",&NCities);
    scanf("%d",&NmaxAirports);
        int Airports[NmaxAirports];
        int VecSize = ((NmaxAirports - 1) * NmaxAirports)/2;
        int AirCosts[VecSize];

    for (i = 0; i < NmaxAirports; i++){
        scanf("%d %d", &city1, &cost);
        /* city1-> aeroporto na cidade city1   /   cost->custo de construção do aeroporto na cidade city1*/
    }

    scanf("%d",&NmaxRoads);

    for (i = 0; i < NmaxRoads; i++){
        scanf("%d %d %d", &city1, &city2, &cost);
        /* city1-> cidade1  /   city2-> cidade2   /   cost->custo de construção da estrada*/
    }


    return 0;
}







/*  Esquecer a partir daqui, mas n tirar pode ser necessário    */



/*  Initializations of Table & vector of final order -> sources  */
void initData(int n){
    int i;
    graph = (node*) malloc(sizeof(node) * n);
    order = (int*) malloc(sizeof(int) * n);
    for(i = 0; i < n; i++){
        graph[i] = newPhoto(i + 1);
        order[i] = 0;
    }
}


/*  Delete all data created  */
void deleteData(int tam){
    int i;
    Pphoto item, next;
    for (i = 0; i < tam; i++){
        for(item = graph[i]; item != NULL; item = next ){
            next = item->next;
            free(item);
        }
    }
    free(graph);
    free(order);
}


/*  Insert new photo on the graph  */
void insertPhoto(int source, int destiny){
    Pphoto new = newPhoto(destiny);
    new->next = graph[source - 1]->next;
    graph[source - 1]->next = new;
}


/*  Create new photo  */
Pphoto newPhoto (int photo){
    Pphoto new = (Pphoto) malloc(sizeof(struct photo));
    new->photoNumber = photo;
    new->state = NOT_VISITED;
    new->startTime = 0;
    new->endTime = 0;
    new->next = NULL;
    return new;
}
