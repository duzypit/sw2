#ifndef __ISHAPE_HPP__
#define __ISHAPE_HPP__

class IShape
{
	public:
		virtual ~IShape() {}
		virtual double getArea() = 0;
        virtual double getCircuit() = 0;
};


#endif
