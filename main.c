#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
void fileraw();
void fragmentationofcode(char chrt[1000000], int sayac);
int fragmentationoffunctions(char chrt[1000000], int x, int y);
int spacecomplexity(char calc[], int size);
void calculator_showing();
void recursivefinder(char chrt[1000000], char funcname[100], int sizechrt, int sizefuncname);
int timecomplexity(char frac[], int size);
int insidecontrol(char frac[], int size);
int ekleyici(int time, int space);
struct calculator
{
    int time;
    int space;
    struct calculator *next;
} calculator;
struct calculator *front = NULL;
struct calculator *rear = NULL;

int ekleyici(int time, int space)
{
    struct calculator *timeandspace;
    if (front == NULL)
    {
        struct calculator *new = (struct calculator *)malloc(sizeof(struct calculator));
        new->time = time;
        new->space = space;
        new->next = NULL;
        front = rear = new;
    }
    else
    {
        struct calculator *new = (struct calculator *)malloc(sizeof(struct calculator));
        new->time = time;
        new->space = space;
        new->next = NULL;
        rear->next = new;
        rear = new;
    }
}

void calculator_showing()
{
    int max1 = 0;
    int max2 = 0;
    struct calculator *cr = front;
    while (cr != NULL)
    {
        if (max1 < cr->time)
        {
            max1 = cr->time;
        }
        if (max2 < cr->space)
        {
            max2 = cr->space;
        }
        cr = cr->next;
    }
    if (max1 == 2)
    {
        printf("Zaman karmasikligi: O(1)\n");
    }
    if (max1 == 3)
    {
        printf("Zaman karmasikligi: O(log(n))\n");
    }
    if (max1 == 4)
    {
        printf("Zaman karmasikligi: O([log(n)]^2)\n");
    }
    if (max1 == 5)
    {
        printf("Zaman karmasikligi: O(n)\n");
    }
    if (max1 == 6)
    {
        printf("Zaman karmasikligi: O([log(n)]^3)\n");
    }
    if (max1 == 7)
    {
        printf("Zaman karmasikligi: O(nlog(n))\n");
    }
    if (max1 == 8)
    {
        printf("Zaman karmasikligi: O(n.[log(n)]^2)\n");
    }
    if (max1 == 9)
    {
        printf("Zaman karmasikligi: O(n^2)\n");
    }
    if (max1 == 10)
    {
        printf("Zaman karmasikligi: O(n^2.log(n))\n");
    }
    if (max1 == 11)
    {
        printf("Zaman karmasikligi: O(n^3)\n");
    }
    if (max2 > 50)
    {
        printf("Yer karmasikligi: O(n^2)\n");
    }
    if (max2 >= 10 && max2 < 20)
    {
        printf("Yer karmasikligi: O(n)\n");
    }
    if (max2 < 10)
    {
        printf("Yer karmasikligi: O(1)\n");
    }
}

void fileraw()
{
    FILE *input;
    char chrt[1000000];
    char character;
    int sayac = 0;
    if ((input = fopen("input.txt", "r")) == NULL)
    {
        printf("input dosyasi bulunamadi.");
    }
    else
    {
        do
        {
            character = fgetc(input);
            printf("%c",character);
            chrt[sayac] = character;
            sayac++;
        } while (character != EOF);
    }
    FILE *program;
    program = fopen("program.c", "a+");
    if (program == NULL)
    {
    }
    else
    {
        for (int i = 0; i < sayac - 1; i++)
        {
            if (i == 0)
            {
                fprintf(program, "#include <time.h>\n");
            }
            fprintf(program, "%c", chrt[i]);
            if (chrt[i - 6] == 'm' && chrt[i - 5] == 'a' && chrt[i - 4] == 'i' && chrt[i - 3] == 'n' && chrt[i - 2] == '(' && chrt[i - 1] == ')' && chrt[i] == '{')
            {
                fprintf(program, "time_t t;int begin = clock(),end;double tt;");
            }
            if (chrt[i + 1] == 'r' && chrt[i + 2] == 'e' && chrt[i + 3] == 't' && chrt[i + 4] == 'u' && chrt[i + 5] == 'r' && chrt[i + 6] == 'n' && chrt[i + 8] == '0' && chrt[i + 9] == ';')
            {
                char pr[21] = {'"', ' ', ' ', 'z', 'a', 'm', 'a', 'n', '-', '>', ' ', '%', 'l', 'f', '"', ',', 't', 't', ')', ';', '\n'};
                fprintf(program, "end = clock();tt = (double)(end-begin)/CLOCKS_PER_SEC;printf(");
                for (int i = 0; i < 21; i++)
                {
                    fprintf(program, "%c", pr[i]);
                }
            }
        }
    }
    fclose(program);
    fragmentationofcode(chrt, sayac);
}

void fragmentationofcode(char chrt[1000000], int sayac)
{
    int voidintpoint[20] = {};
    int sizevoidint = sizeof(voidintpoint) / sizeof(voidintpoint[0]);
    int xvoidint = 0;
    char funcname[250] = {};
    int xfuncname = 0;
    for (int i = 0; i < sayac - 1; i++)
    {
        if (chrt[i - 3] == 'v' && chrt[i - 2] == 'o' && chrt[i - 1] == 'i' && chrt[i] == 'd')
        {
            voidintpoint[xvoidint] = i - 3;
            xvoidint++;
        }
        if (chrt[i - 2] == 'i' && chrt[i - 1] == 'n' && chrt[i] == 't')
        {
            if (chrt[i - 4] == '>' || chrt[i - 4] == '}')
            {
                voidintpoint[xvoidint] = i - 2;
                xvoidint++;
            }
        }
    }

    for (xvoidint = 0; xvoidint < sizevoidint; xvoidint++)
    {
        if (voidintpoint[xvoidint] != 0 && voidintpoint[xvoidint + 1] != 0)
        {
            for (int i = voidintpoint[xvoidint]; i < voidintpoint[xvoidint] + 20; i++)
            {
                if (chrt[i] == '(')
                {
                    break;
                }
                else
                {
                    funcname[xfuncname] = chrt[i];
                    xfuncname++;
                }
            }
        }
        else if (voidintpoint[xvoidint] != 0 && voidintpoint[xvoidint + 1] == 0)
        {
            for (int i = voidintpoint[xvoidint]; i < voidintpoint[xvoidint] + 20; i++)
            {
                if (chrt[i] == '(')
                {
                    break;
                }
                else
                {
                    funcname[xfuncname] = chrt[i];
                    xfuncname++;
                }
            }
        }
        else
        {
            break;
        }
    }
    int funcpoint[20] = {};
    int sizefuncpoint = sizeof(funcpoint) / sizeof(funcpoint[0]);
    int xfuncpoint = 0;
    for (int i = 0; i < xfuncname; i++)
    {
        if (funcname[i - 3] == 'v' && funcname[i - 2] == 'o' && funcname[i - 1] == 'i' && funcname[i] == 'd')
        {
            funcpoint[xfuncpoint] = i + 2;
            xfuncpoint++;
        }
        if (funcname[i - 2] == 'i' && funcname[i - 1] == 'n' && funcname[i] == 't')
        {
            funcpoint[xfuncpoint] = i + 2;
            xfuncpoint++;
        }
    }
    for (int i = 0; i < xfuncpoint; i++)
    {
        if (funcpoint[i] != 0 && funcpoint[i + 1] != 0)
        {
            char fonkad[20] = {};
            int xfonkad = 0;
            for (int j = funcpoint[i]; j < funcpoint[i + 1]; j++)
            {
                if (funcname[j] == 'v' && funcname[j + 1] == 'o' && funcname[j + 2] == 'i' && funcname[j + 3] == 'd')
                {
                    break;
                }
                if (funcname[j] == 'i' && funcname[j + 1] == 'n' && funcname[j + 2] == 't')
                {
                    break;
                }
                if (funcname[j] == 32)
                {
                    break;
                }
                else
                {
                    fonkad[xfonkad] = funcname[j];
                    xfonkad++;
                }
            }
            recursivefinder(chrt, fonkad, sayac, xfonkad);
        }
        else
        {
            break;
        }
    }
    for (xvoidint = 0; xvoidint < sizevoidint; xvoidint++)
    {
        if (voidintpoint[xvoidint] != 0 && voidintpoint[xvoidint + 1] != 0)
        {
            fragmentationoffunctions(chrt, voidintpoint[xvoidint], voidintpoint[xvoidint + 1]);
        }
        else if (voidintpoint[xvoidint] != 0 && voidintpoint[xvoidint + 1] == 0)
        {
            fragmentationoffunctions(chrt, voidintpoint[xvoidint], sayac - 1);
        }
        else
        {
            break;
        }
    }
}

void recursivefinder(char chrt[1000000], char funcname[100], int sizechrt, int sizefuncname)
{
    int i, j, ls, lw1, temp, chk = 0;
    ls = sizechrt;
    lw1 = sizefuncname;
    int counterofreoccuring = 0;
    int point[10] = {};
    int xpoint = 0;
    for (i = 0; i < ls; i++)
    {
        temp = i;
        for (j = 0; j < lw1; j++)
        {
            if (chrt[i] == funcname[j])
            {
                i++;
            }
        }
        chk = i - temp;
        if (chk == lw1)
        {
            counterofreoccuring++;
            point[xpoint] = i;
            xpoint++;
        }
    }
    if (counterofreoccuring == 3)
    {
        for (int i = 0; i < point[1] + 6; i++)
        {
            if (chrt[i - 1] == ')' && chrt[i] == ';')
            {
                if (chrt[i - 3] == '+')
                {
                    printf("Zaman karmasikligi: O(n)\n");
                }
                if (chrt[i - 3] == '-')
                {
                    printf("Zaman karmasikligi: O(n)\n");
                }
                if (chrt[i - 3] == '*')
                {
                    printf("Zaman karmasikligi: O(log(n))\n");
                }
                if (chrt[i - 3] == '/')
                {
                    printf("Zaman karmasikligi: O(log(n))\n");
                }
            }
            if (chrt[i - 2] == 'f' && chrt[i - 1] == 'o' && chrt[i] == 'r')
            {
                printf("Zaman karmasikligi: O(n^2)\n");
            }
        }
    }
    if (counterofreoccuring == 4)
    {
        printf("Zaman karmasikligi: O(a^n)\n");
    }
    return counterofreoccuring;
}

int fragmentationoffunctions(char chrt[1000000], int x, int y)
{
    int typepoint[10000] = {};
    int at1 = 32, at2 = 10, at3 = 9;
    int sizetypepoint = sizeof(typepoint) / sizeof(typepoint[0]);
    int xtype = 0;
    int typefunc[10000] = {};
    int sizetypefunc = sizeof(typefunc) / sizeof(typefunc[0]);
    int xtypefunc = 0;
    char chrtx[10000] = {};
    char chrty[10000] = {};
    char frag[10000] = {};
    int sizefrag = sizeof(frag) / sizeof(frag[0]);
    int xfrag = 0;
    char frac[10000] = {};
    int xfrac = 0;
    int tutucu[150] = {};
    int sizetutucu = sizeof(tutucu) / sizeof(tutucu[0]);
    int xtutucu = 0;
    char letkeep[150] = {};
    int sizeletkeep = sizeof(letkeep) / sizeof(letkeep[0]);
    int xletkeep = 0;
    int numkeep[150] = {};
    int j = 0;
    int r = 0;
    int xxx = 0;
    int yyy = 0;

    for (int i = x; i < y; i++)
    {
        if (chrt[i - 2] == 'f' && chrt[i - 1] == 'o' && chrt[i] == 'r')
        {
            typefunc[xtypefunc] = i - 2;
            xtypefunc++;
        }
        if (chrt[i - 4] == 'w' && chrt[i - 3] == 'h' && chrt[i - 2] == 'i' && chrt[i - 1] == 'l' && chrt[i] == 'e')
        {
            typefunc[xtypefunc] = i - 4;
            xtypefunc++;
        }
        if (chrt[i - 2] == 'd' && chrt[i - 1] == 'o' && chrt[i] == '{')
        {
            typefunc[xtypefunc] = i - 2;
            xtypefunc++;
        }
        if (chrt[i - 5] == 's' && chrt[i - 4] == 'w' && chrt[i - 3] == 'i' && chrt[i - 2] == 't' && chrt[i - 1] == 'c' && chrt[i] == 'h')
        {
            typefunc[xtypefunc] = i - 5;
            xtypefunc++;
        }
        if (chrt[i - 3] == 'c' && chrt[i - 2] == 'a' && chrt[i - 1] == 's' && chrt[i] == 'e')
        {
            typefunc[xtypefunc] = i - 3;
            xtypefunc++;
        }
        if (chrt[i - 1] == 'i' && chrt[i] == 'f')
        {
            typefunc[xtypefunc] = i - 1;
            xtypefunc++;
        }
        if (chrt[i - 5] == 'e' && chrt[i - 4] == 'l' && chrt[i - 3] == 's' && chrt[i - 2] == 'e' && chrt[i - 1] == 'i' && chrt[i] == 'f')
        {
            typefunc[xtypefunc] = i - 5;
            xtypefunc++;
        }
        if (chrt[i - 3] == 'e' && chrt[i - 2] == 'l' && chrt[i - 1] == 's' && chrt[i] == 'e')
        {
            typefunc[xtypefunc] = i - 3;
            xtypefunc++;
        }
        if (chrt[i + 1] == 'r' && chrt[i + 2] == 'e' && chrt[i + 3] == 't' && chrt[i + 4] == 'u' && chrt[i + 5] == 'r' && chrt[i + 6] == 'n' && chrt[i + 8] != '0' && chrt[i + 8] != '1' && chrt[i + 9] != ';')
        {
            typepoint[xtype] = i + 1;
            xtype++;
        }
        if (chrt[i - 4] != '}' && chrt[i - 4] != '>' && chrt[i - 3] != 'r' && chrt[i - 2] == 'i' && chrt[i - 1] == 'n' && chrt[i] == 't')
        {
            typepoint[xtype] = i - 2;
            xtype++;
        }
        if (chrt[i - 3] == 'c' && chrt[i - 2] == 'h' && chrt[i - 1] == 'a' && chrt[i] == 'r')
        {
            typepoint[xtype] = i - 3;
            xtype++;
        }
        if (chrt[i - 5] == 'd' && chrt[i - 4] == 'o' && chrt[i - 3] == 'u' && chrt[i - 2] == 'b' && chrt[i - 1] == 'l' && chrt[i] == 'e')
        {
            typepoint[xtype] = i - 5;
            xtype++;
        }
        if (chrt[i - 4] == 's' && chrt[i - 3] == 'h' && chrt[i - 2] == 'o' && chrt[i - 1] == 'r' && chrt[i] == 't')
        {
            typepoint[xtype] = i - 4;
            xtype++;
        }
        if (chrt[i - 3] == 'l' && chrt[i - 2] == 'o' && chrt[i - 1] == 'n' && chrt[i] == 'g')
        {
            typepoint[xtype] = i - 3;
            xtype++;
        }
        if (chrt[i - 4] == 'f' && chrt[i - 3] == 'l' && chrt[i - 2] == 'o' && chrt[i - 1] == 'a' && chrt[i] == 't')
        {
            typepoint[xtype] = i - 4;
            xtype++;
        }
        if (chrt[i - 9] == 'l' && chrt[i - 8] == 'o' && chrt[i - 7] == 'n' && chrt[i - 6] == 'g' && chrt[i - 5] == 'd' && chrt[i - 4] == 'o' && chrt[i - 3] == 'u' && chrt[i - 2] == 'b' && chrt[i - 1] == 'l' && chrt[i] == 'e')
        {
            typepoint[xtype] = i - 9;
            xtype++;
        }
    }

    for (int i = 0; i < y; i++)
    {
        if (chrt[i] == at1 || chrt[i] == at2 || chrt[i] == at3)
        {
            continue;
        }
        else
        {
            chrty[i] = chrt[i];
            chrtx[i] = chrt[i];
        }
    }
    for (xtypefunc = 0; xtypefunc < sizetypefunc; xtypefunc++)
    {
        if (typefunc[xtypefunc] != 0 && typefunc[xtypefunc + 1] != 0)
        {
            for (int i = typefunc[xtypefunc]; i < typefunc[xtypefunc + 1]; i++)
            {
                frac[xfrac] = chrty[i];
                xfrac++;
            }
        }
        else if (typefunc[xtypefunc] != 0 && typefunc[xtypefunc + 1] == 0)
        {
            for (int i = typefunc[xtypefunc]; i < y; i++)
            {
                frac[xfrac] = chrty[i];
                xfrac++;
            }
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < xfrac - 2; i++)
    {
        if (frac[i] == 123)
        {
            letkeep[xletkeep] = 'A';
            numkeep[xletkeep] = i;
            xletkeep++;
        }
        if (frac[i] == 125 && frac[i + 1] != 'w')
        {
            letkeep[xletkeep] = 'K';
            numkeep[xletkeep] = i;
            xletkeep++;
        }
        if (frac[i] == 125 && frac[i + 1] == 'w')
        {
            // if(frac[i+11]==';')
            // {
            //     letkeep[xletkeep] = 'K';
            //     numkeep[xletkeep] = i+11;
            //     xletkeep++;
            // }
            // if(frac[i+12]==';')
            // {
            //     letkeep[xletkeep] = 'K';
            //     numkeep[xletkeep] = i+12;
            //     xletkeep++;
            // }
            // if(frac[i+13]==';')
            // {
            //     letkeep[xletkeep] = 'K';
            //     numkeep[xletkeep] = i+13;
            //     xletkeep++;
            // }
            // if(frac[i+14]==';')
            // {
            //     letkeep[xletkeep] = 'K';
            //     numkeep[xletkeep] = i+14;
            //     xletkeep++;
            // }
            // if(frac[i+15]==';')
            // {
            //     letkeep[xletkeep] = 'K';
            //     numkeep[xletkeep] = i+15;
            //     xletkeep++;
            // }
        }
    }
    int prob = 0;
    int increasing = 0;
    int decreasing = 0;
    int timecomp[20] = {};
    int xtimecomp = 0;
    for (int i = 0; i < sizeletkeep; i++)
    {
        if (letkeep[i] == 0 || numkeep[i] == 0)
        {
            break;
        }
        else
        {
            if (letkeep[i] == 'A')
            {
                increasing++;
            }
            if (letkeep[i] == 'K')
            {
                decreasing++;
            }
            if (increasing == decreasing)
            {
                char funky[1000] = {};
                int xfunky = 0;
                for (xfrac = prob; xfrac < numkeep[i] + 1; xfrac++)
                {
                    funky[xfunky] = frac[xfrac];
                    xfunky++;
                }
                timecomp[xtimecomp] = timecomplexity(funky, 1000);
                xtimecomp++;
                increasing = 0;
                decreasing = 0;
                prob = numkeep[i] + 1;
            }
        }
    }
    for (int i = 0; i < 20; ++i)
    {
        if (timecomp[i] == 0)
        {
            break;
        }
        else
        {
            if (timecomp[0] < timecomp[i])
            {
                timecomp[0] = timecomp[i];
            }
        }
    }
    for (xtype = 0; xtype < sizetypepoint; xtype++)
    {
        if (typepoint[xtype] != 0 && typepoint[xtype + 1] != 0)
        {
            for (int i = typepoint[xtype]; i < typepoint[xtype + 1]; i++)
            {
                frag[xfrag] = chrtx[i];
                xfrag++;
                if (chrtx[i] == ';' || chrtx[i] == ')')
                {
                    break;
                }
            }
        }
        else if (typepoint[xtype] != 0 && typepoint[xtype + 1] == 0)
        {
            for (int i = typepoint[xtype]; i < y - 1; i++)
            {
                frag[xfrag] = chrtx[i];
                xfrag++;
                if (chrtx[i] == ';' || chrtx[i] == ')')
                {
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < sizefrag; i++)
    {
        if (frag[i] == ';' || frag[i] == ')')
        {
            tutucu[xtutucu] = i;
            xtutucu++;
        }
    }
    int spacecomp[20] = {};
    int xspacecomp = 0;
    for (xtutucu = 0; xtutucu < sizetutucu; xtutucu++)
    {
        if (tutucu[xtutucu] == 0)
        {
            break;
        }
        else
        {
            char calc[50] = {};
            int xcalc = 0;
            for (j = xxx; j < tutucu[xtutucu]; j++)
            {
                calc[xcalc] = frag[j];
                xcalc++;
            }
            spacecomp[xspacecomp] = spacecomplexity(calc, 50);
            xspacecomp++;
            xxx = tutucu[xtutucu];
        }
    }
    for (int i = 0; i < 20; ++i)
    {
        if (spacecomp[i] == 0)
        {
            break;
        }
        else
        {
            if (spacecomp[0] < spacecomp[i])
            {
                spacecomp[0] = spacecomp[i];
            }
        }
    }
    ekleyici(timecomp[0], spacecomp[0]);
}

int spacecomplexity(char calc[], int size)
{
    int toplam = 0;
    for (int i = 0; i < size; i++)
    {
        if (calc[i] != ';')
        {
        }
        if (calc[i - 2] == 'i' && calc[i - 1] == 'n' && calc[i] == 't')
        {
            toplam += 1;
        }
        if (calc[i] == ',' && toplam > 0)
        {
            toplam += 1;
        }
        if (calc[i] == ']')
        {
            toplam += 10;
            toplam -= 1;
        }
        if (calc[i - 1] == ']' && calc[i] == '[')
        {
            toplam += 100;
            toplam -= 17;
        }
        if (calc[i + 1] == 'r' && calc[i + 2] == 'e' && calc[i + 3] == 't' && calc[i + 4] == 'u' && calc[i + 5] == 'r' && calc[i + 6] == 'n')
        {
            toplam += 10;
        }
        if (calc[i - 3] == 'c' && calc[i - 2] == 'h' && calc[i - 1] == 'a' && calc[i] == 'r')
        {
            toplam += 1;
        }
        if (calc[i - 5] == 'd' && calc[i - 4] == 'o' && calc[i - 3] == 'u' && calc[i - 2] == 'b' && calc[i - 1] == 'l' && calc[i] == 'e')
        {
            toplam += 2;
        }
        if (calc[i - 4] == 's' && calc[i - 3] == 'h' && calc[i - 2] == 'o' && calc[i - 1] == 'r' && calc[i] == 't')
        {
            toplam += 1;
        }
        if (calc[i - 3] == 'l' && calc[i - 2] == 'o' && calc[i - 1] == 'n' && calc[i] == 'g')
        {
            toplam += 2;
        }
        if (calc[i - 4] == 'f' && calc[i - 3] == 'l' && calc[i - 2] == 'o' && calc[i - 1] == 'a' && calc[i] == 't')
        {
            toplam += 1;
        }
        if (calc[i - 9] == 'l' && calc[i - 8] == 'o' && calc[i - 7] == 'n' && calc[i - 6] == 'g' && calc[i - 5] == 'd' && calc[i - 4] == 'o' && calc[i - 3] == 'u' && calc[i - 2] == 'b' && calc[i - 1] == 'l' && calc[i] == 'e')
        {
            toplam += 2;
        }
    }
    return toplam;
}

int timecomplexity(char frac[], int size)
{
    char toplam[20] = {};
    int xtoplam=0;
    for (int i = 0; i < size; i++)
    {
        if (frac[i - 2] == 'f' && frac[i - 1] == 'o' && frac[i] == 'r')
        {
            toplam[xtoplam]='A';
            xtoplam++;
        }
        if (frac[i - 4] == 'w' && frac[i - 3] == 'h' && frac[i - 2] == 'i' && frac[i - 1] == 'l' && frac[i] == 'e')
        {
            toplam[xtoplam]='a';
            xtoplam++;
        }
        if(frac[i]=='=')
        {
            toplam[xtoplam]='e';
            xtoplam++;
        }
    }
    printf("\n");
    int calculus=0;
    int pro=0;
    for (int i = 0; i < xtoplam; i++)
    {
        if(toplam[i]=='A' && toplam[i+1]=='e')
        {

            calculus+=10;
            pro+=1;
        }
        if(toplam[i]=='a' && toplam[i+1]=='e')
        {
            calculus+=10;
            pro+=1;
        }
        if(toplam[i]=='e')
        {
            calculus+=1;
        }
    }
    int theEnd=calculus-pro;
    int approxiation[10]={};
    int xapp=0;
    while(theEnd > 0) {
        if (theEnd<10)
        {
            approxiation[xapp]=theEnd;
            xapp++;
        }
        if (theEnd>=10 && theEnd<20)
        {
            approxiation[xapp]=10;
            xapp++;
        }
        if (theEnd>=20 && theEnd<30)
        {
            approxiation[xapp]=20;
            xapp++;
        }
        if (theEnd>=30 && theEnd<40)
        {
            approxiation[xapp]=30;
            xapp++;
        }
        if (theEnd>=40 && theEnd<50)
        {
            approxiation[xapp]=40;
            xapp++;
        }
        theEnd = theEnd / 10;
	}
    printf("T(N): ");
    for (int i = 0; i < 10; i++)
    {
        if (approxiation[i]==0)
        {
            break;
        }
        if (approxiation[i]==10)
        {
            printf("2n+2+n*%d",approxiation[i+1]);
        }
        if (approxiation[i]==20)
        {
            printf("2n+2+n*(2m+2)+n*m*%d",approxiation[i+1]);
        }
        if (approxiation[i]==30)
        {
            printf("2n+2+n*(2m+2)+n*m(2o+2)+n*m*o*%d",approxiation[i+1]);
        }
        if (approxiation[i]==40)
        {
            printf("2n+2+n*(2m+2)+n*m(2o+2)+n*m*o(2t+2)+n*m*o*t*%d",approxiation[i+1]);
        }
    }
    char letkeep[150] = {};
    int sizeletkeep = sizeof(letkeep) / sizeof(letkeep[0]);
    int xletkeep = 0;
    int numkeep[150] = {};
    for (int i = 0; i < size; i++)
    {
        if (frac[i] == 40)
        {
            letkeep[xletkeep] = 'O';
            numkeep[xletkeep] = i;
            xletkeep++;
        }
        if (frac[i] == 41)
        {
            letkeep[xletkeep] = 'C';
            numkeep[xletkeep] = i;
            xletkeep++;
        }
    }
    int prob = 0;
    int increasing = 0;
    int decreasing = 0;
    char funky[1000] = {};
    int xfunky = 0;
    for (int i = 0; i < sizeletkeep; i++)
    {
        if (letkeep[i] == 0 || numkeep[i] == 0)
        {
            break;
        }
        else
        {
            if (letkeep[i] == 'O')
            {
                increasing++;
            }
            if (letkeep[i] == 'C')
            {
                decreasing++;
            }
            if (increasing == decreasing)
            {
                for (int x = prob; x < numkeep[i] + 1; x++)
                {
                    if (frac[x] == 'i' && frac[x + 1] == 'f')
                    {
                        break;
                    }
                    funky[xfunky] = frac[x];
                    xfunky++;
                }
                increasing = 0;
                decreasing = 0;
                prob = numkeep[i + 1] - 6;
            }
        }
    }
    int ptr = insidecontrol(funky, 1000);
    if (ptr == 3 || ptr == 9 || ptr == 27)
    {
        return 2;
    }
    if (ptr == 5 || ptr == 15 || ptr == 45)
    {
        return 3;
    }
    if (ptr == 25 || ptr == 75)
    {
        return 4;
    }
    if (ptr == 7 || ptr == 21 || ptr == 63)
    {
        return 5;
    }
    if (ptr == 125)
    {
        return 6;
    }
    if (ptr == 35 || ptr == 105)
    {
        return 7;
    }
    if (ptr == 175)
    {
        return 8;
    }
    if (ptr == 49 || ptr == 147)
    {
        return 9;
    }
    if (ptr == 245)
    {
        return 10;
    }
    if (ptr == 343)
    {
        return 11;
    }
}

int insidecontrol(char frac[], int size)
{
    char toplam[20] = {};
    int xtoplam = 0;
    int maksitaxi[5] = {};
    int xmaksitaxi = 0;
    for (int i = 0; i < size; i++)
    {

        if (frac[i - 1] == '>' && frac[i] != '=')
        {
            int valuesOfStatement = frac[i+1];
            if (valuesOfStatement >= 48 && valuesOfStatement <= 59)
            {
                toplam[xtoplam] = 'i';
                xtoplam++;
            }
            if ((valuesOfStatement >= 65 && valuesOfStatement <= 90) || (valuesOfStatement >= 97 && valuesOfStatement <= 122))
            {
                toplam[xtoplam] = 'c';
                xtoplam++;
            }
        }
        if (frac[i - 1] == '<' && frac[i] != '=')
        {
            int valuesOfStatement = frac[i+1];
            if (valuesOfStatement >= 48 && valuesOfStatement <= 59)
            {
                toplam[xtoplam] = 'i';
                xtoplam++;
            }
            if ((valuesOfStatement >= 65 && valuesOfStatement <= 90) || (valuesOfStatement >= 97 && valuesOfStatement <= 122))
            {
                toplam[xtoplam] = 'c';
                xtoplam++;
            }
        }
        if (frac[i - 1] == '>' && frac[i] == '=')
        {

            int valuesOfStatement = frac[i + 2];
            if (valuesOfStatement >= 48 && valuesOfStatement <= 59)
            {
                toplam[xtoplam] = 'i';
                xtoplam++;
            }
            if ((valuesOfStatement >= 65 && valuesOfStatement <= 90) || (valuesOfStatement >= 97 && valuesOfStatement <= 122))
            {
                toplam[xtoplam] = 'c';
                xtoplam++;
            }
        }
        if (frac[i - 1] == '<' && frac[i] == '=')
        {
            int valuesOfStatement = frac[i + 1];
            if (valuesOfStatement >= 48 && valuesOfStatement <= 59)
            {

                toplam[xtoplam] = 'i';
                xtoplam++;
            }
            if ((valuesOfStatement >= 65 && valuesOfStatement <= 90) || (valuesOfStatement >= 97 && valuesOfStatement <= 122))
            {
                toplam[xtoplam] = 'c';
                xtoplam++;
            }
        }
        if (frac[i - 1] == '+' && frac[i] == '+')
        {
            toplam[xtoplam] = '2';
            xtoplam++;
        }
        if (frac[i - 1] == '-' && frac[i] == '-')
        {
            toplam[xtoplam] = '2';
            xtoplam++;
        }
        if (frac[i - 1] == '+' && frac[i] == '=')
        {
            toplam[xtoplam] = '2';
            xtoplam++;
        }
        if (frac[i - 1] == '-' && frac[i] == '=')
        {
            toplam[xtoplam] = '2';
            xtoplam++;
        }
        if (frac[i - 1] == '*' && frac[i] == '=')
        {
            toplam[xtoplam] = '3';
            xtoplam++;
        }
        if (frac[i - 1] == '/' && frac[i] == '=')
        {
            toplam[xtoplam] = '3';
            xtoplam++;
        }
        if (frac[i - 2] == '=' && frac[i] == '+')
        {
            toplam[xtoplam] = '2';
            xtoplam++;
        }
        if (frac[i - 2] == '=' && frac[i] == '-')
        {
            toplam[xtoplam] = '2';
            xtoplam++;
        }
        if (frac[i - 2] == '=' && frac[i] == '*')
        {
            toplam[xtoplam] = '3';
            xtoplam++;
        }
        if (frac[i - 2] == '=' && frac[i] == '/')
        {
            toplam[xtoplam] = '3';
            xtoplam++;
        }
    }
    for (int i = 0; i < xtoplam; i += 1)
    {
        if (toplam[i] == 'i' && toplam[i + 1] == '2')
        {
            maksitaxi[xmaksitaxi] = 3;
            xmaksitaxi++;
        }
        if (toplam[i] == 'i' && toplam[i + 1] == '3')
        {
            maksitaxi[xmaksitaxi] = 3;
            xmaksitaxi++;
        }
        if (toplam[i] == 'c' && toplam[i + 1] == '2')
        {
            maksitaxi[xmaksitaxi] = 7;
            xmaksitaxi++;
        }
        if (toplam[i] == 'c' && toplam[i + 1] == '3')
        {
            maksitaxi[xmaksitaxi] = 5;
            xmaksitaxi++;
        }
        if (toplam[i] == 'i' && toplam[i + 1] == 'i')
        {
            maksitaxi[xmaksitaxi] = 3;
            xmaksitaxi++;
        }
        if (toplam[i] == 'c' && toplam[i + 1] == 'c')
        {
            maksitaxi[xmaksitaxi] = 7;
            xmaksitaxi++;
        }
        if (toplam[i] == 'i' && toplam[i + 1] == 'c')
        {
            maksitaxi[xmaksitaxi] = 7;
            xmaksitaxi++;
        }
        if (toplam[i] == 'c' && toplam[i + 1] == 'i')
        {
            maksitaxi[xmaksitaxi] = 7;
            xmaksitaxi++;
        }
        if (toplam[i] == 'i' && toplam[i + 1] == 0)
        {
            maksitaxi[xmaksitaxi] = 3;
            xmaksitaxi++;
        }
        if (toplam[i] == 'c' && toplam[i + 1] == 0)
        {
            maksitaxi[xmaksitaxi] = 7;
            xmaksitaxi++;
        }
        // if (toplam[i] == '2' && toplam[i + 1] == 'c')
        // {
        //     maksitaxi[xmaksitaxi] = 7;
        //     xmaksitaxi++;
        // }
        // if (toplam[i] == '3' && toplam[i + 1] == 'c')
        // {
        //     maksitaxi[xmaksitaxi] = 3;
        //     xmaksitaxi++;
        // }
        // if (toplam[i] == '2' && toplam[i + 1] == 'i')
        // {
        //     maksitaxi[xmaksitaxi] = 3;
        //     xmaksitaxi++;
        // }
        // if (toplam[i] == '3' && toplam[i + 1] == 'i')
        // {
        //     maksitaxi[xmaksitaxi] = 3;
        //     xmaksitaxi++;
        // }
    }
    int carp = 1;
    for (int i = 0; i < xmaksitaxi; i++)
    {
        carp = carp * maksitaxi[i];
    }
    return carp;
}

int main()
{
    system("color 74");
    fileraw();
    printf("\n");
    calculator_showing();
    printf("\n");
    system("c:\\users\\dell\\desktop\\Big\\program.c");
    system("gcc -o program program.c");
    system("c:\\users\\dell\\desktop\\Big\\program.exe");
    getch();
    return 0;
}
