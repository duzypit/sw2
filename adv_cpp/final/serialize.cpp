/*
Serializacja klasy
Napisz swoją implementację serializacji klasy:
serializacja do pliku tekstowego lub binarnego w zależności od parametru programu
./nazwa --help
./nazwa txt
./nazwa bin
klasa powinna sygnalizować sytuacje wyjątkowe
*/
#include <array>

enum class FuelType;
enum class Colour;
enum class EmissionsStandards;
struct Weels;

class Car
{
public:
    //  contructor + getters
protected:
    FuelType fuel_type;
    std::array<Weels, 4> weels;
    uint32_t max_speed;
    Colour colour;
};

class PersonalCar: public Car {
public:
	// contructor + getters
protected:
	uint8_t number_of_places;
	EmissionsStandards emission;
};
