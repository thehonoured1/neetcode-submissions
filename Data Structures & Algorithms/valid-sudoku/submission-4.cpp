class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //IDEA: rows and boxes
        // 1. check each row[0 to 8]
        //    build 9* sets box[0 to 8] simultaneously inside box map
        //    build 9* sets column[0 to 8] simultaneously inside column map
        //    build 9* sets row[0 to 8] simultaneously inside row map
        // 2. add condition: duplicate detection on maps during traversal.
        // This will result in total n^3 storage. Lookup via contains() is O(log n)
        // CORRECTION: Used array instead of map for ease.
        
        set<char> rowMap[9];    //<----fixed-size arrays containing already empty sets (C++ feature)
        set<char> columnMap[9];
        set<char> boxMap[9];

        /*// Initialize columnMap vectors                   <------------- **NOW REDUNDANT.
        for (int i = 0; i < 9; i++) {
            columnMap[i] = set<char>();  // Empty vector for row i
            columnMap[i] = set<char>();  // Empty vector for column i
            boxMap[i] = set<char>();  // Empty vector for box i
        }*/

        // Populate and check the map
        for(int i= 0; i<9; i++){
            for(int j=0; j<9; j++){
                
                //skip '.'
                if(board[i][j]=='.')
                    continue;

                // atp, check for sudoku graph validity before the new value is added.
                // saves time if invalid status is caught immediately upon insertion of duplicate.
                if( 
                    (   rowMap[i].contains(board[i][j])
                        || columnMap[j].contains(board[i][j]) )                   
                    )
                {
                    return false;
                    // box checking will be done below, before new char insertion.
                }

                // add to each row/column vector, based on row/col index
                rowMap[i].insert(board[i][j]);
                columnMap[j].insert(board[i][j]);
                
                // add to each box, based on col index...
                if(j<=2){
                    // ...and row index
                    if(i<=2){
                        if(boxMap[0].contains(board[i][j]))
                            return false;
                        boxMap[0].insert(board[i][j]);
                    }
                    if(i>2 && i<=5){
                        if(boxMap[3].contains(board[i][j]))
                            return false;
                        boxMap[3].insert(board[i][j]);
                    }
                    if(i>5 && i<=8){
                        if(boxMap[6].contains(board[i][j]))
                            return false;
                        boxMap[6].insert(board[i][j]);    
                    }     
                }
                else if(j>2 && j<=5){
                        if(i<=2){
                            if(boxMap[1].contains(board[i][j]))
                                return false;
                            boxMap[1].insert(board[i][j]);}
                            
                        if(i>2 && i<=5){
                            if(boxMap[4].contains(board[i][j]))
                                return false;
                            boxMap[4].insert(board[i][j]);}
                            
                        if(i>5 && i<=8){
                            if(boxMap[7].contains(board[i][j]))
                                return false;
                            boxMap[7].insert(board[i][j]); }
                                                        
                }
                else if(j>5 && j<=8){
                    if(i<=2){
                        if(boxMap[2].contains(board[i][j]))
                            return false;
                        boxMap[2].insert(board[i][j]);}
                            
                    if(i>2 && i<=5){
                        if(boxMap[5].contains(board[i][j]))
                            return false;
                        boxMap[5].insert(board[i][j]);}
                           
                    if(i>5 && i<=8){
                        if(boxMap[8].contains(board[i][j]))
                            return false;
                        boxMap[8].insert(board[i][j]);  }
                }
            }
        }
        return true;     
    }
};