#pragma once
#include <initializer_list>
#include <iostream>
#include <sstream>

/**
* @brief Класс, описывающий двусвязный список
*/
template <typename T>
class DoublyLinkedList {
public:
    /**
    * @brief Инициализирует пустой объект класса DoublyLinkedList
    */
    DoublyLinkedList();

    /**
    * @brief Инициализирует объект класса DoublyLinkedList по списку элементов
    * @param elements Набор данных 
    */
    DoublyLinkedList(std::initializer_list<T> elements);
    /**
    * @brief Деструктор, чистит память за собой
    */
    ~DoublyLinkedList();

    /**
    * @brief Преобразование данных объекта в строку
    * @return Строка с данными объекта
    */
    std::string toString() const;

    /**
    * @brief Очистка списка
    */
    void clear();

    /**
    * @brief Определение отсутствия элеменетов в объекте
    * @return true - нет объектов, иначе false
    */
    bool isEmpty() const;

    /**
    * @brief Перегрузка опреатора копирования
    * @param other объект для копирования
    * @return Скопированный объект
    */
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other);

    /**
    * @brief Перегрузка опреатора сдвига влево (Добавление элемента в конец)
    * @param value объект для сдвига
    * @return Полученный объект
    */
    DoublyLinkedList<T>& operator<<(const T& value);

    /**
    * @brief Перегрузка опреатора сдвига вправо (Удаление элемента с начала)
    * @param value объект для сдвига
    * @return Полученный объект
    */
    DoublyLinkedList<T>& operator>>(const T& value);

    /**
    * @brief Перегрузка опреатора вывода
    * @param os Поток вывода
    * @param list Объект для вывода
    * @return Поток вывода с информацией об объекте
    */
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<U>& list);

private:
    /**
    * @brief Класс, описывающий элемент списка
    */
    template <typename T>
    class Node {
    public:
        T data;
        Node<T>* prev;
        Node<T>* next;

        /**
        * @brief Инициализирует объект по значению
        * @param value Значение ноды
        */
        Node(const T& value) 
            : data(value), prev(nullptr), next(nullptr) 
        {}
    };

    Node<T>* head;
    Node<T>* tail;

    // Реализация деталей двусвязного списка
    
};


template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(std::initializer_list<T> elements) : head(nullptr), tail(nullptr) {
    for (const T& element : elements) {
        *this << element;
    }
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template <typename T>
std::string DoublyLinkedList<T>::toString() const {
    std::stringstream result;
    Node<T>* current = head;
    while (current != nullptr) {
        result << current->data << " ";
        current = current->next;
    }
    return result.str();
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other) {
    if (this != &other) {
        clear();

        Node<T>* current = other.head;
        while (current != nullptr) {
            *this << current->data;
            current = current->next;
        }
    }
    return *this;
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator<<(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    return *this;
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator>>(const T& value) {
    if (!isEmpty()) {
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node<T>* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
    }
    return *this;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    while (!isEmpty()) {
        *this >> head->data;
    }
}

// Реализация перегрузки оператора вывода потока
template <typename U>
std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<U>& list) {
    os << list.toString();
    return os;
}
