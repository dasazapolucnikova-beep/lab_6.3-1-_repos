#include "pch.h"
#include "CppUnitTest.h"
#include "../Project 6.3(1)/Project 6.3(1).cpp" // Перевірте точність шляху до файлу

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest63
{
    TEST_CLASS(UnitTest63)
    {
    public:

        TEST_METHOD(TestMethod_Min_Int)
        {
            // Тест для звичайної рекурсивної функції MinRecursive
            const int size = 5;
            int arr[size] = { 3, -10, 5, 0, 8 };

            int expected = -10;
            int actual = MinRecursive(arr, size);

            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(TestMethod_MinTemplate_Double)
        {
            // Тест для шаблону рекурсивної функції MinTemplateRecursive
            const int size = 5;
            double arr[size] = { 2.5, -4.2, 0.0, 10.1, -1.8 };

            double expected = -4.2;
            double actual = MinTemplateRecursive(arr, size);

            Assert::AreEqual(expected, actual, 0.0001);
        }
    };
}