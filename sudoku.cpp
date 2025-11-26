#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

   bool rowcheck(int array[9][9],int lim, int n);
   bool sudoku(int r , int c );
bool box(int array[9][9], int row, int column);  

//before main declaration
bool columncheck(int array[9][9],int lim,int n){
    for(int i=0; i< lim; i++){
        if(array[i][n]==0) {
continue;
}
         for(int j=i+1; j<lim; j++){
            if(array[i][n]==array[j][n]){
                return true;
            }
        }
    }
    return false;
}
//-------------------------------------MAIN FUNCTION---------------------------------------
int main(){

  system("pause");
  return 0;
}
//------------------------------------------------------------------------------------------
bool rowcheck(int array[9][9],int lim, int n){
    for(int j=0; j<lim; j++){      

    if(array[n][j] == 0){
	  continue;  ??If array
	 }
    for(int k=j+1 ; k<lim; k++){
     if(array[n][j]==array[n][k]){
      return true;
            }
        }
    }
      return false;
}
	//------------------------------------------------------------------------------------------------
	bool sudoku(int r , int c ) {
    if(r == 9){
	 return true; 
	 }
	         
     if(c == 9){
	 return sudoku(r + 1, 0); 
}

    for(int count = 0; count < 9; count++) {
    	
        int num = rand() % 9 + 1;   
        array[r][c] = num ;

        if(!rowcheck(array, 9, r) &&
           !columncheck(array, 9, c) &&
           !box(array, r, c)) {

            if(sudoku(r, c + 1)) return true; 
        }

        array[r][c] = 0;        
    }

    return false; 
}  
// before main declaration


bool columncheck(int array[9][9],int lim, int n);





// after main
bool box(int array[9][9], int row, int column)
{
    int startrow = row - (row%3);
    int startcolumn = column - (column%3);
    int one_d[9];
    int enter = 0;
    for (int i = startrow; i < startrow +3; i++) {
        for(int j = startcolumn; j < startcolumn+ 3; j++) {
            one_d[enter] = array[i][j];
            enter++
        }
    }
    for (int k = 0; k <9; k++) {
        if(one_d[k] == 0) {
continue;
}
        for (int j = k + 1; j < 9; j++) {
            if(one_d[k] == rep[j]) {
                return true;
            }
        }
    }
    return false;
}





	



