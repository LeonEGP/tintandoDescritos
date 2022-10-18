#include <iostream>
#include <vector>

using namespace std;

void espacio() {
    cout << endl;
}

bool esSeguro(vector <vector <bool>> matriz, vector <int> colores) {
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = i + 1; j < matriz.size(); j++) {
            if (matriz[i][j] && colores[j] == colores[i]) {
                return false;
            }
        }
    }
    return true;
}

void imprimirColores(vector <int> colores, int cantidadNodos) {
    espacio();
    for (int i = 0; i<cantidadNodos; i++) {
        cout << "Node: " << i << ", Assigned Color: " << colores[i];
        espacio();
    }
}

bool evaluacionMatriz(vector <vector <bool>> matriz, int cantidadColores, int nodo, vector <int> colores) {
    
    if (nodo == matriz.size()) {
        if (esSeguro(matriz, colores)) {
            imprimirColores(colores,matriz.size());
            return true;
        }
        return false;
    }

    for (int i = 0; i < cantidadColores; i++) {
        colores[nodo] = i;
        if (evaluacionMatriz(matriz, cantidadColores, nodo + 1, colores)) {
            return true;
        }
        colores[nodo] = -1;
    }

    return false;
}

void coloreadoDeGrafos(vector <vector <bool>> matriz, int cantidadColores) {
    
    vector <int> colores;

    for (int i = 0; i < matriz.size(); i++) {
        colores.push_back(0);
    }

    if (!evaluacionMatriz(matriz, cantidadColores, 0, colores)) {
        espacio();
        cout << "No es posible asignar colores a los nodos";
        espacio();
    }

}

int main() {

    int n;
    int cantidadColores;
    vector <vector <bool>> matriz;
    cin >> n;

    for (int i = 0; i < n; i++) {
        vector <bool> auxiliar;
        for (int j = 0; j < n; j++) {
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

    coloreadoDeGrafos(matriz, cantidadColores);

    return 0;
}

/*
REFERENCIAS:
    MAIN:
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