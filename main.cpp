#include <iostream>
#include "deck.hpp"

int main() {
    MyDeck<int> deck;

    std::cout << "Добавление элементов:" << std::endl;
    deck.push_back(4);
    deck.push_back(6);
    deck.push_front(1);
    deck.push_back(2);
    deck.push_front(-1);
    std::cout << "Deque после добавления: " << deck << std::endl;
    std::cout << "Размер deque: " << deck.size() << std::endl;

    std::cout << "\nУдаление элементов:" << std::endl;
    std::cout << "Удален с начала: " << deck.pop_front() << std::endl;
    std::cout << "Удален с конца: " << deck.pop_back() << std::endl;
    std::cout << "Deque после удаления: " << deck << std::endl;

    std::cout << "\nТест с double:" << std::endl;
    MyDeck<double> doubleDeck;
    doubleDeck.push_back(1.5);
    doubleDeck.push_back(2.7);
    doubleDeck.push_front(0.5);
    std::cout << "Deque с double: " << doubleDeck << std::endl;

    return 0;
}