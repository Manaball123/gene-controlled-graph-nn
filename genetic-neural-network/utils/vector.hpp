#pragma once
#include "typedefs.hpp"
namespace Vector
{

	template<class dtype>
	class Vector2
	{

	public:
		dtype x;
		dtype y;

		//double& operator[](int index);
		Vector2(dtype x, dtype y)
		{
			this->x = x;
			this->y = y;

		}
		Vector2()
		{
			this->x = 0;
			this->y = 0;
		}
		/*
		double& Vector2::operator[](int index)
		{
			return this->Vector[index];
		}
		*/

		void operator+=(Vector2 v)
		{
			this->x += v.x;
			this->y += v.y;

		};

		void operator-=(Vector2 v)
		{
			this->x -= v.x;
			this->y -= v.y;
		};


		void operator*=(dtype multiplier)
		{
			this->x *= multiplier;
			this->y *= multiplier;
		};

		Vector2 operator+(Vector2 v)
		{
			return Vector2(this->x += v.x, this->y += v.y);

		};
		Vector2 operator-(Vector2 v)
		{
			return Vector2(this->x -= v.x, this->y -= v.y);

		};
		Vector2 operator*(dtype multiplier)
		{
			return Vector2(this->x *= multiplier, this->y *= multiplier);
		};




		//Dot product between this and another vector
		dtype operator*(Vector2<dtype> v)
		{
			return this->x * v.x + this->y * v.y;

		};

		Vector2<dtype> operator=(Vector2<dtype>& v)
		{
			return *this;
		}
		dtype Dot(Vector2<dtype> v)
		{
			return this->x * v.x + this->y * v.y;
		}


		/*
		Vector2<dtype> Cross(Vector2<dtype> v1, Vector2<dtype> v2)
		{

		}
		*/

		dtype Length()
		{
			return pow(pow(this->x, 2.0) + pow(this->y, 2.0), 0.5);
		}

		dtype LengthSquare()
		{
			return pow(this->x, 2.0) + pow(this->y, 2.0);
		}

		//returns the normal vector of the vector object
		Vector2<dtype> Normalize()
		{
			dtype len = this->Length();
			Vector2 v = Vector2();
			v.x = v.x / len;
			v.y = v.y / len;
			return v;
		}




	};
	//export alisases

		using Vector2F = Vector::Vector2<float>;
		using Vectro2D = Vector::Vector2<double>;

		using Vector2I = Vector::Vector2<int32>;
		using Vector2UI = Vector::Vector2<uint32>;

		using Vector2S = Vector::Vector2<int32>;
		using Vector2US = Vector::Vector2<uint32>;

		using Vector2L = Vector::Vector2<int64>;
		using Vector2UL = Vector::Vector2<uint64>;
	



}

