#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map> // Agregamos esta línea

using namespace std;

// Definición de las estructuras de datos
struct Paciente {
    int id;
    string nombre;
    string apellido;
    int edad;
    int diagnostico;
};

struct Medicamento {
    long long EAN;
    string nombre_generico;
    int dosis;
};

struct Prescripcion {
    int id_paciente;
    long long EAN;
    int intervalo_horas;
    string hora_inicio;
};

// Función para calcular la hora de la prescripción
string calcular_hora_inicio(string hora_inicio, int intervalo_horas) {
    int horas = stoi(hora_inicio.substr(0, 2));
    int minutos = stoi(hora_inicio.substr(3, 2));

    horas = (horas + intervalo_horas) % 24;

    return to_string(horas) + ":" + (minutos < 10 ? "0" : "") + to_string(minutos);
}

// Función prescripciones
vector<tuple<int, string, string, long long, string, int, string>> prescripciones(vector<Paciente> &pacientes, vector<Medicamento> &medicamentos, vector<Prescripcion> &prescripciones) {
    // Crear un mapa de medicamentos para acceder rápidamente por EAN
    unordered_map<long long, Medicamento> dict_medicamentos;
    for (auto &medicamento : medicamentos) {
        dict_medicamentos[medicamento.EAN] = medicamento;
    }

    // Ordenar prescripciones por paciente
    sort(prescripciones.begin(), prescripciones.end(), [](const Prescripcion &a, const Prescripcion &b) {
        return a.id_paciente < b.id_paciente;
    });

    // Generar el listado de prescripciones del día
    vector<tuple<int, string, string, long long, string, int, string>> listado_prescripciones;
    for (auto &prescripcion : prescripciones) {
        auto paciente = find_if(pacientes.begin(), pacientes.end(), [&](const Paciente &p) {
            return p.id == prescripcion.id_paciente;
        });
        if (paciente != pacientes.end()) {
            auto medicamento = dict_medicamentos.find(prescripcion.EAN);
            if (medicamento != dict_medicamentos.end()) {
                string hora_prescripcion = calcular_hora_inicio(prescripcion.hora_inicio, prescripcion.intervalo_horas);
                listado_prescripciones.push_back(make_tuple(paciente->id, paciente->nombre, paciente->apellido,
                                                            medicamento->second.EAN, medicamento->second.nombre_generico,
                                                            medicamento->second.dosis, hora_prescripcion));
            }
        }
    }

    return listado_prescripciones;
}

int main() {
    // Ejemplo de datos de pacientes
    vector<Paciente> pacientes = {
        {1, "Juan", "Perez", 45, 1},
        {2, "Maria", "Gomez", 35, 2},
        // Agregar más pacientes según sea necesario
    };

    // Ejemplo de datos de medicamentos
    vector<Medicamento> medicamentos = {
        {1234567890123, "Paracetamol", 500},
        {9876543210987, "Ibuprofeno", 400},
        // Agregar más medicamentos según sea necesario
    };

    // Ejemplo de datos de prescripciones
    vector<Prescripcion> prescripciones = {
        {1, 1234567890123, 6, "08:00"},
        {2, 9876543210987, 8, "10:30"},
        // Agregar más prescripciones según sea necesario
    };

    // Obtener y mostrar el listado de prescripciones
    auto listado = prescripciones(pacientes, medicamentos, prescripciones);
    for (auto &prescripcion : listado) {
        cout << "ID: " << get<0>(prescripcion) << "\tNombre: " << get<1>(prescripcion) << "\tApellido: " << get<2>(prescripcion)
             << "\tEAN: " << get<3>(prescripcion) << "\tNombre Genérico: " << get<4>(prescripcion)
             << "\tDosis: " << get<5>(prescripcion) << "\tHora: " << get<6>(prescripcion) << endl;
    }

    return 0;
}
