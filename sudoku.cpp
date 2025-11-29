#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

   //before main declaration
   bool rowcheck(int array[9][9],int lim, int n);
   bool columncheck(int array[9][9],int lim, int n); 
   bool box(int array[9][9], int row, int column); 
   bool sudoku(int r , int c );
 void missNumbers(int array[9][9], int count);

int sudokusol[9][9]={0};

//-------------------------------------MAIN FUNCTION---------------------------------------
int main(){
	// ANSI colors
    string red     = "\033[31m";
    string green   = "\033[32m";
    string yellow  = "\033[33m";
    string blue    = "\033[34m";
    string magenta = "\033[35m";
    string cyan    = "\033[36m";
    string white   = "\033[37m";
    string bold    = "\033[1m";
    string reset   = "\033[0m";
    // Clear screen
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    // Big ASCII letters for "SUDOKU" (with complete U)
    cout << bold << red     << "  _____ _    _ _____   ____  _   _ _    _ " << reset << endl;
    cout << bold << green   << " / ____| |  | |  __ \\ / __ \\| |/ /| |  | |" << reset << endl;
    cout << bold << yellow  << "| (___ | |  | | |  | | |  | | | / | |  | |" << reset << endl;
    cout << bold << blue    << " \\___ \\| |  | | |  | | |  | |  <  | |  | |" << reset << endl;
    cout << bold << magenta << " ____) | |__| | |__| | |__| | | \\ | |__| |" << reset << endl;
    cout << bold << cyan    << "|_____/ \\____/|_____/ \\____/|_|\\_\\ \\____/  " << reset << endl;
    cout << endl << yellow << "      Welcome to SUDOKU!" << reset << endl << endl;
    // Dummy Sudoku board
    string board[] = {
        "+-------+-------+-------+",
        "| 5 3 . | . 7 . | . . . |",
        "| 6 . . | 1 9 5 | . . . |",
        "| . 9 8 | . . . | . 6 . |",
        "+-------+-------+-------+",
        "| 8 . . | . 6 . | . . 3 |",
        "| 4 . . | 8 . 3 | . . 1 |",
        "| 7 . . | . 2 . | . . 6 |",
        "+-------+-------+-------+",
        "| . 6 . | . . . | 2 8 . |",
        "| . . . | 4 1 9 | . . 5 |",
        "| . . . | . 8 . | . 7 9 |",
        "+-------+-------+-------+"
    };
    // Print board in colors
    for (auto &line : board) {
        for (char ch : line) {
            if (ch == '+' || ch == '-' || ch == '|')
                cout << cyan << ch << reset;
            else if (isdigit(ch))
                cout << bold << green << ch << reset;
            else if (ch == '.')
                cout << white << ch << reset;
            else
                cout << ch;
        }
        cout << endl;
    }
    cout << endl;
    cout << yellow << "Press Enter to start the game..." << reset << endl;
    cin.get();
    cout << green << "Starting Sudoku game..." << reset << endl;
	srand(time(0));  // seed for random numbers
    if(sudoku(0, 0)) {
        cout << "Sudoku generated successfully:\n";
	}
  system("pause");
  return 0;
}
//------------------------------------------------------------------------------------------
bool rowcheck(int array[9][9],int lim, int n){
    for(int j=0; j<lim; j++){      

    if(array[n][j] == 0){
	  continue;  
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
        sudokusol[r][c] = num ;

        if(!rowcheck(array, 9, r) &&
           !columncheck(array, 9, c) &&
           !box(array, r, c)) {

            if(sudoku(r, c + 1)) return true; 
        }

        sudokusol[r][c] = 0;        
    }

    return false; 
}  
// before main declaration






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
            enter++;
        }
    }
    for (int k = 0; k <9; k++) {
        if(one_d[k] == 0) {
continue;
}
        for (int j = k + 1; j < 9; j++) {
            if(one_d[k] == one_d[j]) {
                return true;
            }
        }
    }
    return false;
}

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

--------------------------------------Function for missing values in a valid sudoku board-------------------------------------
	void missNumbers(int array[9][9], int count) {
	int numsmissed = 0;
	while (numsmissed < count) {

		int randomrow = rand() % 9;
		int randomcolumn = rand() % 9;

		if (board[randomrow][randomcolumn] != 0) { // only remove if the cell is not already zero so no duplication occurs
			board[randomrow][randomcolumn] = 0;    //Sets the missed place==0
			numsmissed++;
		}



	}



}



	



