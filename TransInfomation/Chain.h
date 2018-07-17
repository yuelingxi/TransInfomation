#pragma once
#include<iostream>
using namespace std;
template<class T>
class Chain;
template<class T>
class ChainIterator;
string int2string(int i);
int string2int(string s);

template<class T>
class ChainNode
{
	friend Chain<T>;
	friend  ChainIterator<T>;
public:
	T data;
	ChainNode<T> *link;
};
template<class T>
class Chain
{
	friend  ChainIterator<T>;
public:
	Chain(){ first = 0; }
	~Chain(){
		//链表的析构函数，用于删除链表中所有节点
		ChainNode<T> *next;//下一个节点
		while (first)
		{
			next = first->link;
			delete first;
			first = next;
		}
	}
	bool IsEmpty() const{ return first == 0; }

	Chain<T>& Delete(const T&x);//把第k个元素取至x，然后从链表删除第k个元素
	Chain<T>& Insert(int k, const T& x);
	int Search(const T&x)const;
	ChainNode<T> *first;//指向第一个节点的指针
};
template<class T>
class ChainIterator
{
public:
	T* Initialize(const Chain<T>& c)
	{
		location = c.first;
		if (location)
			return &location->data;
		return 0;
	}
	T* Next()
	{
		if (!location) return 0;
		location = location->link;
		if (location)
			return &location->data;
		return 0;
	}
	bool IsEmpty()
	{
		if (location)
			return 1;
		else
			return 0;
	}
private:
	ChainNode<T> *location;
};
template<class T>
Chain<T>& Chain<T>::Delete(const T&x)//索引从1开始

{
	int k = Search(x);
	//k++; 
	//把第k个元素取至x，然后从链表删除第k个元素
	//如果不存在第k个元素，则引发OutOfBounds异常
	if (k < 1 || !first)
		;// AfxMessageBox(TEXT("不存在第k个元素!" + int2Cstring(k)));


	ChainNode<T> *p = first;

	if (k == 1)//p已经指向第k个元素
		first = first->link;//删除之
	else
	{
		//用q指向k-1个元素
		ChainNode<T> *q = first;
		for (int index = 1; index < k - 1 && q; index++)
			q = q->link;
		if (!q || !q->link)
			;// AfxMessageBox(TEXT("不存在第k个元素!!"));
		p = q->link;//存在第k个元素
		q->link = p->link;//从链表中删除该元素

	}

	//x = p->data;
	delete p;
	return *this;
}
template<class T>
Chain<T>& Chain<T>::Insert(int k, const T& x)//索引从1开始
{
	//在第k个元素之后插入x
	//如果不存在第k个元素，则引发异常
	//如果没有足够的空间，引发异常
	if (k < 0)
		;// AfxMessageBox(TEXT("没有足够空间"));
	ChainNode<T> *p = first;
	for (int index = 1; index < k&&p; index++)
		p = p->link;
	if (k < 0 && !p);// AfxMessageBox(TEXT("不存在第k个元素!!!"));
	ChainNode<T> *y = new ChainNode<T>;
	y->data = x;
	if (k)
	{
		y->link = p->link;
		p->link = y;
	}
	else
	{
		y->link = first;
		first = y;
	}
	//AfxMessageBox(TEXT("已插入"));

	return *this;
}
template<class T>
int Chain<T>::Search(const T&x)const
{
	//寻找x，如果发现x，则返回x的地址
	//如果x不在链表中则返回-1
	ChainNode<T> *current = first;
	int index = 1;
	while (current&&current->data != x)
	{
		current = current->link;
		index++;
	}
	if (current)return index;
	return -1;
}

