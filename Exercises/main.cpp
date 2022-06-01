///
/// Ce projet utilise quelques librairies disponibles sur Vcpkg et permet entre autre d'en tester le bon fonctionnement.
///


#include <cstddef>
#include <cstdint>

#include <array>
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <span>
#include <utility>
#include <list>

#include <cppitertools/itertools.hpp>
#include <cppitertools/zip.hpp>

#include "MyClass.hpp"
#include "List.hpp"

using namespace std;
using namespace iter;


void runListExample() {
	{
		List<int> alexanderThibault = {1, 3, 4};
		for (auto it = alexanderThibault.begin(); it != alexanderThibault.end(); ++it)
			cout << *it << " ";
		cout << "\n";
		auto it = ++alexanderThibault.begin(); // Faire ++ sur un itérateur le fait avancer, donc faire ++ sur le résultat de begin() (le premier élément) nous amène au deuxième.
		alexanderThibault.insert(it, 2);
		cout << alexanderThibault << "\n";

		it = alexanderThibault.erase(alexanderThibault.begin());
		cout << "1er elem : " << *it << "\n";
		alexanderThibault.pop_back();
		alexanderThibault.pop_front();
		cout << alexanderThibault << "\n";
	}

	cout << string(60, '-') << endl;

	{
		List<int> michelleCardinal = {69, 420};
		cout << michelleCardinal << "\n";
		michelleCardinal.erase(--michelleCardinal.end()); // On ne peut pas erase le end(), car cet élément n'existe pas (il est après la fin de la liste). C'est pour cela que je fait -- sur end() pour avoir un itérateur sur le dernier élément. C'est pas mal la convention en C++.
		cout << michelleCardinal << "\n";
		michelleCardinal.pop_back();
		cout << michelleCardinal << "\n";
	}
}


void runIteratorExample() {
	vector<int> v = {2, 1, 42, 12, 69};
	//auto it = v.begin();
	//int v[] = {2, 1, 42, 12, 69};
	//int* begin = v;
	auto begin = v.begin();
	//int* end = begin + 5;
	auto end = v.end();
	for (auto p = begin; p != end; ++p)
		cout << *p << " ";
}


int main() {
	runListExample(); cout << "\n\n\n\n";
	//runIteratorExample(); cout << "\n\n\n\n";

	// Soit f() une fn logarithmique sur taille de v
	// Soit g() une fn linéaire sur taille de v
	// Soit n la taille du tableau
	vector<int> v = {2, 1, 42, 12, 69}; // O(n)
	for (auto&& e1 : v) {   // O(n)
		int cnt = 0;        // O(1)
		for (auto&& e2 : v) // O(n)
			if (f(e2, v))   // O(log n)
				g(cnt, v);  // O(n)
		cout << cnt;        // O(1)
	}
	// O(n + n(1 + n(log n + n) + 1))
	// O(n + n(1 + nlog n + n² + 1))
	// O(n + n(n²))
	// O(n³)
}

