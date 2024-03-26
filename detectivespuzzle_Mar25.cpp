#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char crossword[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> crossword[i][j];
        }
    }
    int count = 0;
    vector<pair<int, int>> coords;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            if(crossword[i][j] == '.'){
                if(i==0 & j==0){
                    if(crossword[i][j+1] == '.' & crossword[i][j+2] == '.'){
                        count++;
                        crossword[i][j] = '!';
                        pair<int, int> clue;
                        clue.first = i+1;
                        clue.second = j+1;
                        coords.push_back(clue);
                    }
                    else if(crossword[i+1][j] == '.' & crossword[i+2][j]=='.'){
                        count++;
                        crossword[i][j] = '!';
                        pair<int, int> clue;
                        clue.first = i+1;
                        clue.second = j+1;
                        coords.push_back(clue);
                    }
                }
                else if(i ==0){
                    if(crossword[i][j+1] == '.' & crossword[i][j+2] == '.' & crossword[i][j-1] == '#'){
                        count++;
                        crossword[i][j] = '!';
                        pair<int, int> clue;
                        clue.first = i+1;
                        clue.second = j+1;
                        coords.push_back(clue);
                    }
                    else if(crossword[i+1][j] == '.' & crossword[i+2][j]=='.'){
                        count++;
                        crossword[i][j] = '!';
                        pair<int, int> clue;
                        clue.first = i+1;
                        clue.second = j+1;
                        coords.push_back(clue);
                    }
                }
                else if(j == 0){
                    if(crossword[i][j+1] == '.' & crossword[i][j+2] == '.'){
                        count++;
                        crossword[i][j] = '!';
                        pair<int, int> clue;
                        clue.first = i+1;
                        clue.second = j+1;
                        coords.push_back(clue);
                    }
                    else if(crossword[i+1][j] == '.' & crossword[i+2][j]=='.' & crossword[i-1][j] == '#'){
                        count++;
                        crossword[i][j] = '!';
                        pair<int, int> clue;
                        clue.first = i+1;
                        clue.second = j+1;
                        coords.push_back(clue);
                    }
                }
                else{
                    if(crossword[i][j+1] == '.' & crossword[i][j+2] == '.' & crossword[i][j-1] == '#'){
                        count++;
                        crossword[i][j] = '!';
                        pair<int, int> clue;
                        clue.first = i+1;
                        clue.second = j+1;
                        coords.push_back(clue);
                    }
                    else if(crossword[i+1][j] == '.' & crossword[i+2][j]=='.' & crossword[i-1][j] == '#'){
                        count++;
                        crossword[i][j] = '!';
                        pair<int, int> clue;
                        clue.first = i+1;
                        clue.second = j+1;
                        coords.push_back(clue);
                    }
                }
            }
            
        }
    }
    cout << count << endl;
    for(auto i:coords){
        cout << i.first << " " << i.second << endl;
    }
	return 0;
}