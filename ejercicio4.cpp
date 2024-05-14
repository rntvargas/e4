#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

int main() {
    ifstream archivo_entrada("C:/Users/renat/Desktop/ejercicio4/ejercicio4.txt");
    ofstream archivo_salida("C:/Users/renat/Desktop/ejercicio4/temperaturas_extremas.txt");

    if (!archivo_entrada.is_open()) {
        cerr << "No se pudo abrir el archivo de entrada." << endl;
        return 1;
    }

    if (!archivo_salida.is_open()) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        return 1;
    }

    string fecha, linea;
    double temperatura, max_temp = numeric_limits<double>::lowest();
    double min_temp = numeric_limits<double>::max();
    string fecha_max, fecha_min;

    while (getline(archivo_entrada, linea)) {
        stringstream ss(linea);
        getline(ss, fecha, ',');
        ss >> temperatura;

        if (temperatura > max_temp) {
            max_temp = temperatura;
            fecha_max = fecha;
        }

        if (temperatura < min_temp) {
            min_temp = temperatura;
            fecha_min = fecha;
        }
    }

    archivo_salida << "Día de temperatura máxima: " << fecha_max << ", " << max_temp << endl;
    archivo_salida << "Día de temperatura mínima: " << fecha_min << ", " << min_temp << endl;

    archivo_entrada.close();
    archivo_salida.close();
    cout << "Las temperaturas extremas se han calculado y guardado en el archivo 'temperaturas_extremas.txt'." << endl;

    return 0;
}
