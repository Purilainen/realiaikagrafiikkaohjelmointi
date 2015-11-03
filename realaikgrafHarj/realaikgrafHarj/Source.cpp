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

template<class T> class matrix_T
{
public:
	matrix_T(int _rows,int  _cols, const T& _initial)
	{
		matrix.resize(_rows);
		for (int i = 0; i < matrix.size(); i++)
		{
			matrix[i].resize(_cols, _initial);
		}
		rows = _rows;
		cols = _cols;
	}

	matrix_T operator()(const int& row, const int& col) const
	{
		return matrix[row][col];
	}
	matrix_T operator+(const matrix_T &m) const
	{
		//Matriisien yhteenlasku

		//Luodaan tulosmatriisi
		matrix_T result(rows, cols, 0.0);
		//käydään matriisit läpi ja tehdään laskutoimitukset
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				result(i, j) = matrix[i][j] + m(i, j);
			}
		}
		//palautetaan tulosmatriisi
		return result;
	}
	matrix_T operator*(const matrix_T &m) const
	{
		//Matriisien kertolasku
		rows = m.rows;
		cols = m.cols;
		//Tulosmatriisi
		matrix_T result(rows, cols, 0.0);

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				for (int k = 0; k < rows; k++)
				{
					result(i, j) += matrix[i][k] * m(k, j);
				}
			}
		}
		return result;
	}
	matrix_T operator*(const std::vector<T> &v) const
	{
		//Matriisin kertominen vektorilla
		//Luodaan tulosvektori
		std::vector<T> result(v.size(), 0.0);

		if (result.size() != rows)
		{
			std::cout << "ERROR: vector size incompatible with this matrix";
		}
		else
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					result[i] = matrix[i][j] * v[j];
				}
			}
		}
		return result;
	}


	int GetRows()
	{
		return rows;
	}
	int GetCols()
	{
		return cols;
	}
	matrix_T<T> transpose()
	{
		matrix_T result(rows, cols, 0.0);

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				result(i, j) = matrix[j][i];
			}
		}
		return result;
	}
	//check if ortogonal
	//käänteismatriisin laskenta
	// siirto, kierto, skaalaus
	//Peri matriisi- ja vektoriluokkamallista 2d-homogeenisten koordinaattien --> 3D --> perpektiivimuunnoksen vaatimat matriisit
	//kasittelyyn omat luokkansa ja toteuta matriisiin kierto, siirto ja skaalaus.

private:
	std::vector<std::vector<T>> matrix;
	int rows;
	int cols;

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

	matrix_T<int> mat1(3, 3, 1.0);


	for (int i = 0; i<mat1.GetRows(); i++) 
	{
		for (int j = 0; j<mat1.GetCols(); j++) 
		{
			std::cout << mat1(i,j) << ", ";
		}
		std::cout << std::endl;
	}

	system("pause");
}



