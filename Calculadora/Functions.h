/** \brief Realiza la suma de dos numeros.
 *
 * \param float Recibe el primer numero.
 * \param float Recibe el segundo numero.
 * \return float Devuelve el resultado de la suma.
 *
 */
float suma(float,float);


/** \brief Realiza la resta de dos numeros.
 *
 * \param float Recibe el primer numero.
 * \param float Recibe el segundo numero.
 * \return float Devuelve el resultado de la resta.
 *
 */
float resta(float,float);


/** \brief Realiza la multiplicacion de dos numeros.
 *
 * \param float Recibe el primer numero.
 * \param float Recibe el segundo numero.
 * \return float Devuelve el resultado de la multiplicacion.
 *
 */
float multiplicacion(float,float);


/** \brief Realiza la division de dos numeros.
 *
 * \param float Recibe el primer numero.
 * \param float Recibe el segundo numero.
 * \return float Devuelve el resultado de la division.
 *
 */
float division(float,float);


/** \brief Realiza el factorial de un numero. Tiene ese tipo de dato para que pueda realizar el factorial de un numero alto (llega hasta el factorial de 12).
 *
 * \param int Recibe el numero
 * \return unsigned long long int Devuelve el resultado del factorial.
 *
 */
unsigned long long int factorial(int);


/** \brief Pide un numero.
 *
 * \param char[] Muestra mensaje que indica al usuario que debe ingresar un numero.
 * \return float Devuelve el numero ingresado.
 *
 */
float pedirNumero(char[]);


/** \brief Muestra los resultado de todos los calculos. Tambien valida antes de mostrar que no se puede dividir por 0 y no se puede realizar el factorial de un numero negativo.
 *
 * \param float Recibe el primer numero.
 * \param float Recibe el segundo numero.
 * \param float Recibe el resultado de la suma para mostrar.
 * \param float Recibe el resultado de la resta para mostrar.
 * \param float Recibe el resultado de la multiplicacion para mostrar.
 * \param float Recibe el resultado de la division para mostrar.
 * \param int Reibe el resultado del factorial del primer numero.
 * \param int Recibe el resultado del factorial del segundo nunmero.
 * \param char[] Mensaje que muestra al usuario que eligio la opcion 4 del menu.
 * \return void No retorna nada solo muestra los resultados de todas las operaciones.
 *
 */
void informes(float,float,float,float,float,float,int,int,char[]);


/** \brief Muestra el menu para no ocupar espacio en el main.
 *
 * \return void No retorna nada, solo muestra el menu.
 *
 */
void menu();


/** \brief Funcion que cambia el color de la consola.
 *
 * \return void No retorna nada, solo cambia el color de la consola.
 *
 */
void cambiarColor();


/** \brief Carga la pantalla.
 *
 * \return void No retorna nada.
 *
 */
void pantallaDeCarga();
