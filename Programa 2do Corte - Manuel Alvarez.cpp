//Programa Estudiantes - 2do Corte // 

#include <iostream>
#include <iomanip>

const int NUM_ESTD = 1;
const int NUM_CALF = 3;

// 1era función para cargar nómina de estudiantes

void Nomina(std::string cedulas[], std::string nombres[]) {
    for (int i = 0; i < NUM_ESTD; ++i) {
        std::cout << "Por favor, ingrese la cédula del estudiante " << i + 1 << ": ";
        std::cin >> cedulas[i];

        std::cout << "Por ultimo, ingrese nombre y apellido del estudiante " << i + 1 << ": ";
        std::cin.ignore(); // Utilizamos esta funcion para ignorar el salto de linea anterior
        std::getline(std::cin, nombres[i]);//Utilizamos "GETLINE" para que el codigo pueda leer espacios en blanco y nos permita colocar nombre y apellido
    }
}//fin de 1era funcion

// 2da función para cargar las notas de los estudiantes

void Notas(int notas[][NUM_CALF]) {
    for (int i = 0; i < NUM_ESTD; ++i) {
        std::cout << "Ingrese las 3 calificaciones del estudiante (0-20 pts)" << i + 1 << ":\n";
        for (int j = 0; j < NUM_CALF; ++j) {
            std::cout << "Calificación " << j + 1 << ": ";
            std::cin >> notas[i][j];
            
            //Agregamos un WHILE para validar que la nota se encuentre en el rango de 0-20 ptos.
            while (notas [i][j] < 0 || notas [i][j] > 20){
            	std::cout << "La calificacion debe estar entre 0 y 20 puntos. Por favor, ingrese la nota correcta:  ";
            	std::cin >> notas[i][j];
			}//Fin del While
        }
    }
}//fin de 2da funcion

// Acá utilizamos otra función para calcular las notas el promedio de los estudiantes

void Promedio(const int notas[][NUM_CALF], double promedios[]) {
    for (int i = 0; i < NUM_ESTD; ++i) {
        double suma = 0.0;
        for (int j = 0; j < NUM_CALF; ++j) {
            suma += notas[i][j];
        }
        promedios[i] = suma / NUM_CALF;
    }
}//fin de funcion de promedio (3era)

// Creamos una función donde nos muestre el boletín de cada estudiante

void Boletin(const std::string cedulas[], const std::string nombres[],
                    const int notas[][NUM_CALF], const double promedios[]) {
    std::cout << std::setw(15) << "Cedula" << std::setw(15) << "Nombre"
              << std::setw(15) << "Nota 1" << std::setw(15) << "Nota 2"
              << std::setw(15) << "Nota 3" << std::setw(15) << "Promedio\n";

    for (int i = 0; i < NUM_ESTD; ++i) {
        std::cout << std::setw(15) << cedulas[i] << std::setw(15) << nombres[i];
        for (int j = 0; j < NUM_CALF; ++j) {
            std::cout << std::setw(15) << std::fixed << std::setprecision(2) << notas[i][j];
        }
        std::cout << std::setw(15) << std::fixed << std::setprecision(2) << promedios[i] << "\n";
        //En esta funcion utilice "Fixed y Precision" para mostrar la calificacion solo con 2 decimales en caso de ser necesario.
    }
}//Fin de 4ta funcion que utilizamos para mostrar boletin


//Inicio del main

int main() {
    std::string cedulas[NUM_ESTD];
    std::string nombres[NUM_ESTD];
    int notas[NUM_ESTD][NUM_CALF];
    double promedios[NUM_ESTD];

    Nomina(cedulas, nombres);
    Notas(notas);
    Promedio(notas, promedios);
    Boletin(cedulas, nombres, notas, promedios);

    return 0;

}//Fin del main y programa
