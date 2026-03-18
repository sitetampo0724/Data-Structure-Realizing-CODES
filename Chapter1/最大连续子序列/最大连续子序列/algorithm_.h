#pragma once
class Algorithm_
{
private:
	int max_sum(int a[], int left,int right, int& start, int& end);
public:
	int MAX_1(int a[],int size,int & start,int & end);
	int MAX_2(int a[], int size, int& start, int& end);
	int MAX_3(int a[], int size, int& start, int& end);
	int MAX_4(int a[], int size, int& start, int& end);
	~Algorithm_() {}
};

