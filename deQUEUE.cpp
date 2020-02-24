#include <fstream>

using namespace std ;

template<typename H>
class Node{
    private :
    H data ;
    Node<H> *next ;
    public :
    Node(H elemento) {
        data = elemento ;
        next = NULL ;
    }
    void setData(H elemento) {
        data = elemento ;
    }
    H getData() {
        return data ;
    }
    void setNext(Node<H> *nodo) {
        next = nodo ;
    }
    Node<H> * getNext() {
        return next ;
    }

};

template<typename H>
class Queue{
    private :
    Node<H> *head ;
    Node<H> *tail ;
    public :
    Queue() {
        head = tail = NULL ;
    }
    void enqueue(H data) {
        Node<H> *nodo = new Node<H>(data);
        if(!head) {
            tail = head = nodo ;
        }
        else {
            tail->setNext(nodo);
            tail = nodo;
        }

    }

    void dequeue() {
        Node<H> *nodo = head ;
        head = head->getNext();
        delete nodo ;
    }

    void stampa(ofstream &outfile) {
        Node<H> *nodo = head ;
        while(nodo) {
            outfile << nodo->getData() << " " ;
            nodo = nodo->getNext();
        }
        outfile << endl ;
    }
};

int main() {

    ifstream infile ("input.txt");
    ofstream outfile ("output.txt");

    for(int i = 0 ; i < 100 ; i++) {
        int n ;
        string tipo ;
        infile >> tipo >> n ;
        if(tipo == "int") {
            Queue<int> *coda = new Queue<int>();
            char simbolo ;
            int out ;
            for(int i = 0 ; i < n ; i++) {
                infile >> simbolo ;
                if(simbolo == 'i') {
                    infile >> out ;
                    coda->enqueue(out);
                }
                else {
                    infile.ignore(6);
                    coda->dequeue();
                }
            }
            coda->stampa(outfile);
        }
        if(tipo == "double") {
            Queue<double> *coda = new Queue<double>();
            char simbolo ;
            double out ;
            for(int i = 0 ; i < n ; i++) {
                infile >> simbolo ;
                if(simbolo == 'i') {
                    infile >> out ;
                    coda->enqueue(out);
                }
                else {
                    infile.ignore(6);
                    coda->dequeue();
                }
            }
            coda->stampa(outfile);
        }
        if(tipo == "bool") {
            Queue<bool> *coda = new Queue<bool>();
            char simbolo ;
            bool out ;
            for(int i = 0 ; i < n ; i++) {
                infile >> simbolo ;
                if(simbolo == 'i') {
                    infile >> out ;
                    coda->enqueue(out);
                }
                else {
                    infile.ignore(6);
                    coda->dequeue();
                }
            }
            coda->stampa(outfile);
        }
        if(tipo == "char") {
            Queue<char> *coda = new Queue<char>();
            char simbolo ;
            char out ;
            for(int i = 0 ; i < n ; i++) {
                infile >> simbolo ;
                if(simbolo == 'i') {
                    infile >> out ;
                    coda->enqueue(out);
                }
                else {
                    infile.ignore(6);
                    coda->dequeue();
                }
            }
            coda->stampa(outfile);
        }

    }
}
