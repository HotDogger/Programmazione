#include <fstream>

using namespace std ;

template<typename H>
class Node {
    private :
    H data ;
    Node<H> *father , *sx , *dx ;
    public :
    Node(H elemento) {
        data = elemento ;
        father = sx = dx = NULL ;
    }
    void setData(H elemento) { data = elemento ;}
    H getData() { return data ;}
    void setFather(Node<H> *nodo) { father = nodo ;}
    Node<H> * getFather() { return father ;}
    void setSx(Node<H> *nodo) { sx = nodo ;}
    Node<H> * getSx() { return sx ;}
    void setDx(Node<H> *nodo) { dx = nodo ;}
    Node<H> *getDx() { return dx ;}
};

template<typename H>
class BST {
    private :
    Node<H> *root ;

    void _naturalfill(Node<H> *nodo , H array[] , int &i) {
        if(nodo) {
            _naturalfill(nodo->getSx(),array,i);
            nodo->setData(array[i++]);
            _naturalfill(nodo->getDx(), array, i);
        }
    }

    void _postOrder(Node<H> *nodo , ofstream &outfile) {
        if(nodo) {
            _postOrder(nodo->getSx(), outfile);
            _postOrder(nodo->getDx(), outfile);
            outfile << nodo->getData() << " " ;
        }
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
            if( data > ins->getData()) { ins=ins->getDx();}
            else ins=ins->getSx();
        }
        Node<H> *newn = new Node<H>(data) ;
        if(p==NULL) {
            root = newn ;
            return this ;
        }
        if( data > p->getData()) { p->setDx(newn);}
        else p->setSx(newn);
        newn->setFather(p);
        return this ;
    }

    void naturalFill(H array[]) {
        int i = 0 ;
        _naturalfill(root,array, i);
    }

    void postOrder(ofstream &outfile) {
        _postOrder(root, outfile) ;
    }


};

int main() {

    ifstream infile ("input.txt");
    ofstream outfile("output.txt");


    for(int i = 0 ; i < 100 ; i++) {
        string tipo ;
        int n ;
        infile >> tipo >> n ;
        if(tipo == "int" ) {
            BST<int> *tree = new BST<int>() ;
            int out ;
            for(int i = 0 ; i < n ; i++) {
                infile >> out ;
                tree->insert(out);
            }
            int array[n] ;
            for(int i = 0 ; i < n ; i++) {
                infile >> array[i] ;
            }
            tree->naturalFill(array);
            tree->postOrder(outfile);
        }
        if(tipo == "double" ) {
            BST<double> *tree = new BST<double>() ;
            double out ;
            for(int i = 0 ; i < n ; i++) {
                infile >> out ;
                tree->insert(out);
            }
            double array[n] ;
            for(int i = 0 ; i < n ; i++) {
                infile >> array[i] ;
            }
            tree->naturalFill(array);
            tree->postOrder(outfile);
        }
        outfile << endl ;
    }


}
