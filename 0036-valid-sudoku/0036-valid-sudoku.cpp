class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //create 9 hash tables for rows, columns ans boxes
        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> columns(9);
        vector<unordered_set<int>> boxes(9);

        //traverse for rows and columns
        for(int r = 0; r<9; r++){
            for(int c = 0; c < 9; c++){

                //base case
                if(board[r][c] == '.'){
                    continue;
                }

                char num = board[r][c];
                //find which 3*3 box this num belong to
                int box = (r/3) * 3 + (c/3);
                
                //duplicates
                if(rows[r].count(num) || columns[c].count(num) || boxes[box].count(num)){
                    return false;
                }

                //insert into row , column and box
                rows[r].insert(num);
                columns[c].insert(num);
                boxes[box].insert(num);
            }
        }
        return true;
    }
};