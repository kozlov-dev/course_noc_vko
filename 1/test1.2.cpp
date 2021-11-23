/*Задача
https://www.codewars.com/kata/5aba780a6a176b029800041c/train/cpp
Учитывая делитель и границу,найдите наибольшее целое число N такое,что
Условия : N делится на делитель N меньше или равно границе N больше 0.
Примечания Параметры (делитель, граница), переданные в функцию, имеют только положительные значения.
Гарантируется, что делитель найден.
Input >> Output Examples
maxMultiple (2,7) ==> return (6)
Explanation:
(6) делится на (2), (6) меньше или равно оценке (7), и (6) больше 0 .

maxMultiple (10,50)  ==> return (50)
Explanation:
(50) делится на (10) , (50) меньше или равно оценке , and (50) is > 0 .*
*/

#include <iostream>

int maxMultiple(int divisor, int bound)
{
    int n = 0;
    n = bound % divisor;

    return (bound - n);
}
int main()
{
    maxMultiple(2, 7);
    maxMultiple(3, 10);
    maxMultiple(7, 17);

    maxMultiple(10, 50);
    maxMultiple(37, 200);
    maxMultiple(7, 100);

return 0;
}