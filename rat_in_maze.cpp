#include <iostream>
#include <vector>

using namespace std;

// Function to check if a cell is valid
bool is_valid(int x, int y, vector<vector<int>>& maze) {
    int n = maze.size();
    return x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1;
}

// Recursive function to solve the maze
bool solve_maze_helper(int x, int y, vector<vector<int>>& maze, vector<vector<int>>& solution) {
    int n = maze.size();
    if (x == n - 1 && y == n - 1) {
        solution[x][y] = 1;
        return true;
    }
    if (is_valid(x, y, maze)) {
        solution[x][y] = 1;
        if (solve_maze_helper(x + 1, y, maze, solution))
            return true;
        if (solve_maze_helper(x, y + 1, maze, solution))
            return true;
        solution[x][y] = 0;
    }
    return false;
}

// Function to solve the maze
void solve_maze(vector<vector<int>>& maze, vector<vector<int>>& solution) {
    if (solve_maze_helper(0, 0, maze, solution))
        cout << "Path found!" << endl;
    else
        cout << "No path found." << endl;
}

int main() {
    // Take input from the user to create the maze
    int n;
    cout << "Enter the size of the maze: ";
    cin >> n;
    vector<vector<int>> maze(n, vector<int>(n));
    cout << "Enter the maze (1s for open cells, 0s for blocked cells):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    // Solve the maze and print the solution
    vector<vector<int>> solution(n, vector<int>(n));
    solve_maze(maze, solution);
    cout << "Solution:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
