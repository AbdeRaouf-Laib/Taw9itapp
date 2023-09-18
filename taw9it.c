#include <ncurses.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <ctype.h>
#include "logo_face.h"
#include <regex.h>

//defind window
WINDOW * W__logo;
WINDOW * W__welcome;
WINDOW * W__about;
WINDOW * W__vertion_sponsor;
WINDOW * W__ABOUT;
WINDOW * W__list_of_using;
WINDOW * W__F1;
WINDOW * W__main;
WINDOW * W__list2_of_using;
WINDOW * W__how_use;
WINDOW * W__return;
WINDOW * W__exit;
WINDOW * W__list1;
WINDOW * W__EDT;
WINDOW * W__tasks;
WINDOW * W__tasks_dec;
WINDOW * W__chenge_tasks;
WINDOW * W__list2;
WINDOW * W__statistcs;
WINDOW * W__results;
WINDOW * W__arguments;
WINDOW * W__hikma;
WINDOW * W__adduser;
WINDOW * W__listuser;
WINDOW * W__print_adduser;
WINDOW * W__print_listuser;
WINDOW * W__name_user ;
WINDOW * W__family_name_user;
WINDOW * W__account_name;
WINDOW * W__passowrd;
WINDOW * W__signin;
WINDOW * W__user1;
WINDOW * W__user2;
WINDOW * W__user3;
WINDOW * W__user4;
WINDOW * W__verification;
WINDOW * W__print;

/*VariWINDOW *ables are used to define colors*/
#define BW 1
#define BLW 2
#define BLB 3
#define RB 4

//const Value
#define welcome "WELCOME; to,"
#define enter 10
#define curs_down 258
#define curs_up 259
#define curs_right 261
#define curs_left 260
#define esc 27
#define f1 265
#define space 32
#define main__width 18
#define main__height 3
#define list__width 22
#define list__height 19 
#define yx__main 0 
#define width__list2 22
#define heigth__list2 15
#define y__list2 3
#define x__list2 1
#define returnandexit__width 19
#define returnanfexit__heigth 3

//define values
int Fonction__Key__values;
int Key__values1;
int Key__values2;
int Key__values3;
int effect__leftandright = 0;
int effect__upanddown1 = 0;
int effect__upanddown2 = 0;
int effect__upanddown3 = 0;
int rtu_print_face;
int rtu_print_face2;
int rtu_print_face_user;
int y__f2_list1;
int x__f2_list1;
int turnKey = 0;
int rounhikma = 1;
int sign_in;
int number_of_user = 0;
int currentline = 1;
int rtu_passowrd = 0;
char line[256];
char * foldername = "Database";
char * foldername1 = "account";
char * userfile = "userfile";
char  userfilebranch[180];
char globalfolder[100];
char file_name[250];
char * nameofwin = "user";
char nameoffile[256];
char infooffile[256];
char basename[256];
//struct declration
typedef struct account{
    char name_user[70];
    char family_name_user[70];
    char passowrd[70];
}account;

//file declration
FILE * numberuser;
FILE * user;
FILE * infofile;
FILE * fi_hikma;

//declration of fonction
void F__Color(); 
int F__print_face();
void F__vertion_sponsor();
int F__face_about();
int F__about(int k);
int F__welcome(int *y1,int *x1);
void F__title(int y1,int x1,int *z1,int *r1);
void F__list(int z1,int r1);
int F__face_F1();
int F__face_user();
void F__print_add_user();
void F__print_list_user();
int F__print_face2();
void F__print_list2_of_using();
void F__list2_of_using();
void F__how_use();
void F__returnandexit();
void F__print_list1_win();
void F__print_list2_win();
void F__print_hikma_win();
int F__Password_verification();

int main(){
    dubT:
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    start_color();
    F__Color();
    keypad(stdscr,TRUE);
    refresh();
    mkdir(foldername,0777);
    snprintf(globalfolder,100,"%s/%s",foldername,foldername1);
    mkdir(globalfolder,0777);
    snprintf(userfilebranch,180,"%s/%s",globalfolder,userfile);
    mkdir(userfilebranch,0777);
    rtu_print_face = F__print_face();
    if(rtu_print_face == esc){
        endwin();
        return 0;
    }
    rtu_print_face_user = F__face_user();
    if(rtu_print_face_user == space){
        clear();
        refresh();
        goto dubT;
    }
    clear();
    endwin();
    return 0;
}

/*define colors*/
void F__Color(){
    init_pair(BW, COLOR_BLACK, COLOR_WHITE);
    init_pair(BLW, COLOR_BLUE, COLOR_WHITE);
    init_pair(BLB, COLOR_BLUE, COLOR_BLACK);
    init_pair(RB, COLOR_RED, COLOR_BLACK);
}

//face app fonction
int F__print_face(){
    dub:
    Key__values1 = curs_down;
    int k = 0;
    int b;

    do{
        int x1;
        int y1;
        int z1,r1;
        
        F__about(k); 
        F__welcome(&y1,&x1);
        F__title(y1,x1,&z1,&r1);
        F__list(z1,r1);
        F__vertion_sponsor();

        delwin(W__logo);
        delwin(W__about);
        delwin(W__welcome);
        delwin(W__list_of_using);
        delwin(W__vertion_sponsor);
            Key__values1 = getch();
            if(Key__values1 == curs_down || Key__values1 == curs_up)
                k++;
            if(k == 1)
                if(Key__values1 == enter){
                    clear();
                    refresh();
                    Key__values1 = F__face_about();
                    break;
                }
            if(k > 1)
                k = 0;

    }while( Key__values1 != enter &&  Key__values1 != esc && Key__values1 != f1);
    if(Key__values1 == f1){
        clear();
        refresh();
        Key__values1 = F__face_F1();;
    }
    if(Key__values1 == 0)
        goto dub;  
    if(Key__values1 == esc)
        return Key__values1;
    
}
//print the vertion and sponsor
void F__vertion_sponsor(){  
    W__vertion_sponsor = newwin(4,40,33,120);
    wattron(W__vertion_sponsor,A_BOLD);
    mvwprintw(W__vertion_sponsor,1,1,"version: 1.00.000.102.H_kakashi R&H");
    mvwprintw(W__vertion_sponsor,2, 1,"Sponsor: 3moke Uchiha_MADARA");
    wattroff(W__vertion_sponsor,A_BOLD);
    wrefresh(W__vertion_sponsor);
}

//print the about content 
int F__face_about(){
        W__ABOUT = newwin(3,40,17,60);
        wrefresh(W__ABOUT);
        wprintw(W__ABOUT,"NOT FOUND!!!press 'enter' for return...");
        wrefresh(W__ABOUT);
        Fonction__Key__values = getch();
        if(Fonction__Key__values == enter){
            clear();
            refresh();
            return Fonction__Key__values = 0;
        }
        else{
            clear();
            refresh();
            F__face_about();
        }
}

//print the about window 
int F__about(int k){
    W__about = newwin(3,11,1,155);
    if( k == 1)
        wbkgd(W__about, COLOR_PAIR(BW));
    
    box(W__about,0,0);
    wattron(W__about,A_BOLD);
    mvwprintw(W__about,1,1,"ABOUT (!)");
    wattroff(W__about,A_BOLD);
    wrefresh(W__about);
    return 0;
}

//print welcome
int F__welcome(int *y1,int *x1){
    int y,x; 
    W__welcome = newwin(4,12,3,8);
    wattron(W__welcome,A_BOLD);
    mvwprintw(W__welcome,1,0,"WELCOME; to,");
    wattroff(W__welcome,A_BOLD);
    wrefresh(W__welcome);
    getmaxyx(W__welcome,y,x);
    *y1 = y;
    *x1 = x;
    return 0;
}

//Calling the logo function from a logo_face lib
void F__title(int y1,int x1,int *z1,int *r1){
    ftitle_logo(8,14);
    int z,r;
    getyx(W__logo, z, r);
    *z1 = z;
    *r1 = r;
}

//useing list 
void F__list(int z1,int r1){
    W__list_of_using = newwin(4, 45,z1 + 13, r1 );
    wattron(W__list2_of_using,A_BOLD);
    wprintw(W__list_of_using,("!!!....press ('F1') how to use ;\n"));
    wprintw(W__list_of_using,("!!!....press ('ENTER') to continue ;\n"));
    wprintw(W__list_of_using,("!!!....press ('ESC') to exit ;\n"));
    wattroff(W__list2_of_using,A_BOLD);
    wrefresh(W__list_of_using);
}

//print f1 content 
int F__face_F1(){
    W__F1 = newwin(3,40,17,60);
        wrefresh(W__F1);
        wprintw(W__F1,"NOT FOUND!!!press 'ENTER' for return...");
        wrefresh(W__F1);
        Fonction__Key__values = getch();
        if(Fonction__Key__values == enter){
            clear();
            refresh();
            return Fonction__Key__values = 0;
        }
        else{
            clear();
            refresh();
            F__face_F1();
        }
}
int F__face_user(){
    dubN:
    effect__leftandright = 0;
    effect__upanddown1 = 0;
    effect__upanddown2 = 0;
    effect__upanddown3 = 0;
    clear();
    refresh();
    do{
        if(Key__values3 == curs_left)
            effect__leftandright--;
        if(Key__values3 == curs_right)
            effect__leftandright++;
        if(effect__leftandright == 0)
            if(Key__values3 == curs_up || Key__values3 == curs_down)
                effect__upanddown1++;
        if(effect__leftandright == 2){
            if(Key__values3 == curs_down)
                effect__upanddown2++;
            else if(Key__values3 == curs_up)
                effect__upanddown2--;
        }
        
        if(effect__leftandright > 2)
            effect__leftandright = 0;
        else if(effect__leftandright < 0)
            effect__leftandright = 2;
        if(effect__upanddown1 > 1)
            effect__upanddown1 = 0;
        if(effect__upanddown1 < 0)
            effect__upanddown1 = 1;
        numberuser = fopen("Database/account/numberuser_file.csv","r");
        if(numberuser != NULL){
            fscanf(numberuser,"%d",&number_of_user);
            fclose(numberuser);
        }
        else{
            number_of_user = 0;
        }
            if(effect__upanddown2 > number_of_user)
                effect__upanddown2 = 0;
            if(effect__upanddown2 < 0)
                effect__upanddown2 = number_of_user;
        F__print_list2_of_using();
        F__print_add_user();
        F__print_list_user();
        if(rtu_print_face2 == space ){
            rtu_print_face2 = 0;
            goto dubN;
        }
        if(rtu_print_face2 == 1){
            return 1;
        }
        Key__values3 = getch();
        if(effect__leftandright == 0){
            if(effect__upanddown1 == 0){
                if(Key__values3 == enter){
                    clear();
                    return space;
                }
            }
            if(effect__upanddown1 == 1)
                if(Key__values3 == enter){
                    clear();
                    refresh();
                    return 1;
                }
        }
    }while(Key__values3 != 32 && Key__values3 != 27);

}

void F__print_add_user(){
    W__print_adduser = newwin(5,20,yx__main + 2, yx__main + 54);
    box(W__print_adduser,0,0);
    wrefresh(W__print_adduser);
    wbkgd(W__print_adduser,COLOR_PAIR(3));
    W__adduser = newwin(23,49,yx__main + 7, yx__main + 40);
    box(W__adduser,0,0);
    wbkgd(W__adduser,COLOR_PAIR(3));
    wrefresh(W__adduser);
    attron(A_BOLD|COLOR_PAIR(1));
    mvprintw(yx__main + 8,yx__main + 45,"Name: ");
    mvprintw(yx__main + 15,yx__main + 45,"Family Name: ");
    mvprintw(yx__main + 22,yx__main + 45,"password: ");
    attroff(A_BOLD|COLOR_PAIR(1));
    refresh();
    W__name_user = subwin(W__adduser,5,41,yx__main + 9,yx__main + 44);
    box(W__name_user,0,0);
    wrefresh(W__name_user);
    W__family_name_user = subwin(W__adduser,5,41,yx__main + 16,yx__main + 44);
    box(W__family_name_user,0,0);
    wrefresh(W__family_name_user);
    W__passowrd = subwin(W__adduser,5,41,yx__main + 23,yx__main + 44);
    box(W__passowrd,0,0);
    wrefresh(W__passowrd);
    W__signin = newwin(3,25,yx__main + 30, yx__main + 52);
    box(W__signin,0,0);
    wattron(W__signin,A_BOLD);  
    mvwprintw(W__signin,1,9,"sign in");
    wattroff(W__signin,A_BOLD);
    wrefresh(W__signin);
    if(effect__leftandright == 1){
        wbkgd(W__print_adduser,COLOR_PAIR(1));
        wattron(W__print_adduser,A_BOLD|COLOR_PAIR(1));
        mvwprintw(W__print_adduser,2,4,"add account");
        wattroff(W__print_adduser,A_BOLD|COLOR_PAIR(1));
        wrefresh(W__print_adduser);
        if(Key__values3 == enter){
            numberuser= fopen("Database/account/numberuser_file.csv","r");
            if(numberuser == NULL){
                number_of_user = 0;
            }
            if(numberuser != NULL){
                fscanf(numberuser,"%d",&number_of_user);
                fclose(numberuser);
            }
            if(number_of_user < 3){
                account info;
                echo();
                curs_set(1);
                int i = 0;
                do{ 
                    mvwgetstr(W__name_user,1,1,info.name_user);
                        while (info.name_user[i] != '\0') {
                            if (!isalpha(info.name_user[i]) && !isspace(info.name_user[i])) {
                                attron( COLOR_PAIR(5)|A_BLINK);
                                mvwprintw(W__adduser,7,1,"(!)Enter only letters of the alphabet or spaces");
                                attroff( COLOR_PAIR(5)|A_BLINK);
                                wrefresh(W__adduser);
                                break;
                            }
                            i++;
                        }  
                }while(strcmp(info.name_user , "\0") == 0 || info.name_user[i] != '\0');
                i = 0;
                do{ 
                    mvwgetstr(W__family_name_user,1,1,info.family_name_user);
                        while (info.family_name_user[i] != '\0') {
                            if (!isalpha(info.family_name_user[i]) && !isspace(info.family_name_user[i])) {
                                attron( COLOR_PAIR(5)|A_BLINK);
                                mvwprintw(W__adduser,14,1,"(!)Enter only letters of the alphabet or spaces");
                                attroff( COLOR_PAIR(5)|A_BLINK);
                                wrefresh(W__adduser);  
                                break;
                            }
                            i++;
                        }  
                }while(strcmp(info.family_name_user , "\0") == 0 || info.family_name_user[i] != '\0');
                i = 0;
                do{ 
                    noecho();
                    mvwgetstr(W__passowrd,1,1,info.passowrd);
                        while (info.passowrd[i] != '\0') {
                            i++;
                        }   
                    if(i < 8 || i > 16){   
                        wattron(W__adduser,A_BOLD);
                        mvwprintw(W__adduser,21,4,"(!)The password must be 8 or 16 character");
                        wattroff(W__adduser,A_BOLD);
                        wrefresh(W__adduser);
                    }
                }while(i < 8 || i > 16 || strcmp(info.passowrd , "\0") == 0 || info.passowrd[i] != '\0');
                    wbkgd(W__signin,COLOR_PAIR(3));
                    wrefresh(W__signin);
                    noecho();
                    curs_set(0);
                    do{
                        sign_in = getch();
                    }while(sign_in != enter && sign_in != curs_right && sign_in != curs_left);
                if(sign_in == enter){
                    snprintf(file_name,300,"%s/%s_%s_user.csv",userfilebranch,info.name_user,info.family_name_user);  
                    infofile = fopen(file_name,"w");
                    if(infofile != NULL){
                        fprintf(infofile,"Name: %s\nFamily Name: %s\n%s",info.name_user,info.family_name_user,info.passowrd);
                        fclose(infofile);
                    }
                    else{
                        mkdir(foldername,0777);
                        snprintf(globalfolder,100,"%s/%s",foldername,foldername1);
                        mkdir(globalfolder,0777);
                        snprintf(userfilebranch,180,"%s/%s",globalfolder,userfile);
                        mkdir(userfilebranch,0777);
                        refresh();
                    }
                    numberuser= fopen("Database/account/numberuser_file.csv","r");
                    if(numberuser != NULL){
                        fscanf(numberuser,"%d",&number_of_user);
                        fclose(numberuser);
                        number_of_user++;
                        numberuser= fopen("Database/account/numberuser_file.csv","w");
                        if(numberuser != NULL){
                            fprintf(numberuser,"%d",number_of_user);
                            fclose(numberuser);
                        }
                        else{
                            mkdir(foldername,0777);
                            snprintf(globalfolder,100,"%s/%s",foldername,foldername1);
                            mkdir(globalfolder,0777);
                            snprintf(userfilebranch,180,"%s/%s",globalfolder,userfile);
                            mkdir(userfilebranch,0777);
                        }
                    }
                    else{
                        numberuser= fopen("Database/account/numberuser_file.csv","w");
                        number_of_user = 0;
                        fprintf(numberuser,"%d",number_of_user);
                        fclose(numberuser);  
                    }
                    
                    user = fopen("Database/account/user_file.csv","a+");
                    if(user != NULL){
                        fprintf(user,"%s\n",file_name);
                        fclose(user);
                    }
                    else{
                        mkdir(foldername,0777);
                        snprintf(globalfolder,100,"%s/%s",foldername,foldername1);
                        mkdir(globalfolder,0777);
                        snprintf(userfilebranch,180,"%s/%s",globalfolder,userfile);
                        mkdir(userfilebranch,0777);
                    }
                }
                wbkgd(W__signin,COLOR_WHITE);
                wrefresh(W__signin);
            }
            else if(number_of_user >= 3){
                echo();
                mvwprintw(W__adduser,21,4,"you are can`t add the user");
                wrefresh(W__adduser);
                noecho();
            }
        }
    }
    else if(effect__leftandright != 1){
        wattron(W__print_adduser,A_BOLD);
        mvwprintw(W__print_adduser,2,4,"add account");
        wattroff(W__print_adduser,A_BOLD);
        wrefresh(W__print_adduser);  
    }
}
void F__print_list_user(){
    account info;
    W__print_listuser = newwin(5,20,yx__main + 2, yx__main + 114);
    box(W__print_listuser,0,0);
    wbkgd(W__print_listuser,COLOR_PAIR(3));
    wrefresh(W__print_listuser);
    wattron(W__print_listuser,A_BOLD);
    mvwprintw(W__print_listuser,2,7,"log in");
    wattroff(W__print_listuser,A_BOLD);
    wrefresh(W__print_listuser);
    if(effect__leftandright == 2){
        wbkgd(W__print_listuser,COLOR_PAIR(1));
        wrefresh(W__print_listuser);
    }
    else{
        wattron(W__print_listuser,A_BOLD);
        mvwprintw(W__print_listuser,2,7,"log in");
        wattroff(W__print_listuser,A_BOLD);
        wrefresh(W__print_listuser);
    }
    W__listuser = newwin(23,49,yx__main + 7, yx__main + 100);
    box(W__listuser,0,0);
    wbkgd(W__listuser,COLOR_PAIR(3));
    numberuser = fopen("Database/account/numberuser_file.csv","r");
    if(numberuser != NULL){
        fscanf(numberuser,"%d",&number_of_user);
        fclose(numberuser);
        if(number_of_user >= 0){
            W__user1 = subwin(W__listuser,9,20,yx__main + 9,yx__main + 103);
            box(W__user1,0,0);
            mvwprintw(W__user1,4,7,"user1");
            if(effect__leftandright == 2){
                if(effect__upanddown2 == 0){
                    wbkgd(W__user1,COLOR_PAIR(1));
                    if(Key__values3 == enter){
                        rtu_passowrd = F__Password_verification();
                        if(rtu_passowrd == 1){
                            rtu_print_face2 = F__print_face2();
                            if(rtu_print_face2 == space){
                                return;
                            }
                        }
                        else{
                            return;
                        }
                    }
                }
            }
            wrefresh(W__user1);
        }
        if(number_of_user >= 1){
            W__user2 = subwin(W__listuser,9,20,yx__main + 9,yx__main + 125);
            box(W__user2,0,0);
            mvwprintw(W__user2,4,7,"user2");
            if(effect__leftandright == 2){
                if(effect__upanddown2 == 1){
                    wbkgd(W__user2,COLOR_PAIR(1));
                    if(Key__values3 == enter){
                        rtu_passowrd = F__Password_verification();
                        if(rtu_passowrd == 1){
                            rtu_print_face2 = F__print_face2();
                            if(rtu_print_face2 == space){
                                return;
                            }
                        }
                        else{
                            return;
                        }
                    }
                }
            }
            wrefresh(W__user2);
        }
        if(number_of_user >= 2){
            W__user3 = subwin(W__listuser,9,20,yx__main + 19,yx__main + 103);
            box(W__user3,0,0);
            mvwprintw(W__user3,4,7,"user3");
            if(effect__leftandright == 2){
                if(effect__upanddown2 == 2){
                    wbkgd(W__user3,COLOR_PAIR(1));
                    if(Key__values3 == enter){
                        rtu_passowrd = F__Password_verification();
                        if(rtu_passowrd == 1){
                            rtu_print_face2 = F__print_face2();
                            if(rtu_print_face2 == space){
                                return;
                            }
                        }
                        else{
                            return;
                        }
                    }
                }
            }
            wrefresh(W__user3);
        }
        if(number_of_user >= 3){
            W__user4 = subwin(W__listuser,9,20,yx__main + 19,yx__main + 125);
            box(W__user4,0,0);
            mvwprintw(W__user4,4,7,"user4");
            if(effect__leftandright == 2){
                if(effect__upanddown2 == 3){
                    wbkgd(W__user4,COLOR_PAIR(1));
                    if(Key__values3 == enter){
                        rtu_passowrd = F__Password_verification();
                        if(rtu_passowrd == 1){
                            rtu_print_face2 = F__print_face2();
                            if(rtu_print_face2 == space){
                                return;
                            }
                        }
                        else{
                            return;
                        }
                    }
                }
            }
            wrefresh(W__user4);
        }
    }
    wrefresh(W__listuser);   
}
int F__Password_verification(){
account info;
    W__verification = newwin(3,46,32,102);
    W__print =  newwin(2,46,30,102);
    mvwprintw(W__print,1,1,"Enter your passowrd*");
    wrefresh(W__print);
    box(W__verification,0,0);
    wrefresh(W__verification);
    echo();
    curs_set(1);
    mvwgetstr(W__verification,1,1,info.passowrd);
    wrefresh(W__verification);
    wclear(W__print);
    wrefresh(W__print);
    wclear(W__verification);
    wrefresh(W__verification);
    noecho();
    curs_set(0);
        user = fopen("Database/account/user_file.csv","r");
        if(user != NULL){
            currentline = 1;
            while(fgets(nameoffile,sizeof(nameoffile),user)){
                for(int i = 0 ; i < 200; i++){
                    if(nameoffile[i] == '\n') 
                        nameoffile[i] = '\0';
                }
                if(currentline == effect__upanddown2 + 1){
                    wrefresh(W__print);
                    fclose(user);
                    break;
                }
                currentline++;    
            }
        }
        infofile = fopen(nameoffile,"r");
        if(infofile == NULL){
        wprintw(W__print,"%s",nameoffile);
        wrefresh(W__print);}
        else if(infofile != NULL){
        currentline = 1;
            while(fgets(infooffile,sizeof(infooffile),infofile)){
                if(currentline == 3){
                    fclose(infofile);
                    break;
                }
                currentline++;
            }
            if(strcmp(infooffile,info.passowrd) == 0){
                return 1;
            }else{
                wprintw(W__print,"Enter the correct passowrd");
                wrefresh(W__print);
                return 0; 
            }
        }
    
}

int F__print_face2(){
    effect__leftandright = 0;
    effect__upanddown1 = 0;
    effect__upanddown2 = 0;
    effect__upanddown3 = 0;
    do{
        if(Key__values2 == curs_right)
            effect__leftandright++;
        else if(Key__values2 == curs_left)
            effect__leftandright--;
        if(Key__values2 == curs_right || Key__values2 == curs_left || Key__values2 == curs_up || Key__values2 == curs_down)
            turnKey++;
        if(turnKey > 5)
            turnKey = 0;
        if(turnKey == 5)
            rounhikma++;
        if(effect__leftandright < 0)
            effect__leftandright = 2;
        else if(effect__leftandright > 2)
            effect__leftandright = 0;
        if(effect__leftandright == 0)
            if(Key__values2 == curs_up || Key__values2 == curs_down)
                effect__upanddown1++;
        if(effect__leftandright == 1){
            if(Key__values2 == curs_down)
                effect__upanddown2++;
            else if(Key__values2 == curs_up)
                effect__upanddown2--;
        }
        if(effect__leftandright == 2){
            if(Key__values2 == curs_down)
                effect__upanddown3++;
            else if(Key__values2 == curs_up)
                effect__upanddown3--;
        }
        
        if(effect__upanddown1 > 1)
            effect__upanddown1 = 0;
        if(effect__upanddown2 > 3)
            effect__upanddown2 = 0;
        else if(effect__upanddown2 < 0)
            effect__upanddown2 = 3;
        if(effect__upanddown3 > 2)
            effect__upanddown3 = 0;
        else if(effect__upanddown3 < 0)
            effect__upanddown3 = 2;
        clear();
        refresh();
        F__print_list2_of_using();
        F__print_list1_win();
        F__print_list2_win();
        F__print_hikma_win();
        Key__values2 = getch();
        if(effect__leftandright == 0){
            if(effect__upanddown1 == 0)
                if(Key__values2 == enter){
                        clear();
                        refresh();
                        return space;
                }
            if(effect__upanddown1 == 1)
                if(Key__values2 == enter){
                        clear();
                        refresh();
                        rtu_print_face2 = 1;
                        return rtu_print_face2 ;
                }
            

        }

    }while(Key__values2 != 32 && Key__values2 != 27);

}

void F__print_list2_of_using(){
    W__main = newwin(main__height,main__width,yx__main,yx__main);
    wborder(W__main,'|','|','-','-','+','+','+','+');
    if(effect__leftandright != 0){
        F__list2_of_using();
        wattron(W__main,A_BOLD);
            mvwprintw(W__main,1,7,"main");
        wattroff(W__main,A_BOLD);
   }
   else if(effect__leftandright == 0){
        F__list2_of_using();
        wbkgd(W__main,COLOR_PAIR(BW));
        wattron(W__main,A_BOLD);
            mvwprintw(W__main,1,7,"main");
        wattroff(W__main,A_BOLD);
   }
    wrefresh(W__main);
    getmaxyx(W__main,y__f2_list1,x__f2_list1);
}
void F__list2_of_using(){
        W__list2_of_using = newwin(heigth__list2,width__list2,y__list2,x__list2);
        if(effect__leftandright == 0){
            box(W__list2_of_using,0,0);
        }
        F__how_use();
        F__returnandexit();
        wrefresh(W__list2_of_using);
}
void F__how_use(){
    W__how_use = subwin(W__list2_of_using ,4 ,19 ,2 ,2 );
    if(effect__leftandright != 0){
        wclear(W__how_use);
    }
    else{
        wattron(W__list2_of_using,A_BOLD);
        mvwprintw(W__list2_of_using,2,1,"('ENTER'):to selcte");
        mvwprintw(W__list2_of_using,4,1,"('SPACE'):to returne");
        mvwprintw(W__list2_of_using,6,1,"('ESC'):to exit");
        wattroff(W__list2_of_using,A_BOLD);
        wrefresh(W__how_use);
    }
}
void F__returnandexit(){
    W__return = subwin(W__list2_of_using,3,19,11,2);
    W__exit = subwin(W__list2_of_using,3,19,14,2);
    if(effect__leftandright != 0){
        wclear(W__exit);
        wclear(W__return);
    }
    else if(effect__leftandright == 0){
        if(effect__upanddown1 == 0){
                wattron(W__return,COLOR_PAIR(BLB)|A_BOLD);
                box(W__return,0,0);
                mvwprintw(W__return,1,1,"*.....return   ");
                wattroff(W__return,COLOR_PAIR(BLB)|A_BOLD); 
                box(W__exit,0,0);
                mvwprintw(W__exit,1,1,"*.....exit   ");
                wrefresh(W__exit);    
            }  
        else if(effect__upanddown1 == 1){   
                box(W__return,0,0);
                mvwprintw(W__return,1,1,"*.....return");
            wattron(W__exit,COLOR_PAIR(BLB)|A_BOLD);
               box(W__exit,0,0);
               mvwprintw(W__exit,1,1,"*.....exit       ");
            wattroff(W__exit,COLOR_PAIR(BLB)|A_BOLD);
        }
    }    
}

void F__print_list1_win(){
    W__list1 = newwin(22,27,y__f2_list1 + 2,x__f2_list1 + 10);
    if(effect__leftandright == 1){
        wbkgd(W__list1,COLOR_PAIR(1));
    }
    box(W__list1,0,0);
    wrefresh(W__list1);
    W__EDT = subwin(W__list1,5,23,y__f2_list1 + 3,x__f2_list1 + 12);
    box(W__EDT,0,0);
    W__tasks = subwin(W__list1,5,23,y__f2_list1 + 8,x__f2_list1 + 12);
    box(W__tasks,0,0);
    W__tasks_dec = subwin(W__list1,5,23,y__f2_list1 + 13,x__f2_list1 + 12);
    box(W__tasks_dec,0,0);
    W__chenge_tasks = subwin(W__list1,5,23,y__f2_list1 + 18,x__f2_list1 + 12);
    box(W__chenge_tasks,0,0);
    if(effect__leftandright == 1){
        if(effect__upanddown2 == 0){
            wattron(W__EDT,A_BOLD|COLOR_PAIR(3));
            mvwprintw(W__EDT,2,5,"Schedule time");
            wattroff(W__EDT,A_BOLD|COLOR_PAIR(3));
            wrefresh(W__EDT);
        }
        else{
            wattron(W__EDT,A_BOLD);
            mvwprintw(W__EDT,2,5,"Schedule time");
            wattroff(W__EDT,A_BOLD);
            wrefresh(W__EDT);            
        }
        if(effect__upanddown2 == 1){
            wattron(W__tasks,A_BOLD|COLOR_PAIR(3));
            mvwprintw(W__tasks,2,9,"Tasks");
            wattroff(W__tasks,A_BOLD|COLOR_PAIR(3));
            wrefresh(W__tasks);
        }
        else{
            wattron(W__tasks,A_BOLD);
            mvwprintw(W__tasks,2,9,"Tasks");
            wattroff(W__tasks,A_BOLD);
            wrefresh(W__tasks);            
        }
        if(effect__upanddown2 == 2){
            wattron(W__tasks_dec,A_BOLD|COLOR_PAIR(3));
            mvwprintw(W__tasks_dec,2,3,"Tasks documention");
            wattroff(W__tasks_dec,A_BOLD|COLOR_PAIR(3));
            wrefresh(W__tasks_dec);
        }
        else{
            wattron(W__tasks_dec,A_BOLD);
            mvwprintw(W__tasks_dec,2,3,"Tasks documention");
            wattroff(W__tasks_dec,A_BOLD);
            wrefresh(W__tasks_dec);            
        }      
        if(effect__upanddown2 == 3){
            wattron(W__chenge_tasks,A_BOLD|COLOR_PAIR(3));
            mvwprintw(W__chenge_tasks,2,6,"Chenge tasks");
            wattroff(W__chenge_tasks,A_BOLD|COLOR_PAIR(3));
            wrefresh(W__chenge_tasks);
        }
        else{
            wattron(W__chenge_tasks,A_BOLD);
            mvwprintw(W__chenge_tasks,2,6,"Chenge tasks");
            wattroff(W__chenge_tasks,A_BOLD);
            wrefresh(W__chenge_tasks);            
        }
    }
    else{
        wattron(W__EDT,A_BOLD);
        mvwprintw(W__EDT,2,5,"Schedule time");
        wattroff(W__EDT,A_BOLD);
        wrefresh(W__EDT);            
        wattron(W__tasks,A_BOLD);
        mvwprintw(W__tasks,2,9,"Tasks");
        wattroff(W__tasks,A_BOLD);
        wrefresh(W__tasks);                      
        wattron(W__tasks_dec,A_BOLD);
        mvwprintw(W__tasks_dec,2,3,"Tasks documention");
        wattroff(W__tasks_dec,A_BOLD);
        wrefresh(W__tasks_dec);      
        wattron(W__chenge_tasks,A_BOLD);
        mvwprintw(W__chenge_tasks,2,6,"Chenge tasks");
        wattroff(W__chenge_tasks,A_BOLD);
        wrefresh(W__chenge_tasks);                 
    }
}
void F__print_list2_win(){
    W__list2 = newwin(19,29,y__f2_list1 + 4,x__f2_list1 + 82);
    if(effect__leftandright == 2){
        wbkgd(W__list2,COLOR_PAIR(1));
    }
    box(W__list2,0,0);
    wrefresh(W__list2);
    W__statistcs = subwin(W__list2,5,27,y__f2_list1 + 5,x__f2_list1 + 83);
    box(W__statistcs,0,0);
    W__results = subwin(W__list2,5,27,y__f2_list1 + 11,x__f2_list1 + 83);
    box(W__results,0,0);
    W__arguments = subwin(W__list2,5,27,y__f2_list1 + 17,x__f2_list1 + 83);
    box(W__arguments,0,0);
    if(effect__leftandright == 2){
        if(effect__upanddown3 == 0){
            wattron(W__statistcs,A_BOLD|COLOR_PAIR(3));
            mvwprintw(W__statistcs,2,9,"Statistcs");
            wattroff(W__statistcs,A_BOLD|COLOR_PAIR(3));
            wrefresh(W__statistcs);
        }
        else{
            wattron(W__statistcs,A_BOLD);
            mvwprintw(W__statistcs,2,9,"Statistcs");
            wattroff(W__statistcs,A_BOLD);
            wrefresh(W__statistcs);            
        }
        if(effect__upanddown3 == 1){
            wattron(W__results,A_BOLD|COLOR_PAIR(3));
            mvwprintw(W__results,2,10,"Results");
            wattroff(W__results,A_BOLD|COLOR_PAIR(3));
            wrefresh(W__results);
        }
        else{
            wattron(W__results,A_BOLD);
            mvwprintw(W__results,2,10,"Results");
            wattroff(W__results,A_BOLD);
            wrefresh(W__results);            
        }
        if(effect__upanddown3 == 2){
            wattron(W__arguments,A_BOLD|COLOR_PAIR(3));
            mvwprintw(W__arguments,2,9,"Arguments");
            wattroff(W__arguments,A_BOLD|COLOR_PAIR(3));
            wrefresh(W__arguments);
        }
        else{
            wattron(W__arguments,A_BOLD);
            mvwprintw(W__arguments,2,9,"Arguments");
            wattroff(W__arguments,A_BOLD);
            wrefresh(W__arguments);            
        }
    }
    else{
        wattron(W__statistcs,A_BOLD);
        mvwprintw(W__statistcs,2,9,"Statistcs");
        wattroff(W__statistcs,A_BOLD);
        wrefresh(W__statistcs);    
        wattron(W__results,A_BOLD);
        mvwprintw(W__results,2,10,"Results");
        wattroff(W__results,A_BOLD);
        wrefresh(W__results);       
        wattron(W__arguments,A_BOLD);
        mvwprintw(W__arguments,2,9,"Arguments");
        wattroff(W__arguments,A_BOLD);
        wrefresh(W__arguments);                         
    }

}

void F__print_hikma_win(){
    W__hikma = newwin(7,165,y__f2_list1 + 27,1);
    box(W__hikma,0,0);
    if(rounhikma == 52){
        rounhikma = 1;
    }
    fi_hikma = fopen("hikma.txt","r");
    if (fi_hikma == NULL) {
        mvwprintw(W__hikma,1,1,"Error opening file");
        wrefresh(W__hikma);
        return ;
    }
    for (int current_line = 1; fgets(line, sizeof(line), fi_hikma) ; current_line++) {
        if (current_line == rounhikma) {
            mvwprintw(W__hikma,3,2,"%s", line);
            break;
        }
    }
    wrefresh(W__hikma);
    fclose(fi_hikma);
}

