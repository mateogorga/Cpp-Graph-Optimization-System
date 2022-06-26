# tp3
Victoria: 
Ingreso de datos (getline)
Autores en tabla de Hashing
Agregue un metodo a lista_escritores, le agregue el codigo al metodo de mostrar datos de escritor

Va todo bien excepto que con algunos numeros que parecen re random me anda mal el metodo obtener_escritor, como con el 3 y con el 5555. Un posible motivo seria que algo sale mal con el stoi, y posibles soluciones serian hacer que se guarde el codigo como int y no como string, o que cuando se use el metodo obtener_escritor chequee primero si el codigo que voy a pasar por parametro se encuentra en la tabla.

Mateo:
Impresion de texto que avisa que no se leyeron los archivos
Arbol expansion minima

Marco:
    *¿parches de ultimo minuto de la lista aux para que no tenga leaks? (menu.cpp 385)

    *Parser_lecturas::procesar_autor cambiar la forma de relacionarlos (ahora busca por posicion en la lista
        debe buscar por ISNI) 
        --> ver como hace  vicky la tabla

    *Grafo
        -->hacer cpp y h
        -->generalizarlo? facilitar metodos de alta y baja? (unificar aristas con pesos)
        -->integrarlo al resto del tp
