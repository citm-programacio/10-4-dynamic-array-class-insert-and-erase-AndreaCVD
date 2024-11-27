#include <iostream>
#include <cassert>

using namespace std;

class DynamicArray {
private:
	int size = 0;
	int capacity;

	string* array;

public:
	DynamicArray() {
		capacity = 10;
		array = new string[capacity];
	}

	DynamicArray(int _capacity) {
		capacity = _capacity;
		array = new string[_capacity];
	}

	DynamicArray(int _capacity, string* init, int init_size) {
		capacity = _capacity;
		size = init_size;
		array = new string[capacity];

		for (int i = 0; i < init_size; i++)
		{
			array[i] = init[i];
		}
	}


	// insert
	bool insert(string newElement, int pos) {
		// validar que la posició existeix
		if (pos < 0 || pos > size) {
			cout << "Posicio incorrecte: " << pos << endl;
			return false;
		}

		// Si la capacitat ja es troba al maxim, es cambia aquesta duplicant-la
		if (size == capacity) {
			capacity *= 2;
		}

		string* newArray = new string[capacity];
		
		// Es copia els elements en una nova array abans de insertar

		for (int i = 0; i < pos; i++) {
			newArray[i] = array[i];
		}

		// s'inserta el nou element
		newArray[pos] = newElement;

		// es copia els elements despres del punt d'inserció
		for (int i = pos; i < size; i++)
		{
			newArray[i + 1] = array[i];
		}

		// es borra l'anterior array perque n'hi haura una de nova que es puntua sobre ella mateixa.
		delete[] array;
		array = newArray;

		// s'augmenta el tamany en 1
		size++;
		return true;
	}

	// delete
	bool remove(int pos) {

		if (pos < 0 || pos >= size) {
			cout << "Posicio incorrecte: " << pos << endl;
			return false;
		}

		// es crea la nova array
		string* newArray = new string[capacity];

		// es copia els elements de l'anterior array en la nova
		for (int i = 0; i < pos; i++)
		{
			newArray[i] = array[i];
		}

		// es copia els elements despres de eliminar la posició demanada
		for (int i = pos; i < capacity - 1; i++)
		{
			newArray[i] = array[i + 1];
		}

		// esborrem la array per posar la nova en el mateix lloc de memoria inicial.
		delete[] array;
		array = newArray;

		// es redueix el tamany en 1
		size--;
		return true;


	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << array[i] << ", ";
		}
		cout << endl;
	}
};

int main() {
	string start[10];

	DynamicArray a(10);

	a.insert("bli", 0);
	a.print();
	a.insert("blo", 0);
	a.print();
	a.insert("blu", 0);
	a.print();
	a.remove(-10);
	a.print();
	a.remove(1);
	a.print();

}

/*
void splitArray(string* originalArray, int originalSize, int splitPoint, string* firstPart, string* secondPart) {

	int firstSize = splitPoint - 1, secondSize = originalSize - splitPoint + 1;

	int j = 0;

	for (int i = 0; i < originalSize; i++)
	{

		if (i < firstSize) {

			firstPart[i] = originalArray[i];
		}
		else {

			secondPart[j] = originalArray[i];

			j++;
		}

	}

	// Print firstPart
	cout << "	first part is: " << "{ ";
	for (int i = 0; i < firstSize; i++)
	{
		cout << " " << firstPart[i] << " ";
	}
	cout << " }" << endl;

	// Print secondPart
	cout << "	second part is: " << "{ ";
	for (int i = 0; i < secondSize; i++)
	{
		cout << " " << secondPart[i] << " ";
	}
	cout << " }";
}

int main() {
	int size = 10, num = 0;

	string* arr = new string[size]{ "zero", "one", "two", "tree", "four", "five", "six", "seven", "eight", "nine" };

	cout << "Original array:" << endl << "{ ";
	for (int i = 0; i < size; i++)
	{
		cout << " " << arr[i] << " ";
	}
	cout << " }" << endl;

	cout << "Insert number to cut the array: ";
	cin >> num;

	int firstSize = num - 1, secondSize = size - num + 1;

	string* firstPart = new string[firstSize];
	string* secondPart = new string[secondSize];

	splitArray(arr, size, num, firstPart, secondPart);

	delete[] arr, firstPart, secondPart;
}
*/