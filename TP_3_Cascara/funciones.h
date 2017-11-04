#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char titulo[40];
    char genero[20];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[200];
}EMovie;
/**
 *  \brief Agrega una pelicula al archivo binario
 */
void agregarPelicula();
/**
 *  \brief Borra una pelicula del archivo binario
 */
void borrarPelicula();
/**
 * \brief Pide que se ingrese el puntaje y lo verifica. No sale de la función hasta que se haya ingresado un número válido.
 * \return Retorna el número validado.
 */
int pedirPuntaje();
/**
 * \brief Pide que se ingrese la duracion y la verifica. No sale de la función hasta que se haya ingresado un número válido.
 * \return Retorna el número validado.
 */
int pedirDuracion();
/**
 * \brief Pide que se ingrese el DNI y lo verifica. No sale de la función hasta que se haya ingresado un número válido.
 * \param Recibe la cadena a buscar.
 * \return Retorna el ID de la pelicula cuyo nombre coincide, retorna -1 si no hay coincidencia.
 */
int buscarPeliculaPorTitulo(char titulo[]);
/**
 * \brief Pide los datos necesarios para guardar una pelicula en el archivo binario.
 * \param titulo
 * \param genero
 * \param descripcion
 * \param link de la imagen
 * \param puntaje
 * \param duracion
 */
void guardarPeliculaEnArchivo(char titulo[], char genero[], char descripcion[], char linkImagen[], int puntaje, int duracion);
/**
 * \brief Genera la pagina web añadiendo las peliculas del archivo binario.
 */
void generarWeb();
/**
 * \brief Añade una pelicula a la pagina web.
 * \param La pelicula a añadir.
 * \return 0 si no se guardo la pelicula, 1 si se guardo.
 */
int addMovieToWeb(EMovie pelicula);
/**
 * \brief Pide que se ingrese el ID y lo verifica. No sale de la función hasta que se haya ingresado un número válido.
 * \return Retorna el número validado.
 */
int ingresarIdPelicula();
/**
 * \brief Pide que se ingrese el titulo.
 * \param La cadena donde almacenar el titulo.
 */
void pedirTitulo(char titulo[]);
/**
 * \brief Pide que se ingrese el genero.
 * \param La cadena donde almacenar el genero.
 */
void pedirGenero(char genero[]);
/**
 * \brief Pide que se ingrese la descripcion.
 * \param La cadena donde almacenar la descripcion.
 */
void pedirDescripcion(char descripcion[]);
/**
 * \brief Pide que se ingrese el link de la imagen.
 * \param La cadena donde almacenar el link de la imagen.
 */
void pedirLink(char linkImagen[]);
/**
 * \brief Muestra las peliculas del archivo binario
 * \return 0 si no hay peliculas registradas, 1 si hay peliculas registradas.
 */
int mostrarPeliculas();

#endif // FUNCIONES_H_INCLUDED