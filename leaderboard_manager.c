#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PLAYERS 100

// Structure to hold player data
typedef struct {
    char name[MAX_NAME_LEN];
    int score;
} Player;

/**
 * Comparison function for qsort.
 * 1. Primary Sort: High scores come first (descending order).
 * 2. Secondary Sort (Tie-breaker): Alphabetical order (ascending order).
 */
int compare_players(const void* a, const void* b) {
    Player* playerA = (Player*)a;
    Player* playerB = (Player*)b;

    // Check primary score condition
    if (playerB->score != playerA->score) {
        return playerB->score - playerA->score; 
    }

    // Tie-breaker: Alphabetical comparison of names
    return strcmp(playerA->name, playerB->name);
}

/**
 * Displays the top N performers on the leaderboard.
 * Properly manages duplicate ranks for tied players.
 */
void display_leaderboard(Player* players, int count, int top_n) {
    if (count == 0) {
        printf("The leaderboard is currently empty.\n");
        return;
    }

    // Sort players using our custom rules
    qsort(players, count, sizeof(Player), compare_players);

    printf("\n=== LEADERBOARD TOP %d ===\n", top_n > count ? count : top_n);
    printf("%-6s | %-20s | %-6s\n", "Rank", "Player Name", "Score");
    printf("---------------------------------------\n");

    int current_rank = 1;
    for (int i = 0; i < count && i < top_n; i++) {
        // Adjust rank display if someone ties with the previous player
        if (i > 0 && players[i].score < players[i - 1].score) {
            current_rank = i + 1;
        }

        printf("#%-5d | %-20s | %-6d\n", current_rank, players[i].name, players[i].score);
    }
    printf("===============================\n");
}

// --- Demonstration ---
int main() {
    Player leaderboard[MAX_PLAYERS] = {
        {"Alice", 850},
        {"Bob", 920},
        {"Charlie", 850}, // Ties with Alice (Should rank higher alphabetically)
        {"David", 600},
        {"Emma", 950},
        {"Frank", 920}   // Ties with Bob (Should rank lower alphabetically)
    };
    
    int player_count = 6;

    // Display top 5 players
    display_leaderboard(leaderboard, player_count, 5);

    return 0;
}
