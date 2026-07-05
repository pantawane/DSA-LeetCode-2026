class Solution {
public:
    bool dfs(vector<vector<char>>& board, string &word, int i, int j, int index){
        //base case
        if(index == word.length())
        return true;

        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index]){
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';
        
        //explore all 4 directions
        bool found = dfs(board, word, i-1, j, index+1) ||
                     dfs(board, word, i, j+1, index+1) ||
                     dfs(board, word, i+1, j, index+1) ||
                     dfs(board, word, i, j-1, index+1);
        //backtrack
        board[i][j] = temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dfs(board, word, i, j, 0))
                return true;
            }
        }
        return false;
    }
};