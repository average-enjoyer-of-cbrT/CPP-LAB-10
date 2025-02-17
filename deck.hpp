#pragma once

#include <ostream>
#include <stdexcept>

template <typename T>
class MyDeck {
private:
    struct Node {
        T value;
        Node* next;
        Node* prev;

        Node(T val, Node* p = nullptr, Node* n = nullptr) : value(val), prev(p), next(n) {}
    };

    int elements = 0;
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    MyDeck() = default;

    ~MyDeck() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr; // Добавлено для ясности, хотя и необязательно
        elements = 0; //Добавлено для ясности
    }

    void push_back(const T& value) { // Добавлена константная ссылка
        Node* newNode = new Node(value, tail);
        if (empty()) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
        ++elements; // Префиксный инкремент чуть эффективнее
    }
     void push_front(const T& value) { // Добавлена константная ссылка
        Node* newNode = new Node(value, nullptr, head);
        if (empty()) {
            tail = newNode;
        } else {
            head->prev = newNode;
        }
        head = newNode;
        ++elements;
    }

    T pop_back() {
        if (empty()) {
            throw std::out_of_range("Дек пуст");
        }

        Node* temp = tail;
        T val = temp->value; // Переименовал для единообразия
        tail = tail->prev;

        if (!tail) { // Более лаконичная проверка на nullptr
            head = nullptr;
        } else {
            tail->next = nullptr;
        }

        delete temp;
        --elements; // Префиксный декремент
        return val;
    }

    T pop_front() {
        if (empty()) {
            throw std::out_of_range("Дек пуст");
        }

        Node* temp = head;
        T val = temp->value;
        head = head->next;

        if (!head) {
            tail = nullptr;
        } else {
            head->prev = nullptr;
        }

        delete temp;
        --elements;
        return val;
    }

    [[nodiscard]] bool empty() const {
        return !elements; // Более короткая запись
    }

    [[nodiscard]] int size() const {
        return elements;
    }

    friend std::ostream& operator<<(std::ostream& os, const MyDeck<T>& deck) { //const ссылка
        os << '[';
        Node* current = deck.head;
        while (current) { // Более лаконичная проверка на nullptr
            os << current->value;
            if (current->next) {
                os << ", ";
            }
            current = current->next;
        }
        os << ']';
        return os;
    }
};

