
	███████╗ ██████╗         ██╗      ██████╗ ███╗   ██╗ ██████╗ 
	██╔════╝██╔═══██╗        ██║     ██╔═══██╗████╗  ██║██╔════╝ 
	███████╗██║   ██║        ██║     ██║   ██║██╔██╗ ██║██║  ███╗
	╚════██║██║   ██║        ██║     ██║   ██║██║╚██╗██║██║   ██║
	███████║╚██████╔╝███████╗███████╗╚██████╔╝██║ ╚████║╚██████╔╝
	╚══════╝ ╚═════╝ ╚══════╝╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ 
---
# So Long 🕹️

This project is part of the **42 School** curriculum. It is the fifth project, although it is the first graphic project in the Cursus. The project aims to create a `2D video game` using the graphic library `MiniLibX` from the campus and the C language.

## Project Description 📖

In this project, I use the ``MiniLibX`` graphic library to create a window, manipulate images, and work with keyboard events. This library is a reduced and adapted version of ``OpenGL``.

It involves a series of validations for the map passed as an argument, checks to prevent memory leaks, game engineering, managing windows, events, sprites, and maps.

In my case, I set the challenge of making it run on ``MACos``, ``Linux``, and ``Windows11``, although at the moment, ``Windows`` is **unsupported**. For this challenge, I had to create the game on MACos and later adapt it to Linux, since ``MiniLibX`` was originally built for ``MACos``, and when adapting it to ``Linux``, most functions and hooks had their names changed or even their forms.

## Prerequisites ⚠️

If you want to download my repo and try it out, you must consider your operating system.

<!-- TODO: pendiente añadir sistema de descarga y ejecución -->

## Compilation Instructions 📐

1. Clone this repository to your local machine.
2. Navigate to the project directory.
3. Run the compilation command to generate the executable.

<!-- TODO:pendiente añadir intrucciones -->

## Usage 🤟

Once compiled, run the program, and you can interact with the window using the keyboard.

<!-- TODO: pendiente explicar uso -->


## Sprites 🎞️

The images of the sprites must be in ``.xpm`` format. If you want to create your sprites, follow these steps:

1. **Find** or **create** sprites in any image format.
2. Resize them in any editing program to ``64px x 64px``.
(``64px`` is not arbitrary; my project is defined like that, check what you need in your case).
3. Transform to the ``.xpm`` format through [Convertio](https://convertio.co/es/png-xpm/).

## Controls 🎮


| KEY 		 |	OBJECT   		 |
| -----------|------------------ |
| `W` or ⬆️	 |    Move up  		|
| `A` or ⬅️  |    Move left 	|
| `S` or ⬇️  |    Move down  	|
| `D` or ➡️  |   Move right		|      
| `Q` or Esc |   Close the game  | 

## Map 🗺️

You can create another map if you wish, as it can analyze any type of map, as long as it follows these rules:

- The map must be a .ber file.
- It can only contain these characters:
- It must be rectangular and surrounded by walls.
- The map must contain at least one exit, one collectible, and an initial position.


|	OBJECT    | CHAR 	  |
| ------------| --------- |
|   Wall      | 1         |
|   Coin      | C	      |
|   Exit      | E	      |
|   Player    | P         |      
|   Floor     | 0         |

*See some examples in the /assets/maps folder 🗺️.*

ejemplo:

	11111111111
	10C0P1C0011
	10000100001
	1C0000C0001
	111C01E00C1
	11111111111

## Contact 📩

Si tienes alguna pregunta o sugerencia, no dudes en ponerte en contacto.



<!-- # So Long

Este proyecto forma parte del curso de **42 School**. Es el quinto proyecto aunque es el primer proyecto gráfico del Cursus.  El proyecto trata de crear un **videojuego en 2D** utilizando la biblioteca gráfica ``MiniLibX`` del campus y el lenguaje C.

## Descripción del proyecto

En este proyecto, utilizo la biblioteca gráfica ``MiniLibX`` para crear una ventana, manipular imágenes y trabajar con eventos de teclado.
Esta libreria es una version reducida y readaptada de `OpenGl`.

It involves a series of validations from the map that is passed as argument, checks to prevent memoy leaks, the game engineering, managing windows, events, sprites and maps.

En mi caso, me he puesto como reto la posibilidad de ejecutarlo en `MACos`, `Linux` y `Windows11`, aunque por el momento `Windows` está **sin soporte**. Para este reto, he tenido que crear el juego en `MACos` y posteriormente adaptarlo a `Linux`, ya que `MinilibX` originalmente se construyó para `MACos` y al adaptarla a `Linux` la mayoria de funciones y hooks fueron cambiadas de nombre o incluso de forma.

## Requisitos previos

Si quieres descargar mi repo y probarlo, debes tener en cuenta tu sistema operativo

## Instrucciones de compilación

1. Clona este repositorio en tu máquina local.
2. Navega hasta el directorio del proyecto.
3. Ejecuta el comando de compilación para generar el ejecutable.

## Uso

Una vez compilado, ejecuta el programa y podrás interactuar con la ventana utilizando el teclado y el ratón.


## Contacto

Si tienes alguna pregunta o sugerencia, no dudes en ponerte en contacto.

## Sprites
Las imagenes de los sprites deben estar en formato `.xpm`.
En el caso de querer crear tus propios sprites debes:
1. **Buscar** o **crear** sprites en cualquier formato de imagen.
2. Redimensionarlas en algún programa de edición a `64px x 64px`.
(`64px` no es arbitrario, mi proyecto está definido asi, revisa que necesitas en tu caso).
1. Transformar al formato `.xpm` a traves de [Convertio](https://convertio.co/es/png-xpm/).

---

## Controls


| KEY 		 |	OBJECT   		 |
| -----------|------------------ |
| `W` or ⬆️	 |    Move up  		|
| `A` or ⬅️  |    Move left 	|
| `S` or ⬇️  |    Move down  	|
| `D` or ➡️  |   Move right		|      
| `Q` or Esc |   Close the game  | 

---
## Mapa

Puedes crear otro mapa si lo deseas, ya que puede analizar cualquier tipo de mapa. siempre que respete las siguientes reglas:
- El mapa debe ser un archivo .ber.
- sólo puede contener estos caracteres:
- Debe ser rectangular y estar rodeado por las paredes.
- El mapa debe contener al menos una salida, un coleccionable y una posición inicial.

|	OBJECT    | CHAR 	  |
| ------------| --------- |
|   Wall      | 1         |
|   Coin      | C	      |
|   Exit      | E	      |
|   Player    | P         |      
|   Floor     | 0         |

*Consulte algunos ejemplos en la carpeta /assets/maps 🗺️.*

ejemplo:

	11111111111
	10C0P1C0011
	10000100001
	1C0000C0001
	111C01E00C1
	11111111111

 -->