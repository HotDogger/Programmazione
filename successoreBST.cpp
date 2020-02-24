#include <fstream>

using namespace std ;

template<typename H>
class Node{
    private :
    H data ;
    Node<H> *father , *sx , *dx ;
    public :
    Node(H elemento) {
        data = elemento ;
        father = sx = dx = NULL ;
    }
    void setData(H elemento) {
        data = elemento ;
    }
    H getData() { return data ;}
    void setFahter(Node<H> *nodo) { father = nodo ;}
    Node<H> * getFather() { return father ;}
    void setSx(Node<H> *nodo) { sx = nodo ;}
    Node<H> * getSx() { return sx ;}
    void setDx(Node<H> *nodo) { dx = nodo ;}
    Node<H> * getDx() { return dx ;}

};

template<typename H>
class BST {
    private :
    Node<H> *root ;

    Node<H> *search ( H data) {
        Node<H> *nodo = root ;
        while ( data != nodo->getData()) {
            if(data>nodo->getData())
                nodo=nodo->getDx();
            else
                nodo=nodo->getSx();
        }
        return nodo ;
    }

    Node<H> *minimo(Node<H> *nodo) {
        while(nodo->getSx())
            nodo=nodo->getSx();
        return nodo;
    }

    public :

    BST() {
        root = NULL ;
    }

    BST<H> *insert(H data) {
        Node<H> *ins = root ;
        Node<H> *p = NULL ;
        while(ins != NULL) {
            p = ins ;
            if(data > ins->getData()) { ins = ins->getDx();}
            else ins=ins->getSx();
        }
        Node<H> *newn = new Node<H>(data);
        if(p == NULL) {
            root = newn ;
            return this ;
        }
        if(data > p->getData()) { p->setDx(newn);}
        else p->setSx(newn);
        newn->setFahter(p);
        return this ;
    }

    void canc(H data) {
        Node<H> *nodo = search(data) ;
        if(nodo->getDx() && nodo->getSx()) {
            Node<H> *succ = minimo(nodo->getDx());
            H temp = succ->getData();
            canc(temp);
            nodo->setData(temp);
        }
        else {
            Node<H> *genitore = nodo->getFather();
            Node<H> *figlio = nodo->getSx();
            if(!figlio)
                figlio = nodo->getDx();
            if(genitore){
                if(data > genitore->getData()) { genitore->setDx(figlio);}
                else genitore->setSx(figlio);
            }
            else root = figlio ;
            if(figlio)
                figlio->setFahter(genitore) ;
            delete nodo ;
        }
    }

    void successore(H data , ofstream &outfile) {
        Node<H> *nodo = search(data);
        if(nodo->getDx()) {
            Node<H> *succ = minimo(nodo->getDx());
            outfile << succ->getData() << " " ;
        }
        else {
            Node<H> *genitore = nodo->getFather();
            while(genitore && nodo==genitore->getDx()) {
                nodo = genitore ;
                genitore = genitore->getFather();
            }
            if(!genitore)
                outfile << -1 << " " ;
            else
                outfile << genitore->getData() << " " ;
        }
    }
};

int main() {

    ifstream infile ("input.txt");
    ofstream outfile("output.txt");

    for(int i = 0 ; i < 100 ; i++) {
        string tipo ;
        int n , m ;
        infile >> tipo >> n >> m ;
        if(tipo == "int") {
            BST<int> *tree = new BST<int>();
            char simbolo ;
            int out ;
            for(int i = 0 ; i < n ; i++) {
                infile >> simbolo ;
                if(simbolo == 'i') {
                    infile.ignore(3);
                    infile >> out ;
                    tree->insert(out);
                }
                else {
                    infile.ignore(4);
                    infile >> out ;
                    tree->canc(out);
                }
            }
            for(int i = 0 ; i < m ; i++) {
                infile >> out ;
                tree->successore(out,outfile);
            }
        }
        if(tipo == "double") {
            BST<double> *tree = new BST<double>();
            char simbolo ;
            double out ;
            for(int i = 0 ; i < n ; i++) {
                infile >> simbolo ;
                if(simbolo == 'i') {
                    infile.ignore(3);
                    infile >> out ;
                    tree->insert(out);
                }
                else {
                    infile.ignore(4);
                    infile >> out ;
                    tree->canc(out);
                }
            }
            for(int i = 0 ; i < m ; i++) {
                infile >> out ;
                tree->successore(out,outfile);
            }
        }
        outfile << endl ;
    }

}
