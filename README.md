# **So_long** 42 Madrid

Un videojuego inspirado en Pokémon en el que debes recoger todas las Pokeballs y llegar a la cesta del Profesor sin ser atacado por **Ditto** o **Snorlax**.
Este tiene una estética animada, colorida y ofrece una experiencia de juego muy divertida.

![bueno_Trim (1)](https://github.com/4g4x0r/so_long/assets/106092515/be751aac-6969-4cfd-a7b4-f4e6649ed78f)


## ¿Cómo compilo el proyecto?

¡Fácil!, el proyecto dispone de un **Makefile** con diversas instrucciones para hacer esta tarea más fácil.

**•** `Linux`

Ejecuta `make` en el directorio raíz del proyecto.
Si quisieras forzar un make completo ejecuta `make re`.


### Información relevante
Además de la ventana de juego se puede observar bastante información interesante durante la ejecución del juego en la línea de comandos.

![Desktop 04-07-2023 15-57-41_Trim](https://github.com/4g4x0r/so_long/assets/106092515/3d3b5575-457f-422f-bfdf-9bb18b7a4475)

###  Animación | Transparencia | Tasa de refresco

**•** Mientras las `entity` se desplazan de unas casillas a otras gracias de variables `float` para conseguir un efecto fluido en lugar de 
un salto de casilla a casilla voy variando sus sprites dando pasos en función de las coordenadas hacia las que se muevan.

**•** He diseñado una función que almacena una imagen sobre otra sin pintar los píxeles de un color determinado, por lo que consigo `transparencia`
y así las imagenes no son cargadas como bloques.

**•** El juego se renderiza de una sola vez almacenando cada uno de los items del mapa en un `buffer` e imprime la imagen total
en lugar de ir una a una lo cual podría aumentar significativamente el consumo de recursos. Tras imprimir el mapa hago uso de una función que he
creado para dibujar imagenes con transparencia para poner a las `entity` sobre este.
###  Sistemas de búsqueda
Durante la ejecución del programa se llevan a cabo diversos algoritmos de búsqueda.
En una primera instancia se emplea un Algoritmo DFS para comprobar que existe una ruta válida de punto `'P'` a `'E'`,
después durante todo el juego y en hilos separados los enemigos `Ditto` y `Snorlax` tratan de encontrar al `player`
através de un algoritmo de línea recta que respeta `coins`, `walls`, `exit` y a su pokecompañero y se mueven en
intervalos  diferentes a distintas velocidades.

# EXTRA

He creado un script en bash que consulta todos y cada uno de los ficheros del directorio actual y enumera sus funciones, es bastante útil.

![image](https://github.com/4g4x0r/so_long/assets/106092515/9ee4128d-95b4-4a5f-a980-aee55fab0d53)

