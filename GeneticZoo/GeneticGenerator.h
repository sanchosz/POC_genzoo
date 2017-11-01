#pragma once
#include <boost\property_tree\ptree.hpp>
#include <iostream>


class Genom {
public:
	static const int dna_size = 5;
	std::array<std::string, dna_size> m_gen_names;

	std::array<int, dna_size> m_gens;


	Genom()
	{
		m_gen_names = { "A", "B", "C", "D", "E" };
	}
};

Genom generateGenom() {
	auto genom = Genom();

	for (size_t i = 0; i < Genom::dna_size; i++)
	{
		genom.m_gens[i] = std::rand() % 100;
	}
	return genom;
};

void printOutGenom(const Genom &genom)
{
	auto gen = genom.m_gens.cbegin();
	std::cout << "Genom (" << *gen++;

	for (; gen != genom.m_gens.cend(); ++gen)
	{
		std::cout << ", " << *gen;
	}
	std::cout << ")\n";
}


class GeneticGenerator
{
public:
	GeneticGenerator();
	~GeneticGenerator();

	
};


class GenDescription {
public:
	boost::property_tree::ptree monsters;
	boost::property_tree::ptree description;

	GenDescription();
	~GenDescription();
};

void printOut(const GenDescription &gd, std::ostream& log = std::cout);
