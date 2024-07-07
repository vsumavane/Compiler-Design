#include<stdio.h>
#include<string.h>
#include<ctype.h>

void followfirst(char , int , int);
void findfirst(char , int , int);
void follow(char c);

int count,n=0;
char calc_first[10][100];
char calc_follow[10][100];
char producWon[10][10], first[10];
char f[10];
int k;
char ck;
int e;

int main(int argc,char **argv) {
    int jm=0;
    int km=0;
    int i,choice;
    char c,ch;

    printf("How many productions? : ");
    scanf("%d", &count);
    printf("\nEnter %d productions in form A=B where A and B are grammar symbols:\n\n", count);
    
    for(i=0;i<count;i++) {
        scanf("%s%c", producWon[i], &ch);
    }

    int kay;
    char done[count];
    int ptr = -1;
    
    for(k=0;k<count;k++) {
        for(kay=0;kay<100;kay++) {
            calc_first[k][kay] = '!';
        }
    }

    int point1 = 0,point2,xxx;
    
    printf("\nFirst sets:\n");
    for(k=0;k<count;k++) {
        c=producWon[k][0];
        point2 = 0;
        xxx = 0;
        
        for(kay = 0; kay <= ptr; kay++)
            if(c == done[kay])
                xxx = 1;
        
        if (xxx == 1) continue;
        
        findfirst(c,0,0);
        ptr+=1;
        done[ptr] = c;
        printf("\nFirst(%c) = { ",c);
        calc_first[point1][point2++] = c;
        
        for(i=0+jm;i<n;i++) {
            int lark = 0,chk = 0;
            
            for(lark=0;lark<point2;lark++) {
                if (first[i] == calc_first[point1][lark]) {
                    chk = 1;
                    break;
                }
            }
            
            if(chk == 0) {
                printf("%c, ",first[i]);
                calc_first[point1][point2++] = first[i];
            }
        }
        printf("}\n");
        jm=n;
        point1++;
    }

    printf("\nFollow sets:\n");
    for (i = 0; i < count; i++) {
        printf("\nFollow(%c) = { ", producWon[i][0]);
        for (int j = 0; j < strlen(calc_follow[i]); j++) {
            printf("%c ", calc_follow[i][j]);
        }
        printf("}\n");
    }

    printf("\n");

    return 0;
}

void follow(char c) {
    int i,j;
    int m = 0;
    
    if(producWon[0][0]==c) {
        f[m++]='$';
    }
    
    for(i=0;i<10;i++) {
        for(j=2;j<10;j++) {
            if(producWon[i][j]==c) {
                if(producWon[i][j+1]!='\0') {
                    followfirst(producWon[i][j+1],i,(j+2));
                }
                if(producWon[i][j+1]=='\0' && c!=producWon[i][0]) {
                    follow(producWon[i][0]);
                }
            }
        }
    }
}

void findfirst(char c, int q1, int q2) {
    int j;
    
    if(!(isupper(c))) {
        first[n++]=c;
    }
    
    for(j=0;j<count;j++) {
        if(producWon[j][0]==c) {
            if(producWon[j][2]=='#') {
                if(producWon[q1][q2] == '\0') {
                    first[n++]='#';
                }
                else if(producWon[q1][q2] != '\0' && (q1 != 0 || q2 != 0)) {
                    findfirst(producWon[q1][q2], q1, (q2+1));
                }
                else {
                    first[n++]='#';
                }
            }
            else if(!isupper(producWon[j][2])) {
                first[n++]=producWon[j][2];
            }
            else {
                findfirst(producWon[j][2], j, 3);
            }
        }
    }
}

void followfirst(char c, int c1, int c2) {
    int k;
    int m = 0;
    
    if(!(isupper(c))) {
        f[m++]=c;
    }
    else {
        int i=0,j=1;
        
        for(i=0;i<count;i++) {
            if(calc_first[i][0] == c) {
                break;
            }
        }
        
        while(calc_first[i][j] != '!') {
            if(calc_first[i][j] != '#') {
                f[m++] = calc_first[i][j];
            }
            else {
                if(producWon[c1][c2] == '\0') {
                    follow(producWon[c1][0]);
                }
                else {
                    followfirst(producWon[c1][c2],c1,c2+1);
                }
            }
            j++;
        }
    }
}
