# Plakatowanie
 
## PL
 
Projekt jest rozwiązaniem zadania "Plakatowanie" z XV OLIMPIADY INFORMATYCZNEJ.

Treść zadana znajduje się z pliku "oi15-b5.pdf".

### Plakatowanie.cpp 
Rozwiazanie polega na kerurencyjnym przechodzeniu prezez fragmenty tablicy we której zapisane są wysokości budynków. 
Algorytm wyszukuje miniumum w przedziale a nastęonie zmniejsza wartości w przedziale o wartość najmniejszego elementu. 
Następnie wyszuiwane są kolejne niezerowe przedziały. 
Algorytm kończy pracę kiedy wszystkie elemnty tablicy są zerowe lub otrzymany przedział zawiera tylko jeden elemnt. 

### Plakatowanie_vol2.cpp 
W pliku znajduje się alternatywne podejście bazujące na strukturze drzewa przechowywującego jako vektor listę wysokości wyższysz od niego. Korzeniem drzewa jest najniższy element. Drzewo tworzone jest jednocześnie w trakcie wczytywania danych.

## EN

The project is a solution to the "Posters" task from the 15th IT OLYMPIAD.

The content is from the "oi15-b5.pdf" file.

### Plakatowanie.cpp 
The solution is to walk through the fragments of the board in which the building heights are written. 
The algorithm searches for the minimum in the interval and then decreases the values in the interval by the value of the smallest element. 
Next, more non-zero intervals are searched for. 
The algorithm ends when all the array elements are zero or the resulting interval contains only one element.

### Plakatowanie_vol2.cpp 
Tn the file there is an alternative approach based on the tree structure storing as a vector a list of heights higher than it. The root of the tree is the lowest element. The tree is created simultaneously while reading the data.
