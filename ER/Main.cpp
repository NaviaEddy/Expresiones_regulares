#include <iostream>
#include <regex>
#include <string>
#include <windows.h>


using namespace std;

static string ci, pv, na, fch;
static bool start = true;

void cls();
bool Validar_CI(const string&);
bool Validar_PV(const string&);
bool Validar_NA(const string&);
bool Validar_FCH(const string&);
int MC_CI() { return 1; };
int MI_CI(const string&);
int MC_PV() { return 1; };
int MI_PV(const string&);
int MC_NA() { return 1; };
int MI_NA(const string&);
int MC_FCH() { return 1; };
int MI_FCH(const string&);
void Informacion(const string&, const string&, const string&, const string&);


int main() {

	/*INTERFAZ  DE MANTENIMIENTO DE VEHICULO*/
	cout << "                       BIENVENIDO" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "CI (Ejem:15789565-Pt): "; getline(cin, ci); Validar_CI(ci) ? MC_CI() : MI_CI(ci); 
	cout << "Placa del vehiculo (Ejem:3529TBD): "; getline(cin, pv); Validar_PV(pv) ? MC_PV() : MI_PV(pv);
	cout << "Nombre completo (Solo letras): "; getline(cin, na); Validar_NA(na) ? MC_NA() : MI_NA(na);
	cout << "Fecha (dd/mm/aaaa): "; getline(cin, fch); Validar_FCH(fch) ? MC_FCH() : MI_FCH(fch);
	cout << "-------------------------------------------------------" << endl;

	Sleep(2000);
	cls();
	Informacion(ci, pv, na, fch);

	exit(0);
}

//-------------------------------FUNCIONES ER------------------------------------------------

bool Validar_CI(const string& _ci) {
	
	//ER PARA VERIFICAR EL CORRECTO INGRESO DEL CI
	const regex er1("(\\d{8})-([A-Z][a-z])$");
	return regex_match(_ci, er1);
}



bool Validar_PV(const string& _pv) {

	//ER PARA VERIFICAR EL CORRECTO INGRESO DE LA PLACA DE UN VEHICULO
	const regex er2("([1-9]{4}[A-Z]{3})$");
	return regex_match(_pv, er2);
}



bool Validar_NA(const string& _na) {

	//ER PARA VERIFICAR QUE SOLO SE ESCRIBAN LETRAS
	const regex er3("^[A-ZÑa-zñáéíóúÁÉÍÓÚ'° ]+$");
	return regex_match(_na, er3);
}



bool Validar_FCH(const string& _fch) {

	//ER PARA VERIFICAR EL CORRECTO INGRESO DE LA FECHA
	const regex er4("^(0?[1-9]|[1-2]?[0-9]|[3]?[0-1])(/)([0]?[1-9]|[1]?[0-2])(/)(\\d{4})$");
	
	return regex_match(_fch, er4);

}

// ---------------------------------------------------------------------------------------------

void cls()
{
	//CODIGO ANSI PARA LIMPIAR PANTALLA
	cout << "\x1B[2J\x1B[H";
}

int MI_CI(const string& _ci)
{
	cout << endl << "CI_Incorrecto: " << _ci << " | " << "CI_Correcto: 15789565-Pt" << endl;
	cout << "Por favor. Vuelva a intertarlo";
	Sleep(4000);
	cls();
	return main();
}

int MI_PV(const string& _pv)
{
	cout << endl << "Placa_Incorrecta: " << _pv << " | " << "Placa_Correcta: 3529TBD" << endl;
	cout << "Por favor. Vuelva a intertarlo";
	Sleep(4000);
	cls();
	return main();
}

int MI_NA(const string& _na)
{
	cout << endl << "Nombre_Incorrecto: " << _na << " | " << "Nombre_Correcto: Julian Perez Acho" << endl;
	cout << "Por favor. Vuelva a intertarlo";
	Sleep(4000);
	cls();
	return main();
}

int MI_FCH(const string& _fch)
{
	cout << endl <<"Fecha_Incorrecta: " << _fch << " | " << "Fecha_Correcta: 11/05/2023" << endl;
	cout << "Por favor. Vuelva a intertarlo";
	Sleep(4000);
	cls();
	return main();
}

void Informacion(const string& _ci,const string& _pv,const string& _na,const string& _fch)
{
	cout << "-----------------------------------------------------" << endl;
	cout << "CI: " << _ci << "  *verificado*" << endl;
	cout << "PLACA DE AUTOMOVIL: " << _pv << "  *verificado*" << endl;
	cout << "NOMBRE COMPLETO: " << _na << "  *verificado*" <<endl;
	cout << "FECHA DE INGRESO: " << _fch << "  *verificado*" <<endl;
	cout << " " << endl;
	cout << "MUCHAS GRACIAS, QUE TENGA UNA LINDA JORNADA" << endl;
	cout << "-----------------------------------------------------" << endl;

	exit(0);
}

