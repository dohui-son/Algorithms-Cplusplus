#include <iostream>
#include <vector>

using namespace std;
#define endl "\n"

int N, minus_one,zero,one;
vector<vector<int>> paper;

void cut(int size, int row, int col){
    if(size==1){
        if(paper[row][col] == -1) minus_one++;
        else if(paper[row][col] == 0)zero++;
        else {one++;}
        return;
    }

    int first = paper[row][col];
    bool available = true;
    for(int i = row; i < size+row; i++){
        for(int j = col; j<size+col; j++){
            if(paper[i][j]!=first){
                available = false;
                break;

            }

        }
        if(!available)break;
    }
    if(available){
        if(paper[row][col] == -1) minus_one++;
        else if(paper[row][col] == 0)zero++;
        else {one++;}
        return;
    }
    else{
        cut(size/3,row,col);
        cut(size/3,row+size/3,col);
        cut(size/3,row,col+size/3);
        cut(size/3,row+size/3,col+size/3);
        cut(size/3,row+size/3+size/3,col);
        cut(size/3,row,col+size/3+size/3);
        cut(size/3,row+size/3,col+size/3+size/3);
        cut(size/3,row+size/3+size/3,col+size/3);
        cut(size/3,row+size/3+size/3,col+size/3+size/3);

    }

}


int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    cin >> N;
    paper = vector<vector<int>>(N+1,vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for(int j = 0 ;  j <N;j++){
            cin >> paper[i][j];
        }
    }

    cut(N,0,0);
    cout << minus_one<<endl;
    cout << zero<<endl;
    cout << one<<endl;
    


    return 0;
}