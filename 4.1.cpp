#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
 
using namespace std;
 
template<typename T>
bool check_equality_coordinates(T x , T y) {
    return x == y;
}
 
template <typename T>
struct  Point
	{
        /*
        @brief инициализирует новый объект класса Point
        @param x - абсцисса
        @param y - ордината
        */
        Point(const T x = 0, const T y = 0);
        /*
        @brief Перегрузка оператора потока вывода
        @param os поток вывода
        @param point точка
        @return Поток вывода
        */
 
        template<typename U>
        friend std::ostream& operator<< (std::ostream& os, const Point<U>& point);
 
        /*
        @brief Перегрузка оператора сравнения
        @param lhs Первый аргумент
        @param rhs Второй аргумент
        @return Поток вывода
        */
 
        template <typename U>
        friend bool operator ==(const Point<U>& lha, const Point<U>& rha);
 
        T x;
        T y;
 
 
};
 
 
template<typename T>
Point<T>::Point(const T x, const T y)
    :x(x), y(y)
{
}
 
template <typename T>
std::ostream& operator<<(std::ostream& os, const Point<T>& point)
{
    return os << "Point: " << point.x << ", " << point.y;
}
 
template<typename T>
bool operator==(const Point<T>& lha, const Point<T>& rha)
{
    return check_equality_coordinates<T>(lha.x, rha.x) && check_equality_coordinates<T>(lha.y, rha.y);
}
 
 
/////////////////////////////////////
 
template<typename T>
	class Color 
	{
	public:
		/*
		@brief инициализирует новый объект класса Color
		@param r Параметр красного цвета
		@param g Параметр зеленого цвета
		@param b Параметр синего цвета
		*/
		Color(const T r, const T g, const T b);
 
		/*
		@brief Перегрузка оператора сравнения
		@param lha Первый параметр для сравнения
		@param rha Второй параметр для сравнения
		@return true - равны, false - неравны
		*/
        template<typename U>
		friend bool operator ==(const Color<U>& lha, const Color<U>& rha);
 
		/*
		@brief Перегрузка оператора потока вывода
		@param os поток вывода
		@param color цвет
		@return Поток вывода
		*/
        template<typename U>
		friend std::ostream& operator<< (std::ostream& os, const Color<U>& color);
	private:
		T r;
		T g;
		T b;
	};
 
template<typename T>
Color<T>::Color(const T r, const T g, const T b)
	:r(r), g(g), b(b)
{	
}
 
template<> // Специализация для случая, когда T=int
Color<int>::Color(const int r, const int g, const int b)
	:r(r), g(g), b(b)
{
	if (r < 0 || r > 255 || b < 0 || b > 255 || g < 0 || g > 255)
	{
		throw std::out_of_range("Wrong color");
	}
}
 
template<typename T>
bool operator==(const Color<T>& lha, const Color<T>& rha)
{
	return lha.r == rha.r || lha.g == rha.g || lha.b == rha.b;
}
 
template<typename T>
std::ostream& operator<<(std::ostream& os, const Color<T>& color)
{
	return os << "Color: (" << color.r << ", " << color.g << ", " << color.b << ")";
}
 
/////////////////////////////
 
 
////////////////////////////
 
template<typename T>
class Font 
	{
	public:
		/*
		@brief инициализирует новый объект класса Font
		@param name Имя шрифта
		@param color Цвет шрифта
		@param size Размер шрифта
		*/
		Font(const std::string& name, const Color<T>& color, const int size);
 
		/*
		@brief Перегрузка оператора потока вывода
		@param os поток вывода
		@param fonst шрифт
		@return Поток вывода
		*/
        template<typename U>
		friend std::ostream& operator<< (std::ostream& os, const Font<U>& font);
 
		/*
		@brief Перегрузка оператора сравнения
		@param lha Первый параметр для сравнения
		@param rha Второй параметр для сравнения
		@return true - равны, false - неравны
		*/
        template<typename U>
		friend bool operator ==(const Font<U>& lha, const Font<U>& rha);
 
		/*
		@brief Изменение цвета шрифта
		@param color Новый цвет
		*/
		void set_color(const Color<T>& color);
 
		/*
		@brief Изменение размера шрифта
		@param size Новый размер
		*/
		void set_size(const int size);
 
		/*
		@brief Получение цвета шрифта
		@return Цвет шрифта
		*/
		const Color<T>& get_color() const;
 
		/*
		@brief Получение размера шрифта
		@return Размер шрифта
		*/
		const int get_size() const;
 
	private:
		std::string name;
		Color<T> color;
		int size;
};
 
template<typename T>
Font<T>::Font(const std::string& name, const Color<T>& color, const int size)
	:name(name), color(color), size(size)
{
}
 
template<typename T>
void Font<T>::set_color(const Color<T>& color)
{
	this->color = color;
}
 
template<typename T>
void Font<T>::set_size(const int size)
{
	this->size = size;
}
 
template<typename T>
const Color<T>& Font<T>::get_color() const
{
	return this->color;
}
 
template<typename T>
const int Font<T>::get_size() const
{
	return this->size;
}
 
template<typename T>
std::ostream& operator<<(std::ostream& os, const Font<T>& font)
{
	return os << "Name: " << font.name << " Color: " << font.color << " Size: " << font.size;
}
 
template<typename T>
bool operator==(const Font<T>& lha, const Font<T>& rha)
{
	return lha.name == rha.name && lha.color == rha.color && lha.size == rha.size;
}
 
////////////////////////////
 
 
//////////////////////////////
 
template<typename T , typename U>
	class Text 
	{
	public:
		/*
		@brief инициализирует новый объект класса Text
		@param text Текст
		@param start_point Начальная точка
		*/
		Text(const std::string& text, const Font<U>& font, const Point<T>& start_point);
 
		/*
		@brief Изменения текста
		@param text Новый текст
		*/
		void set_text(const std::string& text);
 
		/*
		@brief Получение текста
		@return Текст
		*/
		std::string get_text();
 
		/*
		@brief Здание шрифта текста
		@param font Новыйшрифт
		*/
		void set_font(const Font<U>& font);
 
		/*
		@brief Получение шрифта
		@return Шрифт
		*/
		Font<U> get_font() const;
 
 
		/*
		@brief Здание точки начала текста
		@param start_point Новая точка начала
		*/
		void set_start_point(const Point<T>& start_point);
 
		/*
		@brief Получение точки начала текста
		@return Точка начала текста
		*/
		Point<T> get_start_point() const;
 
 
		/*
		@brief Преобразование объекта в строку
		@return Строка с параметрами объекта
		*/
		std::string to_string() const;
 
		/*
		@brief Перегрузка оператора потока вывода
		@param os поток вывода
		@param text текст
		@return Поток вывода
		*/
        template<typename X , typename Y>
		friend std::ostream& operator<< (std::ostream& os, const Text<X , Y>& text);
 
		/*
		@brief Перегрузка оператора сравнения
		@param lha Первый параметр для сравнения
		@param rha Второй параметр для сравнения
		@return true - равны, false - неравны
		*/
        template<typename X , typename Y>
		friend bool operator ==(const Text<X , Y>& lha, const Text<X , Y>& rha);
 
	private:
		Point<T> start_point;
		Font<U> font;
		std::string text;
	};
 
template<typename T , typename U>
Text<T , U>::Text(const std::string& text, const Font<U>& font, const Point<T>& start_point)
	:start_point(start_point), font(font), text(text)
{
}
 
template<typename T , typename U>
void Text<T , U>::set_text(const std::string& text)
{
	this->text = text;
}
 
template<typename T , typename U>
std::string Text<T , U>::get_text()
{
	return this->text;
}
 
template<typename T , typename U>
void Text<T , U>::set_font(const Font<U>& font)
{
	this->font = font;
}
 
template<typename T , typename U>
Font<U> Text<T , U>::get_font() const
{
	return this->font;
}
 
template<typename T , typename U>
void Text<T , U>::set_start_point(const Point<T>& start_point)
{
	this->start_point = start_point;
}
 
template<typename T , typename U>
Point<T> Text<T , U>::get_start_point() const
{
	return this->start_point;
}
 
template<typename T , typename U>
std::string Text<T , U>::to_string() const
{
	std::stringstream sstring;
	sstring << "Text: " << this->text << "Font: " << this->font << "Start: " << this->start_point;
	return sstring.str();
}
 
template<typename T , typename U>
std::ostream& operator<<(std::ostream& os, const Text<T , U>& text)
{
	return os << text.to_string();
}
 
template<typename T , typename U>
bool operator==(const Text<T , U>& lha, const Text<T , U>& rha)
{
	return lha.font == rha.font && lha.text == rha.text;
}
 
//////////////////////////
 
 
int main() {
    Color<string> c1("red" , "green" , "blue");
    Font<string> f1("Times New Roman" , c1 , 12);
	Point<int> p1(1 , 2);
 
	string s1 = "abc";
	Text<int , string> t1(s1 , f1 , p1);
    //Color<int> c2(1 , 2 , 3);
    //cout << (c1 == c2) << endl;
    //cout << c1 << endl;
 
    cout << t1.to_string() << endl;
    return 0;
}
