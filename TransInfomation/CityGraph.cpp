#ifndef TRAN_
#define TRAN_

#include "stdafx.h"
#include "CityGraph.h"
#include "Chain.h"
#include <afxtempl.h>
#endif

#include <sstream>
#include <iostream>

using namespace std;
string int2string(int i);
int string2int(string s);

CString int2Cstring(int i);


	void CityGraph::ShortestPathtime(int s, int t, int d[], int p[])
	{

		//寻找从顶点s（s为对应下标）出发的最短路径，在d中返回最短距离
		//t为火车还是飞机。 0为火车，1为飞机
		//int s = HeadIndex(first);
		//在p中返回前继节点
		if (s<1 || s>sum);// out << "非法的输入" << endl;
		Chain<int>L;
		ChainIterator<int>I;
		//初始化d，p，L
		for (int i = 1; i <= sum; i++)
		{
			d[i] = city[s][i].time[t];
			if (d[i] == NoEdge)p[i] = 0;
			else
			{
				p[i] = s;
				L.Insert(0, i);

			}
		}
		//cout << "已出使话" << endl;
		//更新d，p
		while (!L.IsEmpty())
		{
			int *v = I.Initialize(L);
			int *w = I.Next();

			//cout << "断点1" << endl;
			while (w)
			{
				if (d[*w] < d[*v])v = w;

				w = I.Next();//发生访问冲突

			}
			//AfxMessageBox(TEXT("更新dp"));
			//从L中删除通向顶点v的下一条最短路径并更新d
			int i = *v;
			L.Delete(*v);

			//cout << "断点2" << endl;
			for (int j = 1; j <= sum; j++)
			{
				if (city[i][j].time[t] != NoEdge && (!p[j] || d[j] > d[i] + city[i][j].time[t]))

				{
					d[j] = d[i] + city[i][j].time[t];
				//	cout << "断点3" << endl;
					if (!p[j])
						L.Insert(0, j);
					p[j] = i;
				}
			}
		}
	}
	void CityGraph::ShortestPathcost(int s, int t, int d[], int p[])
	{

		//寻找从顶点s（s为对应下标）出发的最短路径，在d中返回最短距离
		//t为火车还是飞机。 0为火车，1为飞机
		//int s = HeadIndex(first);
		//在p中返回前继节点
		if (s<1 || s>sum);// out << "非法的输入" << endl;
		Chain<int>L;
		ChainIterator<int>I;
		//初始化d，p，L
		for (int i = 1; i <= sum; i++)
		{
			d[i] = city[s][i].cost[t];
			if (d[i] == NoEdge)p[i] = 0;
			else
			{
				p[i] = s;
				L.Insert(0, i);

			}
		}
		//cout << "已出使话" << endl;
		//更新d，p
		while (!L.IsEmpty())
		{
			int *v = I.Initialize(L);
			int *w = I.Next();

			//cout << "断点1" << endl;
			while (w)
			{
				if (d[*w] < d[*v])v = w;

				w = I.Next();//发生访问冲突

			}
			//AfxMessageBox(TEXT("更新dp"));
			//从L中删除通向顶点v的下一条最短路径并更新d
			int i = *v;
			L.Delete(*v);

			//cout << "断点2" << endl;
			for (int j = 1; j <= sum; j++)
			{
				if (city[i][j].cost[t] != NoEdge && (!p[j] || d[j] > d[i] + city[i][j].cost[t]))

				{
					d[j] = d[i] + city[i][j].cost[t];
					//	cout << "断点3" << endl;
					if (!p[j])
						L.Insert(0, j);
					p[j] = i;
				}
			}
		}
	}

	void CityGraph::AddCity(string b, string e, int t[], int c[])
	{
		int head = HeadIndex(b);
		//cout << "Add" + head << endl;
		if (head != -1)
		{

			//起始点

			city[head][1].aim = b;
			city[head][1].cost[0] = 0;
			city[head][1].cost[1] = 0;
			city[head][1].time[0] = 0;
			city[head][1].time[1] = 0;

			//终止点

			//city[head][tool] = e;
			int tool = HeadIndex(e);
			city[tool][1].aim = e;
			city[tool][1].cost[0] = 0;
			city[tool][1].cost[1] = 0;
			city[tool][1].time[0] = 0;
			city[tool][1].time[1] = 0;
			city[head][tool].aim = e;
			city[head][tool].cost[0] = c[0];
			city[head][tool].cost[1] = c[1];
			city[head][tool].time[0] = t[0];
			city[head][tool].time[1] = t[1];
		}
		sum++;
	}
	int CityGraph::Index(int n, string s)//查找第n行(1为第一行),返回可用位置
	{
		int i;
		for (i = 2; i<sum + 1; i++)
		if (!((city[n][i].aim).compare(s)))
			break;
		if (i == sum + 1)//如果没找到
		{
			int j;
			for (j = 2; j <= num; j++)
			if (!((city[n][j].aim).compare("0")))
				break;
			if (j == num + 1)

			{
				//AfxMessageBox(TEXT("已满"));
				return -1;
			}
			else
				return j;
		}
		else//找到了
			return i;
	}
	int CityGraph::HeadIndex(string s)//查找第一列，返回可用位置
	{
		int i;
		for (i = 1; i<sum + 1; i++)
		if (!(city[i][1].aim).compare(s))
			break;
		if (i == sum + 1)//如果没找到
		{
			int j;
			for (j = 1; j<num + 1; j++)
			if (!(city[j][1].aim).compare("0"))
				break;
			if (j == num + 1)

			{
				//AfxMessageBox(TEXT("已满"));
				return -1;
			}
			else
				return j;
		}
		else//找到了
			return i;

	}
int string2int(string s){//将string转换为int
	if ("" == s)
		return 0;
	int t = 0, i = 0;
	while (i<s.length()){
		t *= 10;
		t += s[i] - '0';
		i++;
	}
	return t;
}
string int2string(int i)
{
	
	string c;

	ostringstream oss;
	oss << i;

	c = oss.str();
	return c;
}
CString int2Cstring(int i)
{
	CString str;
	str.Format(_T("%d"), i);
	return str;
}