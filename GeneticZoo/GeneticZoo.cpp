// GeneticZoo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

#include "GeneticZoo.h"
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include "GeneticGenerator.h"

void init()
{
	std::srand(std::chrono::steady_clock::now().time_since_epoch().count());
}


int main()
{
	try
	{
		GenDescription desc;
		printOut(desc);
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}

	std::array<Genom, 5> genoms;
	for (size_t i = 0; i < 5; i++)
	{
		genoms[i] = generateGenom();
		printOutGenom(genoms[i]);
	}
	
	
	

	return 0;
}

