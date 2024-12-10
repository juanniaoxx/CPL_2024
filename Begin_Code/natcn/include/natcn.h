#pragma once

/* Implement All These Function in src/natcn.c */

#include <stdlib.h>
#include <stdbool.h>

/*
    Initialize your Value-Position pair array with the given map.
    @param
        - map: the map of the game.
        - n: the number of rows of the map.
        - m: the number of columns of the map.
    @notation
        - Define the Value-Position pair array yourself, you may need to define it as a global variable.
    @advanced* (you may ignore this part)
        - But if you have a perfect understanding of pointer, you can allocate memory for this array (remember to free), modify 
          related declarations, parameters, and main.c as you like, run in your own computer, but do not submit it to the online-judge
          because online-judge will substitute the main.c with the original one. Your hard work won't pay (Now I see you in a better place🎵). 
          It's not a good idea to support this diversity here because it will limit your implementation.
*/
void init(int map[][505], int n, int m);

/*
    Get the position of the given value.
    @param
        - value: the value needed to get the position.
        - order: which appearance of the value, range from 0 to 1.
    @return
        - the position of the given value.
    @notation
        - The position is a 1D array with the size of 2.
        - position[0] stands for the x-coordinate of the value, position[1] stands for the y-coordinate 
          of the value.
        - Use heap memory rather than stack memory to store the position. If you can't understand, just 
          do not modify the commented lines in the initial code.
    @advanced* (you may ignore this part)
        - If you wanna know the difference between heap memory and stack memory, you can STFW.
        - If you still bother after STFW, come and meet us in MMWL 604 during office hour.
*/
int *get_position(int value, int order);

/*
    Check whether Alan Walker (Imaginary🎶) with the given direction vector (dx, dy) can walk from 
    the position (x, y) to the border of the map without crushing into obstacles.
    @param
        - map: the map of the game.
        - n: the number of rows of the map.
        - m: the number of columns of the map.
        - x: the x-coordinate of the starting position.
        - y: the y-coordinate of the starting position.
        - dx: the x-coordinate of the direction vector.
        - dy: the y-coordinate of the direction vector.
    @return
        - if Alan Walker can walk to the border (Under The Sea🎵), return true; otherwise, return false.
    @notation
        - The direction vector is a combination of two integers (dx, dy), range in {(-1, 0), (1, 0), (0, -1), (0, 1)}.
          Let's say Alan Walker currently locates at (x, y), then his next position will be (x + dx, y + dy).
        - Boolean type in C is defined in <stdbool.h>, with true and false as the only two values,
          btw you can simply use 1 and 0 to represent true and false.
        - It's not so good to have too many parameters in a function, but it's absolutely worse to have too many 
          global variables in multi-file programs. So, just keep it.
*/
bool walk(int map[][505], int n, int m, int x, int y, int dx, int dy);