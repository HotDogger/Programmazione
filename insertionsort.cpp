#include <iostream>
#include <fstream>

using namespace std ;

void selection(int array[],int n ,ofstream &outfile) {
    int count = 0 ;
    for(int i = 1 ; i < n ; i++) {
        int j = i ;
        while(j > 0 && array[j] < array[j-1] ){
            int temp = array[j];
            array[j] = array[j-1];
            array[j-1] = temp ;
            j-- ;
            count ++;
        }
    }
    outfile << count << endl ;
    
}

int main() {
    
    ifstream infile("input.txt") ;
    ofstream outfile("output.txt") ;
    
    for(int i = 0 ; i < 100  ; i++) {
        int n ;
        infile >> n ;
        int array[n] ;
        for(int i = 0 ; i < n ; i++ ){
            infile >> array[i];
        }
        selection(array,n,outfile);
    }
}
