class Solution {
public:
    vector<vector<int>> memory;
    int min_insertion (string &input, int i, int j) {

        if ((j -i) == 0) return 0;
        if ((j - i) == 1) {
            if (input[i] == input[j]) return 0;
            else return 1;
        }
        
        if (memory[i][j] != -1) {
            return memory[i][j];
        }

        if (input[i] != input[j]) {
    
            memory[i][j] = min(min_insertion(input, i+1, j), min_insertion(input, i, j-1)) + 1;
            return memory[i][j];
        } else {
            memory[i][j] = min_insertion(input, i+1, j-1);
            return memory[i][j];
        }
    }

    
    int minInsertions(string s) {
        memory.resize(s.length(),vector<int>(s.length(),-1));
        return min_insertion(s, 0, s.length() - 1);
    }
};