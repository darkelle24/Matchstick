/*
** EPITECH PROJECT, 2019
** dab
** File description:
** dab
*/

#ifndef MY_H_
    #define MY_H_

    typedef struct toolbox_t
    {
        int *tab;
        int nbrtotal;
        int nbrcologne;
        int nbrmaxstick;
        int largeur;
    }       toolbox;

    int my_strlen(char const *str, char end);
    void print_game_board_3(toolbox *toolbox, int i, int a, int b);
    void print_game_board_2(toolbox *toolbox);
    void print_game_board(toolbox *toolbox);
    int chartoint(char *nb, char end);
    int my_str_isnum(char const *str, char end);
    toolbox *check_recup_param(int ac, char **av);
    toolbox *prep(toolbox *toolbox);
    int my_put_nbr (long long nb);
    char *readouput(toolbox *toolbox);
    int player_1(toolbox *toolbox, int *pass);
    int player_2_3(toolbox *toolbox, int pass, int matches);
    int player_2_2(toolbox *toolbox, char *str, int *pass, int ligne);
    int player_2(toolbox *toolbox, int ligne, int *pass);
    void print_result(int ligne, int nbrmatch);
    toolbox *player(toolbox *toolbox);
    void algo_safe_check(toolbox *toolbox, int *ligne, int *nbrmatch);
    void algo_win_2(toolbox *toolbox, int *ligne, int *nbrmatch, int pass[]);
    void algo_win_1(toolbox *toolbox, int *ligne, int *nbrmatch, int *pass);
    void algo_ai (int *ligne, int *nbrmatch, toolbox *toolbox);
    toolbox *ai(toolbox *toolbox);
    void write_win(int win);
    int jeu(toolbox *toolbox);
    int main(int ac, char **av);
    void algo_win_2_1(toolbox *toolbox, int *ligne, int *nbrmatch, int pass[]);
#endif /* !MY_H_ */