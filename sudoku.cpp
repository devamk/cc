#include<iostream>
using namespace std;
bool solve(int **mat, int i, int j);
bool check_hori(int **mat,int i, int j);
bool check_vert(int **mat,int i, int j);
bool check_box(int **mat,int i, int j);
bool find_next(int **mat, int *i, int *j);

int main()
{
    int T;
    scanf("%d\n",&T);
    while ((T--)>0)
    {
        int **mat = (int**) malloc(sizeof(int*)*9);
        for (int i=0;i<9;i++)
        {
            mat[i]=(int*)malloc(sizeof(int)*9);
        }
        int first_i,first_j;
        bool first_fill=false;
        for (int i=0;i<9;i++)
        {
            for (int j=0;j<9;j++)
            {
                int readI;
                scanf ("%d",&readI);
                mat[i][j]=readI;
                if (!first_fill && mat[i][j]==0)
                {
                    first_fill=true;
                    first_i=i;
                    first_j=j;
                }
            }
        }

        
        bool if_solved=false;
        if_solved = solve(mat,first_i,first_j);
        if (if_solved)
        {
            for (int i=0;i<9;i++)
            {
                for (int j=0;j<9;j++)
                {
                    printf ("%d ",mat[i][j]);
                }
            }

        }else
        {
            printf("no_soln\n");
        }
        printf ("\n");
    }
}

bool find_next(int **mat, int *i, int *j)
{
    
    for (int search_i=0;search_i<9;search_i++)
    {
        for (int search_j=0;search_j<9;search_j++)
        {
            if (mat[search_i][search_j]==0)
            {
                *i=search_i;
                *j=search_j;

                return false;
            }
        }
    }
    return true;
}


bool solve(int **mat, int i, int j)
{
    int writeI;
    bool soln_exist=false;
    for (writeI=1;writeI<=9;writeI++)
    {
        mat[i][j]=writeI;
        
        bool c1 = check_box(mat,i,j),
        c2=check_hori(mat,i,j),
        c3=check_vert(mat,i,j);
        
        if (c1 && c2 && c3)
        {
            
            int *next_i = (int*)malloc(sizeof(int)),
            *next_j = (int*)malloc(sizeof(int));

            bool if_solved = find_next(mat,next_i,next_j);
            
            if (if_solved)
            {
                free (next_i);
                free (next_j);
                return true;
            }else
            {

                soln_exist=solve(mat, *next_i, *next_j);
                if (soln_exist)
                {
                    free (next_i);
                    free (next_j);
                    return true;
                }
                
            }
        }
        mat[i][j]=0;
    }
    return false;
}


bool check_hori(int **mat,int i, int j)
{
    bool *table = (bool*) malloc(sizeof(int)*9);
    for (int init_i=0;init_i<9;init_i++)
    {
        table[init_i]=false;
    }
    for (int check_i=0;check_i<9;check_i++)
    {
        if(mat[i][check_i]!=0)
        {
            if(!table[mat[i][check_i]])
            {
                table[mat[i][check_i]]=true;
            }else{
                return false;
            }
        }
    }
    return true;
}

bool check_vert(int **mat,int i, int j)
{
    bool *table = (bool*) malloc(sizeof(int)*9);
    for (int init_i=0;init_i<9;init_i++)
    {
        table[init_i]=false;
    }
    for (int check_i=0;check_i<9;check_i++)
    {
        if(mat[check_i][j]!=0)
        {
            if(!table[mat[check_i][j]])
            {
                table[mat[check_i][j]]=true;
            }else{
                return false;
            }
        }
    }
    return true;
}


bool check_box(int **mat,int i, int j)
{
    bool *table = (bool*) malloc(sizeof(int)*9);
    for (int init_i=0;init_i<9;init_i++)
    {
        table[init_i]=false;
    }
    
    int start_i=i-(i%3),
    start_j=j-(j%3);

    for (int check_i=start_i;check_i<start_i+3;check_i++)
    {
        for (int check_j=start_j; check_j<start_j+3;check_j++)
        {
            if(mat[check_i][check_j]!=0)
            {
                if(!table[mat[check_i][check_j]])
                {
                    table[mat[check_i][check_j]]=true;
                }else{
                    return false;
                }
            }
        }
    }
    return true;
}