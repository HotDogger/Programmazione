//
//  main.cpp
//  bilanciamento-BST
//
//  Created by Giuseppe Marletta on 16/02/2020.
//  Copyright © 2020 Giuseppe Marletta. All rights reserved.
//

#include <fstream>

using namespace std ;

template<typename H>
class Node {
    private :
    H data ;
    Node<H> *father ;
    Node<H> *sx ;
    Node<H> *dx ;
    public :
    Node(H elemento) {
        data = elemento ;
        father = sx = dx = NULL ;
    }
    void setData(H elemento) {
        data = elemento ;
    }
    H getData() {
        return data ;
    }
    void setSx(Node<H> *nodo) {
        sx = nodo ;
    }
    Node<H> * getSx() {
        return sx ;
    }
    void setFather(Node <H> *nodo) {
        father = nodo ;
    }
    Node<H> * getFather() {
        return father ;
    }
    void setDx(Node<H> *nodo) {
        dx = nodo ;
    }
    Node<H> * getDx() {
        return dx ;
    }
};

template<typename H>
class BST{
    private:
    
    Node<H> *root ;
    
    Node<H> *search(H data) {
        Node<H> *nodo = root ;
        while( data != nodo->getData()) {
            if( data > nodo->getData()) { nodo = nodo->getDx();}
            else nodo=nodo->getSx();
        }
        return nodo;
    }
    
    Node<H> *minimo(Node<H> *nodo) {
        while(nodo->getSx())
            nodo = nodo->getSx();
        return nodo;
    }
    
    int _bilancia(Node<H> *nodo) {
        if(!nodo)
            return 0;
        else return 1 + _bilancia(nodo->getDx()) + _bilancia(nodo->getSx()) ;
    }
    public:
    BST() {
        root = NULL ;
    }
    BST<H> *insert(H data) {
        Node<H> *ins = root;
        Node<H> *p = NULL ;
        while( ins != NULL ) {
            p = ins ;
            if ( data > ins->getData()) { ins = ins->getDx();}
            else ins = ins->getSx();
        }
        Node<H> *newn = new Node<H>(data);
        if( p == NULL ){
            root = newn ;
            return this ;
        }
        if( data > p->getData()) { p->setDx(newn) ;}
        else p->setSx(newn);
        newn->setFather(p);
        return this ;
    }
    
    void canc(H data) {
        Node<H> *nodo = search(data);
        if(nodo->getSx() && nodo->getDx()) {
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
            if(genitore) {
                if(data > genitore->getData()) { genitore->setDx(figlio) ;}
                else genitore->setSx(figlio);
            }
            else root = figlio ;
            if(figlio)
                figlio->setFather(genitore);
            delete nodo;
        }
    }
    
    void bilancia(H data,ofstream &outfile) {
        Node<H> *nodo = search(data);
        outfile << abs(_bilancia(nodo->getDx()) - _bilancia(nodo->getSx())) << endl ;
    }
};

int main() {
    
    ifstream infile ("input.txt") ;
    ofstream outfile ("output.txt") ;
    
    for(int i = 0 ; i < 100 ; i++) {
        
        string tipo;
        int n ;
        infile >> tipo >> n ;
        if(tipo == "int") {
            BST<int> *tree = new BST<int>() ;
            char operazione ;
            int out ;
            for(int i = 0 ; i < n ; i++) {
                infile >> operazione ;
                if(operazione == 'i' ) {
                    infile.ignore(3);
                    infile >> out ;
                    tree->insert(out) ;
                }
                else {
                    infile.ignore(4);
                    infile >> out ;
                    tree->canc(out) ;
                }
            }
            infile >> out ;
            tree->bilancia(out, outfile) ;
        }
        if(tipo == "double") {
            BST<double> *tree = new BST<double>() ;
            char operazione ;
            double out ;
            for(int i = 0 ; i < n ; i++) {
                infile >> operazione ;
                if(operazione == 'i' ) {
                    infile.ignore(3);
                    infile >> out ;
                    tree->insert(out) ;
                }
                else {
                    infile.ignore(4);
                    infile >> out ;
                    tree->canc(out) ;
                }
            }
            infile >> out ;
            tree->bilancia(out, outfile) ;
        }
    }
}
