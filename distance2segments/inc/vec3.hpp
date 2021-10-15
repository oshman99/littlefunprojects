#ifndef VEC3_HPP
#define VEC3_HPP

#include <cmath>
#include <iostream>
//
//GLSL-type vec3 class. So, can represent points, vectors and colors if needed
//
template<typename T>
class Vec3
{
    public:
        //---Constructors---
        Vec3():x(0), y(0), z(0) 
        {}
        Vec3(T xValue, T yValue, T zValue): x(xValue), y(yValue), z(zValue)
        {}
        //---Getters and setters---

        void set(const T &xValue, const T &yValue, const T &zValue)
        {
            x = xValue;
            y = yValue;
            z = zValue;
        }

        void setX(const T &xValue){ x = xValue; }
        void setY(const T &yValue){ y = yValue; }
        void setZ(const T &zValue){ z = zValue; }

        T getX() const { return x; }
        T getY() const { return y; }
        T getZ() const { return z; }

        //---Not overloaded operators(vector math mostly)---

        //Method to reset vec to zero
        void zero(){ x = y = z = 0; }

        //Method to calculate vector's length
        T magnitude() const
        {
            return std::sqrt(x*x + y*y + z*z);
        }
        
        //Method to normalise and return vector
        Vec3 normalise() const
        {
            T vecMagnitude = magnitude();
            if(magnitude() != 0)
            {
                return Vec3(x / magnitude(), y / magnitude(), z / magnitude());
            }
            return Vec3(0, 0, 0);
        }

        //Static method to calculate and return dot product of 2 vec3. Usable to tell things about angle between vec3
        static T dot(const Vec3& v1, const Vec3& v2)
        {
            return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
        }

        //Static method to calculate and return vector representing cross product between 2 vec3. Cross product ector is perpendicular to plane formed by those 2 vectors
        static Vec3 cross(const Vec3& v1, const Vec3& v2)
        {
            return Vec3(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
        }

        //Static method to calculate and return distance between 2 vec3s
        static T getDistance(const Vec3& v1, const Vec3& v2)
        {
            T dx = v2.x - v1.x;
            T dy = v2.y - v1.y;
            T dz = v2.z - v1.z;

            return std::sqrt(dx * dx + dy * dy + dz * dz);
        }

        //Easy adders
        void addX(T val){ x += val; }
        void addY(T val){ y += val; }
        void addZ(T val){ z += val; }

        //Method to show and easily check values
        void showVals()
        {
            std::cout << "X: " << x << "\t Y: " << y << "\t Z: " << z << std::endl;
        }

        //--Overloaded operators---

        //Overloaded addition operator to add Vec3 together
        Vec3 operator+(const Vec3 &v1) const
        {
            return Vec3(x + v1.x, y + v1.y, z + v1.z);
        }

        //Overloaded += operator to add Vec3 together
        Vec3 operator+=(const Vec3 &v1)
        {
            x += v1.x;
            y += v1.y;
            z += v1.z;
        }


        //Overloaded subtraction operator to subtract Vec3 form another Vec3
        Vec3 operator-(const Vec3 &v1) const
        {
            return Vec3(x - v1.x, y - v1.y, z - v1.z);
        }

        //Overloaded -= operator to subtract Vec3 form another Vec3
        Vec3 operator-=(const Vec3 &v1)
        {
            x -= v1.x;
            y -= v1.y;
            z -= v1.z;
        }

        //Overloaded multiply operator to multiply Vec3s
        Vec3 operator*(const Vec3 &v1) const
        {
            return Vec3(x * v1.x, y * v1.y, z * v1.z);
        }

        //Overloaded *= operator to multiply Vec3s
        Vec3 operator*=(const Vec3 &v1)
        {
            x *= v1.x;
            y *= v1.y;
            z *= v1.z;
        }

        //Overloaded multiply operator to multiply a Vec3 by a scalar
        Vec3 operator*(const T &value) const
        {
            return Vec3(x * value, y * value, z * value);
        }

        //Overloaded *= operator to multiply a Vec3 by a scalar
        Vec3 operator*=(const T &value)
        {
            x *= value;
            y *= value;
            z *= value;
        }

        //Overloaded division operator to divide a Vec3 by a scalar
        Vec3 operator/(const T &value) const
        {
            return Vec3(x / value, y / value, z / value);
        }

        //Overloaded /= operator to divide a Vec3 by a scalar
        Vec3 operator/=(const T &value)
        {
            x /= value;
            y /= value;
            z /= value;
        }

        //Overloaded subtraction operator to negate Vec3 and return it
        Vec3 operator-() 
        { return Vec3(-x, -y, -z); }

    private:
        T x, y ,z;
};

#endif