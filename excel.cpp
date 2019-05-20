#include <iostream>
#include <vector>
#include <string>
#include <xlnt/xlnt.hpp>

using namespace std;

int contarFilas(xlnt::workbook);
vector<vector<string>> llenarVector(xlnt::workbook);
// void eliminarDatosRepetidos(vector<string> &);
void mostrarCursosProfes(vector<vector<string>>);


int main()
{
    xlnt::workbook cursos;
    xlnt::workbook docentes;
    xlnt::workbook salas;
    
    cursos.load("archivosExcel/Cursos.xlsx");
    docentes.load("archivosExcel/Docentes.xlsx");
    salas.load("archivosExcel/Salas.xlsx");

    vector<vector<string>> vectorCursos;
    vectorCursos = llenarVector(cursos);
    mostrarCursosProfes(vectorCursos);

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

vector<vector<string>> llenarVector(xlnt::workbook cursos){
    auto hojaActiva = cursos.active_sheet();
    
    vector<vector<string>> vectorHojaCompleta;
    
    for(auto fila : hojaActiva.rows(false)){
        vector<string> vectorFilasIndividuales;
        for (auto celda : fila)
            vectorFilasIndividuales.push_back(celda.to_string());
        
        vectorHojaCompleta.push_back(vectorFilasIndividuales);
    }

    return vectorHojaCompleta;
}

// void eliminarDatosRepetidos(vector<string> &vectorProfes){
//     for(int i = 0; i < vectorProfes.size(); i++){

//     }
// }


void mostrarCursosProfes(vector<vector<string>> vectorCursos){
    vector<string> vectorProfes;

    for(int i = 1; i < vectorCursos.size(); i++){
            vectorProfes.push_back(vectorCursos[i][2]);     
    }

    int contadorRamosPorProfe;
    for(int i = 1; i < vectorCursos.size(); i++){
        contadorRamosPorProfe = 0;
        for(int j = 0; j < vectorProfes.size(); j++){
            if(vectorProfes[j] == vectorCursos[i][2])
                contadorRamosPorProfe++;
        }

        cout << "El/la profesor/a " << vectorCursos[i][3] << " " 
        << vectorCursos[i][4] << " tiene " << contadorRamosPorProfe << " ramos." << endl;
    }
}