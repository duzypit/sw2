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

enum class FuelType{
    gas, diesel
};
enum class Colour{
    black, red, white
};
enum class EmissionsStandards{
    euro1, euro2, euro3
};
struct Weels;


class Car
{
public:
    Car() : fuel_type(FuelType::gas), max_speed(120), colour(Colour::red) {}

    Car(FuelType f, uint32_t m, Colour c) : fuel_type(f), max_speed(m), colour(c){}

    //void read(Stream& stream);

    //void write(Stream& stream);

    friend std::ostream& operator<<(std::ostream& os, const Car& c)
    {
        return os << c.fuel_type << ' ' << c.max_speed << ' ' << c.colour;
    }

    // Serialized input
    friend std::istream& operator>>(std::istream& is, Car& c)
    {
        return is >> c.fuel_type >> c.max_speed >> c.colour;
    }

    //  getters
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
