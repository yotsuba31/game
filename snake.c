#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

typedef struct Snake {
    int x;
    int y;
    int i;
    int j;
    struct Snake* next;
}snake;
char key, wait;
int score = 0;
snake head = { 33,11,33,11,NULL };
snake* currents = NULL, * then = NULL;
void   gotoxy(int, int);
void   gotoprint(int, int, char*);
void   move(void);
int    food(void);
void   add(void);
void   moves(void);

int main()
{
    /*地图打印*/
    for (int i = 0; i < 66; i++)
    {
        gotoprint(i, 0, "▔");
        gotoprint(i, 26, "▁");
    }
    for (int i = 0; i < 27; i++)
    {
        gotoprint(0, i, "┃");
        gotoprint(65, i, "┃");
    }
    //实现 
    key = _getch();
    while (key != 'w' && key != 's' && key != 'a' && key != 'd')
        key = _getch();
    gotoprint(head.x, head.y, "◆");
    int n = food();
    int a = n / 100, b = n - a * 100;
    int c = 0, d = 0;
    while (1)
    {
        move();
        moves();
        Sleep(115 - score * 3);
        c = a, d = b;
        if (head.x == a && head.y == b)
        {
            score++;
            n = food();
            a = n / 100, b = n - a * 100;
            add();
        }
        else;
        currents = &head;
        then = head.next;
        while (then != NULL)
        {
            if (then->next == NULL && head.x == c && head.y == d)
            {
                gotoprint(then->x, then->y, " ");
                then = then->next;
            }
            else
            {
                if (then->next == NULL)
                    gotoprint(then->x, then->y, " ");
                else;
                then->x = currents->i;
                then->y = currents->j;
                currents = then;
                then = currents->next;
            }
        }
        currents = &head;
        while (currents != NULL)
        {
            currents->i = currents->x;
            currents->j = currents->y;
            currents = currents->next;
        }
        if (_kbhit())
            wait = _getch();
        else;
        if (key != wait)
        {
            if (wait != 'w' && wait != 's' && wait != 'a' && wait != 'd')
                ;
            else if (key == 'w' && wait != 's')
                key = wait;
            else if (key == 's' && wait != 'w')
                key = wait;
            else if (key == 'a' && wait != 'd')
                key = wait;
            else if (key == 'd' && wait != 'a')
                key = wait;
            else;
        }
        else;
    }
    return 0;
}

void gotoxy(int x, int y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void gotoprint(int x, int y, char* a)
{
    gotoxy(x, y);
    printf("%s", a);
}
int  food(void)
{
    srand((unsigned)(time(0) + rand()));
    int m, n;
    m = rand() % 64 + 1;
    n = rand() % 25 + 1;
    snake* current = &head;
    while (current != NULL)
    {
        if (current->x == m && current->y == n)
        {
            srand((unsigned)(time(0) + rand()));
            m = rand() % 64 + 1;
            n = rand() % 25 + 1;
            current = &head;
            continue;
        }
        else;
        current = current->next;
    }
    gotoprint(m, n, "☆");
    return m * 100 + n;
}
void move(void)
{
    gotoprint(head.x, head.y, " ");
    switch (key)
    {
    case 'w':
        (head.y)--;
        (head.j)--;
        break;
    case 's':
        (head.y)++;
        (head.j)++;
        break;
    case 'a':
        (head.x)--;
        (head.i)--;
        break;
    case 'd':
        (head.x)++;
        (head.i)++;
        break;
    default:
        break;
    }
    gotoprint(head.x, head.y, "◆");
}
void moves(void)
{
    snake* current = head.next;
    while (current != NULL)
    {
        gotoprint(current->x, current->y, "○");
        current = current->next;
    }
    current = head.next;
    if (head.x == 0 || head.x == 65 || head.y == 0 || head.y == 26)
    {
        gotoxy(0, 27);
        printf("Your score is %d.\n", score);
        char pau;
        while (1)
        {
            pau = _getch();
            if (pau == 'q')
                exit(0);
            else
                printf("key \'q\' goes quit.\n");
        }
    }
    else;
    while (current != NULL)
    {
        if (head.x == current->x && head.y == current->y)
        {
            gotoxy(0, 27);
            printf("Your score is %d.", score);
            char pau = _getch();
            exit(0);
        }
        else;
        current = current->next;
    }
}
void add(void)
{
    snake* current = &head;
    while (current->next != NULL)
        current = current->next;
    int x = current->x, y = current->y;
    current->next = (snake*)malloc(sizeof(snake));
    current = current->next;
    if (current != NULL)
    {
        current->x = x;
        current->y = y;
        current->i = x;
        current->j = y;
        current->next = NULL;
    }
    else;
}