#include "C++20.cpp"

int main() {
    cout << "--- PRUEBA VARIADIC ---" << endl;
    auto suma = core_numeric::sum_variadic(1, 2, 33, 4); // [cite: 194]
    cout << "Suma Variadica: " << suma << endl;

    auto media = core_numeric::mean_variadic(10.0, 20.0, 30.0);
    cout << "Media Variadica: " << media << endl;
    return 0;
}