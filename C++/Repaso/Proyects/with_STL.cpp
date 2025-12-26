#include <iostream>
#include <vector>
#include <unordered_map>
#include <array>
#include <algorithm>

using namespace std;

// ================= TIPOS =================
enum class Cell { Empty, Wall, Trap, Treasure, Portal, Entry, Exit };

struct Player {
    int r, c;
    int life;
};

using Maze = vector<vector<Cell>>;

// ================= MAPEOS =================
unordered_map<char, Cell> charToCell = {
    {'.', Cell::Empty}, {'#', Cell::Wall}, {'X', Cell::Trap},
    {'T', Cell::Treasure}, {'P', Cell::Portal},
    {'E', Cell::Entry}, {'S', Cell::Exit}
};

unordered_map<Cell, char> cellToChar = {
    {Cell::Empty, '.'}, {Cell::Wall, '#'}, {Cell::Trap, 'X'},
    {Cell::Treasure, 'T'}, {Cell::Portal, 'P'},
    {Cell::Entry, 'E'}, {Cell::Exit, 'S'}
};

// key = r * cols + c
unordered_map<int, pair<int,int>> portalMap;

// ================= UI =================
void printBanner() {
    cout << "\n========================================\n";
    cout << "      ESCAPE DEL LABERINTO MAGICO        \n";
    cout << "========================================\n\n";
}

void printLegend() {
    cout << "\n----------- LEYENDA -----------\n";
    cout << "@ Jugador   E Entrada   S Salida\n";
    cout << "T Tesoro    X Trampa    P Portal\n";
    cout << "# Muro      . Camino\n";
    cout << "-------------------------------\n\n";
}

void printMaze(const Maze& maze, const Player& p) {
    int rows = maze.size(), cols = maze[0].size();

    cout << "\n+";
    for (int i = 0; i < cols; i++) cout << "---";
    cout << "+\n";

    for (int i = 0; i < rows; i++) {
        cout << "|";
        for (int j = 0; j < cols; j++) {
            if (p.r == i && p.c == j)
                cout << " @ ";
            else
                cout << " " << cellToChar[maze[i][j]] << " ";
        }
        cout << "|\n";
    }

    cout << "+";
    for (int i = 0; i < cols; i++) cout << "---";
    cout << "+\n";
}

// ================= INSERTAR ELEMENTOS =================
void insertElements(Maze& maze) {
    portalMap.clear();

    int types;
    cout << "[*] Total de tipos de elementos: ";
    cin >> types;

    int rows = maze.size(), cols = maze[0].size();

    for (int i = 0; i < types; i++) {
        char ch;
        int q;
        cout << "Tipo (E/S/T/X/#/P) y cantidad: ";
        cin >> ch >> q;

        Cell type = charToCell[ch];

        if ((type == Cell::Entry || type == Cell::Exit) && q > 1) q = 1;
        if ((type == Cell::Trap || type == Cell::Treasure || type == Cell::Wall) && q > 10) q = 10;
        if (type == Cell::Portal) {
            if (q % 2 != 0) q--;
            q = clamp(q, 2, 20);
        }

        vector<pair<int,int>> portals;

        for (int j = 0; j < q; j++) {
            int r, c;
            while (true) {
                cout << "Coords (" << j+1 << "/" << q << "): ";
                cin >> r >> c;
                if (r < 0 || r >= rows || c < 0 || c >= cols) continue;
                if (maze[r][c] != Cell::Empty) continue;
                maze[r][c] = type;
                if (type == Cell::Portal) portals.push_back({r,c});
                break;
            }
        }

        for (size_t k = 0; k + 1 < portals.size(); k += 2) {
            int a = portals[k].first * cols + portals[k].second;
            int b = portals[k+1].first * cols + portals[k+1].second;
            portalMap[a] = portals[k+1];
            portalMap[b] = portals[k];
        }
    }
}

// ================= MOVIMIENTO =================
bool movePlayer(Player& p, Maze& maze, int cols,
                int maxLife, int& treasures, int& traps, bool& exitReached) {

    static const unordered_map<char, pair<int,int>> dirs = {
        {'w', {-1,0}}, {'s', {1,0}},
        {'a', {0,-1}}, {'d', {0,1}}
    };

    char m;
    cout << "[*] Movimiento (w/a/s/d): ";
    cin >> m;

    if (!dirs.count(m)) return false;

    int nr = p.r + dirs.at(m).first;
    int nc = p.c + dirs.at(m).second;

    if (nr < 0 || nr >= maze.size() || nc < 0 || nc >= maze[0].size()) return false;
    if (maze[nr][nc] == Cell::Wall) return false;

    p.r = nr; p.c = nc;
    Cell& cell = maze[nr][nc];

    if (cell == Cell::Trap) {
        p.life -= 10;
        traps++;
        cell = Cell::Empty;
    }
    else if (cell == Cell::Treasure) {
        p.life = min(p.life + 20, maxLife);
        treasures++;
        cell = Cell::Empty;
    }
    else if (cell == Cell::Portal) {
        int key = nr * cols + nc;
        auto dest = portalMap[key];
        maze[nr][nc] = Cell::Empty;
        maze[dest.first][dest.second] = Cell::Empty;
        p.r = dest.first;
        p.c = dest.second;
    }
    else if (cell == Cell::Exit) {
        exitReached = true;
    }

    return true;
}

// ================= JUEGO =================
void gameLoop(Maze& maze, Player& p, int moves, int maxLife) {
    int treasures = 0, traps = 0;
    bool exitReached = false;
    int cols = maze[0].size();

    int totalTreasures = 0;
    for (const auto& r : maze)
        totalTreasures += count(r.begin(), r.end(), Cell::Treasure);

    printLegend();

    while (moves > 0 && p.life > 0 && !exitReached) {
        printMaze(maze, p);
        cout << "Vida: " << p.life << " | Movimientos: " << moves << "\n";

        if (movePlayer(p, maze, cols, maxLife, treasures, traps, exitReached))
            moves--;
    }

    printMaze(maze, p);

    cout << "\n========== RESULTADO ==========\n";
    cout << "Tesoros: " << treasures << "/" << totalTreasures << "\n";
    cout << "Trampas: " << traps << "\n";
    cout << "Vida: " << p.life << "\n";

    if (exitReached && p.life > 0)
        cout << (treasures == totalTreasures ? "SORPRENDENTE\n" : "LOGRADO\n");
    else if (p.life <= 0)
        cout << "MUERTO\n";
    else
        cout << "ATRAPADO\n";

    cout << "===============================\n";
}

// ================= MAIN =================
int main() {
    printBanner();

    int N, M;
    cout << "[*] Dimensiones (filas columnas): ";
    cin >> N >> M;

    Maze maze(N, vector<Cell>(M, Cell::Empty));
    insertElements(maze);

    Player p;
    p.life = 100;

    cout << "[*] Posición inicial jugador: ";
    cin >> p.r >> p.c;

    int moves;
    cout << "[*] Energía (movimientos): ";
    cin >> moves;

    gameLoop(maze, p, moves, 100);
    return 0;
}
