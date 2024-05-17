# cub3d
> This repository contains a "Cub3D" project that is part of the École 42 curriculum.
## PROJECT TREE

```
.
├── MLX42/
├── inc
│   ├── cub3D.h
│   └── cub_structs.h
├── libft/
├── maps/
├── textures/
├── objs/
├── src
│   ├── main.c
│   ├── parser
│   │   ├── char_check.c
│   │   ├── colour_handle.c
│   │   ├── get_map.c
│   │   ├── parse.c
│   │   ├── read_file.c
│   │   ├── read_scene.c
│   │   ├── scene_check.c
│   │   └── wall_check.c
│   ├── render
│   │   ├── 3Der.c
│   │   ├── map.c
│   │   ├── paint.c
│   │   ├── player.c
│   │   └── raycast.c
│   └── utils
│       ├── candle.c
│       ├── clean_handling.c
│       ├── collision.c
│       ├── controls.c
│       ├── error_handling.c
│       ├── load_images.c
│       └── window.c
└── Makefile
```

The goal of ``cub3d`` is to make *something* using raycasting (like [Wolfenstein 3D](https://fr.wikipedia.org/wiki/Wolfenstein_3D)).
This project’s objectives are similar to all this first year’s objectives: Rigor, use of C, use of basic algorithms, information research etc.
As a graphic design project, cub3D will enable you to improve your skills in these areas: windows, colors, events, fill shapes, etc.
To conclude cub3D is a remarkable playground to explore the playful practical applications of mathematics without having to understand the specifics.
With the help of the numerous documents available on the internet, you will use mathematics as a tool to create elegant and efficient algorithms.

<div align="center">
  <img src="https://github.com/MofMiq/cub3d/blob/main/readme%20images/mandatory.gif" width="600"/>
</div>

## Rules
The constraints are as follows: \
• We must use the miniLibX or MLX42. Either the version that is available on the operating system, or from its sources. \
• The management of the window must remain smooth: changing to another window, minimizing, etc.\
• Display different wall textures (the choice is yours) that vary depending on which side the wall is facing (North, South, East, West). \
• The program must be able to set the floor and ceiling colors to two different ones. \
• The program must take as a first argument a scene description file with the .cub extension. \
• The map must be composed of only 6 possible characters: 0 for an empty space, 1 for a wall, and N,S,E or W for the player’s start position and spawning orientation. We must check for any possible parsing error.

## Bonus
• Wall collisions ✅ \
• A minimap system ✅ \
• Animated sprite ✅ \
• Rotate the point of view with the mouse ✅ \
• Doors which can open and close ❌

# ⚡RAYCAST TUTORIAL⚡
### Variables necesarias antes de lanzar el rayo

- Coordenadas de la posición del jugador (serán el origen del rayo)
- Ángulo del rayo y del jugador
- Campo de visión
- Ancho de ventana

### Variables necesarias durante y después del lanzamiento

- Vector direccional del rayo
- Puntos de cruce con los ejes *x* e *y* del rayo
- Coordenadas de colisión con el muro
- Orientación del muro (para cargar las texturas)
- Longitud del rayo y distancia del personaje al muro (no son exactamente lo mismo)

### Sobre el ángulo del rayo

Al igual que el ángulo del personaje, en ningún caso puede sobrepasar los 360º. Deberá mantenerse siempre en la horquilla de 0 a 360º. Por tanto, cuando sea menor a 0, deberemos sumarle 360º o 2π si trabajamos en radianes. Cuando sea mayor a 360º, se los restaremos.

Otra cuestión a tener en consideración es que, en nuestro caso, el eje **y** se encuentra invertido. Es decir, aumentar nuestro valor en y, no implicará subir sino bajar. Esto se debe a que, al estar trabajando con una matriz de caracteres, la coordenada (0,0) se encuentra en la esquina superior izquierda. Por tanto, si queremos dirigirnos al norte, disminuiremos el valor de y, y si queremos dirigirnos al sur, lo aumentaremos. De forma, que nuestro norte se encuentra en 270º:
<p align="center">
  <img src="https://github.com/erivero-p/cub3d/blob/main/readme%20images/coord.png" width="450" height="450" alt="Nombre alternativo">
</p>

Al calcular el vector de dirección del jugador o de los rayos, sabremos que el seno se encuentra invertido [cos$α$, - sin$α$]. Sin embargo, si consideramos desde el inicio que el norte se corresponde con 270º, no tendremos que invertir el seno. De forma que, el vector unitario de un personaje que spawnea mirando al norte será `[0, -1]`, ya que, si nos moviésemos una casilla, x no cambiaría e y decrecería en 1.
# Lanzamiento de un rayo

### Inicialización

Lo primero que haremos será setear el punto de origen del rayo en las coordenadas del personaje. También podremos tomar el ángulo del rayo y calcular el vector direccional del mismo, sabiendo que en x será el coseno del ángulo y en y será el seno.

Será conveniente que, conociendo el vector direccional del rayo, guardemos el signo del mismo, para saber hacia dónde tendremos que movernos en x y en y para seguir el trazado del rayo.

```c
  ray->sgn.x = 1;
	ray->sgn.y = 1;
	if (ray->dir.x < 0)
		ray->sgn.x *= -1;
	if (ray->dir.y < 0)
		ray->sgn.y *= -1;
```

También será conveniente que conozcamos qué ángulo se forma entre la dirección del jugador, y el rayo que estamos lanzando.

## ¿Cómo recorrer el rayo?

No es necesario analizar todo el recorrido del rayo, ya que, dentro de las coordenadas del mapa, ya conocemos previamente que los muros ocupan una casilla completa. Por tanto, siempre se van a encontrar en coordenadas enteras. De esta forma, sólo tendremos que analizar aquellos puntos en los que el rayo se cruza con las casillas en x (en rojo) o y (en verde). Es decir, las coordenadas en las que x ó y sean enteros.

![rayo1.png](https://github.com/erivero-p/cub3d/blob/main/readme%20images/xy_cross.png)

Dependiendo del ángulo del rayo, la posición de los muros, y la posición de nuestro personaje, que no siempre será entera, a veces lo oportuno será chequear los cruces con el eje x y otras veces los cruces con el eje y. Por tanto, deberemos chequear ambos para después seleccionar la colisión más próxima con un muro.

La idea será, calcular el tamaño de los pasos a dar, es decir, cuánto debemos movernos para encontrar un cruce con un eje, y, tras el mismo, comprobar en nuestra matriz del mapa si en la siguiente casilla hay un `‘1’`.

## Cálculo de los pasos

Para recorrer los cruces verticales las casillas (y_cross), deberemos movernos horizontalmente (ya sea a derecha o a izquierda) una casilla completa. Lo mismo sucede para los cruces horizontales (x_cross). En este caso, nos deberemos desplazar una casilla completa en y.

![Y_CROSS.png](https://github.com/erivero-p/cub3d/blob/main/readme%20images/xy_steps.png)

Por tanto, tenemos que, en los cruces con el eje *x*, la altura (seno) siempre va a ser el alto de la casilla (1 ó -1 dependiendo de si miramos arriba o abajo). Y que en los cruces con el eje *y*, el ancho del paso (coseno) se corresponderá con el ancho de las casillas. Para calcular las dos medidas restantes, como tenemos el ángulo, haremos uso de: 

$tan(α) = sin(α)/cos(α)$ → $cos = sin(α)/tan(α)$ → $sin(α) = cos(α) * tan(α)$

Por tanto, en los x_cross, el ancho será $1 / tan(α)$ y en los y_cross, el alto será $tan(α) *  1$

En este caso, dado que los pasos nos dan la información de en cuánto debemos aumentar las coordenadas en x e y para encontrarnos con el siguiente cruce, deberemos tener muy en cuenta el signo. Si nuestro personaje mira al norte, la y deberá ser negativa. Lo mismo sucede con x si nuestro personaje mira al oeste. Es un buen momento para hacer uso de la variable signo en caso de que la guardáramos 

Todos los pasos miden lo mismo, con una excepción: el primero.

### El primer paso

Nuestro personaje, y por tanto el origen de nuestro rayo, no siempre se encontrará en coordenadas enteras. Habrá ocasiones en las que se encuentre en el interior de las casillas, por ejemplo, en la coordenada (3.5, 4.7). Por tanto, el primer paso siempre será más pequeño que los demás.

<p align="center">
    <img src="https://github.com/erivero-p/cub3d/blob/main/readme%20images/primer%20paso.png" width="450" height="450" alt="Nombre alternativo">
</p>

De nuevo, nos encontramos con problemas de signo. No podemos simplemente restarle el flotante de la posición de nuestro personaje al tamaño del paso, ya que, dependiendo de hacia dónde mire el rayo, el resultado debe ser distinto. Es decir:

En un cruce con el eje x, la variable que se castea a entero es la y. Esto querrá decir que después del primer paso que demos, y debe estar en una posición entera. Concretamente deberá ser casteada al alza si el rayo mira hacia abajo, y casteada a la baja si miramos hacia arriba.

Es decir, si nuestro rayo en origen tiene su coordenada y en (3.5) y mira al norte, tras el primer paso deberemos chequear la coordenada (3.0), y si mira al sur, deberemos chequear la coordenada (4.0).

La variable restante, en este caso la x, la calcularemos igual que hicimos anteriormente, utilizando la tangente del ángulo.

## Colisiones

A la hora de calcular si el rayo está o no colisionando contra un muro, habrá también que tener en cuenta que, si el personaje mira hacia arriba o hacia la izquierda, la distancia que nos dará al muro será mayor de lo que realmente es. Esto se debe a que los muros ocupan una casilla entera, por lo que si un muro se encuentra en la coordenada (0, 3) y nuestro personaje se encuentra debajo, el rayo debería chocar con la cara sur del muro, que estará en (1, 3).

Deberemos, por tanto, corregir estas casuísticas. No podremos simplemente mirar si nuestro vector direccional es negatrivo y restar 1 a x o y, ya que habrá casos en los que el vector direccional será negativo tanto en x como en y, y si restamos 1 a ambas coordenadas, estaremos desplazándonos diagonalmente. ¿La solución? Hacer que este arreglo dependa, no sólo de la dirección del rayo, sino también de si estamos mirando un x_cross o un y_cross.

<p align="center">
    <img src="https://github.com/erivero-p/cub3d/blob/main/readme%20images/colisiones_mal.png" width="450" height="450" alt="Nombre alternativo">
</p>
Con todo esto, ya podremos saber qué longitud tiene el rayo, y en qué punto de la casilla colisiona con el muro, lo cual es necesario para cargar las texturas. Necesitaremos también tomar la orientación del muro con el que nuestro rayo está colisionando.

### Orientación del muro

Al tener el punto en el que colisionamos con el muro, conoceremos si lo estamos haciendo por alguna de sus caras horizontales o verticales. Si hemos colisionado horizontalmente, querrá decir que nuestro valor en y es entero. Es decir, que estamos en un x_cross. Si hemos colisionado verticalmente será porque estábamos revisando los y_cross, y el valor de x será entero.

Conociendo ésto, sólo tendremos que revisar el vector de dirección para decidir si la orientación es norte o sur (en los x_cross), o si es este u oeste (en los y_cross).

<p align="center">
    <img src="https://github.com/erivero-p/cub3d/blob/main/readme%20images/orientacin.png" width="450" height="450" alt="Nombre alternativo">
</p>

## Cálculo de la distancia y escalado

Una vez hemos encontrado la colisión, ya sabremos en cuánto tenemos que aumentar x e y en la dirección del rayo para alcanzar un muro. Es decir, ya tendremos el tamaño de los catetos. La longitud del rayo será, por tanto, la hipotenusa.

Sin embargo, para obtener la distancia del jugador a los muros, no podremos tomar directamente la longitud del rayo. Esto se debe a que, los rayos que se alejen más del centro del abanico de rayos que hemos lanzado, medirán más que los del centro, aunque los muros se encuentren a la misma distancia. De hacerlo así, tendríamos un efecto ojo de pez. Para evitarlo, deberemos trazar una línea imaginaria transversal al vector de dirección de nuestro personaje, y calcular la distancia del punto de colisión a la misma.

![distancia1.png](https://github.com/erivero-p/cub3d/blob/main/readme%20images/col_distance.png)

¿Cómo haremos esto? Considerando que la distancia real del personaje a los muros va a depender, no sólo de la longitud del rayo, sino también, de cuánto se aleja éste del rayo central, correspondiente al vector de dirección del personaje. Será tan sencillo como tomar la longitud del rayo y multiplicarla por el coseno del ángulo que se forma entre el rayo, y el vector de dirección del personaje.

### Escalado

Para el escalado podemos, simplemente, decidir qué altura queremos que tenga en píxeles un muro a longitud 1,  y dividirlo entre la distancia que acabamos de calcular, de forma que, a mayor distancia, menor será nuestro muro a escala.

También es posible tener en cuenta la distancia entre el jugador y el plano de proyección (la vista de la ventana), aunque no es lo que hemos hecho en este caso.

Para calcular la distancia del jugador al plano de proyección tomaremos la amplitud del campo de visión y lo dividiremos en dos, para formar un triángulo rectángulo con el plano de proyección. Sabiendo, que la ventana, de ancho, son 1080 píxeles, tomaremos también la mitad para obtener el seno de ese triángulo. De forma que:

$tan(α) = sin(α)/cos(α)$ → $cos = 540/tan(45)$

![plano-proyecc](https://github.com/erivero-p/cub3d/blob/main/readme%20images/plano_proyecci%C3%B3n.png)

Con este dato, y teniendo en cuenta que desde el jugador al muro, y desde el jugador al plano de proyección, se forman dos triángulos equivalentes o similares, es decir, que comparten tangente, podremos calcular la escala. 

![plano2](https://github.com/erivero-p/cub3d/blob/main/readme%20images/plano2.png)

altura(real) / distancia al muro = altura (escalada) / distancia al plano

Altura escalada del muro = altura del muro / distancia al muro * distancia al plano

# Lanzamiento del abanico de rayos

Deberemos lanzar tantos rayos como columnas de píxeles tenga nuestra ventana. En mi caso, 1080. Y éstos, deben cubrir el campo de visión que elijamos, en mi caso, 90º.

Conociendo ésto, hay diferentes formas de espaciar los rayos entre sí. Si simplemente dividimos el número de rayos entre el campo de visión, para que los rayos tengan entre sí, una diferencia del mismo ángulo, tendremos un poco de efecto ojo de pez, ya que, cuando los rayos choquen contra el plano de proyección, no lo harán de forma equidistante, sino que habrá más densidad de rayos en el centro

<p align="center">
    <img src="https://github.com/erivero-p/cub3d/blob/main/readme%20images/deltaang-mal.png" width="450" height="450" alt="Nombre alternativo">
</p>

En mi caso, para asegurarme de que todos los rayos tocan el plano de proyección a la misma distancia, he tomado como referencia el plano de proyección dividido en 1080 partes iguales, y conociendo ya la distancia del personaje al plano de proyección ya tengo el seno del triángulo formado entre el rayo central, y el rayo lanzado. Obtendré el coseno teniendo en cuenta en qué iteración esté, y con esto tendré el ángulo entre el rayo central y el rayo lanzado.

<p align="center">
    <img src="https://github.com/erivero-p/cub3d/blob/main/readme%20images/deltaang-bien.png" width="450" height="450" alt="Nombre alternativo">
</p>
