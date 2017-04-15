#include <iostream>
#include "Life.h"
#include <algorithm>

void print(const Life& life) {
	std::cout << '+';
	for(std::size_t x = 0; x < life.get_width(); ++x) {
		std::cout << '-';
	}
	std::cout << '+' << std::endl;
    for(std::size_t y = 0; y < life.get_height(); ++y) {
		std::cout << '|';
		for(std::size_t x = 0; x < life.get_width(); ++x) {
			std::cout << life.get(x, y);
		}
		std::cout << '|' << std::endl;
	}
	std::cout << '+';
	for(std::size_t x = 0; x < life.get_width(); ++x) {
		std::cout << '-';
	}
	std::cout << '+' << std::endl;
}

int main() {
	// {ширина, высота} поля
	Life life {40, 20};
		std::string glider =
                           " o \n"
                           "  o\n"
                           "ooo\n"
                   ;
      // ставит глайдер в указанные координаты
            life.set_string(5, 2, glider);
            life.set_string(10, 4, glider);
            life.set_string(15, 6, glider);
            life.set_string(20, 10, glider);
            life.set_string(25, 12, glider);
            life.set_string(30, 14, glider);
            life.set_string(35, 16, glider);
            life.set_string(40, 18, glider);
       // пару зомбаков
            life.set_string(1, 1, "Z");
            life.set_string(5, 5, "Z");
            life.set_string(15, 10, "Z");
            life.set_string(25, 15, "Z");
            life.set_string(35, 20, "Z");
            life.set_string(40, 7, "Z");
	while(true) {
		// Консоль очищает
    system("cls");
		// выводит поле
		print(life);
		// переход на следующий шаг
		life.eval();
    system("pause");
	}
	return 0;
}
