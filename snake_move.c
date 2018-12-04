#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define WALL_CELL '*'
#define food $

void snake_move();
void output();
int gameover();
void creat_food();
//画出贪吃蛇的地图 
char map[12][12] = {
    "***********",
    "*XXXXH    *",
    "*         *",
    "*         *",
    "*         *",
    "*         *",
    "*         *",
    "*         *",
    "*         *",
    "*         *",
    "***********",
};
//定义蛇的长度 
int snake_length = 5;
int snake_location_x[10] = {5, 4, 3, 2, 1};
int snake_location_y[10] = {1, 1, 1, 1, 1};
int food_x;
int food_y;


int main() {
    char choice;
    output();
    while (1) {
        scanf(" %c", &choice);
        snake_move();//控制蛇的上下左右移动 
        if (choice == 'w') {
            snake_location_y[0] -= 1;
            map[snake_location_y[0]][snake_location_x[0]] = 'H';
        }
        if (choice == 's') {
            snake_location_y[0] += 1;
            map[snake_location_y[0]][snake_location_x[0]] = 'H';
        }
        if (choice == 'a') { 
            snake_location_x[0] -= 1;
            map[snake_location_y[0]][snake_location_x[0]] = 'H';
        }
        if (choice == 'd') { 
            snake_location_x[0] += 1;
            map[snake_location_y[0]][snake_location_x[0]] = 'H';
        }
        
        if (!gameover()) {
            printf("GAMEOVER!\n");
            return 0;
        } else {
            output();
        }
    }
    return 0;
}

void snake_move() {//控制蛇的走位 
    int i;
    map[snake_location_y[snake_length - 1]][snake_location_x[snake_length - 1]] = ' ';
    for (i = snake_length - 1; i > 0; i--) {
        snake_location_x[i] = snake_location_x[i - 1];
        snake_location_y[i] = snake_location_y[i - 1];
        map[snake_location_y[i]][snake_location_x[i]] = 'X';//使蛇的长度加一 
    }
}

int gameover() {//游戏结束 
    if (snake_location_x[0] == 10 || snake_location_x[0] == 0) {
        return 0;
    }
    if (snake_location_y[0] == 10 || snake_location_y[0] == 0) {
        return 0;
    }
    int i;
	for ( i = 1; i < snake_length; i++) {
        if (snake_location_x[0] == snake_location_x[i] && snake_location_y[0] == snake_location_y[i]) {
            return 0;
        }
    }
    return 1;
}
void output() {//产生新画面 
    int j,i;
	for ( i = 0; i <= 11; i++) {
        for ( j = 0; j <= 11; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}
