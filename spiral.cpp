#include <iostream>
#include <chrono>
#include <unistd.h>


using namespace std;

int main()
{
    int N;
    cin >> N;

    int mat[N][N];
    for (int i = 0 ; i<N ; i++)
    {
        for (int j = 0 ; j<N ; j++)
        {
            mat[i][j] = 0;
        }
    }


    int dirx_lst[] = {0, 1, 0, -1};
    int diry_lst[] = {1 , 0, -1, 0};
    int dir_x = 0, dir_y = 0;

    int write_x = 0, write_y = 0;
    for (int write_i = 1 ; write_i <= N*N ; write_i++)
    {
        mat[write_x][write_y] = write_i;

        int next_x = write_x + dirx_lst[dir_x];
        int next_y = write_y + diry_lst[dir_y];
        
        if ((next_x<N) && (next_y< N) && (next_x>=0) && (next_y>= 0) && mat[next_x][next_y]==0 && mat[next_x][next_y]==0)
        {
            write_x = next_x;
            write_y = next_y;
        }else
        {
            dir_x = (dir_x + 1)%4;
            dir_y = (dir_y + 1)%4;

            write_x = write_x + dirx_lst[dir_x];
            write_y = write_y + diry_lst[dir_y];
        }
        
    }

    for (int i = 0 ; i<N ; i++)
    {
        for (int j = 0 ; j<N ; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}