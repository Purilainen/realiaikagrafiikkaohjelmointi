#include <vector>
#include <iostream>
#include <math.h>

template<class T> class vector_T
{
public:
	vector_T(int n)
	{
		values.resize(n); 
		for  (auto i : values)
		{
			i = 0.0;
		}
		initialSize = n;
	}
	vector_T(int n, T &v)
	{
		values.resize(n);
		for (int  i = 0; i < n; i++)
		{
			values[i] = v[i];
		}
		initialSize = n;
	}

	vector_T operator+(const vector_T &x) const
	{
		if (GetSize() != x.GetSize())
		{
			std::cout << "Error +operator";
		}
		vector_T v(GetSize());
		for (int i = 0; i < GetSize(); i++)
		{
			v.values[i] = values[i] + x.values[i];
		}
		return v;
	}
	vector_T operator-(const vector_T &x) const
	{
		if (GetSize() != x.GetSize())
		{
			std::cout << "Error -operator";
		}
		vector_T v(GetSize());
		for (int i = 0; i < GetSize(); i++)
		{
			v.values[i] = values[i] - x.values[i];
		}
		return v;

	}
	vector_T operator*(const vector_T &x) const
	{
		
		if (GetSize() != x.GetSize())
		{
			std::cout << "Error *operator";
		}
		vector_T v(GetSize());
		for (int i = 0; i < GetSize(); i++)
		{
			v.values[i] = values[i] * x.values[i];
		}
		return v;

	} // Pistetulo
	vector_T operator*(int scalar) const
	{
		vector_T v(GetSize());
		for (int i = 0; i < GetSize(); i++)
		{
			v.values[i] = values[i] * scalar;
		}
		return v;
	} // Skalaaritulo

	void Push(T const& x)
	{
		if (values.front() == 0 && values.size() <= initialSize)
		{
			values.erase(values.begin());
		}
		values.push_back(x);
		
	}
	void Print() const
	{
		for (int i = 0; i < GetSize(); i++)
		{
			std::cout << values[i] << std::endl;
		}
		
	}
	int GetSize() const
	{
		return values.size();
	}
	float GetNorm()
	{
		vector_T v(GetSize());
		for (int i = 0; i < GetSize(); i++)
		{
			v.values[i] = (values[i]) ^ 2;
		}

		for (int  i = 0; i < v.GetSize(); i++)
		{
			vecLength += std::sqrt(v.values.at(i));
		}

		std::cout << vecLength;
		return vecLength;
	}

private:
	std::vector<T> values;
	int initialSize = 0;
	float vecLength = 0;
	float tempValue = 0;
};


int main()
{
	vector_T<int> vector1(3);
	vector_T<int> vector2(3);
	vector_T<int> vector3(3);

	vector1.Push(2);
	vector1.Push(3);
	vector1.Push(4);

	vector2.Push(5);
	vector2.Push(6);
	vector2.Push(7);

	vector3 = vector1 + vector2;
	vector3.Print();

	vector3 = vector2 - vector1;
	vector3.Print();

	vector3 = vector2 * vector1;
	vector3.Print();

	vector3 = vector1 * 2;
	vector3.Print();

	vector1.GetNorm();


	system("pause");
}



