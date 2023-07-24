// https://app.codesignal.com/challenge/3EkYGbXa26Zia7EL4

enum Direction {
    RIGHT,
    UP,
    LEFT,
    DOWN
};

vector<vector<int>> solution(vector<vector<int>> board, vector<int> pos) {
    auto payload = board[pos[0]][pos[1]];
    board[pos[0]][pos[1]] = 0;
    
    int dir = (pos[0] == 0 ? LEFT : RIGHT);
    while (payload > 0) {
        switch (dir) {
        case RIGHT:
            if (pos[1] == 5) dir = UP;
            else {
                pos[1]++;
                board[pos[0]][pos[1]]++;
                payload--;
            }
            break;
        case UP:
            if (pos[0] == 0) dir = LEFT;
            else {
                pos[0]--;
                board[pos[0]][pos[1]]++;
                payload--;
            }
            break;
        case LEFT:
            if (pos[1] == 0) dir = DOWN;
            else {
                pos[1]--;
                board[pos[0]][pos[1]]++;
                payload--;
            }
            break;
        case DOWN:
            if (pos[0] == 1) dir = RIGHT;
            else {
                pos[0]++;
                board[pos[0]][pos[1]]++;
                payload--;
            }
            break;
        default:;
        }
    }
    
    return board;
}
