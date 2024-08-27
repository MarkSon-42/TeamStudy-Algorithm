#include<iostream>
#include<vector>

using namespace std;

//1-5는 cctv
//0은 가능공간
//6은 벽


//map을 돌면서 찾다가
//1-5번을 만나면
//해당 방향으로 다 퍼져나감. '6'을 마주치면 차단당함
//#을 최대한 많이. -> 
int n, m = 0;
int cctv_count = 0;
int map[8][8];

struct cctv_coord{
    int y, x;
    int num;
    int direct;
};

vector<cctv_coord> cctvs;
int cctv_directs[9]; //cctv는 최대 8개
int count_ = 0;

vector<vector<int>> directs;


#include<iostream>
using namespace std;


int N = 5;
int DAT[10];
vector<vector<vector <int>>> direct_map;
 


void func(int now) {
	if (now >= cctv_count) { // 0 1 2  총 3개의 주사위를 굴리게 된다.

        vector<int> direct;
        vector<vector<int>> di_map(8, vector<int>(8, 0)); //di_map초기화

		for (int i = 0; i < cctv_count; i++) {
            di_map[cctvs[i].y][cctvs[i].x] = DAT[i];
		}
        direct_map.push_back(di_map);
		return;
	}

	//1. 재귀 기본
	for (int i = 1; i <= 4; i++) { // i : 주사위의 눈금
		//3-1 앞에서 처리되야 하는 코드
		DAT[now] = i; // index : now 번째 주사위 , value : 주사위 눈금
		func(now + 1); // 주사위를 하나 더 굴린다. 다음 박스로 가라~!!
		DAT[now] = 0; // 기록을 삭제
	}
}



int visited[9][9];


int cctv1[4][4] = {
    {1,0,0,0},
    {0,0,0,0}
};

int cctv2[4][4] = {
    {1,0,1,0},
    {0,0,0,0}
};

int cctv3[4][4] = {
    {1,0,0,0},
    {0,1,0,0}
};

int cctv4[4][4] = {
    {1,1,0,0},
    {0,0,-1,0}
};

int cctv5[4][4] = {
    {1,-1,0,0},
    {0,0,1,-1}
};


void dfs(int sy, int sx, int dmap_index, int cctv_num){



    if(cctv_num == 1){
        
    }else if(cctv_num == 2){

    }else if(cctv_num == 3){

    }else if(cctv_num == 4){

    }else if(cctv_num == 5){

    }

    


    
}


int main(){

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j] >= 1 and map[i][j] <= 5){
                cctv_count++;
                cctv_coord new_cctv;
                new_cctv.x = j;
                new_cctv.x = i;
                new_cctv.x = map[i][j] - 1;
                cctvs.push_back(new_cctv);
            }
        }
    }

    func(0); //direct방향 다 구함.


    for(int i=0; i<directs.size(); i++){//방향 조합
        for(int j=0; j<cctvs.size(); i++){
            cctvs[j].direct = directs[i][j]; 
        }

        
        for(int ii = 0; ii<n; ii++){
            for(int jj=0; jj<m; jj++){
                if(map[ii][jj] >= 1 and map[ii][jj] <= 5){
                    visited[ii][jj] = 1;
                    dfs(ii,jj,i,map[ii][jj]);
                }
            }
        }


    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] >= 1 && map[i][j] <= 5){

            }
        }
    }

    
}