#include <iostream>
#include <vector>
#include <concepts>
#include <iterator>
#include <string>

using namespace std;

// =================================================================
// 1. CONCEPTOS PERSONALIZADOS (REQUERIMIENTO 1)
// =================================================================
namespace core_numeric {

    // Conceptos exigidos por la guia [cite: 126, 127]
    template <typename Contenedor>
    concept EsRecorrible = requires (Contenedor c) {
        begin(c);
        end(c);
    };

    template <typename T>
    concept SoportaSuma = requires (T a, T b) {
        { a + b } -> same_as<T>;
    };

    template <typename T>
    concept SoportaDivision = requires (T a, size_t n) {
        { a / n } -> same_as<T>;
    };

    // Concepto propio creado desde cero (Requerimiento 1 final) [cite: 146]
    template <typename T>
    concept EsComparable = requires (T alfa, T beta) {
        { alfa > beta } -> convertible_to<bool>;
    };
}