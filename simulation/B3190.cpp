
#include<iostream>//숏코딩
#include<cstring>
using namespace std;
int ch[101][101],x=1,y=1,n,t=0,apple=1;
bool ap[101][101];
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
void move(int d){
	t++;
	int nx=x+dx[d],ny=y+dy[d];
	if(nx<1||ny<1||nx>n||ny>n){cout<<t;exit(0);}
	if(ch[nx][ny]!=-1&&t-ch[nx][ny]<=apple){cout<<t;exit(0);}
	ch[nx][ny]=t;
	if(ap[nx][ny]==1){apple++;ap[nx][ny]=0;}
	x=nx,y=ny;
}
int main(){
	memset(ch,-1,sizeof(ch));
	int i,k,l,d=0;
	cin>>n>>k;
	for(i=0;i<k;i++){
		int a,b;
		cin>>a>>b;
		ap[a][b]=1;
	}
	cin>>l;
	ch[1][1]=0;
	while(l--){
		int a;char b;
		cin>>a>>b;
		while(t<a)move(d);
		if(b=='D')d=(d+1)%4;
		else if(b=='L')d=(d+3)%4;
	}
	while(1)move(d);
}
//내 답 -->맞음
#include <bits/stdc++.h> 
using namespace std;

int n, k, l, g[102][102], dir = 1;
deque<pair<int, int> > dq;
queue<pair<int, int> > ll;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

bool go()
{
    //game over == return true;
    int ny = dy[dir] + dq.front().first;
    int nx = dx[dir] + dq.front().second;
    if (ny < 0 || nx < 0 || ny >= n || nx >= n || g[ny][nx] == 1)
        return true;
    dq.push_front({ny, nx});
    if (g[ny][nx] == 2)
    {
        g[ny][nx] = 1;
        return false;
    }
    g[dq.back().first][dq.back().second] = 0;
    dq.pop_back();
    g[ny][nx] = 1;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    int tmp1 = 0, tmp2 = 0;
    char tmp3 = '\0';
    for (int i = 0; i < k; i++)
    {
        cin >> tmp1 >> tmp2;
        tmp1--, tmp2--;
        g[tmp1][tmp2] = 2;
    }
    cin >> l;
    g[0][0] = 1;
    for (int i = 0; i < l; i++)
    {
        cin >> tmp1 >> tmp3;
        if (tmp3 == 'L')
            tmp2 = -1;
        else
            tmp2 = 1;
        ll.push({tmp1, tmp2});
    }
    dq.push_back({0, 0});
    int time = 0;
    while (1)
    {
        time++;
        if (go())
            break;

        if (ll.front().first == time)
        {
            dir += ll.front().second;
            if (dir < 0)
                dir += 4;
            dir %= 4;
            ll.pop();
        }
    }
    cout << time << "\n";

    return 0;
}