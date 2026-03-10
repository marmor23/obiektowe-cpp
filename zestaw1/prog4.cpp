#include <iostream>

template<template<int N> class C, int K>
void f(C<K> arg)
{
	std::cout << K << std::endl;
}

template<int N>
class test {};

int main()
{
	test<10> cl;
	test<17> cl2;
	test<-23> cl3;
	f(cl);
	f(cl2);
	f(cl3);
	return 0;
}