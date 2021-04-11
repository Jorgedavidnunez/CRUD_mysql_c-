// Proyecto_CRUD.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <mysql.h>
#include <iostream>
#include <string>
using namespace std;
void insertar_marca();
void insertar_producto();
void mostrar_marca();
void mostrar_producto();
void modificar_marca();
void modificar_producto();
void eliminar_marca();
void eliminar_producto();
int q_estado;
int main()
{
	int op1, op2;
	do {
		system("cls");
		cout << "Seleccione la tabla en la que quiera trabajar\n";
		cout << "1. Marcas\n";
		cout << "2. Productos\n";
		cout << "3. Salir\n";
		cin >> op1;
		switch (op1)
		{
		case 1:
			do{ 
				system("cls");
				cout << "1. Insertar en marcas\n";
				cout << "2. Ver contenido de marcas\n";
				cout << "3. Modificar en marcas\n";
				cout << "4. Eliminar en marcas\n";
				cout << "5. Volver al menu principal\n";
				cin >> op2;
				switch (op2) 
				{
				case 1:
					insertar_marca();
					break;
				case 2:
					mostrar_marca();
					break;
				case 3: 
					modificar_marca();
					break;
				case 4:
					eliminar_marca();
					break;
				}
			} while (op2 != 5);
			break;
		case 2:
			do {
				system("cls");
				cout << "1. Insertar en productos\n";
				cout << "2. Ver contenido de productos\n";
				cout << "3. Modificar en productos\n";
				cout << "4. Eliminar en productos\n";
				cout << "5. Volver al menu principal\n";
				cin >> op2;
				switch (op2)
				{
				case 1:
					insertar_producto();
					break;
				case 2:
					mostrar_producto();
					break;
				case 3: 
					modificar_producto();
					break;
				case 4:
					eliminar_producto();
					break;
				default:
					break;
				}
		} while (op2 != 5);
			break;
		default:
			break;
		}
	} 		while (op1 != 3);
	system("pause");
	return 0;
}
void insertar_marca() {
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "root", "db_crud", 3306, NULL, 0);
	if (conectar) {
		system("cls");
		cout << "Conexion exitosa\n";
		string marca;
		cout << "Ingrese la marca:\n";
		cin.ignore();
		getline(cin, marca);
		string insert = "insert into marcas(marca) values('" + marca + "')";
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);
		if (!q_estado) {
			cout << "Ingreso exitoso\n";
		}
		else {
			cout << "Error al ingresar\n";
		}
	}
	else {
		system("cls");
		cout << "Error en la conexion\n";
	}
	system("pause");
}
void insertar_producto() {
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "root", "db_crud", 3306, NULL, 0);
	if (conectar) {
		system("cls");
		cout << "Conexion exitosa\n";
		string producto, descripcion;
		string idmarca, existencia;
		string precio_costo, precio_venta;
		string fecha_ingreso = "now()";
		cout << "Ingrese el producto:\n";
		cin.ignore();
		getline(cin, producto);
		cout << "Ingrese el id de marca:\n";
		cin >> idmarca;
		cout << "Ingrese la descripcion:\n";
		cin.ignore();
		getline(cin,descripcion);
		cout << "Ingrese el precio de costo:\n";
		cin >> precio_costo;
		cout << "Ingrese el precio de venta:\n";
		cin >> precio_venta;
		cout << "Ingrese la cantidad de existencias:\n";
		cin >> existencia;
		string insert = "insert into productos(producto,idmarca,descripcion,precio_costo,precio_venta,existencia,fecha_ingreso) values('" + producto + "'," + idmarca + ", '" + descripcion + "', " + precio_costo + ", " + precio_venta + ", " + existencia + ", " + fecha_ingreso + ")";
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);
		if (!q_estado) {
			cout << "Ingreso exitoso\n";
		}
		else {
			cout << "Error al ingresar\n";
		}
	}
	else {
		system("cls");
		cout << "Error en la conexion\n";
	}
	system("pause");
}
void mostrar_marca() {
	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "root", "db_crud", 3306, NULL, 0);
	if (conectar) {
		system("cls");
		cout << "Conexion exitosa\n";
		string consulta = "select * from marcas";
		const char* c = consulta.c_str();
		q_estado = mysql_query(conectar, c);
		if (!q_estado) {
			cout << "ID - MARCA\n";
			resultado = mysql_store_result(conectar);
			while (fila = mysql_fetch_row(resultado)) {
				cout << fila[0] << " , " << fila[1] << endl;
			}
		}
		else {
			cout << "Error al consultar\n";
		}
	}
	else {
		system("cls");
		cout << "Error en la conexion\n";
	}
	system("pause");
}
void mostrar_producto() {
	MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "root", "db_crud", 3306, NULL, 0);
	if (conectar) {
		system("cls");
		cout << "Conexion exitosa\n";
		string consulta = "select * from productos";
		const char* c = consulta.c_str();
		q_estado = mysql_query(conectar, c);
		if (!q_estado) {
			cout << "ID - PRODUCTO - IDMARCA - DESCRIPCION - PRECIO COSTO - PRECIO VENTA - EXISTENCIA - FECHA INGRESO\n";
			resultado = mysql_store_result(conectar);
			while (fila = mysql_fetch_row(resultado)) {
				for (int j = 0; j < 8; j++) {
					cout << " - " << fila[j];
				}
				cout << "<\n";
			}
		}
		else {
			cout << "Error al consultar\n";
		}
	}
	else {
		system("cls");
		cout << "Error en la conexion\n";
	}
	system("pause");
}
void modificar_marca() {
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "root", "db_crud", 3306, NULL, 0);
	if (conectar) {
		system("cls");
		cout << "Conexion exitosa\n";
		string idmarca, marca;
		cout << "Ingrese el id del registro que desea modificar\n";
		cin >> idmarca;
		cout << "ingrese el nuevo nombre de la marca\n";
		cin.ignore();
		getline(cin, marca);
		string modificar = "update marcas set marca = '" + marca + "' where idmarca =" + idmarca + "";
		const char* m = modificar.c_str();
		q_estado = mysql_query(conectar, m);
		if (!q_estado) {
			cout << "Modificacion exitosa\n";
		}
		else {
			cout << "Error al modificar\n";
		}
	}
	else {
		system("cls");
		cout << "Error en la conexion\n";
	}
	system("pause");
}
void modificar_producto() {
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "root", "db_crud", 3306, NULL, 0);
	if (conectar) {
		system("cls");
		cout << "Conexion exitosa\n";
		string idproducto, producto, descripcion, idmarca, existencia, precio_costo, precio_venta;
		cout << "Ingrese el id del registro que desea modificar\n";
		cin >> idproducto;
		cout << "Ingrese el nuevo nombre del producto\n";
		cin.ignore();
		getline(cin, producto);
		cout << "Ingrese la nueva descripcion\n";
		cin.ignore();
		getline(cin,descripcion);
		cout << "Ingrese el nuevo id de marca\n";
		cin >> idmarca;
		cout << "Ingrese la nueva cantidad de existencias\n";
		cin >> existencia;
		cout << "Ingrese el nuevo precio de costo\n";
		cin >> precio_costo;
		cout << "Ingrese el nuevo precio de venta\n";
		cin >> precio_venta;
		string modificar = "update productos set producto = '" + producto + "', idmarca = "+ idmarca +", descripcion = '"+ descripcion +"', precio_costo = "+ precio_costo +", precio_venta = "+ precio_venta +", existencia = "+ existencia +" where idproducto =" + idproducto + "";
		const char* m = modificar.c_str();
		q_estado = mysql_query(conectar, m);
		if (!q_estado) {
			cout << "Modificacion exitosa\n";
		}
		else {
			cout << "Error al modificar\n";
		}
	}
	else {
		system("cls");
		cout << "Error en la conexion\n";
	}
	system("pause");
}
void eliminar_marca() {
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "root", "db_crud", 3306, NULL, 0);
	if (conectar) {
		system("cls");
		cout << "Conexion exitosa\n";
		string idmarca;
		cout << "Ingrese el id de la marca que desea eliminar\n";
		cin >> idmarca;
		string eliminar = "delete from marcas where idmarca =" + idmarca + "";
		const char* d = eliminar.c_str();
		q_estado = mysql_query(conectar, d);
		if (!q_estado) {
			cout << "Eliminacion exitosa\n";
		}
		else {
			cout << "Error al eliminar\n";
		}
	}
	else {
		system("cls");
		cout << "Error en la conexion\n";
	}
	system("pause");
}
void eliminar_producto() {
	MYSQL* conectar;
	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "root", "db_crud", 3306, NULL, 0);
	if (conectar) {
		system("cls");
		cout << "Conexion exitosa\n";
		string idproducto;
		cout << "Ingrese el id del producto que desea eliminar\n";
		cin >> idproducto;
		string eliminar = "delete from productos where idproducto =" + idproducto + "";
		const char* d = eliminar.c_str();
		q_estado = mysql_query(conectar, d);
		if (!q_estado) {
			cout << "Eliminacion exitosa\n";
		}
		else {
			cout << "Error al eliminar\n";
		}
	}
	else {
		system("cls");
		cout << "Error en la conexion\n";
	}
	system("pause");
}