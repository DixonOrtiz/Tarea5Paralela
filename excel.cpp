#include <iostream>
#include <vector>
#include <string>
#include <xlnt/xlnt.hpp>

using namespace std;

int contarFilas(xlnt::workbook);
void contarAsignaturasProfes(xlnt::workbook);

int main()
{
    xlnt::workbook cursos;
    xlnt::workbook docentes;
    xlnt::workbook salas;
    
    cursos.load("archivosExcel/Cursos.xlsx");
    docentes.load("archivosExcel/Docentes.xlsx");
    salas.load("archivosExcel/Salas.xlsx");
 

    cout << "El archivo cursos tiene " << contarFilas(cursos) << " filas. " << endl;
    cout << "El archivo docentes tiene " << contarFilas(docentes) << " filas. " << endl;
    cout << "El archivo salas tiene " << contarFilas(salas) << " filas. " << endl;

    return 0;
}

int contarFilas(xlnt::workbook archivoExcel){
    auto hojaActiva = archivoExcel.active_sheet();

    int contadorFilasHojaActiva = 1;
    for(auto fila : hojaActiva.rows(false))
        contadorFilasHojaActiva++;
    
    return contadorFilasHojaActiva;
}

// void contarAsignaturasProfes(xlnt::workbook cursos){
//     auto hojaActiva = cursos.active_sheet();
//     vector<string> vectorProfesores;


//     cursos.
    
// }