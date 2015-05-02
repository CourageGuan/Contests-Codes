#include<cstdio>
char m[4][4][4]={'G','G','G','G','G','G','G','G','G','G','G','G','G','G','G','G',
                    'R','G','R','G','G','G','G','G','R','G','R','G','G','G','G','G',
                    'R','R','R','R','R','R','G','R','R','G','G','G','R','R','G','R',
                    'R','R','R','R','R','R','R','R','R','R','R','G','R','R','G','G'};

int main()
{
    int X, R, C, t;
    FILE *fin, *fout;
    fin = fopen("D-small-attempt1.in","r");
    fout = fopen("a.out","w");
    fscanf(fin,"%d",&t);
    for(int i = 1; i <= t; i++)
    {
        fscanf(fin,"%d%d%d",&X,&R,&C);
        switch (m[X-1][R-1][C-1])
        {
            case 'G':fprintf(fout,"Case #%d: GABRIEL\n",i);break;
            case 'R':fprintf(fout,"Case #%d: RICHARD\n",i);break;
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
