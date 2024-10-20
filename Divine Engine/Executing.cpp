#include <SFML/Graphics.hpp>
#include <chrono>
#include "Headers.h"

int fps = 2;

int main() {
    size_t Width = 50, Height = 50, CELL_SIZE = 20;

    // �������� �����
    char** Map = new char* [Width];
    for (size_t i = 0; i < Width; i++) {
        Map[i] = new char[Height];
        for (size_t j = 0; j < Height; j++) {
            Map[i][j] = ' ';
        }
    }

    // �������� ������� �����
    bool** MapBool = new bool* [Width];
    for (size_t i = 0; i < Width; i++) {
        MapBool[i] = new bool[Height];
        for (size_t j = 0; j < Height; j++) {
            MapBool[i][j] = false;
        }
    }

    // ������������� ����� ������
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

    // ������� ������� ����
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // ���������� �����
        if (clock.getElapsedTime().asSeconds() >= delay) {
            UpdateMap(Map, MapBool, Width, Height);  // ����������� ������� ����������
            clock.restart();
        }

        // ������� ���� ����� ��������
        window.clear();

        // ��������� ������
        for (size_t i = 0; i < Width; i++) {
            for (size_t j = 0; j < Height; j++) {
                sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));  // ������ ���� ������, ����� ���� ����� �������
                cell.setPosition(i * CELL_SIZE, j * CELL_SIZE);

                if (Map[i][j] == '#') {
                    cell.setFillColor(sf::Color::Green);  // ����� ������
                }
                else {
                    cell.setFillColor(sf::Color::White);  // ������� ������
                }

                window.draw(cell);
            }
        }

        // ���������� ��� �� ������
        window.display();
    }

    // ����������� ������
    for (size_t i = 0; i < Width; i++) {
        delete[] Map[i];
        delete[] MapBool[i];
    }
    delete[] Map;
    delete[] MapBool;

    return 0;
}