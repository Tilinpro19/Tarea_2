#include "C++20.cpp"

int main() {
    vector<double> mis_datos = {1.0, 2.0, 3.0};
    cout << "--- PRUEBA ESTADISTICA ---" << endl;
    cout << "Promedio: " << core_numeric::mean(mis_datos) << endl;
    cout << "Varianza: " << core_numeric::variance(mis_datos) << endl;

    /* CASO QUE NO COMPILA 
    vector<string> palabras = {"hola", "mundo"};
    // core_numeric::mean(palabras);
    // Falla: string no cumple SoportaDivision
    */
    return 0;
}