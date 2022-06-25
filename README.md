# tp3

Agregue un metodo a lista_escritores, le agregue el codigo al metodo de mostrar datos de escritor

Va todo bien excepto que con algunos numeros que parecen re random me anda mal el metodo obtener_escritor, como con el 3 y con el 5555. Un posible motivo seria que algo sale mal con el stoi, y posibles soluciones serian hacer que se guarde el codigo como int y no como string, o que cuando se use el metodo obtener_escritor chequee primero si el codigo que voy a pasar por parametro se encuentra en la tabla.

Tambien se podria hacer que agregar_lectura se fije primero si el escritor ya existe.

Modularizar agregar_lectura y validar cuando el usuario ingresa el tipo de lectura, que pasa si pone 4.