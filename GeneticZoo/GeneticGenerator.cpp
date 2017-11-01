#include "stdafx.h"
#include "GeneticGenerator.h"
#include <boost\property_tree\json_parser.hpp>
#include <iostream>


GeneticGenerator::GeneticGenerator()
{
}


GeneticGenerator::~GeneticGenerator()
{
}

GenDescription::GenDescription()
{
	boost::property_tree::read_json("config/gen_desc.json", description);
	boost::property_tree::read_json("config/monsters.json", monsters);
}

GenDescription::~GenDescription()
{}

void printOut(const GenDescription &gd, std::ostream& log)
{
	log << "###\tGen Description:\t###\n";
	for each (boost::property_tree::ptree::value_type gen in gd.description.get_child("gens"))
	{
		log << "#\t" << gen.second.get<int>("n") << ": " << gen.second.get<std::string>("name") << " (";
		
		auto skills = gen.second.get_child("skills");
		auto skillsIt = skills.begin();
		std::cout << skillsIt->second.get<std::string>("name");
		skillsIt++;
		for(;skillsIt != skills.end(); skillsIt++)
		{
			log << ", " << skillsIt->second.get<std::string>("name") ;
		}
		log << ")" <<  std::endl;
	}
	log << "--------------------------\n";
	log << "###\tMonsters:\t###\n";
	for each (auto m in gd.monsters.get_child("monsters"))
	{
		log << "#\t" << m.second.get<std::string>("instance") 
			<< "\t(HP:" << m.second.get<int>("hp")
			<< ", STAMINA:" << m.second.get<int>("stamina")
			<< ", ARMOR:" << m.second.get<int>("armor")
			<< ", DMG:" << m.second.get<int>("demage")
			<< ", SPEED:" << m.second.get<int>("speed")
			<< ")\n";
	}
	
	log << "##########################\n";
}
