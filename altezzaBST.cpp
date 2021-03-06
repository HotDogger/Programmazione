#include <fstream>

using namespace std ;

template<typename H>
class Node{
    private :
    H data ;
    Node<H> *father , *dx , *sx ;
    public :
    Node(H elemento) {
        data = elemento ;
        father = dx = sx = NULL ;
    }
    void setData(H elemento) { data = elemento ;}
    H getData() { return data ;}
    void setFather(Node<H> *nodo) { father = nodo ;}
    Node<H> * getFather() { return father ;}
    void setSx(Node<H> *nodo) { sx = nodo ;}
    Node<H>  * getSx() { return sx ;}
    void setDx(Node<H> *nodo) { dx = nodo ;}
    Node<H>  * getDx() { return dx;}
};

template<typename H>
class BST {
    private :
    Node<H> *root ;

    Node<H> *search(H data) {
        Node<H> *nodo = root ;
        while ( data != nodo->getData()) {
            if(data > nodo->getData())
                nodo = nodo->getDx();
            else
                nodo=nodo->getSx();
        }
        return nodo;
    }

    Node<H> *minimo(Node<H> *nodo) {
        while(nodo->getSx())
            nodo=nodo->getSx();
        return nodo;
    }

    int _altezza(Node<H> *nodo) {
        if(!nodo) {
            return 0 ;
        }
        else {
            int altezzadestra = 1 + _altezza(nodo->getDx());
            int altezzasinistra = 1+ _altezza(nodo->getSx());
            if(altezzadestra>altezzasinistra) {
                return altezzadestra;
            }
            else {
                return altezzasinistra;
            }
        }
    }

    public :

    BST() {
        root = NULL ;
    }

    BST<H> *insert(H data) {
        Node<H> *ins = root ;
        Node<H> *p = NULL ;
        while( ins != NULL ) {
            p = ins ;
            if(data > ins->getData()) { ins=ins->getDx();}
            else ins=ins->getSx();
        }
        Node<H> *newn = new Node<H>(data);
        if( p == NULL ) {
            root = newn ;
            return this ;
        }
        if(data > p->getData()) { p->setDx(newn);}
        else p->setSx(newn);
        newn->setFather(p);
        return this;
    }

    void canc(H data) {
        Node<H> *nodo = search(data);
        if(nodo->getDx() && nodo->getSx()) {
            Node<H> *succ = minimo(nodo->getDx());
            H temp = succ->getData();
            canc(temp);
            nodo->setData(temp);
        }
        else{
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
                figlio->setFather(genitore);
            delete nodo;
        }
    }

    void altezza(ofstream &outfile) {
        outfile << _altezza(root) << endl ;
    }
};

int main() {

    ifstream infile ("input.txt");
    ofstream outfile("output.txt");

    for(int i = 0 ; i < 100 ; i++) {
        int n ;
        string tipo ;
        infile >> tipo >> n ;
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
            tree->altezza(outfile);
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
            tree->altezza(outfile);
        }
    }

}

