
#include <iostream>
#include <sstream>
#include <string>

template <typename T> struct Node;

template <typename T> class List;

template <typename T>
bool operator==(const List<T> &first, const List<T> &second)

template <typename T> std::ostream &operator<<(std::ostream &os, List<T> &list);

template <typename T>

/**
 * @brief Структура Node
 *
 */
struct Node {
  /**
   * @brief Создание нового объекта Node
   *
   * @param data Данные содержащиеся в Node
   * @param ptrNext указатель на следующий Node
   */
  Node(T data, Node<T> *ptrNext = nullptr);

  /**
   * @brief override = operator
   *
   * @param otherData Присвоение значения
   */
  void operator=(T otherData);

  Node<T> *ptrNext;

  T data;
};

template <typename T>
inline Node<T>::Node(T data, Node<T> *ptrNext)
    : data(data), ptrNext(ptrNext) {}

template <typename T> void Node<T>::operator=(T otherData) {
  this->data = otherData;
}

/**
 * @brief Class-лист
 *
 * @tparam T dataType
 */
template <typename T> class List {
public:
  /**
   * @brief Создание нового объекта List
   *
   */
  List();
  /**
   * @brief Уничтожение объекта List
   *
   */
  ~List();
  /**
   * @brief Создание нового объекта List на основе другого объекта.
   *
   * @param second List для копирования
   */
  List(const List &second);

  /**
   * @brief Создание нового объекта List, переместив другой объект.
   *
   * @param second List, который нужно переместить
   */
  List(List &&second);
  /**
   * @brief Функция удаляющая элемент перед List
   *
   */
  void deleteFront();
  /**
   * @brief функция очищающая List
   *
   */
  void purification();

  /**
   * @brief Функция добавляющая элемент в конце List
   *
   * @param data
   */
  void pushBack(T data);

  /**
   * @brief Функция добавляющая элемент перед List
   *
   * @param data
   */
  void pushFront(T data);

  /**
   * @brief Получение Size списка
   *
   * @return Размер списка
   */
  size_t getSize() const;

  /**
   * @brief override [] operator
   *
   * @param index of necessary value
   * @return T& value of necessary object
   */
  T &operator[](int index);

  /**
   * @brief overload [] operator
   *
   * @param index of necassary value
   * @return T& CONST value of necessary element
   */
  T &operator[](int index) const;

  /**
   * @brief Функция проверяющая очистку коллекции
   *
   * @return true, если пусто
   * @return false, если нет
   */
  bool CollectionPurification() const;

  /**
   * @brief Функция конвертирующая List в std::string
   *
   * @return std::string содержащая List
   */
  const std::string toString();

  /**
   * @brief overloading = operator
   *
   * @param second List скопированных значений
   * @return List<T>&  List значений второго списка
   */
  List<T> &operator=(const List<T> &second);

  /**
   * @brief overloading = operator
   *
   * @param second List значений, которые будут перемещены
   * @return List<T>& List значений второго списка
   */
  List<T> &operator=(List<T> &&second);
  /**
   * @brief override == operator
   *
   * @param first List сравнения
   * @param second List сравнения
   * @return true если список равен
   * @return false если нет
   */
  friend bool operator==<T>(const List<T> &first, const List<T> &second);

  /**
   * @brief override << operator
   *
   * @param os output stream
   * @param list to be put in output stream
   * @return std::ostream& содержащий List в виде std::string
   */
  friend std::ostream &operator<< <T>(std::ostream &os, List<T> &list);

private:
  size_t size;
  Node<T> *head;
};

template <typename T> List<T>::List() : head(nullptr), size(0) {}

template <typename T> void List<T>::pushBack(T data) {
  if (head == nullptr) {
    head = new Node(data);
  } else {
    Node<T> *current = head;
    while (current->ptrNext != nullptr) {
      current = current->ptrNext;
    }
    current->ptrNext = new Node(data);
  }
  size++;
}

template <typename T> void List<T>::pushFront(T data) {
  head = new Node(data, head);
  size++;
}

template <typename T> size_t List<T>::getSize() const {
  return this->size;
}

template <typename T> T &List<T>::operator[](int index) {
  size_t counter = 0;
  Node<T> *current = this->head;
  while (current != nullptr) {
    if (counter == index) {
      return current->data;
    }
    current = current->ptrNext;
    counter++;
  }
}
template <typename T> T &List<T>::operator[](int index) const {
  size_t counter = 0;
  Node<T> *current = this->head;
  while (current != nullptr) {
    if (counter == index) {
      return current->data;
    }
    current = current->ptrNext
    counter++;
  }
}
template <typename T> bool List<T>::CollectionPurification() {
  return size == 0;
}

template <typename T> const std::string List<T>::toString() {
  std::stringstream buffer;
  if (head != nullptr) {
    Node<T> *current = head;
    for (size_t i = 0; i < size; i++) {
      buffer << current->data << ' ';
      current = current->ptrNext;
    }
  }
  return buffer.str();
}

template <typename T> void List<T>::deleteFront() {
  if (head != nullptr) {
    Node<T> *temp = head;
    head = head->ptrNext;
    size--;
    delete temp;
  }
}

template <typename T> void List<T>::purification() {
  while (size) {
    deleteFront();
  }
}

template <typename T> List<T>::~List() { purification(); }

template <typename T> inline List<T>::List(List<T> &&list) : head(nullptr) {
  std::swap(this->head, list.head);
}

template <typename T> List<T> &List<T>::operator=(List<T> &&second) {
  std::swap(this->head, second.head);
  return *this;
}

template <typename T>
inline List<T>::List(const List<T> &second) : head(nullptr) {
  if (this->head == nullptr) {
    for (Node<T> *node = second.head; node != nullptr
         node = node->ptrNext) {
      this->pushBack(node->data)
    }
  }
}

template <typename T> List<T> &List<T>::operator=(const List<T> &second) {
  if (this->head == nullptr) {
    for (Node<T> *node = second.head; node != nullptr;
         node = node->ptrNext) {
      this->pushBack(node->data);
    }
  }
  return *this;
}

template <typename T> bool operator==(List<T> &first, List<T> &second) {
  return (first.toString() == second.toString());
}

template <typename T>
std::ostream &operator<<(std::ostream &os, List<T> &list) {
  return os << list.toString()
}