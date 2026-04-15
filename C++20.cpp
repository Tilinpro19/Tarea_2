#include <iostream>
#include <vector>
#include <concepts>
#include <iterator>
#include <string>

using namespace std;


namespace core_numeric {

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

    template <typename T>
    concept EsComparable = requires (T alfa, T beta) {
        { alfa > beta } -> convertible_to<bool>;
    };
}

namespace core_numeric {

    // Funcion base para sumar colecciones
    template <EsRecorrible C>
    requires SoportaSuma<typename C::value_type>
    auto sum(const C& bolsa_datos) {
        typename C::value_type total_acumulado{};
        for (const auto& elemento : bolsa_datos) {
            total_acumulado = total_acumulado + elemento;
        }
        return total_acumulado;
    }

    template <EsRecorrible C>
    requires SoportaDivision<typename C::value_type> && SoportaSuma<typename C::value_type>
    auto mean(const C& coleccion) {
        if (coleccion.empty()) return typename C::value_type{};
        return sum(coleccion) / size(coleccion);
    }
    template <EsRecorrible C>
    requires EsRecorrible<C> && SoportaSuma<typename C::value_type>
    auto variance(const C& datos) {
        auto promedio_actual = mean(datos);
        double suma_cuadratica = 0;

        for (const auto& x : datos) {
            auto residuo = x - promedio_actual;
            suma_cuadratica += (residuo * residuo);
        }

        if constexpr (is_integral_v<typename C::value_type>) {
            return static_cast<long long>(suma_cuadratica / size(datos)); // Para enteros
        } else {
            return suma_cuadratica / size(datos); // Para flotantes
        }
    }

    template <EsRecorrible C>
    requires EsComparable<typename C::value_type>
    auto max(const C& almacen) {
        auto it = begin(almacen);
        auto campeon_temporal = *it;
        for (; it != end(almacen); ++it) {
            if (*it > campeon_temporal) campeon_temporal = *it;
        }
        return campeon_temporal;
    }

    template <EsRecorrible C, typename Operacion>
    auto transform_reduce(const C& entrada, Operacion rito) {
        typename C::value_type resultado_final{};
        for (const auto& item : entrada) {
            resultado_final = resultado_final + rito(item);
        }
        return resultado_final;
    }
}

namespace core_numeric {

    template <SoportaSuma... Args>
    auto sum_variadic(Args... valores) {
        return (... + valores); // Fold expression
    }

    template <SoportaDivision... Args>
    auto mean_variadic(Args... valores) {
        auto suma_total = (... + valores);
        return suma_total / sizeof...(valores);
    }
}

class ObjetoFisico {
public:
    double peso;
    ObjetoFisico(double p = 0) : peso(p) {}
    ObjetoFisico operator+(const ObjetoFisico& otro) const { return ObjetoFisico(peso + otro.peso); }
    bool operator>(const ObjetoFisico& otro) const { return peso > otro.peso; }
};