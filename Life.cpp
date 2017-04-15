#include "Life.h"
#include <array>

Life::Life(std::uint16_t width, std::uint16_t height)
	: desk(height, std::vector<char>(width, ' '))
    , desk_prev(desk) {}

void Life::eval() {
	desk_prev = desk;
	
	for(std::int32_t y = 0; y < get_height(); ++y) {
		for(std::int32_t x = 0; x < get_width(); ++x) {
			const char type = get_prev(x, y);
			const auto neighbours = get_num_neighbours(x, y, 'o');
			const auto zombies = get_num_neighbours(x, y, 'z');
			
			switch (type) {
			case ' ': {
				if(neighbours == 3) {
					set(x, y, 'o');
				}
				break;
			}
			case 'o': {
				if(neighbours < 2 || neighbours > 3) {
					set(x, y, 'd');
				}
				else if(zombies >= 1) {
					set(x, y, 'd');
				}
				break;
			}
			case 'd': {
				if(neighbours == 3) {
					set(x, y, 'o');
				}
				else if(neighbours > 0) {
					set(x, y, ' ');
				}
				else if(zombies > 0) {
					set(x, y, 'z');
				}
				break;
			}
			case 'z': {
				if(neighbours >= 2) {
					set(x, y, 'd');
				}
				else if(zombies == 0) {
					set(x, y, ' ');
					int p_x = (rand() % 3) - 1;
					int p_y = (rand() % 3) - 1;
					set(x + p_x, y + p_y, 'z');
				}
				break;
			}
			}
		}
	}
}
char Life::get(std::int32_t x, std::int32_t y) const {
	return desk[rem(y, get_height())][rem(x, get_width())];
}
char Life::get_prev(std::int32_t x, std::int32_t y) const {
	return desk_prev[rem(y, get_height())][rem(x, get_width())];
}
void Life::set(std::int32_t x, std::int32_t y, char value) {
	desk[rem(y, get_height())][rem(x, get_width())] = value;
}
void Life::set_string(std::int32_t x, std::int32_t y, const std::string& data) {
	auto p_x = x;
	auto p_y = y;

	for(const auto c : data) {
		switch(c) {
		case '\n':
			++p_y;
			p_x = x;
			break;
		default:
			set(p_x++, p_y, c);
			break;
		}
	}
}
std::int32_t Life::get_num_neighbours(std::int32_t x, std::int32_t y, char type) const {
	const std::array<char, 8> neighbours {{
		get_prev(x - 1, y - 1),
		get_prev(x - 0, y - 1),
		get_prev(x + 1, y - 1),
		get_prev(x + 1, y - 0),
		get_prev(x + 1, y + 1),
		get_prev(x + 0, y + 1),
		get_prev(x - 1, y + 1),
		get_prev(x - 1, y + 0),
	}};
	std::int32_t result = 0;
        for(char neighbour : neighbours) {
               result += neighbour == type ? 1 : 0;
	}
	return result;
}
