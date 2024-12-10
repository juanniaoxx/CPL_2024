/* DO NOT MODIFY THIS FILE */
/* In other words, modification in this file has no effect in online-judge */

#include "natcn.h"
#include <stdio.h>
#include <string.h>

int main() {
    const int dx[4] = {-1, 1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    int n, m;
    int map[505][505];

    // Initialize local variables in a new way (maybe), do not use this function in the future before you completely understand it.
    // How to check whether you understand it? Try to predict the result of 'memset(map, 2, sizeof(map))' and 'memset(map, -1, sizeof(map))'.
    // Learning with a question is always better than learning with an answer.
    memset(map, 0, sizeof(map));

    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    // Implement the following functions in src/natcn.c
    // Initialize Value-Position pair array with the given map.
    init(map, n, m);

    // See it as pos[2][2] if you don't understand it.
    int *pos[2];
    for(int i = 1; i <= n * m / 2; i++) {

        // Iterate four directions
        for(int d = 0; d < 4; d++) {
            // Implement the following function in src/natcn.c
            // Get the position of the given value.
            pos[0] = get_position(i, 0);
            pos[1] = get_position(i, 1);

            // Implement the following function in src/natcn.c
            // Check whether Alan Walker can be under the sea.
            if(walk(map, n, m, pos[0][0], pos[0][1], dx[d], dy[d]) &&
               walk(map, n, m, pos[1][0], pos[1][1], dx[d], dy[d])) {

                // Value i is able to be removed.
                printf("%d ", i);
                // Remove the value i from the map
                map[pos[0][0]][pos[0][1]] = 0;
                map[pos[1][0]][pos[1][1]] = 0;
                break;
            }
            
            // Free the memory allocated in get_position, you may not understand it now, but you will understand it in the future.
            free(pos[0]);
            free(pos[1]);
        }
    }
    printf("\n");
    return 0;
}