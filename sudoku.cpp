#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

   bool rowcheck(int array[9][9],int lim, int n);

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
