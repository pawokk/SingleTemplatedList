#include "pch.h"
#include "CppUnitTest.h"
#include"..//mtarix/Generator.h"
#include "../mtarix/RandomGenerator.h"
#include "../mtarix/Matrix.h"
#include"../mtarix/Task.h"
#include"../mtarix/Row.h"
#include "../mtarix/KeyboardGenerator.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace matrix;
namespace MatrixTest
{
	TEST_CLASS(MatrixTest)
	{
	public:

		TEST_METHOD(ConstructorTest_ValidData_Success)
		{
			RandomGenerator gen(-10, 10);
			Matrix m(3, 3, &gen);

			Assert::IsNotNull(&m);

		}
		TEST_METHOD(Copy_Test_Success) {
			RandomGenerator rnd(-10, 10);
			Matrix matrix(3, 3, &rnd);

			Matrix matrixtwo(matrix);
			Assert::AreEqual(matrix.MatrixToString(), matrixtwo.MatrixToString());
		}
		TEST_METHOD(GetCol_Test_Validdata_Succes) {
			RandomGenerator rnd(-10, 10);
			Matrix matrix(3, 5, &rnd);
			size_t expcol = 5;
			Assert::AreEqual(matrix.Get_cols(), expcol);
		}
		TEST_METHOD(GetRow_Test_Validdata_Succes) {
			RandomGenerator rnd(-10, 10);
			Matrix matrix(3, 5, &rnd);
			size_t expcol = 3;
			Assert::AreEqual(matrix.Get_rows(), expcol);
		}
	};
	TEST_CLASS(TaskTest)
	{
	public:
		TEST_METHOD(ConstructorTest_ValidData_Success)
		{
			RandomGenerator rnd(-5, 5);
			Matrix matrix(3, 3, &rnd);
			Task task(matrix, &rnd);

			Assert::IsNotNull(&task);
		}

		TEST_METHOD(GetTask2_ValidData_Success)
		{
			std::istringstream in("1 2 3 5");
			KeyboardGenerator kbd(in);
			Matrix matrix(2, 2, &kbd);
			Task task(matrix, &kbd);
			Matrix matrix2 = task.getTask2();
			std::string exp = "1 2 \n1 2 \n3 5 \n";
			bool AreEqual = (exp == matrix2.MatrixToString());
			Assert::IsTrue(AreEqual);
		}
		TEST_METHOD(GetTask1_ValidData_Success)
		{
			std::istringstream in("1 2 3 5");
			KeyboardGenerator kbd(in);
			Matrix matrix(2, 2, &kbd);
			Task task(matrix, &kbd);
			Matrix matrix2 = task.getTask1();
			std::string exp = "1 0 \n3 5 \n";
			bool AreEqual = (exp == matrix2.MatrixToString());
			Assert::IsTrue(AreEqual);
		}

	};
}
