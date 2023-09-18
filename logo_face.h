#include <ncurses.h> 
#include <locale.h>

//defind window
WINDOW * W__logo;
WINDOW * W__welcome;
WINDOW * W__about;
WINDOW * W__vertion_sponsor;
WINDOW * W__ABOUT;
WINDOW * W__list;
WINDOW * W__F1;

void ftitle_logo(int max_yw,int max_xw){
    W__logo = newwin(22,140,max_yw  ,max_xw + 3);
    wattron(W__logo,A_BOLD);
    wprintw(W__logo,"--The------------------------------------------------------------------------------------------------------------------------------\n\n");
    wprintw(W__logo,"TTTTTTTTTTTTTTTTTTTTTTT         AAA   WWWWWWWW                           WWWWWWWW     999999999     IIIIIIIIIITTTTTTTTTTTTTTTTTTTTTTT\n");
    wprintw(W__logo,"T:::::::::::::::::::::T        A:::A  W::::::W                           W::::::W   99:::::::::99   I::::::::IT:::::::::::::::::::::T\n");
    wprintw(W__logo,"T:::::::::::::::::::::T       A:::::A W::::::W                           W::::::W 99:::::::::::::99 I::::::::IT:::::::::::::::::::::T\n");
    wprintw(W__logo,"T:::::TT:::::::TT:::::T      A:::::::AW::::::W                           W::::::W9::::::99999::::::9II::::::IIT:::::TT:::::::TT:::::T\n");
    wprintw(W__logo,"TTTTTT  T:::::T  TTTTTT     A:::::::::AW:::::W           WWWWW           W:::::W 9:::::9     9:::::9  I::::I  TTTTTT  T:::::T  TTTTTT\n");
    wprintw(W__logo,"        T:::::T            A:::::A:::::AW:::::W         W:::::W         W:::::W  9:::::9     9:::::9  I::::I          T:::::T        \n");
    wprintw(W__logo,"        T:::::T           A:::::A A:::::AW:::::W       W:::::::W       W:::::W    9:::::99999::::::9  I::::I          T:::::T        \n");
    wprintw(W__logo,"        T:::::T          A:::::A   A:::::AW:::::W     W:::::::::W     W:::::W      99::::::::::::::9  I::::I          T:::::T        \n");
    wprintw(W__logo,"        T:::::T         A:::::A     A:::::AW:::::W   W:::::W:::::W   W:::::W         99999::::::::9   I::::I          T:::::T        \n");
    wprintw(W__logo,"        T:::::T        A:::::AAAAAAAAA:::::AW:::::W W:::::W W:::::W W:::::W               9::::::9    I::::I          T:::::T        \n");
    wprintw(W__logo,"        T:::::T       A:::::::::::::::::::::AW:::::W:::::W   W:::::W:::::W               9::::::9     I::::I          T:::::T        \n");
    wprintw(W__logo,"        T:::::T      A:::::AAAAAAAAAAAAA:::::AW:::::::::W     W:::::::::W               9::::::9      I::::I          T:::::T        \n");
    wprintw(W__logo,"      TT:::::::TT   A:::::A             A:::::AW:::::::W       W:::::::W               9::::::9     II::::::II      TT:::::::TT      \n");
    wprintw(W__logo,"      T:::::::::T  A:::::A               A:::::AW:::::W         W:::::W               9::::::9      I::::::::I      T:::::::::T      \n");
    wprintw(W__logo,"      T:::::::::T A:::::A                 A:::::AW:::W           W:::W               9::::::9       I::::::::I      T:::::::::T      \n");
    wprintw(W__logo,"      TTTTTTTTTTTAAAAAAA                   AAAAAAAWWW             WWW               99999999        IIIIIIIIII      TTTTTTTTTTT      \n\n                                                                                                                      .APPLICATION\n");
    wprintw(W__logo,"-----------------------------------------------------------------------------------------------------------------------------------\n");
    wrefresh(W__logo);

    





}

