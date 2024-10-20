#include <SFML/Graphics.hpp>
#include <chrono>
#include "Headers.h"

int fps = 2;

int main() {
    size_t Width = 50, Height = 50, CELL_SIZE = 20;

    // Создание карты
    char** Map = new char* [Width];
    for (size_t i = 0; i < Width; i++) {
        Map[i] = new char[Height];
        for (size_t j = 0; j < Height; j++) {
            Map[i][j] = ' ';
        }
    }

    // Создание булевой карты
    bool** MapBool = new bool* [Width];
    for (size_t i = 0; i < Width; i++) {
        MapBool[i] = new bool[Height];
        for (size_t j = 0; j < Height; j++) {
            MapBool[i][j] = false;
        }
    }

    // Инициализация живых клеток
    Map[25][24] = '#';
    Map[25][25] = '#';
    Map[25][26] = '#';
    Map[24][25] = '#';

    Map[25][30] = '#';
    Map[25][31] = '#';
    Map[25][32] = '#';
    Map[24][31] = '#';

    sf::RenderWindow window(sf::VideoMode(Width * CELL_SIZE, Height * CELL_SIZE), "Game of Life");
    sf::Clock clock;
    double delay = 1.0 / fps;

    // Главный игровой цикл
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Обновление карты
        if (clock.getElapsedTime().asSeconds() >= delay) {
            UpdateMap(Map, MapBool, Width, Height);  // Реализовать функцию обновления
            clock.restart();
        }

        // Очищаем окно перед рендером
        window.clear();

        // Отрисовка клеток
        for (size_t i = 0; i < Width; i++) {
            for (size_t j = 0; j < Height; j++) {
                sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));  // Клетка чуть меньше, чтобы были видны границы
                cell.setPosition(i * CELL_SIZE, j * CELL_SIZE);

                if (Map[i][j] == '#') {
                    cell.setFillColor(sf::Color::Green);  // Живая клетка
                }
                else {
                    cell.setFillColor(sf::Color::White);  // Мертвая клетка
                }

                window.draw(cell);
            }
        }

        // Отображаем все на экране
        window.display();
    }

    // Освобождаем память
    for (size_t i = 0; i < Width; i++) {
        delete[] Map[i];
        delete[] MapBool[i];
    }
    delete[] Map;
    delete[] MapBool;

    return 0;
}