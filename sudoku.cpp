#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

   //before main declaration
   
   bool rowcheck(int array[9][9],int lim, int n);
   bool columncheck(int array[9][9],int lim, int n); 
   bool box(int array[9][9], int row, int column); 
   bool sudoku(int r , int c );
   void missNumbers(int board[9][9], int count);
   void printBoard(int board[9][9]);
   bool validmove(int board[9][9], int r, int c, int num);
   void hint();
   void playsudoku();
   bool complete(int board[9][9]);

int score = 0;
int sudokusol[9][9]={0};
int playboard[9][9]={0};
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

	srand(time(0));  // seed for random numbers
    if(sudoku(0, 0)) {
        cout << "Sudoku generated successfully "<<endl;
	}
	
	for(int i = 0; i < 9; i++){
     for(int j = 0; j < 9; j++){
         playboard[i][j] = sudokusol[i][j];
     }
 }
	printBoard(playboard)
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

    for(int count = 0; count < 19; count++) {
    	
        int num = rand() % 9 + 1;   
        sudokusol[r][c] = num ;

        if(!rowcheck(sudokusol, 9, r) &&
           !columncheck(sudokusol, 9, c) &&
           !box(sudokusol, r, c)) {

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

//--------------------------------------Function for missing values in a valid sudoku board-------------------------------------
	void missNumbers(int board[9][9], int count) {
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

//--------------------------------------Function for printing a valid sudoku board-------------------------------------
void printBoard(int board[9][9]) {
    string green = "\033[32m";
    string white = "\033[37m";
    string cyan  = "\033[36m";
    string reset = "\033[0m";
    cout <<cyan<<"+-------+-------+-------+"<<reset<<endl;

    for (int i = 0; i < 9; i++) {

        cout <<cyan<< "| "<<reset;   // left border

        for (int j = 0; j < 9; j++) {

            if (board[i][j] == 0)
                cout << white <<"_ "<< reset;
            else
                cout <<green <<board[i][j] << " "<<reset;

            if ((j + 1) % 3 == 0)   // after every 3 columns
                cout <<cyan<< "| "<<reset;
        }

        cout << "\n";

        if ((i + 1) % 3 == 0)  // after every 3 rows
            cout <<cyan<< "+-------+-------+-------+"<<reset<<endl;
    }
}

//----------------------------------------------------------------------------
	bool validmove(int board[9][9], int r, int c, int num)
{
  
    if(board[r][c] != 0){
        return false;}

    
    board[r][c] = num;

    
    if(!rowcheck(board, 9, r) &&
       !columncheck(board, 9, c) &&
       !box(board, r, c)) {
        board[r][c] = 0; 
        return true;
    }

    board[r][c] = 0; 
    return false;
}

//-----------------------------------------------------------------------------
void hint(){

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(playboard[i][j] == 0){
                playboard[i][j] = sudokusol[i][j];
                score -= 10; 
                cout << "\033[33m Hint used! (-10 points)\033[0m"<<reset<<endl;
                printBoard(playboard);
                return;
            }
        }
    }
    cout << "No empty cells left for hint."<<endl;

}
//---------------------------------------------------------------------
void playsudoku(){
	char ch;
	int row; column; numb; 
	
	while(true){
		printBoard(playboard);
		cout<<endl;
		cout<<"Do You want to play or get hints or solve sudoku"<<endl;
		cout<<"Press P= play, H=hint, S=solve & X=exit , "
		cin >> ch;
		if(ch == 'H' || ch == 'h') {
            hint();
            continue;
        }
        else if(ch== 'S' || ch == 's') {
			score -= 20;
            printBoard(sudokusol);
            break;
        }
          else if(ch== 'X' || ch == 'x') {
            cout << "Game exited"<<endl;
            break;
        }
        if(ch == 'P' || ch == 'p') {
    cout << "ENTER THE ROW (1-9): ";
    cin >> row;
    cout << "ENTER THE COLUMN (1-9): ";
    cin >> column;
    cout << "ENTER THE NUMBER (1-9): ";
    cin >> numb;

    
    row--; 
    column--;

    if(validmove(playboard, row, column, numb)) {
        playboard[row][column] = numb;
        score += 10;
        cout << "\033[32m Valid Move  (+10 points)\033[0m"<<reset<<endl; // green
    
		if(complete(playboard)) {
            printBoard(playboard);
            cout << "\033[32mCongratulations! You have completed the Sudoku!\033[0m\n";
            cout << "Your final score: " << score << endl;
            break; 
        }
	}
	else {
        score -= 5;
        cout << "\033[31mInvalid move! (-5 points)\033[0m"<<reset<<endl;   // red
    }
}
	}
}
//----------------------------------------------------------------------------------
	bool complete(int board[9][9]) {
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == 0)  
                return false;
        }
    }
    return true;  
}

