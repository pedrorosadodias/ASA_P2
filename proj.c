/********************************************
* IST ASA -> Proj 2                         *
* @autor Catarina Coelho 84706              *
* @autor Pedro Dias 84752                   *
********************************************/

#include <stdio.h>
#include <stdlib.h>

#define BASE 0
#define OK 0
#define INSUFICIENTE 1

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
int Flag;
int airportSingleCost;  /*in case there is just one airport*/


/*  Headers  */
Pconnection newConnection (int city1, int city2, int cost);
int cmpfunction(const void* a, const void* b);
void Kruskal(Pconnection* graph, int V, int E, int flagI);
void visit(int city1, int city2, int verify[], int flagI);
void makeSet(int vertix, int p[], int rank[], int flagI);
int findSet(int vertix, int p[], int rank[], int flagI);
void Union(int vertix1, int vertix2, int p[], int rank[], int flagI);
void Link(int vertix1, int vertix2, int p[], int rank[], int flagI);
void deleteData(int NmaxAirports, int NmaxRoads, Pconnection *airportsData,Pconnection *data, Pconnection *test);



int main (){

    int NmaxAirports;       /*number max of airports*/
    int NmaxRoads;          /*number max of roads*/
    int i, city1, city2, cost;
    int Naeroportos, Nestradas, custo, teste;

    /*  Initializations */
    NRoads = 0;
    NAirports = 0;
    TotalCost = 0;
    Flag = OK;

    scanf("%d",&NCities);
    scanf("%d",&NmaxAirports);

    Pconnection *airportsData = (Pconnection*) malloc(sizeof(struct connection) * NmaxAirports);

    for (i = 0; i < NmaxAirports; i++){
        scanf("%d %d", &city1, &cost);
        airportsData[i] = newConnection(BASE, city1, cost);
    }

    scanf("%d",&NmaxRoads);
    Pconnection *data = (Pconnection*) malloc(sizeof(struct connection) * (NmaxAirports + NmaxRoads));

    Pconnection *test = (Pconnection*) malloc(sizeof(struct connection) * NmaxRoads);

    for (i = 0; i < NmaxRoads; i++){
        scanf("%d %d %d", &city1, &city2, &cost);
        Pconnection new = newConnection(city1, city2, cost);
        data[i] = new;
        test[i] = new;
    }

    /*  copy information of airportsData to data    */
    for (i = NmaxRoads; i < (NmaxAirports + NmaxRoads); i++){
        data[i] = airportsData[i - NmaxRoads];
        airportsData[i - NmaxRoads] = NULL;
    }

    Kruskal(test, NCities, NmaxRoads, 1);
    Naeroportos = NAirports;
    Nestradas = NRoads;
    custo = TotalCost;
    teste = Flag;

    if (NmaxAirports > 0){
        Kruskal(data, NCities + 1, NmaxAirports + NmaxRoads, BASE);
    }

    if ((custo == TotalCost) && (teste != INSUFICIENTE)){
        printf("%d\n%d %d\n", custo, Naeroportos, Nestradas);
    }
    else{
        if((Flag != INSUFICIENTE) && (NAirports > 1)){
            printf("%d\n%d %d\n", TotalCost, NAirports, NRoads);
        }
        else if ((Flag != INSUFICIENTE) && (NAirports == 1)){
            TotalCost -= airportSingleCost;
            NAirports--;
            printf("%d\n%d %d\n", TotalCost, NAirports, NRoads);
        }
        else{puts("Insuficiente");}
    }

    deleteData(NmaxAirports, NmaxRoads, airportsData, data, test);
    return 0;
}



/*  Create new connection  */
Pconnection newConnection (int city1, int city2, int cost){
    Pconnection new = (Pconnection) malloc(sizeof(struct connection));
    new->city1 = city1;
    new->city2 = city2;
    new->cost = cost;
    return new;
}



/*  Delete all data created */
void deleteData(int NmaxAirports, int NmaxRoads, Pconnection *airportsData,Pconnection *data, Pconnection *test){
    int i;
    for (i = 0; i < (NmaxAirports + NmaxRoads); i++){
        free(data[i]);
    }
    free(data);
    free(test);
    free(airportsData);
}



/*  Kruskal Algorithm */
void Kruskal(Pconnection* graph, int V, int E, int flagI){

	int rank[V];
    int p[V];
    int i;
    int verify[V];
    int visited = 1;

    /*  Initializations */
    NRoads = 0;
    NAirports = 0;
    TotalCost = 0;
    Flag = OK;

    for(i = 0; i < V; i++){
        makeSet(i, p, rank, flagI);
        verify[i] = 0;
    }

    /*  Sort vector data based on the cost   */
    qsort(graph, E, sizeof(Pconnection), cmpfunction);

    for(i = 0; i < E; i++){
        int city1, city2, cost;
        city1 = graph[i]->city1;
        city2 = graph[i]->city2;
        cost = graph[i]->cost;

        if (findSet(city1, p, rank, flagI) != findSet(city2, p, rank, flagI)){

            if(city1 == BASE){
                NAirports++;
                airportSingleCost = cost;
            }
            else{
                NRoads++;
            }

            TotalCost += cost;
            Union(city1, city2, p, rank, flagI);
            visit(city1, city2, verify, flagI);
        }
    }

    /*Verify INSUFICIENTE case*/
    for(i = 0; i < V; i++){
        if (verify[i] != visited){
            Flag = INSUFICIENTE;
            break;
        }
    }
}



void visit(int city1, int city2, int verify[], int flagI){
    int visited = 1;
    if (flagI == BASE){
        verify[city1] = visited;
        verify[city2] = visited;
    }
    else{
        verify[city1 - flagI] = visited;
        verify[city2 - flagI] = visited;
    }
}



void makeSet(int vertix, int p[], int rank[], int flagI){
    p[vertix] = vertix + flagI;
    rank[vertix] = 0;
}



int findSet(int vertix, int p[], int rank[], int flagI){
    if (vertix != p[vertix - flagI])
        p[vertix - flagI] = findSet(p[vertix - flagI], p, rank, flagI);
    return p[vertix - flagI];
}



void Union(int vertix1, int vertix2, int p[], int rank[], int flagI){
    Link(findSet(vertix1, p, rank, flagI), findSet(vertix2, p, rank, flagI), p, rank, flagI);
}



void Link(int vertix1, int vertix2, int p[], int rank[], int flagI){
    if (rank[vertix1 - flagI] > rank[vertix2 - flagI])
        p[vertix2 - flagI] = vertix1;
    else{
        p[vertix1 - flagI] = vertix2;
        if(rank[vertix1 - flagI] == rank[vertix2 - flagI])
            rank[vertix2 - flagI]++;
    }
}



int cmpfunction(const void* a, const void* b){

	const Pconnection p1 = *(const Pconnection *)a;
	const Pconnection p2 = *(const Pconnection *)b;
	return (p1->cost - p2->cost);
}
