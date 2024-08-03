//AC <<Red And Black>> 考察bfs和图的知识相结合
#include<iostream>
#include<queue>
using namespace std;

int num,Wx,Wy;
char a[200][200];
struct Node { int x; int y; };
int dir[4][2] = {
	{0,-1},//上
	{0,1}, //下
	{-1,0},//左
	{1,0}  //右
};

//宏定义函数的写法，两个括号，第一个括号放不带类型的形参，第二个括号写表达式，末尾没有分号
#define check(x,y) (x <= Wx - 1&& x >= 0&& y <= Wy - 1&& y >= 0 )//x代表列，y代表行
void bfs(int dx, int dy) {
	queue<Node> q;
	Node start;
	start.x = dx;
	start.y = dy;
	q.push(start);
	while (!q.empty()) {
		start = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			Node next;
			next.x = start.x + dir[i][0];
			next.y = start.y + dir[i][1];
			if (a[next.y][next.x] == '.'&&check(next.x,next.y)) {
				q.push(next);
				num++;
				a[next.y][next.x] = '#';
			}
		}
	}
	cout << num << endl;
}

int main() {
	int dx=0, dy=0;
	while (cin >> Wx >> Wy&&Wx!=0&&Wy!=0) {
		num = 1;
		for (int i = 0; i < Wy; i++){
			for (int j = 0; j < Wx; j++) {
				cin >> a[i][j];
				if (a[i][j] == '@') {
					dy = i;
					dx = j;
				}
			}
		}
		bfs(dx, dy);
	}
	return 0;
}
