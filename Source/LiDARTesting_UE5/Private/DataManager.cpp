// Fill out your copyright notice in the Description page of Project Settings.


#include "DataManager.h"

#include <pdal/Options.hpp>
#include <io/LasReader.hpp>
#include <pdal/PointView.hpp>

#include <memory>
#include <string>
#include <stdexcept>

// Sets default values
ADataManager::ADataManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADataManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADataManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADataManager::Import()
{
	using namespace pdal;

	const std::string file("C:/Users/Connor/Downloads/bc_092f005_2_4_3_xyes_8_utm10_2019.laz");

	const Option opt_filename("filename", file);
	Options opts;
	opts.add(opt_filename);

	LasReader reader;
	reader.setOptions(opts);

	PointTable table;
	PointLayoutPtr layout(table.layout());

	reader.prepare(table);
	PointViewSet viewSet = reader.execute(table);
	PointViewPtr view = *viewSet.begin();

	UE_LOG(LogTemp, Warning, string_format("%d\n", layout->pointSize()))
}

template<typename ... Args>
std::string string_format(const std::string& format, Args ... args)
{
	int size_s = std::snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
	if (size_s <= 0) { throw std::runtime_error("Error during formatting."); }
	auto size = static_cast<size_t>(size_s);
	auto buf = std::make_unique<char[]>(size);
	std::snprintf(buf.get(), size, format.c_str(), args ...);
	return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
}