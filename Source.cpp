#include <Windows.h>
#include <GL\glut.h>
#include <iostream>
#include "sortAlgos.h"
#include <string>
#include <algorithm> 
using namespace std;

const int N = 190;
int input[N];
int arr[N];
int sortAlgo = 0;
bool blackBackground = true;
int colorNumber;
int submenu_id1;
int submenu_id2;
int submenu_id3;
int submenu_id4; 
int main_menu;
float bar;
int comps = 0, swaps = 0;
string AlgoUsed = "INPUT ARRAY";
float r = 0.525, g = 0.172, b = 0.788;

void drawBars(int* arr, string, int, int);
void writeText(float, float, string);

void printArray() {
	
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
}

void fillArrWithInput()
{
	for (int i = 0; i < N; i++)
	{
		arr[i] = input[i];
	}
}

void bubbleSort()
{
	cout << "\n\n";
	fillArrWithInput();
	cout << "BEFORE SORTING THE ARRAY : " << endl;
	printArray();
	cout << "\n\n";
	bubbleSort(arr, N);
	cout << "AFTER SORTING THE ARRAY : " << endl; 
	printArray();
	
}

void insertionSort()
{
	cout << "\n\n";
	fillArrWithInput();
	cout << "BEFORE SORTING THE ARRAY : " << endl;
	printArray();
	cout << "\n\n";
	insertionSort(arr, N);
	cout << "AFTER SORTING THE ARRAY : " << endl;
	printArray();

}

void selectionSort()
{
	cout << "\n\n";
	fillArrWithInput();
	cout << "BEFORE SORTING THE ARRAY : " << endl;
	printArray();
	cout << "\n\n";
	selectionSort(arr, N);
	cout << "AFTER SORTING THE ARRAY : " << endl;
	printArray();

}

void mergeSort()
{
	cout << "\n\n";
	fillArrWithInput();
	cout << "BEFORE SORTING THE ARRAY : " << endl;
	printArray();
	cout << "\n\n"; 
	mergeSort(arr, 0, N - 1);
	cout << "AFTER SORTING THE ARRAY : " << endl;
	printArray();

}

void quickSort() {
	cout << "\n\n";
	fillArrWithInput();
	cout << "BEFORE SORTING THE ARRAY : " << endl;
	printArray();
	cout << "\n\n";
	quickSort(arr, 0, N - 1);
	cout << "AFTER SORTING THE ARRAY : " << endl;
	printArray();

}

void shellSort() {
	cout << "\n\n";
	fillArrWithInput();
	cout << "BEFORE SORTING THE ARRAY : " << endl;
	printArray();
	cout << "\n\n";
	shellSort(arr, N);
	cout << "AFTER SORTING THE ARRAY : " << endl;
	printArray();

}



void selectAlgo(int option)
{
	switch (option)
	{
		case 1: bubbleSort();
			break;
		case 2: selectionSort();
			break;
		case 3:insertionSort();
			break;
		case 4: mergeSort();
			break;
		case 5: quickSort();
			break;
		case 6: shellSort();
			break;
		case 7: exit(0);
	}
}

void generateRandomArray() {
	srand((unsigned)time(0));
	for (int i = 0; i < N; i++) {
		input[i] = (rand() % 600);
	}
}

void generateUniformArray() {
	input[0] = 3;
	for (int i = 1; i < N; i++) {
		input[i] = input[i - 1] + 3;
	}
	unsigned seed = 0;
	random_shuffle(input, input + N);
}

void barColor(int colorNumber)
{
	switch (colorNumber)
	{
		case 1: r = 0.0f; g = 0.0f; b = 1.0f;
			fillArrWithInput();
			drawBars(arr, AlgoUsed, comps, swaps);
			break;
		case 2: r = 1.0f; g = 0.0f; b = 0.0f;
			fillArrWithInput();
			drawBars(arr, AlgoUsed, comps, swaps);
			break;
		case 3: r = 0.0f; g = 1.0f; b = 0.0f;
			fillArrWithInput();
			drawBars(arr, AlgoUsed, comps, swaps);
			break;
		case 4: r = 1.0f; g = 0.0f; b = 1.0f;
			fillArrWithInput();
			drawBars(arr, AlgoUsed, comps, swaps);
			break;
		case 5: r = 1.0f; g = 1.0f; b = 0.0f;
			fillArrWithInput();
			drawBars(arr, AlgoUsed, comps, swaps);
			break;
		case 6: r = 0.0f; g = 1.0f; b = 1.0f;
			fillArrWithInput();
			drawBars(arr, AlgoUsed, comps, swaps);
		break;
	}
}

void black_bg() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT); 
	blackBackground = true;
	fillArrWithInput();
	drawBars(arr, AlgoUsed, 0, 0);
}

void white_bg() {
	
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	blackBackground = false;
	fillArrWithInput();
	drawBars(arr, AlgoUsed, 0, 0);
}

void theme(int option)
{
	switch (option)
	{
		case 1: black_bg();
			break;
		case 2: white_bg();
			break;
	}
}

void mainMenu(int option)
{
	switch (option) {
	case 5: exit(0); 
	}
}

void newArray(int option) {
	switch (option)
	{
		case 1:	generateUniformArray(); 
				fillArrWithInput(); 
				drawBars(arr, AlgoUsed, 0, 0);
				break; 
		case 2: generateRandomArray();
				fillArrWithInput();
				drawBars(arr, AlgoUsed, 0, 0);
				break; 
	}
}

void createMenu(void) {

	submenu_id4 = glutCreateMenu(newArray);
	glutAddMenuEntry("Uniform Array", 1); 
	glutAddMenuEntry("Random Array", 2); 

	submenu_id3 = glutCreateMenu(barColor);
	glutAddMenuEntry("Blue", 1);
	glutAddMenuEntry("Red", 2);
	glutAddMenuEntry("Green", 3);
	glutAddMenuEntry("Magenta", 4);
	glutAddMenuEntry("Yellow", 5);
	glutAddMenuEntry("Cyan", 6);

	submenu_id2 = glutCreateMenu(theme);
	glutAddMenuEntry("Dark Theme", 1);
	glutAddMenuEntry("Light Theme", 2);

	submenu_id1 = glutCreateMenu(selectAlgo);
	glutAddMenuEntry("Bubble Sort", 1);
	glutAddMenuEntry("Selection Sort", 2);
	glutAddMenuEntry("Insertion Sort", 3);
	glutAddMenuEntry("Merge Sort", 4);
	glutAddMenuEntry("Quick Sort", 5);
	glutAddMenuEntry("Shell Sort", 6);


	main_menu = glutCreateMenu(mainMenu);
	glutAddSubMenu("Sort Method", submenu_id1);
	glutAddSubMenu("Theme", submenu_id2);
	glutAddSubMenu("Bar Color", submenu_id3);
	glutAddSubMenu("Generate Array", submenu_id4);
	glutAddMenuEntry("Quit", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutAttachMenu(GLUT_LEFT_BUTTON);
}


void displayCallback()
{
	drawBars(input, AlgoUsed, 0, 0);
}

int main(int argc, char** argv) {

	generateUniformArray(); 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1525, 860);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Sorting Visualizer");
	createMenu();
	gluOrtho2D(0, 1525, 0, 860);
	glutDisplayFunc(displayCallback);
	glutMainLoop();
	return 0;

}


void drawBars(int* arr, string AlgoUsed, int comps, int swaps) {
	glClear(GL_COLOR_BUFFER_BIT);
	string compString = "Number of Comparisons : " + to_string(comps);
	string swapString = "Number of Swaps: " + to_string(swaps);
	writeText(700, 800, AlgoUsed);
	writeText(700, 775, compString);
	writeText(700, 750, swapString);
	glColor3f(r, g, b);
	for (int i = 0; i < N; i++)
	{
		glRecti(8 * i, 60, 8 * i + 6, 60 + arr[i]);
	}
	glFlush();
}


void writeText(float x, float y, string str)
{
	if (blackBackground)
	{
		glColor3f(1.0f, 1.0f, 1.0f);
	}
	else
	{
		glColor3f(0.0f, 0.0f, 0.0f);
	}

	glRasterPos2f(x, y);
	int len, i;
	len = str.length();
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);
	}
}

