#pragma once
#include <iostream>
#include <vector>
#include <exception>

template <typename t, typename t2>
class Pair {
public:
	Pair() {};
	Pair(t _key, t2 _value) : key(_key), value(_value) {};
	Pair(const Pair& other) {
		key = other.key;
		value = other.value;
	}
	Pair& operator=(const Pair& other) {
		key = other.key;
		value = other.value;
		return *this;
	}
	t getKey() const { return key; }
	t2 getValue() const { return value; }
	void setKey(t _key) { key = _key; }
	void setValue(t2 _value) { value = _value; }
	void set(t _key, t2 _value) { key = _key; value = _value; }
	void input() {
		std::cout << "Input the key: " << std::endl;
		std::cin >> key;
		std::cout << "Input the value: " << std::endl;
		std::cin >> value;
	}
private:
	t key;
	t2 value;
};

template<typename t, typename t2>
class Register {
public:
	Register() {}
	Register(int n) { reg.resize(n); }
	Register(const Register<t, t2>& other) {
		clear();
		resize(other.size());
		for (int i = 0; i < other.size(); ++i)
			reg[i] = other[i];
	}
	Register& operator=(const Register<t, t2>& other) {
		clear();
		resize(other.size());
		for (int i = 0; i < other.size(); ++i)
			reg[i] = other[i];
		return *this;
	}
	void add(const Pair<t, t2>& pair) { reg.push_back(pair); }
	void remove(t delKey) {
		for (int i = 0; i < reg.size(); ++i) {
			if (reg[i].getKey() == delKey)
				reg.erase(reg.begin() + i);
		}
	}
	void print() {
		for (int i = 0; i < size(); ++i)
			std::cout << reg[i].getKey() << ": " << reg[i].getValue() << std::endl;
	}
	int size() const { return (int)reg.size(); }
	void clear() { reg.clear(); }
	void resize(int n) { reg.resize(n); }
	Pair<t, t2>& operator[](const int i) { return reg[i]; }
	Pair<t, t2> operator[](const int i) const { return reg[i]; }
	void input() {
		if (size() == 0)
			throw std::invalid_argument("Register can't be empty");
		for (int i = 0; i < size(); ++i) {
			reg[i].input();
			std::cout << std::endl;
		}
	}
	Register find(t findKey) const {
		Register returnReg;
		for (int i = 0; i < size(); ++i) {
			if (reg[i].getKey() == findKey)
				returnReg.add(reg[i]);
		}
		return returnReg;
	}
private:
	std::vector<Pair<t, t2>> reg;
};