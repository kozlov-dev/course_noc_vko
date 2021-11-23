/*
https://www.codewars.com/kata/5bb3e299484fcd5dbb002912/train/cpp

Напишите функцию, которая принимает количество шаров (≥ 1) и вычисляет,
сколько уровней вы можете построить треугольник.*
pyramid(1) == 1
pyramid(3) == 2
pyramid(6) == 3
pyramid(10) == 4
pyramid(15) == 5*/

#include <iostream>

int pyramid(int n) {
    int i = 1;
    int level = 0;
    while (n >= 0){
        n = n - (i++);
        if (n >=0 )
        {
          level++;
        }
      }
    std::cout << level << std::endl;
    return level;
}
int main() {
    pyramid(1);
    pyramid(3);
    pyramid(6);
    pyramid(10);
    pyramid(15);
    return 0;
}