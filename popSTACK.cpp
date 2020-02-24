#include <fstream>

using namespace std ;

template<typename H>
class Node {
    private :
    H data;
    Node<H> *next ;
    public :
    Node( H elemento ){
        data = elemento ;
        next = NULL ;
    }
    void setData( H elemento) {
        data = elemento ;
    }
    H getData() {
        return data;
    }
    void setNext(Node<H> *nodo) {
        next = nodo ;
    }
    Node<H> * getNext() {
        return next;
    }
};

template<typename H>
class Stack {
    private :
    Node<H> *head ;
    public :
    Stack() {
        head = NULL ;
    }

    void push(H data) {
        Node<H> *nodo = new Node<H>(data);
        if(!head)
            head = nodo ;
        else {
            nodo->setNext(head);
            head = nodo ;
        }
    }

    void pop() {
        Node<H> *nodo = head ;
        head = head->getNext();
        delete nodo;
    }

    void stampa(ofstream &outfile) {
        Node<H> *nodo = head ;
        while(nodo) {
            outfile << nodo->getData() << " ";
            nodo = nodo->getNext();
        }
        outfile << endl ;
    }

};

int main() {

    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    for(int i = 0 ; i < 100 ; i++) {
        string tipo ;
        int n ;
        infile >> tipo >> n ;
        if(tipo == "int") {
            Stack<int> *pila = new Stack<int>();
            int array[n] ;
            char simbolo ;
            for(int i = 0 ; i < n ; i++) {
                infile >> simbolo ;
                if(simbolo == 'i') {
                    infile >> array[i] ;
                    pila->push(array[i]);
                }
                else {
                    infile.ignore(2);
                    pila->pop();
                }
            }
            pila->stampa(outfile);
        }
        if(tipo == "double") {
            Stack<double> *pila = new Stack<double>();
            double out ;
            char simbolo ;
            for(int i = 0 ; i < n ; i++) {
                infile >> simbolo ;
                if(simbolo == 'i') {
                    infile >> out ;
                    pila->push(out);
                }
                else {
                    infile.ignore(2);
                    pila->pop();
                }
            }
            pila->stampa(outfile);
        }
        if(tipo == "char") {
            Stack<char> *pila = new Stack<char>();
            char out ;
            char simbolo ;
            for(int i = 0 ; i < n ; i++) {
                infile >> simbolo ;
                if(simbolo == 'i') {
                    infile >> out ;
                    pila->push(out);
                }
                else {
                    infile.ignore(2);
                    pila->pop();
                }
            }
            pila->stampa(outfile);
        }
        if(tipo == "bool") {
            Stack<bool> *pila = new Stack<bool>();
            bool out ;
            char simbolo ;
            for(int i = 0 ; i < n ; i++) {
                infile >> simbolo ;
                if(simbolo == 'i') {
                    infile >> out ;
                    pila->push(out);
                }
                else {
                    infile.ignore(2);
                    pila->pop();
                }
            }
            pila->stampa(outfile);
        }

    }

}
