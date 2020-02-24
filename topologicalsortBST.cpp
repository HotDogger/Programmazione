#include <fstream>

#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std ;

template<typename H>
class Grafo{
    private:
    
    int nodi ;
    int archi ;
    H *nodo;
    H **adj;
    int *color ;
    H *topologico;
    
    int TrovoIndice(H data) {
        int i = 0 ;
        while( data != nodo[i])
            i++;
        return i;
    }
    
    void _dfs(int i, int &pos) {
        color[i] = GRAY ;
        for(int j = 0 ; j < nodi ; j++) {
            if(adj[i][j] == 1 && color[j] == WHITE)
                _dfs(j , pos);
            }
        color[i] = BLACK ;
        topologico[pos--] = nodo[i] ;
         
        }
    
    public :
    
    Grafo(int n , int a){
        nodi = n ;
        archi = a ;
        nodo = new H[nodi];
        adj = new H*[nodi];
        color = new int[nodi];
        topologico = new H[nodi];
        for(int i = 0 ; i < nodi ; i++) {
            adj[i] = new H[nodi];
            color[i] = WHITE ;
            for(int j = 0 ; j < nodi ; j++)
                adj[i][j] = 0 ;
        }
        
    }
    
    void init(ifstream &infile) {
        for(int i = 0 ; i < nodi ; i++) {
            H valore ;
            infile >> valore ;
            nodo[i] = valore ;
        }
        
        for(int i = 1 ; i < nodi ; i++) {
            int j = i ;
            while(j > 0 && nodo[j] < nodo[j-1]){
                H temp = nodo[j] ;
                nodo[j] = nodo[j-1];
                nodo[j-1] = temp ;
                j--;
            }
        }
        
        for(int i = 0 ; i < archi ; i++) {
            char parentesi ;
            H nodoA ;
            H nodoB ;
            
            infile >> parentesi ;
            infile >> nodoA ;
            infile >> nodoB ;
            infile >> parentesi ;
            
            int a = TrovoIndice(nodoA);
            int b = TrovoIndice(nodoB);
            
            adj[a][b] = 1 ;
        }
        
    }
    
    void dfs(ofstream &outfile) {
        int pos = nodi - 1 ;
        for(int i = 0 ; i < nodi ; i++)
            if(color[i] == WHITE)
                _dfs(i,pos);
        for(int i = 0 ; i < nodi ; i++)
            outfile << topologico[i] << " " ;
        outfile << endl ;
    }
    
};

int main() {
    
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    
    for(int i = 0 ; i < 100 ; i++) {
        int n  , m ;
        string tipo ;
        infile >> n >> m >> tipo ;
        if(tipo == "int"){
            Grafo<int> *graph = new Grafo<int>(n,m);
            graph->init(infile);
            graph->dfs(outfile);
        }
        if(tipo == "double"){
            Grafo<double> *graph = new Grafo<double>(n,m);
            graph->init(infile);
            graph->dfs(outfile);
        }
        if(tipo == "char"){
            Grafo<char> *graph = new Grafo<char>(n,m);
            graph->init(infile);
            graph->dfs(outfile);
        }
    }
    
    
    
}
