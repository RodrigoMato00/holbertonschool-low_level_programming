# Memory Maps — Task 0: AI Memory Visualizer

Análisis de memoria para los programas en `programs/` del bundle oficial [hbtn-edu/ai_memory_visualizer_valgrind_tracer](https://github.com/hbtn-edu/ai_memory_visualizer_valgrind_tracer). Cada programa se compiló con el Makefile proporcionado y se ejecutó normalmente (sin Valgrind). Se usó una herramienta IA para generar borradores de mapas; el contenido final fue revisado y corregido a mano.

---

## 1. stack_example.c

### 1.1 Programas previstos para esta tarea

Según la letra: en `programs/` están `stack_example.c` (obligatorio para memory visualizer), `heap_example.c` (opcional), `aliasing_example.c` (obligatorio). Para esta tarea se analizan los tres; crash_example corresponde a la tarea de crash report.

### 1.2 Puntos de ejecución relevantes

- **Entrada/salida de función:** `main` → `walk_stack(0, 3)` → recursión `walk_stack(1)`, `walk_stack(2)`, `walk_stack(3)`; en cada nivel se llama `dump_frame("enter", depth)` y luego `dump_frame("exit", depth)`.
- **Recursión:** `walk_stack` se llama a sí misma hasta `depth == max_depth` (3); luego vuelve desenrollando.
- **Variables locales y punteros:** En `dump_frame`: `local_int`, `local_buf[16]`, `p_local = &local_int`. En `walk_stack`: `marker = depth * 10`.

### 1.3 Stack vs heap

- **Stack:** Toda la memoria usada por este programa. Cada llamada a `main`, `walk_stack` o `dump_frame` tiene su propio frame con sus parámetros y locales. Las direcciones impresas por el programa (p. ej. `&local_int`, `&marker`) pertenecen al stack; al subir `depth`, las direcciones bajan (stack crece hacia direcciones menores).
- **Heap:** No se usa; no hay `malloc` ni `free`.

### 1.4 Mapas de memoria paso a paso (stack)

**Orden de frames en un momento de máxima profundidad (depth 3):**

De “abajo” (direcciones mayores) a “arriba” (menores):

1. **main:** frame de `main` (sin locales significativos además del retorno).
2. **walk_stack(0):** `marker = 0`; luego llama a `dump_frame("enter", 0)` (frame que ya se ha ido al retornar).
3. **walk_stack(1):** `marker = 10`.
4. **walk_stack(2):** `marker = 20`.
5. **walk_stack(3):** `marker = 30`.
6. **dump_frame("enter", 3):** `local_int = 103`, `local_buf[0] = 'D'`, `p_local = &local_int` (mismo valor que `&local_int`).

Cada vez que vuelve una llamada, su frame deja de ser válido; las direcciones que tenía (p. ej. `&marker` en depth 3) dejan de corresponder a variables “vivas”.

### 1.5 Lifetimes (stack_example)

| Variable / objeto | Vida |
|-------------------|------|
| Locales de `main` | Desde la entrada a `main` hasta que `main` retorna. |
| `marker` en `walk_stack(depth)` | Solo durante esa invocación de `walk_stack`. |
| `local_int`, `local_buf`, `p_local` en `dump_frame` | Solo durante esa invocación de `dump_frame`. |

`p_local` apunta a `local_int` dentro del mismo frame; ambos dejan de existir al retornar `dump_frame`.

---

## 2. heap_example.c

### 2.1 Puntos de ejecución relevantes

- **Asignaciones en heap:** `person_new("Alice", 30)` y `person_new("Bob", 41)` cada una hace `malloc(sizeof(Person))` y `malloc(len+1)` para el nombre.
- **Desasignación:** `free(bob->name)` y `free(bob)`; para Alice solo se llama `person_free_partial(alice)`, que hace `free(p)` del struct pero **no** `free(p->name)`.

### 2.2 Stack vs heap

- **Stack:** En `main`: variables `alice`, `bob` (punteros). En `person_new`: `i`, `len`, `p` (puntero). En `person_free_partial`: `p` (parámetro). Todas estas viven solo durante la ejecución de su función.
- **Heap:** Bloques asignados por `malloc`: (1) struct Person para Alice, (2) buffer para "Alice\0", (3) struct Person para Bob, (4) buffer para "Bob\0". Los punteros `alice`, `alice->name`, `bob`, `bob->name` guardan las direcciones de esos bloques.

### 2.3 Estados de memoria relevantes

**Después de crear alice y bob:**

- `alice` → struct Person (heap); `alice->name` → bloque con "Alice\0" (heap).
- `bob` → struct Person (heap); `bob->name` → bloque con "Bob\0" (heap).

**Después de `free(bob->name); free(bob);`:**

- El bloque del nombre de Bob y el struct de Bob terminan su vida. `bob` (variable en stack) sigue existiendo y conserva la dirección ya liberada (dangling); no se debe usar.
- Alice sigue apuntando a su struct y a su nombre; ambos siguen vivos.

**Después de `person_free_partial(alice);`:**

- Solo se libera el **struct** Person de Alice. El bloque apuntado por `alice->name` **nunca se libera** (fuga deliberada). La variable `alice` en stack sigue conteniendo una dirección que ya no es válida para el struct.

### 2.4 Lifetimes (heap_example)

| Objeto | Inicio de vida | Fin de vida |
|--------|----------------|-------------|
| Struct Person de Alice | `malloc` en `person_new` | `free(p)` en `person_free_partial(alice)` |
| Buffer "Alice" | `malloc(len+1)` en `person_new` | Nunca (leak) |
| Struct Person de Bob | `malloc` en `person_new` | `free(bob)` |
| Buffer "Bob" | `malloc(len+1)` en `person_new` | `free(bob->name)` |

### 2.5 Propiedad

- **Bob:** `main` es dueño de ambos bloques; libera primero el nombre y luego el struct.
- **Alice:** `main` libera solo el struct mediante `person_free_partial`; nadie libera el buffer del nombre → leak.

---

## 3. aliasing_example.c

### 3.1 Puntos de ejecución relevantes

- **Asignación en heap:** `make_numbers(5)` hace `malloc(5 * sizeof(int))`, rellena el array y devuelve el puntero.
- **Aliasing:** `b = a` hace que `a` y `b` apunten al **mismo** bloque.
- **Desasignación y uso posterior:** `free(a)` termina la vida del bloque; `b` sigue con la misma dirección (dangling). Las líneas `b[2]` y `b[3] = 1234` son uso-después-de-free (undefined behavior).

### 3.2 Stack vs heap

- **Stack:** En `main`: `a`, `b`, `n`. En `make_numbers`: `i`, `arr`. Solo almacenan punteros o enteros.
- **Heap:** Un único bloque de 5 `int` asignado en `make_numbers(5)`; devuelto en `a` y luego también referenciado por `b`.

### 3.3 Aliasing

- Antes de `free(a)`: `a` y `b` son **alias**: distintas variables en stack que contienen la **misma** dirección. El objeto referenciado es uno solo (el bloque de 5 int).
- Después de `free(a)`: el bloque deja de existir. `a` y `b` siguen guardando esa dirección; ambos son punteros colgantes. Cualquier lectura o escritura mediante `a` o `b` es use-after-free.

### 3.4 Lifetimes (aliasing_example)

| Objeto | Vida |
|--------|------|
| Variables `a`, `b`, `n` en `main` | Toda la ejecución de `main`. |
| Bloque de 5 int (heap) | Desde `malloc` en `make_numbers` hasta `free(a)`. |
| Variables `i`, `arr` en `make_numbers` | Solo durante la llamada a `make_numbers`. |

La salida típica muestra `a == b` (misma dirección); tras `free(a)`, usar `b[2]` o `b[3]` puede dar valores residuales o provocar fallos según el entorno (Valgrind lo denuncia).

---

## 4. Ejemplo en el que la explicación de la IA era incorrecta (y cómo se corrigió)

### 4.1 Afirmación de la IA (incorrecta)

Para **heap_example.c**, un borrador generado por IA decía:

> “`person_free_partial` libera la persona y su nombre; después de llamarla, no queda memoria asignada para Alice.”

### 4.2 Por qué es falso

- En el código, `person_free_partial` hace **solo** `free(p)`. No toca `p->name`. Por tanto solo se libera el **struct** Person; el bloque apuntado por `p->name` (el string "Alice\0") **nunca** se libera.
- Decir que “no queda memoria asignada para Alice” ignora ese segundo bloque y contradice el comentario del programa (“a deliberate leak”).

### 4.3 Formulación correcta

- **Después de `person_free_partial(alice)`:**  
  - El **struct** Person de Alice ha sido liberado; su dirección ya no es válida.  
  - El **bloque del nombre** (allocado con `malloc(len+1)` en `person_new`) **sigue asignado** y no tiene ningún puntero que lo libere en el resto del programa → **memory leak**.  
  - La variable `alice` (en stack) sigue existiendo hasta que termina `main` y sigue conteniendo la dirección del struct ya liberado (dangling).

La corrección fue: distinguir (1) el struct Person, (2) el bloque del nombre, y (3) no asumir que “liberar la persona” implica liberar el nombre sin leer el código.

---

## 5. Resumen del entregable

- **Stack vs heap:** Diferenciados en cada programa (stack_example: solo stack; heap_example y aliasing_example: stack para variables/punteros, heap para los bloques asignados).
- **Lifetimes:** Descritos de forma explícita para frames y para cada bloque relevante en heap.
- **Aliasing:** En aliasing_example, `a` y `b` referencian el mismo bloque hasta `free(a)`; después ambos son dangling.
- **Corrección a la IA:** Documentado un caso (heap_example, `person_free_partial`) en el que la explicación de la IA era incorrecta y se indica la corrección.

Las ejecuciones se realizaron tras compilar con el Makefile del repo oficial (sin Valgrind) para observar el comportamiento real de los programas.
