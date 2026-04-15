#include "C++20.cpp"

int main() {
    cout << "--- PRUEBA MAX Y OBJETOS ---" << endl;

    vector<ObjetoFisico> caja = {ObjetoFisico(10.5), ObjetoFisico(50.2), ObjetoFisico(20.0)};
    
    auto mas_pesado = core_numeric::max(caja);
    cout << "Peso maximo: " << mas_pesado.peso << " kg" << endl;
    return 0;
}