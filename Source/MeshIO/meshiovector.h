#ifndef _MESH_MESHVECTOR_
#define _MESH_MESHVECTOR_

#include <iostream>
#include <cmath>

//#include "meshio.h"

struct meshio::Vector
{
    double xComp;
    double yComp;
    double zComp;

    Vector()
    {
        xComp = 0;
        yComp = 0;
        zComp = 0;
    }

    Vector(double a, double b)
    {
        xComp = a;
        yComp = b;
        zComp = 0;
    }

    Vector(double a, double b, double c)
    {
        xComp = a;
        yComp = b;
        zComp = c;
    }

    /*
     Operation OVERLOADS!!!!
     whoop WHOOP!!!!

     const at the end allows for Vector to be passed to functions.
     */

    // Bool Overload
    Vector operator==(const Vector& other) const
    {
        Vector nVector;
        nVector.xComp = this->xComp == other.xComp;
        nVector.yComp = this->yComp == other.yComp;
        nVector.zComp = this->zComp == other.zComp;

        return nVector;
    }

    // Not Overload
    Vector operator!=(const Vector& other) const
    {
        Vector nVector;
        nVector.xComp = this->xComp != other.xComp;
        nVector.yComp = this->yComp != other.yComp;
        nVector.zComp = this->zComp != other.zComp;

        return nVector;
    }

    // Copy Overload
    void operator=(const Vector& other)
    {
        this->xComp = other.xComp;
        this->yComp = other.yComp;
        this->zComp = other.zComp;
    }

    // Addition Overload
    Vector operator+(const Vector& other) const
    {
        Vector nVector;
        nVector.xComp = this->xComp + other.xComp;
        nVector.yComp = this->yComp + other.yComp;
        nVector.zComp = this->zComp + other.zComp;

        return nVector;
    }

    // Subtraction Overload
    Vector operator-(const Vector& other) const
    {
        Vector nVector;
        nVector.xComp = this->xComp - other.xComp;
        nVector.yComp = this->yComp - other.yComp;
        nVector.zComp = this->zComp - other.zComp;

        return nVector;
    }

    // Multiplication Overload
    Vector operator*(double value) const
    {
        Vector nVector;
        nVector.xComp = this->xComp * value;
        nVector.yComp = this->yComp * value;
        nVector.zComp = this->zComp * value;

        return nVector;
    }

    // Division Overload
    Vector operator/(double value) const
    {
        Vector nVector;
        nVector.xComp = this->xComp / value;
        nVector.yComp = this->yComp / value;
        nVector.zComp = this->zComp / value;

        return nVector;
    }


    // Vector Cross Product
    Vector CrossProduct(const Vector kThat)
    {
        Vector nVector;
        nVector.xComp = this->yComp * kThat.zComp - this->zComp * kThat.yComp;
        nVector.yComp = this->zComp * kThat.xComp - this->xComp * kThat.zComp;
        nVector.zComp = this->xComp * kThat.yComp - this->yComp * kThat.xComp;

        return nVector;
    }

    // Vector Dot Product
    double DotProduct(const Vector kThat)
    {
        double value = 0.0;
        value += this->xComp*kThat.xComp;
        value += this->yComp*kThat.yComp;
        value += this->zComp*kThat.zComp;

        return value;
    }

    // Vector Normal
    double VectorNorm()
    {
        double value = 0.0;
        value += this->xComp*this->xComp;
        value += this->yComp*this->yComp;
        value += this->zComp*this->zComp;

        value = sqrt(value);

        return value;
    }

    // Unit Vector
    Vector VectorUnit(const Vector kThat)
    {
        Vector nVector;

        nVector = kThat / VectorNorm();

        return nVector;
    }

    void Print()
    {
        std::cout<<this->xComp << " ";
        std::cout<<this->yComp << " ";
        std::cout<<this->zComp;
    }

    friend std::ostream & operator<< (std::ostream& out, Vector& v)
    {
        out << "[" << v.xComp << " " << v.yComp << " " << v.zComp << "]";

        return out;
    }
};

#endif //VECTOR_H
