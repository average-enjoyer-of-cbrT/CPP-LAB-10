#include <iostream>
#include "deck.hpp"

int main() {
    MyDeck<int> deck;

    std::cout << "Тест добавления элементов:" << std::endl;
    deck.push_back(1);
    deck.push_back(2);
    deck.push_front(0);
    deck.push_back(3);
    deck.push_front(-1);
    std::cout << "Дек после добавления: " << deck << std::endl;
    std::cout << "Размер дека: " << deck.size() << std::endl;

    std::cout << "\nТест удаления элементов:" << std::endl;
    std::cout << "Удален с начала: " << deck.pop_front() << std::endl;
    std::cout << "Удален с конца: " << deck.pop_back() << std::endl;
    std::cout << "Дек после удаления: " << deck << std::endl;

    std::cout << "\nТест на исключения:" << std::endl;
    while (!deck.empty()) {
        deck.pop_back();
    }

    try {
        deck.pop_back();
    } catch (const std::out_of_range& e) {
        std::cout << "Перехвачено исключение при pop_back: " << e.what() << std::endl;
    }

    try {
        deck.pop_front();
    } catch (const std::out_of_range& e) {
        std::cout << "Перехвачено исключение при pop_front: " << e.what() << std::endl;
    }

    std::cout << "\nТест с другим типом данных (double):" << std::endl;
    MyDeck<double> doubleDeck;
    doubleDeck.push_back(1.5);
    doubleDeck.push_back(2.7);
    doubleDeck.push_front(0.5);
    std::cout << "Дек с double: " << doubleDeck << std::endl;

    return 0;
}