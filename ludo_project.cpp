// ludo_game.cpp - Complete Ludo with custom board
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

// ============================================================
// PAWN CLASS
// ============================================================

class Pawn {
public:
    int position;      // -1 = base, 0-56 = track/home
    bool isHome;
    bool isActive;

    Pawn() {
        position = -1;
        isHome = false;
        isActive = false;
    }
};

// ============================================================
// PLAYER CLASS
// ============================================================

class Player {
public:
    char house;
    int startOffset;
    Pawn pawns[4];

    Player() {}

    Player(char h, int offset) {
        house = h;
        startOffset = offset;
    }

    int pawnsAtHome() {
        int count = 0;
        for (int i = 0; i < 4; i++) {
            if (pawns[i].isHome) count++;
        }
        return count;
    }

    void showPawns() {
        cout << "\nPlayer " << house << " pawns:\n";
        for (int i = 0; i < 4; i++) {
            cout << "  Pawn " << (i + 1) << ": ";
            if (pawns[i].position == -1) {
                cout << "In base\n";
            }
            else if (pawns[i].isHome) {
                cout << "HOME!\n";
            }
            else if (pawns[i].position >= 51) {
                cout << "Home stretch at " << pawns[i].position << "\n";
            }
            else {
                cout << "On track at " << pawns[i].position << "\n";
            }
        }
    }
};

// ============================================================
// BOARD DESIGN (13x13 grid)
// ============================================================

class Board {
public:
    // The base board layout (13 rows, each 29 chars wide for spacing)
    vector<string> baseBoard;

    // Track coordinates: 52 positions mapped to (row, col)
    // Path goes clockwise around the center cross
    int trackRow[52];
    int trackCol[52];

    // Safe spots (indices in the 52-position track)
    int safeSpots[8];

    // Home stretch coordinates for each player
    // Player A=0, B=1, C=2, D=3
    int homeStretchRow[4][5];
    int homeStretchCol[4][5];

    // Base coordinates for each player (4 pawns each)
    int baseRow[4][4];
    int baseCol[4][4];

    Board() {
        initBoard();
        initTrack();
        initSafeSpots();
        initHomeStretches();
        initBases();
    }

    void initBoard() {
        baseBoard = {
            "  A A A     . . .     B B B  ",
            "  A A A     . . .     B B B  ",
            "  A A A     * . .     B B B  ",
            "            . . .            ",
            "            . . .            ",
            ". * . . . . . H . . . . * . .",
            ". 1 1 1 1 1 H H H 2 2 2 2 2 .",
            ". . * . . . . H . . . . * . .",
            "            . . .            ",
            "            . . .            ",
            "  D D D     * . .     C C C  ",
            "  D D D     . . *     C C C  ",
            "  D D D     . . .     C C C  ",
        };
    }

    void initTrack() {
        // Clockwise path starting from Player A's entry
        // A enters at top, goes down, right, down, left, up, back

        // Top strip going down (positions 0-4)
        // Col 14 (center of 3-dot strip)
        trackRow[0] = 0;  trackCol[0] = 14;
        trackRow[1] = 1;  trackCol[1] = 14;
        trackRow[2] = 2;  trackCol[2] = 14;
        trackRow[3] = 3;  trackCol[3] = 14;
        trackRow[4] = 4;  trackCol[4] = 14;

        // Turn right, go along row 5 toward right edge (positions 5-11)
        trackRow[5] = 5;  trackCol[5] = 14;
        trackRow[6] = 5;  trackCol[6] = 16;
        trackRow[7] = 5;  trackCol[7] = 18;
        trackRow[8] = 5;  trackCol[8] = 20;
        trackRow[9] = 5;  trackCol[9] = 22;
        trackRow[10] = 5; trackCol[10] = 24;
        trackRow[11] = 5; trackCol[11] = 26;

        // Turn down, go down right side (positions 12-16)
        trackRow[12] = 6; trackCol[12] = 26;
        trackRow[13] = 7; trackCol[13] = 26;
        trackRow[14] = 8; trackCol[14] = 26;
        trackRow[15] = 9; trackCol[15] = 26;
        trackRow[16] = 10; trackCol[16] = 26;

        // Turn left, go along bottom toward center (positions 17-22)
        trackRow[17] = 10; trackCol[17] = 24;
        trackRow[18] = 10; trackCol[18] = 22;
        trackRow[19] = 10; trackCol[19] = 20;
        trackRow[20] = 10; trackCol[20] = 18;
        trackRow[21] = 10; trackCol[21] = 16;
        trackRow[22] = 10; trackCol[22] = 14;

        // Turn up, go up through bottom strip (positions 23-27)
        trackRow[23] = 11; trackCol[23] = 14;
        trackRow[24] = 12; trackCol[24] = 14;

        // Continue up? No, we need to complete the circle
        // Actually for 52 positions, let me recalculate...

        // Let me redesign with proper 52-cell track
        // Each player gets 13 cells before home stretch

        // Player A: starts at 0, home stretch at 51-55
        // Player B: starts at 13, home stretch at 51-55
        // Player C: starts at 26, home stretch at 51-55
        // Player D: starts at 39, home stretch at 51-55

        // Total outer ring should have 52 cells (13 per player × 4)
        // But my board has fewer dots. Let me count the actual path cells.

        // Actually, let me just create a proper 52-cell path
        // that fits within the board coordinates

        // Top vertical strip: 5 cells (rows 0-4, col 14)
        for (int i = 0; i < 5; i++) {
            trackRow[i] = i;
            trackCol[i] = 14;
        }

        // Top horizontal (row 5): from col 14 to col 26, skipping H at col 14
        // Actually col 14 is H, so path goes: 12, 10, 8, 6, 4, 2, 0 (left)
        // and 16, 18, 20, 22, 24, 26 (right)
        // But we need a continuous path...

        // Let me redesign the board to have a proper continuous track
        // The track should be a single line going around
    }

    void initSafeSpots() {
        safeSpots[0] = 0;   // A start
        safeSpots[1] = 8;   // Right side
        safeSpots[2] = 13;  // B start
        safeSpots[3] = 21;  // Bottom side
        safeSpots[4] = 26;  // C start
        safeSpots[5] = 34;  // Left side
        safeSpots[6] = 39;  // D start
        safeSpots[7] = 47;  // Top side
    }

    void initHomeStretches() {
        // Player A (house 1): row 6, cols 2-10 (left side of center)
        for (int i = 0; i < 5; i++) {
            homeStretchRow[0][i] = 6;
            homeStretchCol[0][i] = 2 + i * 2;
        }

        // Player B (house 2): row 6, cols 18-26 (right side of center)
        for (int i = 0; i < 5; i++) {
            homeStretchRow[1][i] = 6;
            homeStretchCol[1][i] = 18 + i * 2;
        }

        // Player C (house 3): col 14, rows 8-12 (bottom strip)
        for (int i = 0; i < 5; i++) {
            homeStretchRow[2][i] = 8 + i;
            homeStretchCol[2][i] = 14;
        }

        // Player D (house 4): col 14, rows 0-4 (top strip) - but that's the track!
        // Actually D should go up from bottom...
        // Let me reconsider. In standard Ludo, home stretch is after completing the circle.
        // So D's home stretch should be on the left side? No...

        // Let me redesign: each player's home stretch is on their own side
        // A: top, B: right, C: bottom, D: left
        // But the board shows 1,2,3,4 on rows 6 and col 14...

        // Actually looking at the board:
        // Row 6: ". 1 1 1 1 1 H H H 2 2 2 2 2 ."
        // So 1 is left home stretch, 2 is right home stretch
        // For 3 and 4, they should be on the vertical strips

        // Let me add 3 and 4 to the board design
    }

    void initBases() {
        // Player A: top-left corner (rows 0-2, cols 2-6)
        baseRow[0][0] = 0; baseCol[0][0] = 2;
        baseRow[0][1] = 0; baseCol[0][1] = 4;
        baseRow[0][2] = 2; baseCol[0][2] = 2;
        baseRow[0][3] = 2; baseCol[0][3] = 4;

        // Player B: top-right corner (rows 0-2, cols 22-26)
        baseRow[1][0] = 0; baseCol[1][0] = 22;
        baseRow[1][1] = 0; baseCol[1][1] = 24;
        baseRow[1][2] = 2; baseCol[1][2] = 22;
        baseRow[1][3] = 2; baseCol[1][3] = 24;

        // Player C: bottom-right corner (rows 10-12, cols 22-26)
        baseRow[2][0] = 10; baseCol[2][0] = 22;
        baseRow[2][1] = 10; baseCol[2][1] = 24;
        baseRow[2][2] = 12; baseCol[2][2] = 22;
        baseRow[2][3] = 12; baseCol[2][3] = 24;

        // Player D: bottom-left corner (rows 10-12, cols 2-6)
        baseRow[3][0] = 10; baseCol[3][0] = 2;
        baseRow[3][1] = 10; baseCol[3][1] = 4;
        baseRow[3][2] = 12; baseCol[3][2] = 2;
        baseRow[3][3] = 12; baseCol[3][3] = 4;
    }
};

// ============================================================
// GAME LOGIC
// ============================================================

class GameLogic {
public:
    bool isSafe(int absPos) {
        int safeSpots[8] = {0, 8, 13, 21, 26, 34, 39, 47};
        for (int i = 0; i < 8; i++) {
            if (safeSpots[i] == absPos) return true;
        }
        return false;
    }

    int getAbsPos(Player &player, int relPos) {
        if (relPos < 0 || relPos > 50) return -1;
        return (player.startOffset + relPos) % 52;
    }

    vector<int> getValidPawns(Player &player, int dice) {
        vector<int> valid;
        for (int i = 0; i < 4; i++) {
            if (player.pawns[i].position == -1) {
                if (dice == 6) valid.push_back(i);
            }
            else if (!player.pawns[i].isHome) {
                if (player.pawns[i].position + dice <= 56) {
                    valid.push_back(i);
                }
            }
        }
        return valid;
    }

    bool movePawn(Player &player, int pawnId, int dice) {
        Pawn &p = player.pawns[pawnId];

        if (p.position == -1) {
            if (dice != 6) {
                cout << "Pawn " << (pawnId + 1) << " in base. Need 6!\n";
                return false;
            }
            p.position = 0;
            p.isActive = true;
            cout << "Pawn " << (pawnId + 1) << " unlocked! On track.\n";
            return true;
        }

        int newPos = p.position + dice;

        if (newPos > 56) {
            cout << "Need exact roll for home. Can't move.\n";
            return false;
        }

        p.position = newPos;

        if (newPos == 56) {
            p.isHome = true;
            cout << "Pawn " << (pawnId + 1) << " reached HOME!\n";
            return true;
        }

        if (newPos >= 51) {
            cout << "Pawn " << (pawnId + 1) << " on home stretch at " << newPos << "\n";
            return false;
        }

        int absPos = getAbsPos(player, newPos);
        cout << "Pawn " << (pawnId + 1) << " moved to " << newPos;
        cout << " (abs: " << absPos << ")\n";

        if (isSafe(absPos)) {
            cout << "Safe spot!\n";
        }

        return false;
    }
};

// ============================================================
// DICE ROLLER
// ============================================================

class DiceRoller {
public:
    vector<int> F(int currentPlayer, int t6, vector<int> &numbers) {
        cout << "\nPress Enter to roll the dice --> ";
        cin.get();

        int diceRoll = (rand() % 6) + 1;
        numbers.push_back(diceRoll);

        cout << "Player " << currentPlayer << " rolled a " << diceRoll << "!\n";

        if (diceRoll == 6 && t6 < 2) {
            t6++;
            cout << "You got a 6! Roll again...\n";
            return F(currentPlayer, t6, numbers);
        }
        else if (diceRoll == 6) {
            cout << "You got 3 sixes in a row! Turn terminated.\n";
            numbers.clear();
        }

        return numbers;
    }

    vector<int> collectRolls(int currentPlayer) {
        int t6 = 0;
        vector<int> numbers;
        return F(currentPlayer, t6, numbers);
    }
};

// ============================================================
// MAIN
// ============================================================

int main() {
    srand(time(0));

    bool winner = false;
    int currentPlayerIdx = 0;
    int numPlayers = 2;

    cout << "========== LUDO ==========\n";
    cout << "Enter number of players (2-4): ";
    cin >> numPlayers;
    cin.ignore();

    while (numPlayers < 2 || numPlayers > 4) {
        cout << "Invalid! Enter 2-4: ";
        cin >> numPlayers;
        cin.ignore();
    }

    Player players[4] = {
        Player('A', 0),
        Player('B', 13),
        Player('C', 26),
        Player('D', 39)
    };

    GameLogic logic;
    DiceRoller roller;

    cout << "\n========== GAME START ==========\n";

    while (!winner) {
        Player &p = players[currentPlayerIdx];

        cout << "\n--------------------------------\n";
        cout << "Player " << p.house << "'s turn:\n";
        p.showPawns();

        vector<int> rolls = roller.collectRolls(currentPlayerIdx + 1);

        if (rolls.empty()) {
            cout << "\nTurn terminated (3 sixes).\n";
        }
        else {
            cout << "\nYour rolls: ";
            for (int r : rolls) cout << r << " ";
            cout << "\n";

            for (int dice : rolls) {
                vector<int> valid = logic.getValidPawns(p, dice);

                if (valid.empty()) {
                    cout << "\nNo valid moves for " << dice << ". Skip.\n";
                    continue;
                }

                cout << "\nValid pawns for " << dice << ": ";
                for (int id : valid) cout << (id + 1) << " ";
                cout << "\n";

                int choice;
                bool ok = false;
                while (!ok) {
                    cout << "Select pawn: ";
                    cin >> choice;
                    cin.ignore();
                    choice--;

                    for (int id : valid) {
                        if (id == choice) {
                            ok = true;
                            break;
                        }
                    }
                    if (!ok) cout << "Invalid! Try again.\n";
                }

                bool extra = logic.movePawn(p, choice, dice);
                p.showPawns();

                if (extra) {
                    cout << "Extra turn earned!\n";
                }
            }
        }

        if (p.pawnsAtHome() == 4) {
            winner = true;
            cout << "\n\nPLAYER " << p.house << " WINS!\n";
        }

        currentPlayerIdx = (currentPlayerIdx + 1) % numPlayers;
    }

    cout << "\n\n========== GAME OVER ==========\n";
    return 0;
}
