//
//  main.cpp
//  selectionsort
//
//  Created by Giuseppe Marletta on 04/02/2020.
//  Copyright © 2020 Giuseppe Marletta. All rights reserved.
//

#include <fstream>

using namespace std ;

void selection(int vett[] , int n , ofstream &outfile) {
    int distanza = 0 ;
    for(int i = 0 ; i < n-1 ; i++) {
        int min = i ;
        for(int j = i+1 ; j < n ; j++)
            if(vett[j] < vett[min])
                min = j;
        if( min != i) {
            int temp = vett[i];
            vett[i] = vett[min];
            vett[min] = temp;
            distanza += (min-i);
        }
    }
    outfile << distanza << endl ;
    
}

int main() {
    
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    
    for(int i = 0 ; i < 100 ; i++) {
        int n ;
        infile >> n ;
        int vett[n];
        for(int i = 0 ; i < n ; i++)
            infile >> vett[i];
        selection(vett,n,outfile);
    }
}
