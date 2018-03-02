#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;  // Sepal width	Petal length	Species

vector<double> width, length ;
vector<double> distanceFlower ;
int read ( ifstream & ) ;
double distanceXY ( double x0x1 , double y0y1 ) ;
void showMatrix( double ** matrix, int const SIZE );

int main( void )
{
    ifstream ifs( "4450_lab4.txt" );
    ::read ( ifs ) ;
    int const SIZE = width.size() ;

    double** distMatrix = new double* [SIZE] ;
    for ( int i = 0 ; i < SIZE ; i++ ) distMatrix[i] = new double [ SIZE ] ;

    for ( int i = 0 ; i < SIZE ; i ++ )
        for ( int j = i ; j < SIZE ; j ++ ){
            distMatrix [i][j] = distMatrix[ j ][i ] = distanceXY( width[i]-width[j] , length[i] - length[j] ) ;
        }

    showMatrix( distMatrix , SIZE );

    // cout << ( ifs.is_open() ? "Opened" : "Closed" ) << endl ;
    // cout << "Hello World!" << endl;
    ifs.close();
    return 0;
}




int read ( ifstream & ifs ) {
    string s ;
    stringstream ss ;
    double w = -1.0 , l = -1.0 ;
    char dummy  = 'd';
    getline ( ifs , s ) ;

    //while ( getline (ifs , s ) ) cout << s << endl;
    while ( getline( ifs , s ) ) {
        ss<<s ;
        ss>>w ;
        width.push_back( w );
        //cout << "w : " << w << endl;
        ss>>l ;
        //cout << "l : " << l << endl;
        length.push_back( l );
        // No Need to push dummy
        ss>>dummy ;
            //cout << "dummy : " << dummy << endl;
        //cout << endl;
    }
    return 0 ;
}


double distanceXY ( double x0x1, double y0y1 ) {
    return x0x1*x0x1 + y0y1 *y0y1 ;
}

void showMatrix( double ** matrix , int const size ) {
    for ( int i = 0 ; i < size ; i ++ , cout << endl )
        for ( int j = 0 ; j < size ; j++ ) {
            cout << setprecision(1) << fixed <<  matrix [i][j] << " " ;
        }

}
