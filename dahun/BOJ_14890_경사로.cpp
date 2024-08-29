#include <iostream>
using namespace std;

int N,L;
int world[100][100];
int ans = 0;

void init(){
    cin >> N >> L;
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            cin >> world[x][y];
        }
    }
}

void check(){
    for(int x=0;x<N;x++){
        int y = 0;
        int cnt = 1;
        int now = world[x][y];
        int check = 1;
        //cout << "x: " << x << " ans: " << ans << endl;
        while(1){
            //cout << "y: " << y << " cnt: " << cnt << endl;
            if(y+1 >= N) break;
            y++;

            if(world[x][y] == now){
                cnt++;
            }
            else if(world[x][y]==now+1){
                if(cnt<L){
                    check=0;
                    break;
                }
                now = world[x][y];
                cnt = 1;
            }
            else if(world[x][y]==now-1){
                cnt = 0;
                now = world[x][y];

                if(y+L>N){
                    check=0;
                    break;
                }

                for(int i=0;i<L;i++){
                    if(now == world[x][y+i]) cnt++;
                    else break;
                }
                //cout << "#####" << cnt << endl;

                if(cnt<L){
                    check = 0;
                    break;
                }
                y = y+L-1;
                if(y+1<N && world[x][y] < world[x][y+1]){
                    check = 0;
                    break;
                }
                else{
                    cnt = 0;
                    now = world[x][y];
                }
            }
            else{
                check=0;
                break;
            }
        }
        if(check) ans++;
    }
}

void rotate(){
    int tmp[100][100];
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            tmp[y][x] = world[x][y];
        }
    }
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            world[x][y] = tmp[x][y];
        }
    }
}


int main(){
    init();
    check();
    rotate();
    check();
    cout << ans;
    return 0;
}