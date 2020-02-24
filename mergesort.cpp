//
//  main.cpp
//  mergesort2
//
//  Created by Giuseppe Marletta on 19/02/2020.
//  Copyright © 2020 Giuseppe Marletta. All rights reserved.
//

#include <fstream>

using namespace std ;

int mergesort(int array[] , int low , int high) {
    if(low < high) {
        int mid = (low+high)/2 ;
        int somma = array[low];
        
        somma += mergesort(array,low,mid);
        somma += mergesort(array,mid+1,high);
        
        return somma ;
    }
    else return 0;
}

int main() {
    
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    
    for(int i = 0 ; i < 100 ; i++) {
        int n ;
        infile >> n ;
        int array[n];
        for(int i = 0 ; i < n ; i++)
            infile >> array[i];
        int somma = mergesort(array,0,n-1);
        outfile << somma << endl ;
        
    }
    
}
