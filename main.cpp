//Programa que: Implementa una solución para el "Graph Coloring.
//Programadores: León Emiliano García Pérez [A00573074] y Carla Morales López [A01639225].
//Fecha de entrega: Jueves 19 de Octubre de 2022.

//Inclusión de librerías.
#include <iostream>
#include <vector>

//Ajuste a estandar.
using namespace std;

//Función que imprime un espacio en consola, no recibe valores, no tiene valor de retorno.
void espacio() { //Complejidad Computacional: O(1), es una ejecución lineal en el contenido de la función.
    cout << endl;
}

//Función que comprueba si es seguro o no el coloreado, recibe la matriz de adyacencia en booleanos en forma de un vector de vectores de booleanos, recibe el vector de enteros de colores; y retorna un valor booleano.
bool esSeguro(vector <vector <bool>> matriz, vector <int> colores) { //Complejidad Computacional: O(n^2), siendo n la cantidad de nodos dentro del grafo.
    //Complejidad Computacional: O(n^2).
    for (int i = 0; i < matriz.size(); i++) { //Complejidad Computacional: O(n).
        for (int j = i + 1; j < matriz.size(); j++) { //Complejidad Computacional: O(n).
            if (matriz[i][j] && colores[j] == colores[i]) {
                return false;
            }
        }
    }
    return true;
}

//Función que imprime el color asignado a cada nodo del grafo, recibe el vector de enteros de colores y el entero con la cantidad de nodos del grafo; no tiene valor de retorno.
void imprimirColores(vector <int> colores, int cantidadNodos) { //Complejidad Computacional: O(n), siendo n la cantidad de nodos dentro del grafo.
    for (int i = 0; i<cantidadNodos; i++) {  //Complejidad Computacional: O(n).
        cout << "Node: " << i << ", Assigned Color: " << colores[i];
        espacio();
    }
}

//Función que evalúa si es posible el coloreado pleno del grafo y en caso de que así sea: desarrolla una solución para el coloreado, recibe la Matriz de Adyacencia del grafo, en forma de vector de vectores de booleanos, recibe la cantidad entera de colores, un valor entero que representa a un nodo, y el vector entero de colores; retorna un valor booleano.
bool evaluacionMatriz(vector <vector <bool>> matriz, int cantidadColores, int nodo, vector <int> colores) { //Complejidad Computacional: O(c^n); siendo c la cantidad de colores, y n la cantidad de nodos en el grafo.
    
    if (nodo == matriz.size()) {
        if (esSeguro(matriz, colores)) { //Complejidad Computacional: O(n^2), siendo n la cantidad de nodos dentro del grafo.
            imprimirColores(colores,matriz.size()); //Complejidad Computacional: O(n), siendo n la cantidad de nodos dentro del grafo.
            return true;
        }
        return false;
    }

    for (int i = 0; i < cantidadColores; i++) { //Complejidad Computacional: O(c), siendo c la cantidad de colores.
        colores[nodo] = i;
        if (evaluacionMatriz(matriz, cantidadColores, nodo + 1, colores)) { 
            return true;
        }
        colores[nodo] = -1;
    }

    return false;
}

//Función que maneja el coloreado de grafos a partir de los datos proporcionados en el main; recibe la Matriz de Adyacencia del grafo en forma de vector de vectores de booleanos, y la cantidad entera de colores, no tiene valor de retorno.
void coloreadoDeGrafos(vector <vector <bool>> matriz, int cantidadColores) { //Complejidad Computacional: O(c^n); siendo c la cantidad de colores, y n la cantidad de nodos en el grafo.
    
    vector <int> colores;

    for (int i = 0; i < matriz.size(); i++) { //Complejidad Computacional: O(n), siendo n la cantidad de nodos dentro del grafo.
        colores.push_back(0);
    }

    if (!evaluacionMatriz(matriz, cantidadColores, 0, colores)) { //Complejidad Computacional: O(c^n); siendo c la cantidad de colores, y n la cantidad de nodos en el grafo.
        cout << "No es posible asignar colores a los nodos";
        espacio();
    }

}

//Función main de ejecución del programa, no recibe valores, retorna un valor 0 al finalizar la ejecución.
int main() { //Complejidad Computacional: O(1), dentro de la ejecución se encuentra un ciclo for anidado dentro de otro ciclo for, dando una Complejidad Computacional O(n^2) para la creación de la Matriz de Adyacencia del Grafo. Finalmente, el Coloreado del Grafo poseé una Complejidad Computacional: O(c^n); siendo c la cantidad de colores, y n la cantidad de nodos en el grafo.

    int n; //Cantidad de nodos en el grafo.
    int cantidadColores;
    vector <vector <bool>> matriz;
    cin >> n;

    //Complejidad Computacional: O(n^2). Siendo n la cantidad de nodos en el grafo. 
    for (int i = 0; i < n; i++) { //Complejidad Computacional: O(n).
        vector <bool> auxiliar;
        for (int j = 0; j < n; j++) { //Complejidad Computacional: O(n).
            int temporal;
            cin >> temporal;
            if (temporal == 1) {
                auxiliar.push_back(true);
            }
            else {
                auxiliar.push_back(false);
            }
        }
        matriz.push_back(auxiliar);
    }

    cin >> cantidadColores;

    coloreadoDeGrafos(matriz, cantidadColores); //Complejidad Computacional: O(c^n); siendo c la cantidad de colores, y n la cantidad de nodos en el grafo.

    return 0;
}

/*
REFERENCIAS:
    PRINCIPALES:
        https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/
        https://www.tutorialspoint.com/Graph-Coloring
        https://stackoverflow.com/questions/50550398/graph-colouring-in-using-adjacency-matrix
        https://www.sanfoundry.com/cpp-program-perform-greedy-coloring/
    OTRAS:
        https://www.interviewbit.com/blog/graph-coloring-problem/
        https://www.techiedelight.com/greedy-coloring-graph/
        https://antiguadominic.medium.com/graph-coloring-adjacency-matrix-discrete-math-problem-8bf98295e0d0
        https://www.geeksforgeeks.org/graph-coloring-set-2-greedy-algorithm/
*/