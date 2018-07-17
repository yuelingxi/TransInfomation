#pragma once

#include<string>
using namespace std;
struct City
{
	//包含三个变量成员
	string aim;
	int time[2];//0为火车，1为飞机
	int cost[2];
};
class CityGraph
{
public:
	CityGraph()
	{
		num = 20;
		sum = 1;
		NoEdge = 100;
		city = new City*[num + 1];//为了得到a[m][n]，先动态创建了一维数组a[n]

		for (int i = 0; i <= num; i++)

			city[i] = new City[num + 1];//这样初始话每一个数组

		for (int i = 0; i <= num; i++)

		for (int j = 0; j <= num; j++)
		{

			city[i][j].aim = "0";
			city[i][j].cost[0] = NoEdge;
			city[i][j].cost[1] = NoEdge;
			city[i][j].time[0] = NoEdge;
			city[i][j].time[1] = NoEdge;
		}

	}

	~CityGraph()
	{
		for (int i = 0; i <= num; i++)
			delete[] city[i];
		delete[] city;
	}
	void ShortestPathcost(int s,int t, int d[], int p[]);
	void ShortestPathtime(int s, int t, int d[], int p[]);
	string GetName(int s, int t){ return city[s][t].aim; }
	void AddCity(string b, string e, int t[], int c[]);
	int Index(int n, string s);//在第n行寻找string s，返回其索引值
	int HeadIndex(string s);//在第一列寻找string s，返回其索引值
private:
	City **city;
	int num;
	int sum;//已设置城市数目
	int NoEdge;

};